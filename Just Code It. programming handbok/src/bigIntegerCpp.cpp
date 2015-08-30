string
sumar(const string &a, const string &b) {
  int ia = a.size() - 1, ib = b.size() - 1;
  int llevo = 0;
  string ans = "";
  while (ia >= 0 || ib >= 0) {
    int sum = (ia >= 0 ? toInt(a[ia--]) : 0)
            + (ib >= 0 ? toInt(b[ib--]) : 0);
    sum += llevo;
    llevo = sum / 10;
    ans += toStr(sum % 10);
  }
  if (llevo) ans += toStr(llevo);
  reverse(ans.begin(), ans.end());
  return ans;
}