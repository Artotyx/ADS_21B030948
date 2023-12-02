// D-Dominating Patterns
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll q = 1e9 + 7;
ll p = 31;
map <int, int> mp;
ll my_hash(string& s){
    ll hash = 0;
    ll curP = 1;
    for(int i=0;i<s.size();i++){
        ll curHash = (s[i] - 'a' + 1) * curP % q;
        hash = (hash + curHash) % q;
        curP = (curP * p) % q;
    }
    return hash;
}
void rabinKarp(string& s, pair <string, int>& t, int& mx){
    if(t.first.size() > s.size()) return ;
    ll smallHash = my_hash(t.first);
    vector <ll> hashes(s.size());
    ll curP = 1;
    for(int i=0;i<s.size();i++){
        hashes[i] = (s[i] -'a' + 1) * curP % q;
        if(i){
            hashes[i] = (hashes[i] + hashes[i-1]) % q;
        }
        curP = (curP * p) % q;
    }
    for(int i=0;i<s.size()-t.first.size() + 1;i++){
        ll hashDiff = hashes[i+t.first.size()-1];
        if(i) hashDiff -= hashes[i-1];
        if(hashDiff<0) hashDiff += q;
        if(i) smallHash = (smallHash * p) % q;
        if(smallHash == hashDiff){
            t.second++;
            mx=max(mx, t.second);
        }
    }
}
int main(){
    while(true){
        int q; cin >> q;
        if(q==0) break;
        pair <string, int> str[q];
        for(int i=0;i<q;i++){
            cin >> str[i].first;
            str[i].second = 0;
        }
        string s; cin >> s;
        int mx = -1;
        for(int i=0;i<q;i++){
            rabinKarp(s, str[i], mx);
        }
        cout << mx << endl;
        for(int i=0;i<q;i++){
            if(str[i].second == mx){
                cout << str[i].first << endl;
            }
        }
    }
}