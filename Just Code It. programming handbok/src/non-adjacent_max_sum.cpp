vector <int> arr;

int
findMaxSum(int n) {
  int incl = arr[0];
  int excl = 0;
  int excl_new;
  for (int i = 1; i < n; i++) {
    // Current max excluding i.
    excl_new = (incl > excl) ? incl : excl;
    // Current max including i.
    incl = excl + arr[i];
    excl = excl_new;
  }
  // Return max of incl and excl
  return ((incl > excl) ? incl : excl);
}
