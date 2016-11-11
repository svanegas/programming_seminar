bool is_match(const string &s, const string &p) {
  int n = s.size(), m = p.size();
  bool dp[2][m + 1];
  dp[0][0] = true;
  for (int j = 1; j <= m; ++j)
    dp[0][j] = p[j - 1] == '*' ? dp[0][j - 1] : false;
  for (int i = 1; i <= n; ++i) {
    dp[i % 2][0] = false;
    for (int j = 1; j <= m; ++j) {
      if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
        dp[i % 2][j] = dp[1 - (i % 2)][j - 1];
      else if (p[j - 1] == '*')
        dp[i % 2][j] = dp[1 - (i % 2)][j] || dp[i % 2][j - 1];
      else dp[i % 2][j] = false;
    }
  }
  return dp[n % 2][m];
}
