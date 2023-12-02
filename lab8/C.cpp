// C-Big (and not baby) tape
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll q = 1e9 + 7;
ll p = 31;
map<int, int> mp;
ll my_hash(string & s) {
    ll hash = 0;
    ll curP = 1;
    for (int i = 0; i < s.size(); i ++){
        ll curHash = (s[i] - 'a' + 1) * curP % q;
        hash = (hash + curHash) % q;
        curP = (curP * p) % q;
    }
    return hash;
}
void rabinKarp(string & s, string & t,vector<long long>& hashes, vector<bool>& a) {
    int ans = 0;
    ll smallHash = my_hash(t);
    for (int i = 0; i < s.size() - t.size() + 1; i ++){
        ll hashDiff = hashes[i + t.size() - 1];
        if(i != 0) hashDiff -= hashes[i - 1];
        if (hashDiff < 0) hashDiff += q;
        if (i != 0) smallHash = (smallHash * p) % q;
        if (smallHash == hashDiff){
            for (int j = i; j < i + t.size(); j++){
                a[j] = true;
            }
        }
    }
}
int main() {
    string s; cin >> s;
    vector<long long> hashes(s.size());
    vector<bool> a(s.size());
    ll curP = 1;
    for (int i = 0; i < s.size(); i++){
        hashes[i] = (s[i] - 'a' + 1) * curP % q;
        if (i){
            hashes[i] = (hashes[i] + hashes[i - 1]) % q;
        }
        curP = (curP * p) % q;
    }
    int x; cin >> x;
    while(x--){
        string str; cin >> str;
        rabinKarp(s, str, hashes, a);
    }
    for (int i = 0; i < s.size(); i ++){
        if (!a[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}