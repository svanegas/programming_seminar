//Esteban Foronda Sierra
using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r;}

#define D(x) cout << #x " is " << x << endl

int main(){
   stack<int> s;
   int n;cin>>n;
   while(n--){
      string word;cin>>word;
      if(word == "PUSH"){
         int number;cin>>number;
         s.push(number);  
      }
      if(word == "POP"){
         if(!s.empty())s.pop();
      }
      if(word == "TOP"){
         if(!s.empty())cout << s.top()<<endl;
         else cout << "EMPTY" << endl;   
      }
   }
	return 0;
}
