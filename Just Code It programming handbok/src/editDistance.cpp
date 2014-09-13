const int MAXN = 5005;
int dp[MAXN][MAXN];
// dp[i][j] = Min cost of turning s[0..i) into t[0..j)
// Allowed operations are deletion, insertion and 
// substitution (in the string s) .Note that the same 
// result can be achieved deleting from s or inserting in t 
// and viceversa

int
solve(string s, string t, int n, int m) {
  // Turn the empty string into t[0..j), add to s all
  // of the characters in t
  for (int j = 0; j <= m; j++) dp[0][j] = j; 

  // Turn s[0..i) into the empty string, delete all 
  // of the characters in s
  for (int i = 0; i <= n; i++) dp[i][0] = i;
  

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      // Turn s[0..i) into t[0..j)

      // If the characters match, keep going
      if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
      else {
        int substituteCost, insertCost, deleteCost; 
        substituteCost = insertCost = deleteCost = 1;
        // Try substituting s[i-1] for t[j-1] and turn
        // s[0..i-1) into t[0..j-1)
        dp[i][j] = dp[i - 1][j - 1] + substituteCost;
        // Try deleting character s[i-1] and turn
        // s[0..i-1) into t[0..j)
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + deleteCost);
        // Try inserting character t[j-1] and turn
        // s[0..i) into t[0..j-1)
        dp[i][j] = min(dp[i][j], dp[i][j - 1] + insertCost);
      }
    }
  }
  return dp[n][m];
}