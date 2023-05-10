#include <bits/stdc++.h>
#define ll long long
//#define int ll
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

struct SegmentTree {
  int n, tot;
  vector <int> a, root, node, ls, rs;

  SegmentTree (int n) {
    this -> n = n, tot = 0;
    root = vector <int> (n + 5);
    node = vector <int> (N * 200, 1);
    ls = rs = vector <int> (N * 200);
  }

	int Modify (int pre, int l, int r, int p, ll k) {
		int cur = ++tot;
		node[cur] = (node[pre] * k) % MOD;
		if (l == r) return cur;
		ls[cur] = ls[pre], rs[cur] = rs[pre];
		int mid = l + r >> 1;
		if (p <= mid) ls[cur] = Modify (ls[pre], l, mid, p, k);
		else rs[cur] = Modify (rs[pre], mid + 1, r, p, k);
		return cur;
	}
	
  ll Query (int rt, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return 1ll * node[rt];
    int mid = l + r >> 1;
		ll ans = 1;
    if (ql <= mid) ans = (ans * Query (ls[rt], l, mid, ql, qr)) % MOD;
    if (qr > mid) ans = (ans * Query (rs[rt], mid + 1, r, ql, qr)) % MOD;
    return ans;
  }
};

int n, q;

void init () {}
 
void charming () {
  init ();
  cin >> n;
  vector <int> a (n + 5), fiPrime (N), inv (N);
  
  auto FPOW = [] (ll x, ll p) -> ll {
  	ll ans = 1;
  	while (p) {
  		if (p & 1) ans = (ans * x) % MOD;
  		p >>= 1, x = (x * x) % MOD;
  	}
  	return ans;
  };
  
  auto Get_Prime = [&] () -> void {
  	vector <int> prime;
  	for (int i = 2; i < N; ++i) {
  		if (!fiPrime[i]) fiPrime[i] = i, prime.emplace_back (i);
  		for (int j = 0, siz = prime.size (); i * prime[j] < N && j < siz; ++j) {
  			if (!fiPrime[i * prime[j]]) fiPrime[i * prime[j]] = prime[j];
  			if (i % prime[j] == 0) break;
  		}
  	}
  };
  
  auto Get_inv = [&] () -> void {
  	inv[0] = 1;
  	for (int i = 1; i < N; ++i) inv[i] = FPOW (i, MOD - 2);
  };
 
  Get_Prime (), Get_inv ();
  SegmentTree Tree (n);
  vector <int> last (N);
  for (int i = 1, lastp, mul, val; i <= n; ++i) {
		cin >> a[i], lastp = mul = 0;
		Tree.root[i] = Tree.root[i - 1];
		while (a[i] > 1) {
			val = inv[fiPrime[a[i]]];
			if (fiPrime[a[i]] != lastp) {
				if (mul) Tree.root[i] = Tree.Modify (Tree.root[i], 1, n, i, mul);
				mul = fiPrime[a[i]];
				lastp = mul;
			}
			else mul *= lastp;
			if (last[mul]) Tree.root[i] = Tree.Modify (Tree.root[i], 1, n, last[mul], val);
			last[mul] = i;
			a[i] /= fiPrime[a[i]];
		}
		if (mul) Tree.root[i] = Tree.Modify (Tree.root[i], 1, n, i, mul);
	}
  cin >> q;
  for (int i = 1, l, r, lastans = 0; i <= q; ++i) {
    cin >> l >> r;
    l = (l + lastans) % n + 1;
    r = (r + lastans) % n + 1;
    if (l > r) swap (l, r);
    lastans = Tree.Query (Tree.root[r], 1, n, l, r);
    lastans = ((lastans % MOD) + MOD) % MOD;
    cout << lastans << endl;
  }
}
 
signed main () {
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);
  charming ();
}
