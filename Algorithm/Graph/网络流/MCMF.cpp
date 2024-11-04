namespace MCMF {
	#define INF INT_MAX

	int n, s, t, tot;
	std::vector<int> to, nxt, cap, cost, head;
	std::vector<int> dis;

	void AddEdge(int u, int v, int c, int w) {
		to[tot] = v, nxt[tot] = head[u], cap[tot] = c, cost[tot] = w, head[u] = tot++;
	}

	void Init(int _n, int _s, int _t, std::vector<std::array<int, 4> > edge) {
		n = _n, s = _s, t = _t, tot = 0;
		int m = edge.size();
		to = nxt = cap = cost = std::vector<int> (m << 1);
		head = dis = std::vector<int> (n, -1);
		for (auto [u, v, c, w] : edge) {
			AddEdge(u, v, c, w);
			AddEdge(v, u, 0, -w);
		}
	}

	std::pair<int, int> SPFA() {
		dis = std::vector<int> (n, INF);
		std::vector<int> vis(n), que;
		std::vector<std::pair<int, int> > pre(n, std::make_pair(-1, -1));
		que.emplace_back(s), dis[s] = 0, vis[s] = 1;
		for (int j = 0, u; j < que.size(); ++j) {
			u = que[j], vis[u] = 0;
			for (int i = head[u], v, c, w; ~i; i = nxt[i]) {
				v = to[i], c = cap[i], w = cost[i];
				int new_val = dis[u] + w;
				if (c && dis[v] > new_val) {
					dis[v] = new_val;
					pre[v] = std::make_pair(u, i);
					if (!vis[v]) que.emplace_back(v), vis[v] = 1;
				}
			}
		}
		if (dis[t] >= INT_MAX) return std::make_pair(0, 0);
		int min_cost = 0, max_flow = INF;
		int now = t;
		std::vector<int> all_e_idx;
		while (now != s) {
			auto [u, e_idx] = pre[now];
			now = u;
			max_flow = std::min(max_flow, cap[e_idx]);
			all_e_idx.emplace_back(e_idx);
		}
		for (int e_idx : all_e_idx) {
			min_cost += max_flow * cost[e_idx];
			cap[e_idx] -= max_flow, cap[e_idx ^ 1] += max_flow;
		}

		return std::make_pair(min_cost, max_flow);
	}

	std::pair<int, int> MCMF() {
		int min_cost = 0, max_flow = 0;
		while (true) {
			auto [new_cost, new_flow] = SPFA();
			if (!new_flow) break;
			else min_cost += new_cost, max_flow += new_flow;
		}
		return std::make_pair(min_cost, max_flow);
	}
}