#include<bits/stdc++.h>

#define ll long long int
using namespace std;

ll count(ll s[], ll m, ll n) {
  long long int dp[m + 1][n + 1];
  for (int i = 0; i <= m; i++)
    dp[i][0] = 1;

  for (ll i = 1; i <= n; i++)
    dp[0][i] = 0;

  for (ll i = 1; i <= m; i++) {
    for (ll j = 1; j <= n; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j - s[i - 1] >= 0) {
        dp[i][j] += dp[i][j - s[i - 1]];
      }
    }
  }
  return dp[m][n];

}

int main() {
  ll i, sum, n;

  cin >> sum >> n;
  ll arr[n];

  for (i = 0; i < n; i++)
    cin >> arr[i];

  cout << count(arr, n, sum);
  return 0;
}
