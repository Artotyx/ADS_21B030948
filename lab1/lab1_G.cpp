#include <cstdio>
bool isPrime(int n) {
    for (int d=2; d<=n/d; d++) {
        if (n%d==0) {
            return false;
        }
    }
    return n>1;
}
int main() {
    int need;
    scanf("%d", &need);
    int p1 = 0;
    int p2 = 0;
    for (int i=1; ; i++) {
        if (isPrime(i)) {
            p1++;
            if (isPrime(p1)) {
                p2++;
                if (p2==need) {
                    printf("%d", i);
                    return 0;
                }
            }
        }
    }
}