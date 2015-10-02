#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10;
int nums[MAXN];

void
array() {
  for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
    cin >> nums[i];
  }
  for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
    if (nums[i] == 0) {
      cout << "I found a 0 in position: " << i << endl;
      break;
    }
  }
}

void
dynamic() {
  vector <int> vec;
  for (int i = 1; i <= 5; i++) {
    cout << "Insert integer " << i << ": ";
    int number;
    cin >> number;
    vec.push_back(number);
  }
  for (int i = 1; i < 5; i++) {
    cout << (vec[i] - vec[i - 1]) << endl; 
  }
}

int
main() {
  //array(); //Not commonly used
  dynamic();
  return 0;
}
