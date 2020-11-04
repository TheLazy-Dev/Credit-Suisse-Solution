#include<bits/stdc++.h>

using namespace std;
string find_min_days(int profit[], int price[], int n, int t) {

  int temp = 0;
  string s = "";
  while (t--> 0) {
    int start = 0, end = 0;
    int dis = INT_MAX;
    map < int, int > mp;
    for (int i = 0; i < n; i++) {
      mp[price[i]]++;
    }
    bool ok = true;
    int i = 0;
    for (i = n - 1; i >= 0; i--) {
      int k = price[i] - profit[temp];
      mp[price[i]]--;
      if (mp.find(k) != mp.end() && mp[k] > 0) {
        end = i + 1;
        for (int j = i - 1; j >= 0; j--) {
          if (price[j] == price[i]) {
            end = j + 1;
          }
          if (price[j] == k) {
            start = j + 1;
            break;
          }
        }

      }

    }
    if (start == 0 && end == 0) {
      s += "-1";
      if (t != 0)
        s += ",";
      temp++;
      continue;
    }
    s += to_string(start);
    s += " ";
    s += to_string(end);
    if (t != 0)
      s += ",";

    temp++;
  }
  return s;

}

int main() {
  int n, d, i;
  string answer = "";
  cin >> n >> d;
  int price[n];
  int profit[d];
  for (i = 0; i < n; i++)
    cin >> price[i];
  for (i = 0; i < d; i++)
    cin >> profit[i];
  answer = find_min_days(profit, price, n, d);

  // Do not remove below line
  cout << answer << endl;
  // Do not print anything after this line

  return 0;
}
