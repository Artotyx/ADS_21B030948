#include <bits/stdc++.h>
using namespace std;
#define longg long long

string hashh(string s, int x = 1e9 + 7, int y = 11){
    longg p = 1; longg res = 0;
    for(int i = 0; i < s.size(); i++){
        res = (res + ((s[i] - 47) * p) % x) % x;
        p = (p * y) % x;
    }
    return to_string(res);
}


int main(){
    int n, cnt = 0; 
    cin >> n;
    vector <string> v;
    map <string, string> mp;

    for(int i = 0; i < n*2; i++){
        string s; cin >> s;
        v.push_back(s);
        mp.insert({s, hashh(s)});
    }

    for(auto i : v){
        string str = hashh(i);
        if(mp.find(str) != mp.end()){
            cout << "Hash of string \"" << i << "\" is " << str << "\n";
            cnt++;
        }
        if(cnt == n){
            break;
        }
    }
}