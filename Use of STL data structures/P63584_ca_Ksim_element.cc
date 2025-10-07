// K-èsim element
// https://jutge.org/problems/P63584_ca
// P63584_ca:std:no_main:
// Created on 27/9/2025, 13:40:49 by Biel Martín de Diego

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> VE; 
typedef vector<VE> VVE;

int k_esim(int k, const VVE& V) {
  priority_queue<int> pq;

  int m = 0;
  for (int i = 0; i < V.size(); ++i) {
    for (int j = 0; j < V[i].size(); ++j) {
      if (m == k) {
        if (V[i][j] < pq.top()) {
          pq.pop();
          pq.push(V[i][j]);
        }
      } else {
        pq.push(V[i][j]);
        ++m;
      }
    }
  }

  return pq.top();
}


int main() {
  int n;
  while (cin >> n) {
    VVE V(n);
    int total = 0;
    for (int i = 0; i < n; ++i) {
      int m;
      cin >> m;
      total += m;
      V[i] = VE(m);
      for (int j = 0; j < m; ++j) cin >> V[i][j];
    }

    int i1, i2, k;
    while (cin >> i1 >> i2 >> k, i1 != -1) {
      if (i1 < 0 or i1 >= n or i2 < 0 or i2 >= n or k < 1 or k > total) {
        cerr << "pifia!!! " << i1 << ' ' << i2 << ' ' << k << ' ' << n << ' ' << total << endl;
        return 0;
      }

      swap(V[i1], V[i2]);
      cout << k_esim(k, V) << endl;
    }
  }
}
