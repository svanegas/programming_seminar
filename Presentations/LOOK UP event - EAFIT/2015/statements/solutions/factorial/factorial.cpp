#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MAXN 10
#define D(x) cout << #x << "= " << x << endl

ll fact[MAXN];

void build() {
  fact[0] = 1LL;
  for(int i = 1; i < MAXN; ++i) fact[i] = fact[i - 1] * i;
}

int
main() {
  build();
  int n;
  while(cin >> n) {
    int i = MAXN - 1;
    int ans = 0;
    while(n) {
      if(fact[i] <= n) {
        n -= fact[i];
        ans++;
      }
      else i--;
    }
    cout << ans << endl;
  }
  return 0;
}

