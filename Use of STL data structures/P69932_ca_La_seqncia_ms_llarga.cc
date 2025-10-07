// La seqüència més llarga
// https://jutge.org/problems/P69932_ca
// P69932_ca:std:none:
// Created on 25/9/2025, 10:11:44 by Biel Martín de Diego

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        // si la línia està buida resposta 0
        istringstream iss(line);
        long long x;
        vector<long long> v;
        while (iss >> x) v.push_back(x);

        if (v.empty()) {
            cout << 0 << "\n";
            continue;
        }

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end()); // valors únics i ordenats

        int runs = 1; // hi ha almenys un bloc
        for (size_t i = 1; i < v.size(); ++i) {
            if ((v[i] % 2) != (v[i-1] % 2)) ++runs;
        }

        cout << runs << "\n";
    }
}