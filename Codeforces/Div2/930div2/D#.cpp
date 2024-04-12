#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;

int t, n;
string s;
ll pre_lt_cnt[N], pre_gt_cnt[N], pre_lt_sum[N], pre_gt_sum[N];
ll suf_lt_cnt[N], suf_gt_cnt[N], suf_lt_sum[N], suf_gt_sum[N];
int pos_lt[N], pos_gt[N];

ll Solve2 (int idx, int lim) {
  // 出口在右边，左边最多移动到 lim 下标位置
  ll nans = 0;
  // 左半部分所有 '>' 对答案的贡献
  nans += (pre_gt_sum[idx] - pre_gt_sum[lim - 1]) - (pre_gt_cnt[idx] - 
  pre_gt_cnt[lim - 1]) * (pre_gt_cnt[lim - 1] * 2 - 1);
  // cout << nans << endl;
  // 左半部分所有 '<' 对答案的贡献
  nans += (pre_lt_sum[idx] - pre_lt_sum[lim - 1]) - (pre_lt_cnt[idx] -
  pre_lt_cnt[lim - 1]) * pre_gt_cnt[lim - 1] * 2;
  // cout << nans << endl;
  // 右半部分所有 '>' 对答案的贡献
  nans += suf_gt_sum[idx + 1] + suf_gt_cnt[idx + 1];
  // cout << nans << endl;
  // 右半部分所有 '<' 对答案的贡献
  nans += suf_lt_sum[idx + 1] + suf_lt_cnt[idx + 1] * 2;
  // cout << nans << endl;
  return nans;
}

void Solve1 (vector <ll> &ans) {
  suf_lt_cnt[n + 1] = suf_gt_cnt[n + 1] = 0;
  suf_lt_sum[n + 1] = suf_gt_sum[n + 1] = 0;
  for (int i = 1; i <= n; ++i) {
    pre_lt_cnt[i] = pre_lt_cnt[i - 1];
    pre_gt_cnt[i] = pre_gt_cnt[i - 1];
    pre_lt_sum[i] = pre_lt_sum[i - 1];
    pre_gt_sum[i] = pre_gt_sum[i - 1];
    if (s[i - 1] == '<') {
      ++pre_lt_cnt[i];
      pos_lt[pre_lt_cnt[i]] = i;
      pre_lt_sum[i] += pre_gt_cnt[i - 1] * 2;
    }
    else {
      ++pre_gt_cnt[i];
      pos_gt[pre_gt_cnt[i]] = i;
      pre_gt_sum[i] += pre_gt_cnt[i - 1] * 2;
    }
  }
  for (int i = n; i >= 1; --i) {
    suf_lt_cnt[i] = suf_lt_cnt[i + 1];
    suf_gt_cnt[i] = suf_gt_cnt[i + 1];
    suf_lt_sum[i] = suf_lt_sum[i + 1];
    suf_gt_sum[i] = suf_gt_sum[i + 1];
    if (s[i - 1] == '<') {
      ++suf_lt_cnt[i];
      suf_lt_sum[i] += suf_lt_cnt[i + 1] * 2;
    }
    else {
      ++suf_gt_cnt[i];
      suf_gt_sum[i] += suf_lt_cnt[i + 1] * 2;
    }
  }
  for (int i = 1; i <= n; ++i) {
    int rig = pre_gt_cnt[i - 1];
    int lef = pre_lt_cnt[n] - pre_lt_cnt[i];
    int dir = (s[i - 1] == '>'); // 1 : right, 0 : left
    int esc = (lef <= rig) ^ dir; // 1 : right, 0 : left
    if ((dir == 1 && rig >= lef) || (dir == 0 && rig > lef)) esc = 1;
    else esc = 0;
    int lim = -1;
    if (esc == 1) {
      if (dir == 1) lim = pos_gt[pre_gt_cnt[i - 1] - lef + 1];
      else lim = pos_gt[pre_gt_cnt[i] - lef];
      ans[i] = Solve2 (i, lim);
    }
    // cout << i << " " << lef << " " << rig << " " << dir << " " << esc << " " << lim << endl;
  }
}

void charming () {
  cin >> n >> s;
  vector <ll> ans (n + 1);
  Solve1 (ans);
  // cout << "--------------------------" << endl;
  reverse (s.begin (), s.end ());
  for (char &ch : s) {
    if (ch == '<') ch = '>';
    else ch = '<';
  }
  reverse (ans.begin () + 1, ans.end ());
  Solve1 (ans);
  reverse (ans.begin () + 1, ans.end ());
  for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
}

signed main () {
  ios_base :: sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  cin >> t;
  while (t--) charming ();
  return 0;
}