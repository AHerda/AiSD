#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <memory>
#include <random>

enum class Dir {
    UP,
    LEFT,
    DIAG,
    NONE
};

int counter_if;

auto string_generator(const int len) -> std::string
{
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string s = "";

    std::mt19937 mt(std::random_device{}());
    for (int i = 0; i < len; i++)
        s += alphabet[mt() % alphabet.length()];
    return s;
}

auto lcs_print(std::string& odp, std::vector<std::vector<Dir>> dirs, std::string A, int n, int m) -> void
{
    counter_if+=2;
    if(n == 0 || m == 0) {
        return;
    }
    counter_if++;
    if(dirs[n][m] == Dir::DIAG) {
        lcs_print(odp, dirs, A, n - 1, m - 1);
        odp = odp + A[n];
    }
    else if(dirs[n][m] == Dir::UP) {
        counter_if++;
        lcs_print(odp, dirs, A, n - 1, m - 1);
    }
    else {
        counter_if++;
        lcs_print(odp, dirs, A, n, m - 1);
    }
}

auto lcs_print2(std::vector<std::vector<int>> len, std::string A, int n, int m) -> std::string
{
    std::string odp = "";
    counter_if++;
    while(len[n][m] != 0) {
        counter_if+=3;
        while(len[n][m] == len[n - 1][m]) {
            n--;
            counter_if++;
        }
        while(len[n][m] == len[n][m - 1]) {
            m--;
            counter_if++;
        }
        n--;
        m--;
        odp = A[n] + odp;
    }

    return odp;
}

auto lcs(std::string A, std::string B, bool wypisz = false) -> std::pair<int, std::string>
{
    const int n = A.length();
    const int m = B.length();

    std::vector<std::vector<int>> len(n + 1);

    for (int i = 0; i <= n; i++){
        len[i] = std::vector<int>(m + 1, 0);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            counter_if++;
            if (A[i-1] == B[j-1]) {
                len[i][j] = 1 + len[i-1][j-1];
            }
            else if(len[i - 1][j] > len[i][j - 1]){
                counter_if++;
                len[i][j] = len[i - 1][j];
            }
            else {
                counter_if++;
                len[i][j] = len[i][j - 1];
            }
        }
    }

    if(wypisz) {
        std::cout << "odp:\n    ";
        for (auto i : B) {
            std::cout << i << ' ';
        }
        std::cout << "\n";
        for (int i = 0; i <= n; i++) {
            std::cout << A[i] << " | ";
            for (int j = 0; j <= m; j++) {
                std::cout << len[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }

    std::string odp;
    odp = lcs_print2(len, A, n, m);

    return std::pair(len[n][m], odp);
}

void runTests()
{
    std::ofstream outputFile("results.txt");

    for(int n = 1000; n <= 10000; n+=1000) {
        for(int i = 0; i < 20; i++)
        {
            std::string str1 = string_generator(n);
            std::string str2 = string_generator(n);

            counter_if = 0;

            auto start = std::chrono::high_resolution_clock::now();
            auto result = lcs(str1, str2);
            auto end = std::chrono::high_resolution_clock::now();

            auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

            //std::cout << n << " " << result.first << " " << result.second << std::endl;

            outputFile << n << " " << time << " " << counter_if << " " << result.first << std::endl;
        }
    }

    outputFile.close();
}

int main()
{
    /*std::string str1 = string_generator(20);
    std::string str2 = string_generator(20);

    auto result = lcs(str1, str2, true);

    std::cout  << str1 << std::endl;
    std::cout  << str2 << std::endl;

    std::cout << "Dlugosc NWP: " << result.first << "\nNWP: " << result.second << std::endl;*/

    runTests();

    return 0;
}