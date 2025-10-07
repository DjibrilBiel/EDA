// La bossa de les paraules
// https://jutge.org/problems/P84415_ca
// P84415_ca:std:none:
// Created on 25/9/2025, 8:48:49 by Biel Martín de Diego

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> m;

    string inst;
    while (cin >> inst) {
        if (inst == "store") {
            string p;
            cin >> p;
            ++m[p];
        } else if (inst == "delete") {
            string p;
            cin >> p;
            auto it = m.find(p);
            if (it != m.end()) {
                it->second--;
                if (it->second == 0) m.erase(it);
            }
        } else if (inst == "maximum?") {
            if (not m.empty()) {
                auto it = m.end();
                --it;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            } else cout << "indefinite maximum" << endl;
        } else {
            if (not m.empty()) {
                auto it = m.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            } else cout << "indefinite minimum" << endl;
        }
    }
}
