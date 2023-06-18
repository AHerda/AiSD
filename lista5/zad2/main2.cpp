#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <memory>
#include "fibb.h"

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
        file.open("wyniki/fibb_1_n_500_" + std::to_string(i) + ".txt");
        reset();

        std::shared_ptr<FibHeap> H1(new FibHeap());
        file << end() << " " << H1->get_counter_temp() << std::endl;
        std::shared_ptr<FibHeap> H2(new FibHeap());
        file << end() << " " << H2->get_counter_temp() << std::endl;

        Node* helper;

        for(int n = 0; n < 500; n++) {
            H1->insert(new Node(mt() % (2 * 500)));
            file << end() << " " << H1->get_counter_temp() << std::endl;

            H2->insert(new Node(mt() % (2 * 500)));
            file << end() << " " << H2->get_counter_temp() << std::endl;
        }

        H1->Union(&(*H2));
        file << end() << " " << H1->get_counter_temp() << std::endl;

        for(int n = 0; n < 1000; n++) {
            helper = H1->extractMin();
            file << end() << " " << H1->get_counter_temp() << std::endl;
            std::cout << helper->key << std::endl;
        }

        file.close();
        H1->reset_counter();
        H2->reset_counter();
    }

    for(int i = 1; i <= 5; i++){
        file.open("wyniki/fibb_1_n_1000_" + std::to_string(i) + ".txt");
        reset();

        std::shared_ptr<FibHeap> H1(new FibHeap());
        file << end() << " " << H1->get_counter_temp() << std::endl;
        std::shared_ptr<FibHeap> H2(new FibHeap());
        file << end() << " " << H2->get_counter_temp() << std::endl;

        Node* helper;

        for(int n = 0; n < 1000; n++) {
            H1->insert(new Node(mt() % (2 * 1000)));
            file << end() << " " << H1->get_counter_temp() << std::endl;

            H2->insert(new Node(mt() % (2 * 1000)));
            file << end() << " " << H2->get_counter_temp() << std::endl;
        }
    
        H1->Union(&(*H2));
        file << end() << " " << (H1->get_counter_temp() + H2->get_counter_temp()) << std::endl;

        for(int n = 0; n < 2000; n++) {
            helper = H1->extractMin();
            file << end() << " " << H1->get_counter_temp() << std::endl;
            std::cout << helper->key << std::endl;
        }

        file.close();
    }

    file.open("wyniki/fibb_2.txt");
    for(int n = 100; n <= 10000; n+=100){
        reset();

        std::shared_ptr<FibHeap> H1(new FibHeap());
        std::shared_ptr<FibHeap> H2(new FibHeap());

        Node* helper;

        for(int i = 0; i < n; i++) {
            H1->insert(new Node(mt() % (2 * n)));
            H2->insert(new Node(mt() % (2 * n)));
        }

        int counter = H1->get_counter_temp() + H2->get_counter_temp();

        H1->Union(&(*H2));

        for(int i = 0; i < 2 * n; i++) {
            helper = H1->extractMin();
            std::cout << helper->key << std::endl;
        }

        file << n << " " << (H1->get_counter_temp() + counter) << std::endl;
        H2->reset_counter();
        H1->reset_counter();
    }
    file.close();

    return 0;
}