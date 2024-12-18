#include <bits/stdc++.h>
using namespace std;

//  vector
vector<int> getz(const string& s) {
    int n = s.size();
    vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i != n; ++i) {
        int j = z[i - l];
        if (i+j>r) for (j=max(0, r-i); i+j!=n&&s[i+j]==s[j]; ++j);
        z[i] = j;
        if (i+j-1>r) l=i, r=i+j-1;
    }
    z[0] = n;
    return z;
}

vector<int> gete(const string& s, const string& t, const vector<int>& z) {
    int n = s.size(), m = t.size();
    vector<int> e(m, 0);
    for (int i = 0, l = 0, r = 0; i != m; ++i) {
        int j = i - l < n ? z[i - l] : 0;
        if (i+j>r) for (j=max(0, r-i); i+j!=m&&t[i+j]==s[j]; ++j);
        e[i] = j;
        if (i+j-1>r) l=i, r=i+j-1;
    }
    return e;
}

// array
void getz(char* s, int* z) {
    int n = strlen(s);
    fill_n(z, n, 0);
    for (int i = 1, l = 0, r = 0; i != n; ++i) {
        int j = z[i - l];
        if (i+j>r) for (j=max(0, r-i); i+j!=n&&s[i+j]==s[j]; ++j);
        z[i] = j;
        if (i+j-1>r) l=i, r=i+j-1;
    }
    z[0] = n;
}

void gete(char* s, char* t, int* z, int* e) {
    int n = strlen(s), m = strlen(t);
    fill_n(e, m, 0);
    for (int i = 0, l = 0, r = 0; i != m; ++i) {
        int j = i - l < n ? z[i - l] : 0;
        if (i+j>r) for (j=max(0, r-i); i+j!=m&&t[i+j]==s[j]; ++j);
        e[i] = j;
        if (i+j-1>r) l=i, r=i+j-1;
    }
}
