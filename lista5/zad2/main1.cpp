#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <memory>
#include "bin.h"

int operacja;

void reset() {
    operacja = 0;
}

int end() {
    operacja++;
    return operacja - 1;
}

int main(int argc, char** argv) {
    std::mt19937 mt(std::random_device{}());

    std::ofstream file;

    for(int i = 1; i <= 5; i++){
        file.open("wyniki/1_n_500_" + std::to_string(i) + ".txt");
        reset();

        std::shared_ptr<BHeap> H1(new BHeap());
        file << end() << " " << H1->get_counter_temp() << std::endl;
        std::shared_ptr<BHeap> H2(new BHeap());
        file << end() << " " << H2->get_counter_temp() << std::endl;

        Node* helper;

        int liczba;

        for(int n = 0; n < 500; n++) {
            H1->insert(new Node(mt() % (2 * 500)));
            file << end() << " " << H1->get_counter_temp() << std::endl;

            H2->insert(new Node(mt() % (2 * 500)));
            file << end() << " " << H2->get_counter_temp() << std::endl;
        }

        H1->unionHeap(&(*H2));
        file << end() << " " << (H1->get_counter_temp() + H2->get_counter_temp()) << std::endl;

        for(int n = 0; n < 1000; n++) {
            helper = H1->extractMin();
            file << end() << " " << H1->get_counter_temp() << std::endl;
            std::cout << helper->key << std::endl;
        }

        file.close();
    }

    for(int i = 1; i <= 5; i++){
        file.open("wyniki/1_n_1000_" + std::to_string(i) + ".txt");
        reset();

        std::shared_ptr<BHeap> H1(new BHeap());
        file << end() << " " << H1->get_counter_temp() << std::endl;
        std::shared_ptr<BHeap> H2(new BHeap());
        file << end() << " " << H2->get_counter_temp() << std::endl;

        Node* helper;

        int liczba;

        for(int n = 0; n < 1000; n++) {
            H1->insert(new Node(mt() % (2 * 1000)));
            file << end() << " " << H1->get_counter_temp() << std::endl;

            H2->insert(new Node(mt() % (2 * 1000)));
            file << end() << " " << H2->get_counter_temp() << std::endl;
        }

        H1->unionHeap(&(*H2));
        file << end() << " " << (H1->get_counter_temp() + H2->get_counter_temp()) << std::endl;

        for(int n = 0; n < 2000; n++) {
            helper = H1->extractMin();
            file << end() << " " << H1->get_counter_temp() << std::endl;
            std::cout << helper->key << std::endl;
        }

        file.close();
    }

    return 0;
}