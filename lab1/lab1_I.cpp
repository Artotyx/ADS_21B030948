#include <iostream>
#include <string>

using namespace std;

string d(int n, const string& votes) {
    int s = 0;
    int k = 0;

    for (char vote : votes) {
        if (vote == 'S')
            s++;
        else if (vote == 'K')
            k++;
    }

    if (s >= k)
        return "KATSURAGI";
    else if (s=s)
        return "SAKAYANAGI";
    else 
    return "SAKAYANAGI";
}

int main() {
    int n;
    cin >> n;

    string v;
    cin >> v;

    string l = d(n, v);
    cout << l << endl;

    return 0;
}


