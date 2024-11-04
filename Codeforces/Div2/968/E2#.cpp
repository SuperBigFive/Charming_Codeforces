#include <bits/stdc++.h>
using ll = long long;

void charming() {
  int n, m; std::cin >> n >> m;
  if (!m) {std::cout << 1ll * n * (n - 1) / 2 << '\n'; return;}
  std::vector<int> vis(n + 1, -1);
  std::priority_queue<std::pair<int, int> > pq;
  for (int i = 0, l, r; i < m; ++i) {
    std::cin >> l >> r;
    pq.push({l, r});
  }

  auto overlap = [](std::pair<int, int> a, std::pair<int, int> b) -> bool {
    if (a.first > b.first) std::swap(a, b);
    return b.first <= a.second;
  };

  std::vector<std::pair<int, int> > intervals;
  std::pair<int, int> lst = {-1, -1};
  bool chk = true;
  std::vector<std::pair<int, int> > set0, set1;
  while (!pq.empty()) {
    std::pair<int, int> now = pq.top();
    pq.pop();
    if (now == lst) continue;
    else if (overlap(lst, now)) {
      int l = std::max(lst.first, now.first);
      int r = std::min(lst.second, now.second);
      if (l >= r) {chk = false; break;}
      pq.push({l, r});
      int lef = std::min(lst.first, now.first);
      int rig = std::max(lst.second, now.second);
      if (lef < l) set0.emplace_back(std::make_pair(lef, l - 1));
      if (rig > r) set1.emplace_back(std::make_pair(r + 1, rig));
      lst = {-1, -1};
    }
    else {
      if (lst.first != -1) intervals.emplace_back(lst);
      lst = now;
    }
  }
  if (!chk) {std::cout << -1 << '\n'; return;}
  if (lst.first != -1) intervals.emplace_back(lst);

  std::vector<int> tag0(n + 1), tag1(n + 1);
  for (auto [l, r] : set0) {
    ++tag0[l]; 
    if (r + 1 <= n) --tag0[r + 1];
  }
  for (auto [l, r] : set1) {
    ++tag1[l];
    if (r + 1 <= n) --tag1[r + 1];
  }
  for (int i = 1, sum0 = 0, sum1 = 0; i <= n; ++i) {
    sum0 += tag0[i], sum1 += tag1[i];
    if (sum0 && !sum1) vis[i] = 0;
    else if (sum1 && !sum0) vis[i] = 1;
    else if (sum0 && sum1) {chk = false; break;}
  }
  if (!chk) {std::cout << -1 << '\n'; return;}

  std::vector<std::pair<int, int> > new_intervals;
  int cnt = intervals.size();
  for (int i = 0, l, r; i < cnt; ++i) {
    l = intervals[i].first, r = intervals[i].second;
    int pos0 = -1, pos1 = -1;
    for (int j = l; j <= r; ++j) {
      if (vis[j] == 1 && pos1 == -1) pos1 = j;
      if (vis[j] == 0) pos0 = j;
    }
    if (pos0 == -1 && pos1 == -1) new_intervals.emplace_back(std::make_pair(l, r));
    else if (pos0 == -1) {
      if (pos1 <= l) {chk = false; break;}
      else new_intervals.emplace_back(std::make_pair(l, pos1));
    }
    else if (pos1 == -1) {
      if (pos0 >= r) {chk = false; break;}
      else new_intervals.emplace_back(std::make_pair(pos0, r));
    }
    else if (pos0 >= pos1) {chk = false; break;}
    else new_intervals.emplace_back(std::make_pair(pos0, pos1));
  }
  if (!chk) {std::cout << -1 << '\n'; return;}
  intervals = new_intervals;

  auto Solve = [&](std::vector<std::pair<int, int> > &intervals,
  std::vector<int> &vis) -> ll {
    std::vector<int> in_interval(n + 1);
    for (auto [l, r] : intervals) {
      for (int i = l; i <= r; ++i) assert(!in_interval[i]), in_interval[i] = 1;
      in_interval[r] = 2;
    }
    int now = 1;
    std::vector<ll> dp(n + 1, -1); dp[0] = 0;
    while (now <= n) {
      std::vector<ll> ndp(n + 1, -1);
      if (!in_interval[now]) {
        if (vis[now] != 0) for (int i = 0; i + 1 <= n; ++i) {
          if (dp[i] != -1) ndp[i + 1] = std::max(ndp[i + 1], dp[i]);
        }
        if (vis[now] != 1) for (int i = 0; i <= n; ++i) {
          if (dp[i] != -1) ndp[i] = std::max(ndp[i], dp[i] + i);
        }
        ++now;
      }
      else {
        int nxt = now;
        while (nxt <= n && in_interval[nxt] != 2) ++nxt;
        assert(nxt > now);

        int len = nxt - now + 1;
        for (int cnt0, cnt1 = 1; cnt1 < len; ++cnt1) {
          cnt0 = len - cnt1;
          for (int i = 0; i + cnt1 <= n; ++i) if (dp[i] != -1) {
            ndp[i + cnt1] = std::max(ndp[i + cnt1], dp[i] + 1ll * i * cnt0);
          }
        }

        now = nxt + 1;
      }
      dp = ndp;
    }
    
    ll ans = -1;
    for (int i = 1; i < n; ++i) if (dp[i] != -1) {
      ll nans = dp[i] + 1ll * i * (i - 1) / 2 + 1ll * (n - i) * (n - i - 1) / 2;
      ans = std::max(ans, nans);
    }
    return ans;
  };

  ll ans = Solve(intervals, vis);
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
