#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    int arr[m][4];
    for(int i=0;i<m;i++) {
        for(int j=0;j<4;j++) {
            cin>>arr[i][j];
        }
    }
    int cnt = 0;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(arr[i][0] <= a[j] and arr[i][1] >= a[j]) {
                cnt++;
            }else if(arr[i][2] <= a[j] and arr[i][3] >=a[j]) {
                cnt++;
            }
        }
        cout << cnt << endl;
        cnt = 0;
    }
}