#include <bits/stdc++.h>
using namespace std;

int get(const string& s) {
    return round((log(5)/2+(s.size()-1)*log(10)+
    log(stod(s.substr(0, 20).insert(1, "."))))/log((1+sqrt(5))/2));
}

int main(void) {
    string s;
    while (cin >> s)
        cout << get(s) << endl;
    return 0;
}