const int MAXN = 100005;
int arr[MAXN];

int
binarySearch(int key, int n) {
  int high = n - 1; //Apunto al último elemento
  int low = 0; //Apunto al primer elemento
  while (high - low + 1 > 1) {
     int mid = low + (high-low) / 2;
     if (arr[mid] > key) high = mid;
     else low = mid + 1;
  }
  //Si encuentro el key, retorno el índice
  //Si no lo encuentro, retorno el índice del valor
  //menor más cercano a la key
  //OJO: TENER CUIDADO CUANDO PUEDO RETORNAR UN INDEX
  //INVÁLIDO, O SEA -1
  if (arr[mid] <= key) return high;
  else return high - 1;
}