int
main() {
  string line;
  while (getline(cin, line)) {
    int current, sum = 0;
    stringstream ss(line);
    while (ss >> current) sum += current;
    cout << sum << endl;
  }
  return 0;
}
