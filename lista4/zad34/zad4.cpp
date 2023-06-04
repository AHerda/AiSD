#include <iostream>
#include <fstream>
#include <vector>

#include "RBBST.hpp"
#include "generator.hpp"

int main(int argc, char** argv) {
    std::ofstream myfile;
    myfile.open("zad41.txt");

    for(int n = 10000; n <= 100000; n += 10000) {
        for(int i = 0; i < 20; i++) {
            RBBST drzewo = RBBST();

            std::vector<int> liczby1;
            generator_asc(liczby1, n);
            for(int x : liczby1) {
                drzewo.insert(x);
            }

            std::vector<int> liczby2;
            generator_rand(liczby2, n);
            for(int x : liczby2) {
                drzewo.remove(x);
            }
            myfile << n << " " << drzewo.counter_if << " " << drzewo.counter_swap << " " << drzewo.height() << std::endl;
        }
    }

    myfile.close();

    myfile.open("zad42.txt");

    for(int n = 10000; n <= 100000; n += 10000) {
        for(int i = 0; i < 20; i++) {
            RBBST drzewo = RBBST();

            std::vector<int> liczby1;
            generator_rand(liczby1, n);
            for(int x : liczby1) {
                drzewo.insert(x);
            }

            std::vector<int> liczby2;
            generator_rand(liczby2, n);
            for(int x : liczby2) {
                drzewo.remove(x);
            }
            myfile << n << " " << drzewo.counter_if << " " << drzewo.counter_swap << " " << drzewo.height() << std::endl;
        }
    }

    myfile.close();
    
    return 0;
}