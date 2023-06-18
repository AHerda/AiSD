#include "bin.h"

auto BHeap::combineTrees(Node *root1, Node *root2)->void
{
    counter_increase();
    if(root1->key < root2->key){
        std::swap(root1,root2);
    }
    
    root1->parent = root2;
    root1->sibling = root2->child;
    root2->child = root1;
    
    root2->order = root2->order + 1;
}

auto BHeap::combineHeaps(BHeap *heap1, BHeap *heap2)->Node*
{
    Node *temp1 = new Node(0);
    Node *temp2 = temp1;
    
    Node *root1 = heap1->head;
    Node *root2 = heap2->head;
    
    if (root1 == nullptr) return root2;
    if (root2 == nullptr) return root1;
    
    while (root1 != nullptr || root2 != nullptr)
    {
        if (root1 == nullptr)
        {
            temp2->sibling = root2;
            temp2 = temp2->sibling;
            root2 = root2->sibling;
        }
        else if (root2 == nullptr)
        {
            temp2->sibling = root1;
            temp2 = temp2->sibling;
            root1 = root1->sibling;
        }
        else
        {
            if (root1->order < root2->order)
            {
                temp2->sibling = root1;
                temp2 = temp2->sibling;
                root1 = root1->sibling;
            }
            else
            {
                temp2->sibling = root2;
                temp2 = temp2->sibling;
                root2 = root2->sibling;
            }
        }
    }
    return (temp1->sibling);
}

BHeap::BHeap()
{
    this->head = nullptr;
    reset_counter();
}

BHeap::BHeap(Node* root)
{
    this->head = root;
    reset_counter();
}

auto BHeap::isEmpty()->bool
{
    return (this->head == nullptr);
}

auto BHeap::insert(Node* root)->void
{
    
    BHeap* newHeap=new BHeap(root);
    this->unionHeap(newHeap);
}

auto BHeap::unionHeap(BHeap *heap)->void
{
    BHeap *heap_final = new BHeap();
    
    heap_final->head = combineHeaps(this, heap);
    
    if (heap_final->head == nullptr)
    {
        this->head = nullptr;
        this->min = nullptr;
        return;
    }
    
    Node *prev = nullptr;
    Node *curr = heap_final->head;
    Node *next = curr->sibling;
    
    while (next != nullptr)
    {
        if (curr->order != next->order){
            prev = curr;
            curr = next;
        }
        else if( curr->order == next->order && next->sibling != nullptr && next->sibling->order == curr->order){
            prev = curr;
            curr = next;
        }
        else if (curr->key <= next->key){
            counter_increase();
            curr->sibling = next->sibling;
            combineTrees(next, curr);
        }
        else{
            counter_increase();
            if (prev == nullptr) heap_final->head = next;
            else prev->sibling = next;
            combineTrees(curr, next);
            curr = next;
        }
        next = curr->sibling;
    }
    
    this->head = heap_final->head;
    
    this->min = heap_final->head;
    curr = this->head;
    while (curr != nullptr)
    {
        counter_increase();
        if (curr->key < this->min->key) this->min = curr;
        curr = curr->sibling;
    }
}

auto BHeap::first()->Node*
{
    return this->min;
}

auto BHeap::extractMin()->Node*
{
    Node *mini = this->first();
    
    Node *prev = nullptr;
    Node *curr1 = this->head;
    while (curr1 != mini)
    {
        prev = curr1;
        curr1 = curr1->sibling;
    }
    
    if (prev == nullptr) this->head = curr1->sibling;
    
    else prev->sibling = curr1->sibling;
    
    Node *RevNode = nullptr;
    Node *curr2 = mini->child;
    while (curr2 != nullptr)
    {
        Node *next = curr2->sibling;
        curr2->sibling = RevNode;
        RevNode = curr2;
        curr2 = next;
    }
    
    BHeap *temp = new BHeap();
    temp->head = RevNode;
    this->unionHeap(temp);
    
    //return minimum node.
    return mini;
}

auto BHeap::decreaseKey(Node *root, int val)->void
{
    counter_increase();
    if(val > root->key){
        std::cerr << "Error! New value greater than current key!\n";
        return;
    }
    
    root->key = val;
    
    Node *temp1 = root;
    Node *temp2 = temp1->parent;
    if(temp2 != nullptr) {
        counter_increase();
        while (temp1->key < temp2->key)
        {
            counter_increase();
            std::swap(temp1->key, temp2->key);
            
            temp1 = temp2;
            
            temp2 = temp1->parent;

            if(temp2 != nullptr) break;
        }
    }

    counter_increase();
    if (temp1->key < this->min->key) this->min = temp1;
}


auto BHeap::Delete(Node *root)->void
{
    decreaseKey(root, INT_MIN);
    extractMin();
}

auto BHeap::printTree(Node* root)->void
{
    
    if(root==nullptr){
        return;
    }
    
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        std::cout << node->key << " ";


        if (node->child != nullptr) {
            Node* temp = node->child;
                while (temp != nullptr) {
                    q.push(temp);
                    temp = temp->sibling;
                }
        } 
    }
}

auto BHeap::printHeap()->void
{
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << "B" << curr->order << std::endl;
        std::cout << "There are " << std::pow(2, curr->order) << " nodes in this binomial tree" << std::endl;
        std::cout << "The level order traversal of the tree is ";
        this->printTree(curr);
        curr = curr->sibling;
        std::cout << std::endl << std::endl;
    }
}

auto BHeap::reset_counter()->void
{
    counter_if = 0;
    counter_if_temp = 0;
}

auto BHeap::reset_counter_temp()->void
{
    counter_if_temp = 0;
}

auto BHeap::get_counter()->int
{
    return counter_if;
}

auto BHeap::get_counter_temp()->int
{
    int temp = counter_if_temp;
    reset_counter_temp();
    return temp;
}

auto BHeap::counter_increase()->void
{
    counter_if++;
    counter_if_temp++;
}