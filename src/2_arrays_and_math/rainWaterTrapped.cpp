#include <bits/stdc++.h>
using namespace std;

// Method - 1 (Using pre and post max arrays)
// T(n) : O(n), S(n) : O(n)
int rainWaterTrapped1(vector<int>& level) {

  int n = level.size();

  if (n <= 2) {
    return 0;
  }

  vector<int> post(n);

  post[n - 1] = level[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    post[i] = max(post[i + 1], level[i]);
  }

  int res = 0, temp = level[0];
  for (int i = 1; i < n - 2; i++) {
    res += max(0, min(temp, post[i + 1]) - level[i]);
    temp = max(temp, level[i]);
  }

  return res;
}

// Method - 2 (Two Pointer Method)
// T(n) : O(n), S(n) : O(1)
int rainWaterTrapped2(vector<int>& level) {
  int res = 0;


  return res;
}

// driver code
int main() {

  vector<int> level {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << rainWaterTrapped1(level) << "\n";

  return 0;
}
