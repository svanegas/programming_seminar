// invariants: value > arr[i] for all i < low
//             value < arr[i] for all i > high
//             or <= and => if mutiple elements of
//                          the same value are allowed.
int binary_search(vector <int> arr, int value) {
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  while (low <= high) {
     int mid = (low + high) / 2;
     if (arr[mid] > value) high = mid - 1;
     else if (arr[mid] < value) low = mid + 1;
     else return mid;
  }
  return low; // I didn't find the value.
              // so it would be inserted at low index.
}
