const int MAXN = 1005;
int dp[MAXN];
int prev[MAXN]; //*
int arr[MAXN];

vector <int>
lis(int n) {
  int maxi = 1;
  int indexMaxi = 0; //*
  dp[0] = 1;
  prev[0] = -1; //*
  for (int i = 1; i < n; i++) {
    dp[i] = 1;
    prev[i] = -1; //*
    for (int j = i - 1; j >= 0; j--) {
      //>   estrictamente creciente
      //>=  dos elementos iguales son ambos incluídos
      if (arr[i] > arr[j] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        prev[i] = j; //*
        if (dp[i] > maxi) {
          maxi = dp[i];
          indexMaxi = i; //*
        }
      }
    } 
  }
  //Si se necesita sólo el tamaño retornar maxi aquí
  vector <int> seq;
  for (int i = indexMaxi; i >= 0; i = prev[i]) {
    seq.push_back(arr[i]);
  }
  reverse(seq.begin(), seq.end());
  return seq;
}