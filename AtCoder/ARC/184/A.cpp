#include <bits/stdc++.h>

void charming() {
  int cnt = 0;
  std::function<int(int, int)> Send = [&](int x, int y) {
    ++cnt;
    assert(cnt <= 950);
    assert(x >= 1 && x <= 1000 && y >= 1 && y <= 1000);
    std::cout << "? " << x << ' ' << y << '\n';
    std::cout.flush();
    int rcv; std::cin >> rcv;
    assert(rcv != -1);
    return rcv;
  };

  std::function<void(std::vector<int>)> Answer = [&](std::vector<int> a) {
    std::cout << "! ";
    assert(int(a.size()) == 10);
    for (int i = 0; i < 10; ++i) std::cout << a[i] << " \n"[i == 9];
    std::cout.flush();
  };

  int n, m, q; std::cin >> n >> m >> q;
  assert(n == 1000 && m == 10 && q == 950);
  std::vector<bool> type(n + 1);
  for (int i = 1; i <= n; i += 10) {
    type[i] = 1;
    for (int j = i + 1; j < i + 10; ++j) {
      if (!Send(i, j)) type[j] = 1;
      else type[j] = 0;
    }
  }

  std::vector<int> ans;
  
  bool flag = true;
  for (int i = 1; i <= n; ++i) if (!type[i]) {flag = false; break;}

  if (!flag) {
    int idx = -1;
    for (int i = 1; i <= n; i += 10) {
      bool chk = true;
      for (int j = i; j < i + 10; ++j) {
        if (!type[j]) {chk = false; break;}
      }
      if (chk) {idx = i; break;}
    }
    assert(idx != -1);
    
    for (int i = 1; i <= n; i += 10) {
      bool chk = true;
      for (int j = i; j < i + 10; ++j) {
        if (!type[j]) {chk = false; break;}
      }
      if (!chk) {
        int ret = Send(idx, i);
        if (!ret) {
          for (int j = i; j < i + 10; ++j) {
            if (!type[j]) ans.emplace_back(j);
          }
        }
        else {
          for (int j = i; j < i + 10; ++j) {
            if (type[j]) ans.emplace_back(j);
          }
        }
      }
    }
  }
  else {
    int idx = -1;
    for (int i = 1; i + 20 <= n; i += 20) {
      int ret = Send(i, i + 10);
      if (ret) {idx = i; break;}
    }
    if (idx != -1) {
      int ret = Send(idx, 1000);
      if (ret) {
        for (int i = idx; i < idx + 10; ++i) ans.emplace_back(i);
      }
      else {
        for (int i = idx + 10; i < idx + 10 + 10; ++i) ans.emplace_back(i);
      }
    }
    else {
      int ret = Send(1, 1000);
      if (ret) {
        for (int i = 991; i <= 1000; ++i) ans.emplace_back(i);
      }
      else {
        for (int i = 981; i <= 990; ++i) ans.emplace_back(i);
      }
    }
  }

  Answer(ans);
}

signed main() {
  charming();
  return 0;
}