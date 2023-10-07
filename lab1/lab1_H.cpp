#include <iostream>

using namespace std;

 

int main() {

    int i, n;

    bool isPrimeNumber = true;

    cin >> n;

    if (n == 0 || n == 1) {

        isPrimeNumber = false;

    }

    else {

        for (i = 2; i <= n / 2; ++i) {

            if (n % i == 0) {

                isPrimeNumber = false;

                break;

            }

        }

    }

    if (isPrimeNumber)

        cout << "YES";

    else

        cout << "NO";

 

    return 0;

}

 