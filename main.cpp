#include <iostream>
#include <vector>

class EratosSieve {
private:
    int * arr;
    bool * is_prime;
    int limit;

public:
    EratosSieve(int n) : limit(n) {
        arr = new int[n - 1];
        is_prime = new bool[n - 1];
        for (int i = 2; i <= limit; ++i) {
            arr[i - 2] = i;
            is_prime[i - 2] = true;
        }
    }

    EratosSieve(const EratosSieve & other) : limit(other.limit) {
        arr = new int[other.limit - 1];
        is_prime = new bool[other.limit - 1];
        for (int i = 2; i <= limit; ++i) {
            arr[i - 2] = other.arr[i - 2];
            is_prime[i - 2] = other.is_prime[i - 2];
        }
    }

    EratosSieve & operator=(const EratosSieve & rhs) {
        if (this != &rhs) {
            limit = rhs.limit;

            delete[] arr;
            delete[] is_prime;

            arr = new int[limit - 1];
            is_prime = new bool[limit - 1];

            for (int i = 0; i < limit - 1; ++i) {
                arr[i] = rhs.arr[i];
                is_prime[i] = rhs.is_prime[i];
            }
        }
        return *this;
    }

    ~EratosSieve() {
        delete[] arr;
        delete[] is_prime;
    }

    std::vector<int> get_primes() {
        std::vector<int> primes;
        int i = 0;
        int p = arr[0];

        while (i < limit - 1) {
            primes.push_back(p);
            for (int mults = 2 * p; mults <= limit; mults += p) {
                is_prime[mults - 2] = false;
            }
            ++i;
            // finds the next integer that is marked true
            while (!is_prime[i]) {
                ++i;
            }
            p = arr[i];
        }

        return primes;
    }
};

int main(int argc, char * argv[]) {
    int lim = std::atoi(argv[1]);
    EratosSieve s(lim);
    std::vector<int> p = s.get_primes();
    for (int & i : p) {
        std::cout << i << '\n';
    }
    return 0;
}
