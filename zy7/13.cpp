#include <bits/stdc++.h>
using namespace std;

void merge(const int *a, size_t aLen, const int *b, size_t bLen, int *c) {
  size_t i = 0, j = 0, k = 0;
  while (i < aLen && j < bLen) {
    if (b[j] < a[i]) {  //保证稳定性
      c[k] = b[j];
      ++j;
    } else {
      c[k] = a[i];
      ++i;
    }
    ++k;
  }
  for (; i < aLen; ++i, ++k) c[k] = a[i];
  for (; j < bLen; ++j, ++k) c[k] = b[j];
}

void merge_sort(int *a, int l, int r) {
  if (r - l <= 1) return;
  // 分解
  int mid = l + ((r - l) >> 1);
  merge_sort(a, l, mid), merge_sort(a, mid, r);
  // 合并
  int tmp[1024] = {};
  merge(a + l, a + mid, a + mid, a + r, tmp + l);
  for (int i = l; i < r; ++i) a[i] = tmp[i];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  int *v = new int[n + 1];

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  merge_sort(v, 0, n);

  for (int i = 0; i < n; i++) {
    cout << v[i] << ' ';
  }

  return 0;
}