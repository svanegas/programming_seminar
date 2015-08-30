int
main() {
  int n; cin >> n;
  cin.ignore(); // EXTREMELY IMPORTANT.
  for (int i = 0; i < n; ++i) {
    string line; getline(cin, line);
    int current, sum = 0;
    stringstream ss(line);
    while (ss >> current) sum += current;
    cout << sum << endl;
  }
  return 0;
}
