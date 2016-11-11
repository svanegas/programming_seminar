int max_score(vector<int>& nums) {
  int n = nums.size();
  int dp[n][n];
  for (int l = 0; l < n; ++l) {
    for (int i = 0, j = l; j < n; ++i, ++j) {
      dp[i][j] = -1;
      for (int k = i; k <= j; ++k) {
        int cur_ans = k - 1 < i ? 0 : dp[i][k - 1];
        cur_ans += k + 1 > j ? 0 : dp[k + 1][j];
        cur_ans += burst(nums, k, i - 1, j + 1);
        dp[i][j] = max(dp[i][j], cur_ans);
      }
    }
  }
  return n == 0 ? 0 : dp[0][n - 1];
}

int burst(const vector <int> &nums, int ind, int left, int right) {
  int score = nums[ind];
  score *= left < 0 ? 1 : nums[left];
  score *= right >= nums.size() ? 1 : nums[right];
  return score;
}
