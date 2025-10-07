// Mesures estadístiques
// https://jutge.org/problems/P59282_ca
// P59282_ca:std:none:
// Created on 25/9/2025, 9:16:54 by Biel Martín de Diego

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
using namespace std;

int main() {
    int count = 0;
    double sum = 0;

    map<int, int> m;

    string inst;
    while (cin >> inst) {
        if (inst == "number") {
            int n;
            cin >> n;
            ++m[n];

            sum += n;
            ++count;
        } else {
            if (not m.empty()) {
                auto it = m.begin();
                --(it->second);

                sum -= it->first;
                --count;

                if (it->second == 0) m.erase(it);
            }
        }
        if (not m.empty()) {
            cout << fixed << setprecision(4);
            cout << "minimum: " << m.begin()->first << ", maximum: " << m.rbegin()->first << ", average: " << sum / count << endl;
        } else {
            cout << "no elements" << endl;
        }
    }
}
