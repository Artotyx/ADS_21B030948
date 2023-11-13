#include <iostream>
using namespace std;
int binary_search(int ar[],int sizeOfArr, int x) {
    int left = 0;
    int right = sizeOfArr - 1;
    while(left <= right) {
        int mid = (left+right)/2;
        if(ar[mid] == x) {
            return mid;
        }else if(x < ar[mid]) {
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    int f;
    cin >> f;
    if(binary_search(a, n, f) != -1) {
        cout << "Yes";
    }else{
        cout << "No";
    }
}