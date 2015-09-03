vector <int> g[MAXN];
int d[MAXN], low[MAXN], scc[MAXN];
bool stacked[MAXN];
stack <int> s;
int ticks, current_scc;

// Check initializations.
void tarjan(int u) {
  d[u] = low[u] = ticks++;
  s.push(u);
  stacked[u] = true;
  for (int k = 0; k < g[u].size(); ++k) {
    int v = g[u][k];
    if (d[v] == -1) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    }
    else if (stacked[v]) low[u] = min(low[u], low[v]);
  }
  if (d[u] == low[u]) {
    int v;
    do {
      v = s.top();
      s.pop();
      stacked[v] = false;
      scc[v] = current_scc;
    }
    while (u != v);
    current_scc++;
  }
}
