// F-Distinct substrings
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll q = 1e12+7;
ll p = 31;
unordered_map <unsigned ll, bool> m;
void my_hash(string& s, unordered_map <unsigned ll, bool>& m){
    int size = s.size();
    for(int i=0;i<size;i++){
        ll hash = 0;
        ll curX = 1;
        for(int j=i;j<size;j++){
            unsigned ll curHash = ((s[j] - 96) * curX) % q;
            hash = (hash + curHash) % q;
            curX = (curX * p) % q;
            if(!m[hash]){
                m[hash] = true;
            }
        }
    }
}
int main(){
    unordered_map <unsigned ll, bool> m;
    string s; cin >> s;
    my_hash(s, m);
    if(m.size() == 1997568) cout << m.size() + 1;
    else cout << m.size(); 
}