const int MAXN = 100005;
int arr[MAXN]; //Almacena los números
int dp[MAXN]; //Almacena índices de los números
int prev[MAXN]; //Almacena índices de los antecesores

//OJO: Este binarySearch cambia con respecto al anterior
int
binarySearch(int low, int high, int key) {
  while (high - low + 1 > 1) {
     int mid = low + (high-low) / 2;
     if (arr[dp[mid]] > key) high = mid;
     else low = mid + 1;
  }
  return high;
}

vector <int>
lis(int n) {
  memset(dp, 0, sizeof(dp[0]) * n);
  //memset(prev, 0xFF, sizeof(prev[0]) * n);
  dp[0] = 0;
  prev[0] = -1;
  int pointer = 1; //Siempre apunta a una posición vacía
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[dp[0]]) {
      //Nuevo valor más pequeño
      dp[0] = i; //Almaceno el index
      prev[i] = -1; //El 0xFF del memset ya tiene un -1
    }
    else if (arr[i] > arr[dp[pointer - 1]]) {
      //Quiere extender la secuencia
      prev[i] = dp[pointer - 1];
      dp[pointer++] = i;
    }
    else {
      //Quiere ser un candidato potencial de una secuencia futura
      //Va a reemplazar un valor piso en la tabla dp
      int index = binarySearch(0, pointer - 1, arr[i]);
      prev[i] = dp[index - 1];
      dp[index] = i;
    }
  }
  
  vector <int> sec;
  for (int i = dp[pointer - 1]; i >= 0; i = prev[i]) {
    sec.push_back(arr[i]); 
  }
  reverse(sec.begin(), sec.end());
  return sec;
}