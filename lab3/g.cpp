#include <bits/stdc++.h>

using namespace std;

bool checker(vector<int> a, int n, int x, int h){
    int t = 0;
    for(int i = 0; i < n; i++){
        t += (a[i] + x - 1) / x;
    }
    return t <= h;
}

int main(){
    int n, h; 
    cin >> n >> h;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a.push_back(x);
    }
    int l = 1, r = *max_element(a.begin(), a.end()) + 1;
    while(r - l > 1){
        int mid = l + (r - l) / 2;
        if(checker(a, n, mid, h)) r = mid;
        else l = mid;
    }
    cout << r;
}