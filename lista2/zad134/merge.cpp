#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include "sorts.hpp"

int main(int argc, char** argv) {
    int* tab;
    if(argc == 1) {
        setbuf(stdin, NULL);
        scanf("%d", &size_global);

        tab = new int[size_global];

        for(int i = 0; i < size_global; i++) {
            scanf("%d", &(tab[i]));
        }
    }
    else {
        size_global = argc - 1;
        tab = new int[size_global];

        for(int i = 1; i < argc; i++) {
            sscanf(argv[i], "%d", &(tab[i - 1]));
        }
    }

    if(size_global < 40) {
        print_tab(tab, size_global);
    }

    merge_sort(tab, 0, size_global - 1);

    if(size_global < 40) {
        print_tab(tab, size_global);
    }

    if(size_global < 40) { std::cout << std::endl << "n | # Prównań kluczy | # Podmian kluczy " << std::endl; }
    std::cout << size_global << " " << counter_if << " " << counter_swap << std::endl;

    for(int i = 0; i + 1 < size_global; i++) {
        if(tab[i] > tab[i + 1]) return 0;
    }
    return 1;
}


std::string merge_sort(int* tab, int const begin, int const end)
{
    if (begin >= end)
        return std::to_string(end + 1 - begin) + " " + std::to_string(counter_if) + " " + std::to_string(counter_swap) + "\n";;
 
    int mid = begin + (end - begin) / 2;
    merge_sort(tab, begin, mid);
    merge_sort(tab, mid + 1, end);
    merge(tab, begin, mid, end);

    if(size_global < 40) {
        print_tab(tab, end + 1, begin);
    }

    return std::to_string(end + 1 - begin) + " " + std::to_string(counter_if) + " " + std::to_string(counter_swap) + "\n";
}

void merge(int* tab, int const left, int const mid, int const right) {
    int size_left = mid - left + 1;
    int size_right = right - mid;
 
    int* tab_left = new int[size_left];
    int* tab_right = new int[size_right];
 
    for (int i = 0; i < size_left; i++)
        tab_left[i] = tab[left + i];
    for (int j = 0; j < size_right; j++)
        tab_right[j] = tab[mid + 1 + j];
 
    int li = 0;
    int ri = 0;
    int i = left;
 
    while (li < size_left && ri < size_right) {

        counter_if++;
        if (tab_left[li] <= tab_right[ri]) {
            tab[i] = tab_left[li];
            li++;
        }
        else {
            tab[i] = tab_right[ri];
            ri++;
        }
        i++;
        
        counter_swap++;
    }

    while (li < size_left) {
        tab[i] = tab_left[li];
        li++;
        i++;

        counter_swap++;
    }

    while (ri < size_right) {
        tab[i] = tab_right[ri];
        ri++;
        i++;

        counter_swap++;
    }

    delete[] tab_left;
    delete[] tab_right;
}
