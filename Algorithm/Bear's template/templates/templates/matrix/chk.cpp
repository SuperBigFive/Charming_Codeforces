#include <bits/stdc++.h>
using namespace std;

int main(int, char** argv) {
    ifstream i1("ans");
    ifstream i2("out");
    int n = atoi(argv[1]);
    for (int i = 0; i < n * n; ++i) {
        int x, y;
        i1 >> x;
        i2 >> y;
        if (x != y) {
            cout << "Wrong Answer" << endl;
            exit(1);
        }
    }
    cout << "Accepted" << endl;
    return 0;
}