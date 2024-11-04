#include <bits/stdc++.h>
using ll = long long;
const int N = 20;

void charming() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = n - 1; i > 0; --i) a[i] -= a[i - 1], a[i] = std::abs(a[i]);
    std::vector<int> log2(n + 1);
    for (int i = 0; i < 20; ++i) {
        if ((1 << i) > n) break;
        log2[1 << i] = i;
    }
    for (int i = 1; i <= n; ++i) if (!log2[i]) log2[i] = log2[i - 1];
    std::vector<std::array<int, N> > pre_gcd(n);
    for (int i = 0; i < n; ++i) {
        pre_gcd[i][0] = a[i];
        for (int j = 1; j < N; ++j) {
            if (i - (1 << (j - 1)) >= 0) {
                pre_gcd[i][j] = std::__gcd(pre_gcd[i][j - 1], pre_gcd[i - (1 << (j - 1))][j - 1]);
            }
            else pre_gcd[i][j] = pre_gcd[i][j - 1];
        }
    }

    auto Check = [&](int l, int r) -> bool {
        int len = r - l + 1, k = log2[len];
        int gcd = std::__gcd(pre_gcd[r][k], pre_gcd[l + (1 << k) - 1][k]);
        return __builtin_popcount(gcd) == 1;
    };

    ll ans = 0;
    int mx = 0, pre_diff = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i]) pre_diff = i;
        if (Check(0, i)) {
            int l = 0, r = i, k = 0;
            while (l <= r) {
                int mid = l + r >> 1;
                if (Check(mid, i)) l = mid + 1, k = mid;
                else r = mid - 1;
            }
            mx = std::max(mx, k);
        }
        if (mx >= pre_diff) ans += i + 1;
        else ans += mx + i - pre_diff + 1;
    }
    
    std::cout << ans << '\n';
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int t; std::cin >> t;
    while (t--) charming();
    return 0;
}
