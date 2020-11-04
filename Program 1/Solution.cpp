#include<bits/stdc++.h>

using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int diff = 0, min_element = a[0];
  for (int i = 1; i < n; i++) {
    if (min_element > a[i])
      min_element = a[i];

    diff = max(diff, a[i] - min_element);
  }
  //cout<<diff;

  // Do not remove this line
  cout << diff << "\n";
  // Do not print anything after this line

  return 0;
}
