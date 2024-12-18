#include <bits/stdc++.h>
using namespace std;

typedef double dbl;

const int wrong_answer = 1,
          error_exceed = 2;

dbl err(dbl a, dbl b) { return fabs(a - b) / max(1., b); }
dbl err(dbl xa, dbl ya, dbl xb, dbl yb) { return hypot(xa - xb, ya - yb) / max(1., hypot(xb, yb)); }

int main(int c, char** v) {
    //string id(v[1]);
    dbl err_max = atof(v[1]);
    //ifstream fin(id + ".in"), fout(id + ".out"), fans(id + ".ans");
    ifstream fin("in"), fout("out"), fans("ans");
    int nout, nans;
    fout >> nout; fans >> nans;
    if (nout != nans)
        exit(wrong_answer);
    int q; fin >> q;
    for (int i = 1; i <= q; ++i) {
        int t; fin >> t;
        if (t == 1) {
            dbl x, y; fin >> x >> y;
            string out, ans;
            fout >> out;
            fans >> ans;
            if (out != ans)
                exit(i);
        }
        else if (t == 2) {
            dbl x, y; fin >> x >> y;
            string out, ans;
            fout >> out;
            fans >> ans;
            if (out != ans)
                exit(i);
        }
        else if(t == 3 || t == 4) {
            dbl x, y; fin >> x >> y;
            dbl out, ans;
            fout >> out;
            fans >> ans;
            if (err(out, ans) > err_max)
                exit(i);
        }
        else if (t == 5 || t == 6) {
            dbl x, y; fin >> x >> y >> x >> y;
            int kout, kans;
            fout >> kout;
            fans >> kans;
            if (kout != kans)
                exit(i);
            for (int i = 1; i <= kout; ++i) {
                dbl xout, yout;
                dbl xans, yans;
                fout >> xout >> yout;
                fans >> xans >> yans;
                if (err(xout, yout, xans, yans) > err_max)
                    exit(i);
            }
        }
    }
    return 0;
}