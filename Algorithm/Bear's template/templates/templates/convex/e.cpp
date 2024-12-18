#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct line { ll k, b; };
bool good(line l1, line l, line l2) {
    return (l1.b - l.b) * (l2.k - l.k) < (l2.b - l.b) * (l1.k - l.k);
}
bool operator<(line l1, line l2) {
    return l1.k == l2.k ? l1.b < l2.b : l1.k < l2.k;
}

struct line_hull : vector<line> {
    void push_back(line l) {
        while (size() > 1 && !good(end()[-2], end()[-1], l))
            pop_back();
        if (!empty() && back().k == l.k)
            pop_back();
        vector<line>::push_back(l);
    }
};

int main(void) {

    line_hull h;
    h.push_back({ 1, -1 });
    h.push_back({ 2, -2 });
    h.push_back({ 3, -4 });
    cout << h.size() << endl;
    h.push_back({ 4, -5 });
    cout << h.size() << endl;
    h.push_back({ 5, -7 });
    for (line l : h)
        cout << l.k << ' ' << l.b << endl;
    return 0;
}