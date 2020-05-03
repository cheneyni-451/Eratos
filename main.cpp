#include <iostream>
#include <cmath>
#include <vector>

std::vector<unsigned long int> getPrimes(unsigned long int limit) {
    bool * is_prime = new bool[limit - 1];
    for (unsigned long int i = 0; i < limit - 1; ++i) { is_prime[i] = true; }

    for (unsigned long int i = 2; i <= static_cast<unsigned long int>(pow(limit, 0.5)); ++i) {
        if (is_prime[i - 2]) {
            for (unsigned long int j = static_cast<unsigned long int>(pow(i, 2)); j <= limit; j += i) {
                is_prime[j - 2] = false;
            }
        }
    }

    std::vector<unsigned long int> primes;
    for (unsigned long int i = 0; i < limit - 1; ++i) {
        if (is_prime[i])
            primes.push_back(i + 2);
    }

    delete[] is_prime;

    return primes;
}

unsigned long int greatest_prime(unsigned long int limit) {
    std::vector<unsigned long int> p = getPrimes(limit);
    if (p.size() != 0)
        return p[p.size() - 1];
    else
        return -1;
}

int main(int argc, char * argv[]) {
    if (argc == 2) {
        unsigned long int lim = std::atoi(argv[1]);/* 
        std::vector<long> primes = getPrimes(lim);
        for (const long & i : primes) {
            std::cout << i << '\n';
        } */
        std::cout << greatest_prime(lim) << '\n';
        return 0;
    }
    return 1;
}
