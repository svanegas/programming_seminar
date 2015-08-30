const int MAXN = 1005;
int dp[MAXN][MAXN];

string
backtrack(const string &s, int i, int j, string p) {
  if (dp[i][j] == 0) {
    reverse(p.begin(), p.end());
    return p; 
  }
  else {
    p += s[i-1];
    return backtrack(s, i-1, j-1, p); 
  }
}

string
lcsubstr(const string &s, const string &t, int n, int m) {
  for (int i = 0; i <= n; i++) dp[i][0] = 0;
  for (int j = 0; j <= m; j++) dp[0][j] = 0;
  
  string ret = "";
  int maxi = 0;
  int maxI = -1, maxJ = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i-1] == t[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
        if (dp[i-1][j-1] + 1 > maxi) {
          maxI = i;
          maxJ = j;
          maxi = dp[i-1][j-1] + 1;
        }
      }
      else dp[i][j] = 0;
    } 
  }
  if (maxI != -1 && maxJ != -1) {
    //Reconstruimos el longest common substring
    ret = backtrack(s, maxI, maxJ, "");
  }
  return ret;
}

int
main() {
  string s, t;
  cin >> s >> t;
  string lcsstring = lcsubstr(s, t, s.size(), t.size());
  if (lcsstring == "") printf("No common sequence.\n");
  else cout << lcsstring << endl;
  return 0;
}