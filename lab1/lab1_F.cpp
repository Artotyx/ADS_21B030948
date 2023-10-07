#include <iostream>

using namespace std;

bool isPrime(int num) {
    if (num < 2)
        return false;

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int f(int n) {
    int count = 0;
    int num = 2;

    while (count < n) {
        if (isPrime(num)) {
            ++count;
        }
        if (count == n)
            break;
        ++num;
    }

    return num;
}

int main() {
    int n;
    cin >> n;

    if (n < 1 || n > 1000) {
        cerr << "N should be between 1 and 1000." << endl;
        return 1;
    }

    int nth = f(n);
    cout << nth << endl;

    return 0;
}
