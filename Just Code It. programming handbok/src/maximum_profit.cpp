int maxProfit(int k, const vector<int> &prices) {
  int n = prices.size();
  if (n == 0) return 0;
  int dp[2][n];
  k = min(k, n);
  for (int j = 0; j < n; ++j) dp[0][j] = 0;
  for (int i = 1; i <= k; ++i) {
    dp[i % 2][0] = 0;
    int max_diff = -prices[1 - (i % 2)];
    for (int j = 1; j < n; ++j) {
      max_diff = max(max_diff, dp[1 - (i % 2)][j - 1] - prices[j - 1]);
      dp[i % 2][j] = max(dp[i % 2][j - 1], max_diff + prices[j]);
    }
  }
  return dp[k % 2][n - 1];
}
