#include "generator.hpp"
#include "BST.hpp"
#include <vector>

int main(int argc, char** argv) {
    BST* drzewo1 = new BST();
    BST* drzewo2 = new BST();

    std::vector<int> liczby1;
    std::vector<int> liczby2;
    generator_asc(liczby1, 50);
    generator_rand(liczby2, 50);

    for(int i : liczby1) {
        std::cout << "insert(" << i << ")" << std::endl;
        drzewo1->insert(i);
        drzewo1->print_BST();
    }

    generator_asc(liczby1, 50);

    for(int i : liczby1) {
        std::cout << "remove(" << i << ") " << drzewo1->remove(i) << std::endl;
        drzewo1->print_BST();
    }

    for(int i : liczby2) {
        std::cout << "insert(" << i << ")" << std::endl;
        drzewo2->insert(i);
        drzewo2->print_BST();
    }

    for(int i : liczby1) {
        std::cout << "remove(" << i << ") " << drzewo2->remove(i) << std::endl;
        drzewo2->print_BST();
    }

    return 0;
}