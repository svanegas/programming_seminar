const int MAXN = 100005;
int arr[MAXN]; //Almacena los elementos
int dp[MAXN]; //Almacena la secuencia creciente más larga

int
binarySearch(int low, int high, int key) {
  while (high - low + 1 > 1) {
     int mid = low + (high-low) / 2;
     (arr[mid] >= key ? high : low) = mid;
  }
  return high;
}

int
lis(int n) {
  int pointer = 1; //Siempre apunta un lugar vacío
  memset(dp, 0, sizeof(dp[0]) * n);
  dp[0] = arr[0];
  pointer = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i] < dp[0])
      dp[0] = arr[i]; //Nuevo valor más pequeño
    else if (arr[i] > dp[pointer - 1])
      //Quiere extender la secuencia
      dp[pointer++] = arr[i];
    else {
      //Quiere ser el actual candidate de una secuencia
      //existente, reemplazará un valor piso de la tabla dp
      int index = binarySearch(0, pointer - 1, arr[i]);
      dp[index] = arr[i];
    }
  }
  return pointer;
}