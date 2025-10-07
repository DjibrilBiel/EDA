// First occurrence
// https://jutge.org/problems/P84219_en
// P84219_en:std:no_main:
// Created on 7/10/2025 9:01:15 by Biel Martín de Diego

#include <iostream>
#include <vector>
using namespace std;


int first_occurrence(double x, const vector<double>& v) {
    int e = 0;
    int d = v.size() - 1;
    int res = -1;

    while (e <= d) {
        int m = e + (d - e) / 2;

        if (v[m] > x) d = m-1;
        else if (v[m] < x) e = m+1;
        else {
            d = m-1;
            res = m;
        }
    }

    return res;
}


int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << first_occurrence(x, V) << endl;
        }
    }
}
