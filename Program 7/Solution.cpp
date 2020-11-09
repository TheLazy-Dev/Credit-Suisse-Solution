#include<bits/stdc++.h>

using namespace std;
vector < int > adj[10001];
int flg[10001];
int dfs(int src, int x) {
  int ans = 0;
  for (int i = 0; i < adj[src].size(); i++) {
    if (adj[src][i] == x || ans == 2) {
      flg[adj[src][i]] = 1;
      return 1;
    }

    if (flg[adj[src][i]] != -1)
      ans += 1;
    else
      ans += dfs(adj[src][i], x);
  }
  return flg[src] = ans;
}
int main() {
  int n;
  string s;
  cin >> n;
  char c;
  cin >> c;
  getline(cin, s);
  memset(flg, -1, sizeof(flg));
  s = c + s;
  //cout<<s;
  string str = "";
  int temp = -1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ') {
      int ind = stoi(str);
      if (temp == -1) {
        temp = stoi(str);
      } else {
        adj[temp].push_back(ind);
      }
      str = "";
      continue;
    }
    if (s[i] == ',') {
      int ind = stoi(str);
      if (temp == -1) {
        temp = stoi(str);
      } else {
        adj[temp].push_back(ind);
      }
      temp = -1;
      str = "";
      continue;
    }

    str += s[i];
  }
  int ind = stoi(str);
  adj[temp].push_back(ind);
  vector < int > v;
  for (int i = 1; i <= n; i += 1) {
    int ans = 0;
    ans = dfs(i, i);
    if (adj[i].size() >= 2 && ans >= 2)
      v.push_back(i);
    else if (adj[i].size() == 1 && ans == 1)
      v.push_back(i);

  }
  for (int i = 0; i < v.size(); i++) {
    if (i == v.size() - 1) {
      continue;
    }
    cout << v[i] << ",";
  }
  cout << v[v.size() - 1];
}
