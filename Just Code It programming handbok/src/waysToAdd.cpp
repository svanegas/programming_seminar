const int MAXN = 105;
//El número puede ser demasiado grande
const int MOD = 1000000;
// n: número que quiero hallar
// k: con cuántos sumandos
int n, k;
// Filas: k, Columnas: n
int dp[MAXK][MAXN];

void
build() {
  //Para cualquier n, si tengo 1 sumando, sólo tengo una opción
  //Para cualquier j, si tengo que sumar 0, sólo tengo una opción
  for (int j = 1; j < MAXN; j++) dp[1][j] = 1, dp[j][0] = 1;
  
  for (int i = 2; i < MAXN; i++) {
    for (int j = 1; j < MAXN; j++) {
      dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
    } 
  }
}

int
main() {
  build();
  while (cin >> n >> k && n && k) {
    //Al final, la respuesta está en dp[k][n]
    cout << dp[k][n] << endl; 
  }  
  return 0;
}