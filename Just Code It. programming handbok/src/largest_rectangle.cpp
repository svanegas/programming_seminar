const int MAXN = 100005;
typedef long long ll;
int n;
ll h[MAXN];
stack <int> s;

/* DO NOT call this. Call largest_rectangle */
ll
calc(int i) {
  int smallest = s.top(); s.pop();
  ll cur = h[smallest] * (s.empty() ? i : i - s.top() - 1); 
  return cur; 
}

/* h[i] = height of the bar i.
   n = total number of bars in the histogram.
   s = an empty stack. */
ll
largest_rectangle() {
  ll ans = 0LL;
  int i = 0;
  while (i < n) {
    if (s.empty() || h[s.top()] <= h[i]) s.push(i++);
    else ans = max(ans, calc(i));
  }
  while (!s.empty()) ans = max(ans, calc(i));
  return ans;
}
