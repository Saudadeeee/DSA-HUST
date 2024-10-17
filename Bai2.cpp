#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

bool isBlum(int num) {
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            int q = num / i;
            // Check if both factors are prime and of the form p ≡ 3 (mod 4)
            if (isPrime(i) && isPrime(q) && i % 4 == 3 && q % 4 == 3) {
                return true;
            }
        }
    }
    return false;
}

vector<int> findBlumNumbers(int N) {
    vector<int> blumNumbers;
    for (int i = 6; i < N; ++i) {
        if (isBlum(i)) {
            blumNumbers.push_back(i);
        }
    }
    return blumNumbers;
}

bool isBlumInArray(const vector<int>& blumNumbers, int M) {
    for (int num : blumNumbers) {
        if (num == M) return true;
    }
    return false;
}

void findBlumPairs(const vector<int>& blumNumbers, int N) {
    for (size_t i = 0; i < blumNumbers.size(); ++i) {
        for (size_t j = i + 1; j < blumNumbers.size(); ++j) {
            int sum = blumNumbers[i] + blumNumbers[j];
            if (isBlum(sum) && sum < N) {
                cout << "(" << blumNumbers[i] << ", " << blumNumbers[j] << "co tong la so Blum " << sum << endl;
            }
        }
    }
}

int main() {
    int N, M;
    cout << "Nhap so N: ";
    cin >> N;
    cout << "Nhap so M: ";
    cin >> M;

    vector<int> blumNumbers = findBlumNumbers(N);

    cout << "Blum numbers smaller than " << N << ": ";
    for (int num : blumNumbers) {
        cout << num << " ";
    }
    cout << endl;
    if (isBlumInArray(blumNumbers, M)) {
        cout << M << " La so Blum trong day" << endl;
    } else {
        cout << M << " Khong phai so Blum trong day" << endl;
    }
    cout << "Cap so Blum co tong la mot so Blum trong day nho hon " << N << ":" << endl;
    findBlumPairs(blumNumbers, N);

    return 0;
}
