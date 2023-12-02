// B-Plagiarism
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
int rabinKarp(string &s, string& t){
    int ans = 0;
    if(t.size() > s.size()) return 0;
    ll smallHash = my_hash(t);
    vector <ll> hashes(s.size());
    ll curP = 1;
    for(int i=0;i<s.size();i++){
        hashes[i] = (s[i] - 'a' + 1) * curP % q;
        if(i){
            hashes[i] = (hashes[i] + hashes[i-1]) % q;
        }
        curP = (curP * p) % q;
    }
    for(int i=0;i<s.size() - t.size() + 1;i++){
        ll hashDiff = hashes[i + t.size() - 1];
        if(i) hashDiff -= hashes[i-1];
        if(hashDiff < 0) hashDiff += q;
        if(i) smallHash = (smallHash * p) % q;
        if(smallHash == hashDiff){
            if(mp.find(i) != mp.end()){
                ans++;
            }
            mp[i] = 1;
        }
    }
    return ans;
}
int main(){
    string s, s1, t;
    cin >> s >> s1 >> t;
    int x = rabinKarp(s, t);
    int y = rabinKarp(s1, t);
    cout << x + y << endl;
    return 0;
}
