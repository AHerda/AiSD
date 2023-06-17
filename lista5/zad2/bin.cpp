#include "bin.h"


BinHeap::BinHeap()
{
    head = nullptr;
}

auto BinHeap::getHead() -> std::shared_ptr<Node>
{
    return this->head;
}

auto BinHeap::setHead(std::shared_ptr<Node> head) -> void
{
    this->head = head;
}

auto BinHeap::minimum() -> std::shared_ptr<Node>
{
    std::shared_ptr<Node> y = nullptr;
    std::shared_ptr<Node> x = head;

    int min = INT_MAX;

    while(x) {
        if(x->key < min) {
            min = x->key;
            y = x;
        }
        x = x->sibling;
    }

    return y;
}





/**
 * Dodatkowe funkcje
*/

auto link(std::shared_ptr<Node> head1, std::shared_ptr<Node> head2) -> void
{
    head2->parent = head1;
    head2->sibling = head1->child;
    head1->child = head2;
    head1->degree++;
}


// Raczej żle!!!
auto merge(std::shared_ptr<BinHeap> H1, std::shared_ptr<BinHeap> H2) -> std::shared_ptr<Node>
{
    std::shared_ptr<Node> head1 = H1->getHead();
    std::shared_ptr<Node> head2 = H2->getHead();
    std::shared_ptr<std::shared_ptr<Node>> result;

    while(head1 && head2) {
        if(head1->degree < head2->degree) {
            *result = head1;
            head1 = head1->sibling;
        }
        else {
            *result = head2;
            head2 = head2->sibling;
        }
        result = ((*result)->sibling);
    }
}

auto bhUnion(std::shared_ptr<BinHeap> H1, std::shared_ptr<BinHeap> H2) -> std::shared_ptr<BinHeap>
{
    std::shared_ptr<BinHeap> H(new BinHeap());
    H->setHead(merge(H1, H2));
    H1->~BinHeap();
    H2->~BinHeap();

    if(H->getHead() == nullptr) return H;

    std::shared_ptr<Node> prev = nullptr;
    std::shared_ptr<Node> x = H->getHead();
    std::shared_ptr<Node> next = x->sibling;

    while(next) {
        if(x->degree != next->degree || (next->sibling && next->sibling->degree == x->degree)) {
            prev = x;
            x = next;
        }
        else {
            if(x->key <= next->key) {
                x->sibling = next->sibling;
                link(x, next);
            }
            else {
                if(prev == nullptr) {
                    H->setHead(next);
                }
                else {
                    prev->sibling = next;
                }
                link(next, x);
                x = next;
            }
        }
        next = x->sibling;
    }

    return H;
}