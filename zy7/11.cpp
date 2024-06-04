#include <bits/stdc++.h>
using namespace std;

void selection_sort(int* a, int n) {
  for (int i = 1; i < n; ++i) {
    int ith = i;
    for (int j = i + 1; j <= n; ++j) {
      if (a[j] < a[ith]) {
        ith = j;
      }
    }
    std::swap(a[i], a[ith]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  int *v = new int[n + 1];

  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }

  selection_sort(v, n);

  for (int i = 1; i <= n; i++) {
    cout << v[i] << ' ';
  }

  return 0;
}