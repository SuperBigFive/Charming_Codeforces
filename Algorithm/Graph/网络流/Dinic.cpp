namespace Dinic {
	int n, s, t, tot;
	std::vector<int> to, nxt, cap, head;
	std::vector<int> cur, dep;

	void AddEdge(int u, int v, int c) {
		to[tot] = v, nxt[tot] = head[u], cap[tot] = c, head[u] = tot++;
	}

	void Init(int _n, int _s, int _t, std::vector<std::array<int, 3> > &edge) {
		n = _n, s = _s, t = _t, tot = 0;
		int m = edge.size();
		to = nxt = cap = std::vector<int>(m << 1);
		head = cur = dep = std::vector<int>(n, -1);
		for (auto [u, v, c] : edge) {
			AddEdge(u, v, c);
			AddEdge(v, u, 0);
		}
	}

	bool BFS() {
		dep = std::vector<int>(n, -1);
		std::vector<int> que(1, s);
		dep[s] = 0;
		for (int h = 0, u; h < que.size(); ++h) {
			u = que[h];
			for (int i = head[u], v, c; ~i; i = nxt[i]) {
				v = to[i], c = cap[i];
				if (dep[v] == -1 && c) dep[v] = dep[u] + 1, que.emplace_back(v);
			}
		}
		return dep[t] != -1;
	}

	int DFS (int u, int in) {
		if (u == t || !in) return in;
		int out = 0;
		for (int i = cur[u], v, c; ~i; i = nxt[i]) {
			cur[u] = nxt[i];
			v = to[i], c = cap[i];
			if (c && dep[v] == dep[u] + 1) {
				int ret = DFS(v, std::min(in, c));
				in -= ret, out += ret;
				cap[i] -= ret, cap[i ^ 1] += ret;
			}
		}
		return out;
	}

	int getMaxFlow() {
		int ans = 0;
		while (BFS()) {
			cur = head;
			ans += DFS(s, INT_MAX);
		}
		return ans;
	}
}
