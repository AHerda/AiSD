#include "fibb.h"

FibHeap::FibHeap()
{
    reset_counter();
    this->min = nullptr;
    this->N = 0;
}

FibHeap::FibHeap(Node *n)
{
    reset_counter();
    this->min = n;
    n->left = n->right = n;
    n->parent = n->child = nullptr;
    
    this->N = 1;
}

auto FibHeap::isEmpty() -> bool
{
    return (this->min == nullptr);
}

auto FibHeap::insert(Node *n) -> void
{
    this->Union(new FibHeap(n));
}

auto FibHeap::Union(FibHeap *h) -> void
{
    this->N += h->N;
    if (h->isEmpty()) return;
    if (this->isEmpty())
    {
        this->min = h->min;
        return;
    }
    Node *first1 = this->min;
    Node *last1 = this->min->left;
    Node *first2 = h->min;
    Node *last2 = h->min->left;
    first1->left = last2;
    last1->right = first2;
    first2->left = last1;
    last2->right = first1;

    counter_increase();
    if (h->min->key < this->min->key) this->min = h->min;
}

auto FibHeap::first() -> Node*
{
    return this->min;
}

auto FibHeap::extractMin() -> Node*
{
    Node *ret = this->min;
    this->N = this->N - 1;
    
    if (ret->right == ret)
    {
        this->min = nullptr;
    }
    else
    {
        Node *prev = ret->left;
        Node *next = ret->right;
        prev->right = next;
        next->left = prev;
        this->min = next; // Not necessarily a minimum. This is for assisting with the merge w/ min's children.
    }
    
    if (ret->child != nullptr)
    {
        Node *firstChd = ret->child;
        Node *currChd = firstChd;
        
        do
        {
            currChd->parent = nullptr;
            currChd = currChd->right;
        } while (currChd != firstChd);
        
        if (this->isEmpty())
        {
            this->min = firstChd;
        }
        else
        {
            Node *first1 = this->min;
            Node *last1 = this->min->left;
            Node *first2 = firstChd;
            Node *last2 = firstChd->left;
            first1->left = last2;
            last1->right = first2;
            first2->left = last1;
            last2->right = first1;
        }
    }
    
    if (this->min != nullptr)
    {
        int maxAuxSize = 5 * (((int)log2(this->N + 1)) + 1);
        std::vector<Node*> aux(maxAuxSize + 1);
        for (int i=0;i<=maxAuxSize;i++) aux[i] = nullptr;
        int maxDegree = 0;
        
        Node *curr = this->min;
        
        do
        {
            Node *next = curr->right;
            int deg = curr->degree;
            Node *P = curr;
            while (aux[deg] != nullptr)
            {
                Node *Q = aux[deg];
                aux[deg] = nullptr;
                
                counter_increase();
                if (P->key > Q->key)
                {
                    Node *tmp = P;
                    P = Q;
                    Q = tmp;
                }
                
                Q->parent = P;
                if (P->child == nullptr)
                {
                    P->child = Q;
                    Q->left = Q->right = Q;
                }
                else
                {
                    Node *last = P->child->left;
                    last->right = Q;
                    Q->left = last;
                    P->child->left = Q;
                    Q->right = P->child;
                }
                
                deg++;
                P->degree = deg;
            }
            aux[deg] = P;
            if (deg > maxDegree) maxDegree = deg;
            curr = next;
        } while (curr != this->min);
        
        
        Node *previous = aux[maxDegree];
        this->min = previous;
        for (int i=0;i<=maxDegree;i++)
        {
            if (aux[i] != nullptr)
            {
                previous->right = aux[i];
                aux[i]->left = previous;
                
                counter_increase();
                if (aux[i]->key < this->min->key) this->min = aux[i];
                previous = aux[i];
            }
        }
        
    }
    
    return ret;
}

auto FibHeap::decreaseKey(Node *n, int newKey) -> void
{
    // Precondition: newKey < n->key
    n->key = newKey;
    
    Node *curr = n;
    if (curr->parent != nullptr)
    {
        counter_increase();
        if (curr->key < curr->parent->key)
        {
            Node *parent = curr->parent;
            curr->marked = false;
            
            curr->parent = nullptr;
            if (curr->right == curr) parent->child = nullptr;
            else
            {
                Node *prev = curr->left;
                Node *next = curr->right;
                prev->right = next;
                next->left = prev;
                if (parent->child == curr) parent->child = prev;
            }
            parent->degree = parent->degree - 1;
            
            Node *last = this->min->left;
            last->right = curr;
            curr->left = last;
            this->min->left = curr;
            curr->right = this->min;
            
            counter_increase();
            if (curr->key < this->min->key) this->min = curr;
            
            while (parent->parent != nullptr && parent->marked)
            {
                curr = parent;
                parent = curr->parent;
                curr->marked = false;
                
                curr->parent = nullptr;
                if (curr->right == curr) parent->child = nullptr;
                else
                {
                    Node *prev = curr->left;
                    Node *next = curr->right;
                    prev->right = next;
                    next->left = prev;
                    if (parent->child == curr) parent->child = prev;
                }
                parent->degree = parent->degree - 1;
                
                Node *last = this->min->left;
                last->right = curr;
                curr->left = last;
                this->min->left = curr;
                curr->right = this->min;
                
            }
            if (parent->parent != nullptr) parent->marked = true;
        }
    }
    else if (n->key < this->min->key) {
        counter_increase();
        this->min = n;
    }
    else {
        counter_increase();
    }
}

auto FibHeap::Delete(Node *n) -> void
{
    this->decreaseKey(n, INT_MIN);
    this->extractMin();
}

auto FibHeap::reset_counter() -> void
{
    counter_if = 0;
    counter_if_temp = 0;
}

auto FibHeap::reset_counter_temp() -> void
{
    counter_if_temp = 0;
}

auto FibHeap::get_counter() -> int
{
    return counter_if;
}

auto FibHeap::get_counter_temp() -> int
{
    int temp = counter_if_temp;
    reset_counter_temp();
    return temp;
}

auto FibHeap::counter_increase() -> void
{
    counter_if++;
    counter_if_temp++;
}