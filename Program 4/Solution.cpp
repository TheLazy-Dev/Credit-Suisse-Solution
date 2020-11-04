#include<bits/stdc++.h>

using namespace std;

bool cmp(double x, double y) {
  return x > y;
}

double maximumExpectedMoney(int n, int m, double p[], double x[], double y[]) {
  //Complete the maximumExpectedMoney function.
  vector < double > result;
  for (int i = 0; i < n; i++) {
    double val = (p[i] * x[i]) - ((1 - p[i]) * y[i]);
    if (val > 0) result.push_back(val);
  }
  sort(result.begin(), result.end(), cmp);
  double sum = 0;
  m = (m > result.size()) ? result.size() : m;
  for (int i = 0; i < m; i++) {
    sum += result[i];
  }
  return sum;

}

int main() {
  int n, m;

  cin >> n >> m;
  double p[n], x[n], y[n];

  for (int i = 0; i < n; i++)
    cin >> p[i];
  for (int i = 0; i < n; i++)
    cin >> x[i];
  for (int i = 0; i < n; i++)
    cin >> y[i];

  double result = maximumExpectedMoney(n, m, p, x, y);

  // Do not remove below line
  cout << fixed << setprecision(2) << result << endl;
  // Do not print anything after this line

  return 0;
}
