#include "bis.hpp"

const int maxd = 200;
struct bf {
    bis b;
    int e;
    void trim(int tgt = maxd) {
        int t = (int)b.b.size() - tgt;
        if (t < 0) {
            b.b.resize(tgt, 0);
            rotate(b.b.begin(), b.b.end() + t, b.b.end());
            e += t;
        }
        else {
            rotate(b.b.begin(), b.b.end() - tgt, b.b.end());
            b.b.resize(tgt);
            e += t;
        }
    }
    static void align(bf& f1, bf& f2) {
        bool neg = f1.e > f2.e;
        if (neg) swap(f1, f2);
        int d = f2.e - f1.e; f2.e -= d;
        f2.b.b.resize(f2.b.b.size() + d, 0);
        rotate(f2.b.b.begin(), f2.b.b.end() - d, f2.b.b.end());
        if (neg) swap(f1, f2);
    }
    friend bf operator+(const bf& b1, const bf& b2) {
        bf f1 = b1, f2 = b2; align(f1, f2);
        bf res = { f1.b + f2.b, f1.e };
        res.trim(); return res;
    }
    friend bf operator-(const bf& b1, const bf& b2) {
        bf f1 = b1, f2 = b2; align(f1, f2);
        bf res = { f1.b - f2.b, f1.e };
        res.trim(); return res;
    }
    friend bf operator*(const bf& b1, const bf& b2) {
        bf res = { b1.b * b2.b, b1.e + b2.e };
        res.trim(); return res;
    }
    friend bf operator/(const bf& b1, const bf& b2) {
        bf f1 = b1; f1.trim(2 * maxd);
        bf res = { f1.b / b2.b, f1.e - b2.e };
        res.trim(); return res;
    }
};

string to_string(const bf& b) {
    string s = to_string(b.b); int e = b.e;
    if (s[0] == '0') return s;
    while (s.back() == '0') s.pop_back(), e++;
    bool neg = (s[0] == '-');
    if (neg) s = s.substr(1);
    int sz = s.size();
    if (e < 0) {
        if (sz + e < 0) s = string(-e-sz, '0') + s;
        s.insert(s.size() + e, ".");
        if (s[0] == '.') s = '0' + s;
    }
    else if (e > 0)
        s = s + string(e, '0');
    if (neg) s = '-' + s;
    return s;
}

bf from_string_bf(const string& s) {
    size_t pos = s.find('.', 0);
    if (pos == string::npos) {
        int e = 0;
        while (e + 1 <= s.size() && s[s.size() - e - 1] == '0') e++;
        return { from_string_bis(s.substr(0, s.size() - e)), e };
    }
    else {
        int e = -(s.size() - pos - 1);
        string t = s.substr(0, pos) + s.substr(pos + 1);
        bool neg = (t[0] == '-');
        int l = t.find_first_of('0', neg);
        int r = t.find_first_not_of('0', neg);
        if (t[neg] == '0') t.erase(l, r - l);
        return { from_string_bis(t), e };
    }
}