#include <bits/stdc++.h>
using namespace std;

typedef double dbl;
typedef vector<dbl> vec;
typedef vector<vec> mat;
const dbl eps = 1e-7;

int row_reduction(mat& a) {
    const int& n = a.size(), m = a[0].size();
    for (int i = 0, j = 0; i != n; ++i) {
        do for (int k = i + 1; k != n; ++k)
            if (fabs(a[i][j]) < fabs(a[k][j]))
                swap(a[i], a[k]);
        while (!fabs(a[i][j]) < eps && ++j != n);
        if (j == n) return i; //  rk(a)
        for (int l = m - 1; l >= i; --l)
            a[i][l] /= a[i][j];
        for (int k = 0; k != n; ++k) {
            if (k != i) for (int l = m - 1; l >= i; --l)
                a[k][l] -= a[k][j] * a[i][l];
    }
    return n;
}



int main(void) {

}