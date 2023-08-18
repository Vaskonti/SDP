#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>

using ull_t = unsigned long long;
#define N 3
#define M 4

size_t numberOfDigits(size_t a, size_t b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    size_t digitsCount = 0;
    ull_t product = (ull_t) a * b;

    while (product > 0) {
        product/= 10;
        digitsCount++;
    }
    return digitsCount;
}

size_t numberOfDigitsMaths(size_t a, size_t b) {
    return (size_t) (log10(a) + log10(b) + 1);
}

bool isPrime(size_t a) {
    if (a < 2) {
        return false;
    }
    if (a == 2) {
        return true;
    }
    if (a % 2 == 0) {
        return false;
    }
    for (int i = 2; i < a ; ++i) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

bool isPrimeOptimized(size_t a) {
    if (a < 2) {
        return false;
    }
    if (a == 2) {
        return true;
    }
    if (a % 2 == 0) {
        return false;
    }
    size_t root = sqrt(a);
    for (size_t i = 3; i <= root ;i++) {
        if (a % i == 0)
            return false;
    }
    return true;
}
bool isInteger(double num) {
    return std::abs(num - std::round(num)) < 1e-9;
}

void primeToN(size_t n) {
    for (int i = 2; i <= n ; ++i) {
       if (isPrimeOptimized(i)) {
           std::cout << i << " ";
       }
    }
    std::cout<<std::endl;
}
void reduceToPrimeMultipliers(size_t n) {
    size_t currProduct = 1;
    size_t copy = n;
    for (int i = 2; i <= copy; ++i) {
        if (currProduct == copy) {
            return;
        } else {
           if (isPrimeOptimized(i) && n % i == 0) {
               while (n % i == 0) {
                   std::cout << i << " ";
                   currProduct *= i;
                   n /= i;
               }
           }
        }
    }
}

void reduceToSimpleSums(size_t n, size_t currentSum,size_t last, std::vector<size_t>& combination, std::vector<std::vector<size_t>> & results ) {
    if (currentSum == n) {
        results.push_back(combination);
        return;
    }
    for (size_t i = last; i <= n - currentSum ; ++i) {
        combination.push_back(i);
        reduceToSimpleSums(n, currentSum + i, i, combination, results);
        combination.pop_back();
    }
}

std::vector<std::vector<size_t>> getCombinations(size_t n) {
    std::vector<size_t> combinations;
    std::vector<std::vector<size_t>> results;
    reduceToSimpleSums(n, 0, 1, combinations, results);
    return results;
}

void addMatrices(int mx1 [][N], int mx2 [][N]) {
    for (size_t i= 0;  i < M; i++) {
        for (size_t j = 0; j < N ; ++j) {
            std::cout << mx1[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (size_t i= 0;  i < M; i++) {
        for (size_t j = 0; j < N ; ++j) {
            std::cout << mx2[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    int result[M][N];
    for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < N ; ++j) {
            result[i][j] = mx1[i][j] + mx2[i][j];
        }
    }
    for (size_t i = 0; i < M; ++i) {
        for (size_t j = 0; j < N; ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool isPerfectNumber(size_t n) {
    size_t sum = 0;

    for (int i = 1; i < n ; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

void getFirstNPerfect(size_t n) {
    uint64_t tryWithThis = 0;
    for (size_t i = 0; i < n ; tryWithThis++) {
        if (isPerfectNumber(tryWithThis)) {
            i++;
            std::cout << tryWithThis << " ";
        }
    }
}

bool isMersenNumber(size_t n) {
    double numberPow2 = log2(n + 1);
    return isInteger(numberPow2) && isPrimeOptimized(numberPow2);
}

void getFirstNMercenNumbers(size_t n) {
    uint64_t num = 0;
    for (size_t tries = 0; tries < n; num++) {
        if (isMersenNumber(num)) {
            std::cout << num << " ";
            tries++;
        }
    }
}
std::vector<size_t> getPrimeDivisors(size_t n) {
    size_t copy = n;
    size_t prod = 1;
    std::vector<size_t> divisors;
    for (int i = 2; i <= copy ; ++i) {
        if (prod == copy) {
            break;
        }
        if (isPrimeOptimized(i) && n % i == 0) {
            while (n % i == 0) {
                prod *= i;
                divisors.push_back(i);
                n /= i;
            }
        }
    }
    return divisors;
}
size_t sumDigits(size_t n) {
    size_t sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
bool isSmithNumber(size_t n) {
    size_t sumDigit = sumDigits(n);
    std::vector<size_t> divisors = getPrimeDivisors(n);
    size_t sumDivisors = 0;
    for (const auto & num: divisors) {
        if (num > 10) {
            sumDivisors += sumDigits(num);
        } else {
            sumDivisors += num;
        }
    }
    return sumDigit == sumDivisors;
}

void getFirstNSmithNumbers(size_t n) {
    uint64_t num = 0;
    for (size_t tries = 0; tries < n ; num++) {
        if (isSmithNumber(num)) {
            tries++;
            std::cout << num << " ";
        }
    }
}

int main() {
    getFirstNSmithNumbers(24);
//    std::cout << isSmithNumber(666) << std::endl;
}