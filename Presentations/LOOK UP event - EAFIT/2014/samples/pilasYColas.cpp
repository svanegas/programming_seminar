#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void
stackSample() {
  cout << "Stack" << endl;
  stack <int> s;
  for (int i = 1; i <= 5; i++) {
    cout << "Insert integer " << i << ": ";
    int number;
    cin >> number;
    s.push(number);
  }
  while (!s.empty()) {
    cout << "Pop number: " << s.top() << endl;
    s.pop(); 
  }
}

void
queueSample() {
  cout << "Queue" << endl;
  queue <int> q;
  for (int i = 1; i <= 5; i++) {
    cout << "Insert integer " << i << ": ";
    int number;
    cin >> number;
    q.push(number);
  }
  while (!q.empty()) {
    cout << "Pop number: " << q.front() << endl;
    q.pop(); 
  }
}

int
main() {
  //stackSample();;
  queueSample();
  return 0;
}
