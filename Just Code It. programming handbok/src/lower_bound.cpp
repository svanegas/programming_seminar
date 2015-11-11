// invariants: value > arr[i] for all i < low
//             value <= arr[i] for all i > high
int lower_bound(vector <int> arr, int value) {
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] >= value) high = mid - 1;
    else low = mid + 1;
  }
  return low;
}
