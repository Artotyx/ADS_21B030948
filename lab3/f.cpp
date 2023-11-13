#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector <int> t;
    for (int i=0; i<n; ++i){
        int x;
        cin>>x;
        t.push_back(x);
    }
    int k;
    cin>>k;
     sort(t.begin(),t.end());
    for (int i=0; i<k; ++i){
        int p;
        cin>>p;
   
        int cnt=0;
        int sum=0;
        for(int i=0; i<n;++i){
            
            if(p>=t[i]){
                cnt++;
                sum+=t[i];
            }
            else{
                break;
            }    
        }
    
        cout << cnt <<" "<<sum << endl;
    }    
}