//Santiago Vanegas Gil.
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>

#define D(x) cout << #x " is " << x << endl

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const int MAXN = 105;
const int INF = 1 << 30;
typedef pair <int, int> dist_node;
typedef pair <int, int> edge;
vector <edge> g[MAXN];
int d[MAXN];
int n, m;

void
dijkstra(int s) {
  for (int i = 0; i <= n; ++i) d[i] = INF;
  priority_queue <dist_node, vector <dist_node>, greater<dist_node> > q;
  d[s] = 0;
  q.push(dist_node(0, s));
  while (!q.empty()) {
    int dist = q.top().first;
    int cur = q.top().second;
    q.pop();
    if (dist > d[cur]) continue;
    for (int i = 0; i < g[cur].size(); i++) {
      int next = g[cur][i].first;
      int w_extra = g[cur][i].second;
      if (d[cur] + w_extra < d[next]) {
        d[next] = d[cur] + w_extra;
        q.push(dist_node(d[next], next)); 
      }
    } 
  }
}

int
main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    g[a].push_back(edge(b, w));
  }
  dijkstra(1);
  if (d[n] != INF) cout << d[n] << endl;
  else cout << "-1" << endl;
  return 0;
}
