const int ROW = 105;
const int COL = 105;
int M[ROW][COL];
int arr[ROW];
int start, finish;
int n;

int
kadane() {
  int sum = 0, maxSum = INT_MIN, i;
  finish = -1;
  int local_start = 0;
  for (i = 0; i < n; ++i) {
    sum += arr[i];
    if (sum < 0) {
      sum = 0;
      local_start = i + 1;
    }
    else if (sum > maxSum) {
      maxSum = sum;
      start = local_start;
      finish = i;
    }
  }
  if (finish != -1) return maxSum;
  // Special Case: When all numbers in arr are negative
  maxSum = arr[0];
  start = finish = 0;
  // Find the maximum element in array
  for (i = 1; i < n; i++) {
    if (arr[i] > maxSum) {
      maxSum = arr[i];
      start = finish = i;
    }
  }
  return maxSum;
}

void
findMaxSum() {
  // Variables to store the final output
  int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom; 
  int left, right, i;
  int sum;
  for (left = 0; left < COL; ++left) {
    memset(arr, 0, sizeof(arr));
    for (right = left; right < COL; ++right) {
      for (i = 0; i < ROW; ++i) arr[i] += M[i][right];
      sum = kadane();
      if (sum > maxSum) {
        maxSum = sum;
        finalLeft = left;
        finalRight = right;
        finalTop = start;
        finalBottom = finish;
      }
    }
  }
  printf("(Top, Left) (%d, %d)\n", finalTop, finalLeft);
  printf("(Bottom, Right) (%d, %d)\n", finalBottom, finalRight);
  printf("Max sum is: %d\n", maxSum);
}
