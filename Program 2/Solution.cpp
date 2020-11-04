#include<bits/stdc++.h>

using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    int i = 0, diff = 0;
    while (i < n - 1) {
      while (i < n - 1 && arr[i + 1] <= arr[i])
        i++;
      if (i == n - 1)
        break;
      int ind = i++;
      while (i < n && arr[i - 1] <= arr[i])
        i++;
      int ind1 = i - 1;
      //cout<<ind<<" "<<ind1<<endl;
      diff += arr[ind1] - arr[ind];
    }
    cout << diff;
}
