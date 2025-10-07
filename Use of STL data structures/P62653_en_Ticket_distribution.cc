// Ticket distribution
// https://jutge.org/problems/P62653_en
// P62653_en:std:none:
// Created on 27/9/2025, 15:04:22 by Biel Martín de Diego

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

string w;

struct cmp {
    bool operator() (string a, string b) const {
        if (a.size() != b.size()) return a.size() > b.size();

        string v = w.substr(0, a.size());
        if ((v <= a and v <= b) or (v > a and v > b)) return a > b;
        return a <= b;
    }
};

int main() {
    while (cin >> w) {
        priority_queue<string, vector<string>, cmp> pq;
        int n = 0;

        char inst;
        while (cin >> inst and inst != 'E') {
            if (inst == 'T') ++n;
            else {
                string c;
                cin >> c;
                pq.push(c);
            }

            if (n > 0 and not pq.empty()) {
                cout << pq.top() << endl;
                pq.pop();
                --n;
            }
        }

        while (n > 0 and not pq.empty()) {
            cout << pq.top() << endl;
            pq.pop();
            --n;
        }

        cout << n << " ticket(s) left" << endl;
        cout << pq.size() << " supporter(s) with no ticket" << endl;
        cout << endl;
    }
}
