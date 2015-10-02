#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string s;

bool prime(string n) {
  long long num = atol(n.c_str());
  if (num == 2) return true;
  if (num == 1 || num % 2 == 0) return false;
  for (long long i = 2; i < num; ++i) if (num % i == 0) return false;
  return true;
}

string trans() {
  string ret = "";
  for (int i = 0; i < s.size(); ++i) {
    char c = s[i];
    if (c == '6') c = '9';
    else if (c == '9') c = '6';
    ret = c + ret;
  }
  return ret;
}

bool check() {
  for (int i = 0; i < s.size(); ++i) {
    char c = s[i];
    if (c == '3' || c == '4' || c == '7') return false;
  }
  return prime(s) && prime(trans());
}

int main() {
  cin >> s;
  if (check()) cout << "yes" << endl;
  else cout << "no" << endl;
  return 0;
}
