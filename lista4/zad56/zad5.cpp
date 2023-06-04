#include "generator.hpp"
//#include "SBST.hpp"
#include "SBST.hpp"

#include <iostream>
#include <vector>

int main(int argc, char** argv) {
    SBST* drzewo1 = new SBST();
    SBST* drzewo2 = new SBST();

    std::vector<int> liczby1;
    std::vector<int> liczby2;
    generator_asc(liczby1, 50);
    generator_rand(liczby2, 50);

    for(int i : liczby1) {
        std::cout << "\ninsert(" << i << ")" << std::endl;
        drzewo1->insert(i);
        drzewo1->print_BST();
    }

    generator_asc(liczby1, 50);

    for(int i : liczby1) {
        drzewo1->remove(i);
        std::cout << "\nremove(" << i << ") " << std::endl;
        drzewo1->print_BST();
    }

    for(int i : liczby2) {
        std::cout << "\ninsert(" << i << ")" << std::endl;
        drzewo2->insert(i);
        drzewo2->print_BST();
    }

    for(int i : liczby1) {
        drzewo2->remove(i);
        std::cout << "\nremove(" << i << ") " << std::endl;
        drzewo2->print_BST();
    }

    return 0;
}