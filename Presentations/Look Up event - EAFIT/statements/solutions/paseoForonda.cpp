//Esteban Foronda Sierra
using namespace std;
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

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

#define D(x) cout << #x " is " << x << endl
typedef pair <int, int> dist_node; // Tipo de dato para el heap
typedef pair <int, int> edge; // Arista = pareja de enteros
const int MAXN = 100005; // El maximo numero de nodos
const int INF = 1 << 30; // Infinito = 2^30
vector <edge> g[MAXN]; // g[u] = (v, w)
int d[MAXN]; // d[u] La distancia mas corta de s a u
int p[MAXN]; // p[u] El predecesor de u en el camino mas corto
// La funcion recibe la fuente s y el numero total de nodos n

void dijkstra(int s, int n){
// Limpiar los valores de las variables
    for (int i = 0; i <= n; ++i){
        d[i] = INF; p[i] = -1;
    }
// Construir la cola de prioridades con la funcion mayor
    priority_queue < dist_node, vector <dist_node>, greater<dist_node> > q;
    d[s] = 0;
    q.push(dist_node(0, s));
    while (!q.empty()){
        int dist = q.top().first;
        int cur = q.top().second;
        q.pop();
// No volver a procesar el nodo
        if (dist > d[cur]) continue;
            for (int i = 0; i < g[cur].size(); ++i){
                int next = g[cur][i].first;
                int w_extra = g[cur][i].second;
                if (d[cur] + w_extra < d[next]){
                    d[next] = d[cur] + w_extra;
                    p[next] = cur;
                    q.push(dist_node(d[next], next));
                }
            }
        }
}

int fillGraph(){
   int n;cin>>n;
   for (int i = 0; i < n; ++i){
      int u,v,w;
      cin >> u >> v >> w;
      u--;v--;
      g[u].push_back(make_pair(v,w));
   }  
}


int main(){
   int ne;cin>>ne;
   fillGraph();
   dijkstra(0,ne);
   if(d[ne-1]!=INF)cout<<d[ne-1]<<endl;
   else cout << -1 << endl;
	return 0;
}
