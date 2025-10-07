// Mediana dinàmica
// https://jutge.org/problems/P37064_ca
// P37064_ca:std:none:
// Created on 27/9/2025, 14:30:15 by Biel Martín de Diego

#include <iostream>
#include <set>
using namespace std;

int main() {
    set<string> s;
    string w;

    cin >> w;
    if (w == "END") return 0;
    s.insert(w);
    cout << w << endl;

    auto it = s.begin();
    bool par = false;

    while (cin >> w and w != "END") {
        s.insert(w);

        par = not par;
        if (*it < w) {
            if (not par) ++it;
        } else {
            if (par) --it;
        }

        cout << *it << endl;
    }
}
