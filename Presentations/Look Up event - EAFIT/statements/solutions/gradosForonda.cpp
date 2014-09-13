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
#define MAXN 1000

vector<int> g[MAXN]; //Lista de adyacencia
int d[MAXN];  //Aristas usadas desde la fuente
map<string,int> edge;

void bfs(int s, int n){//s= fuente, n= numero de nodos
   //Marcar todos los nodos como no visitados
   for(int i=0; i < n; ++i)d[i] = -1;
   queue <int> q;
   q.push(s);
   d[s]=0;
   while(q.size() > 0){
      int cur = q.front(); q.pop();
      for(int i=0;i < g[cur].size(); ++i){
         int next = g[cur][i];
         if(d[next] == -1){
            d[next] = d[cur] +1;
            q.push(next);  
         }   
      }  
   }      
}

int fillGraph(){
   int n;cin>>n;
   for (int i = 0; i < n; ++i){
      string u, v; 
      cin >> u >> v;
      //D(u);D(v);
      g[edge[u]].push_back(edge[v]);
      if (edge[u] != edge[v]) g[edge[v]].push_back(edge[u]);
   }  
}

int main(){
   int ne;cin>>ne;
   int x=0;
   for(int i=0;i<ne;i++){
      string word;cin>>word;
      edge[word]=x;
      x++;   
   }
   fillGraph();
   int n;cin>>n;
   while(n--){
      string start,final;
      cin>>start>>final;
      bfs(edge[start],ne);
      if(d[edge[final]]<=6&&d[edge[final]]>=0)cout<<"Aceptada"<<endl;
      else cout <<"Rechazada"<<endl;  
   }
	return 0;
}
