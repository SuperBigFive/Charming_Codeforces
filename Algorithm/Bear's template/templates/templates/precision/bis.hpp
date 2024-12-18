#include "biu.hpp"

struct bis {
    biu b; int s;
    bis operator-() const { return { b, -s }; }
    OP(bis, +) {
        if (!b1.s || !b2.s) return { b1.b + b2.b, b1.s + b2.s };
        if (b1.s == b2.s) return { b1.b + b2.b, b1.s };
        switch(cmp(b1.b, b2.b)){
            case 1: return { b1.b - b2.b, b1.s };
            case 0: return { biu{}, 0 };
            case -1: return { b2.b - b1.b, b2.s };
        }
        assert(false);
        return {};
    }
    OP(bis, -) { return b1 + (-b2); }
    OP(bis, *) { return { b1.b * b2.b, b1.s * b2.s }; }
    OP(bis, /) { biu r = b1.b / b2.b; return { r, r.empty() ? 0 : b1.s * b2.s }; }
};

string to_string(const bis& b) {
    string s = to_string(b.b);
    if (b.s == -1) s = '-' + s;
    return s;
}

bis from_string_bis(const string& s) {
    bool neg = (s[0] == '-');
    string s_ = s.substr(neg);
    return { from_string_biu(s_), neg ? -1 : s_[0] == '0' ? 0 : 1 };
}

istream& operator>>(istream& is, bis& b) {
    string s; is >> s; b = from_string_bis(s);
    return is;
}

ostream& operator<<(ostream& os, const bis& b) {
    return os << to_string(b) << endl;
}