#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int binary_search(int target){
	int left = 0;
	int right = v.size() - 1;
    int res = -1;
	while (left <= right){
		int mid = left + (right - left) / 2;
		if (v[mid] <= target){
            res = mid;
            left = mid + 1;
        }
		else right = mid - 1;
	}
    if(res == -1) return 0;
    return res + 1;
}

int ans(int l, int r){
    return binary_search(r) - binary_search(l - 1);
}

int main(){
    int n;
    unsigned long long k;
    cin >> n >> k;
    vector<int> result;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < k; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(r2 < l1 || r1 < l2){
            int res = ans(l1, r1) + ans(l2, r2);
            cout << res << "\n";
        } 
        else{
            int mini = min(l1, l2);
            int maxi = max(r1, r2);
            cout << ans(mini, maxi) << "\n";
        }
    }     
}