// Rol classificatori
// https://jutge.org/problems/P60296_ca
// P60296_ca:std:none:
// Created on 25/9/2025, 13:46:28 by Biel Martín de Diego

#include <iostream>
#include <unordered_map>
#include <utility>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (const pair<int,string>& a, const pair<int,string>& b) const {
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    }
};

int main() {
    unordered_map<string, pair<int, bool>> m;

    string inst, j;
    while (cin >> inst >> j) {
        if (inst == "LOGIN") {
            m[j].second = true;
            if (m[j].first == 0) m[j].first = 1200;
        } else if (inst == "LOGOUT") {
            auto it = m.find(j);
            if (it != m.end()) m[j].second = false;
        } else if (inst == "PLAY") {
            string j2;
            cin >> j2;
            auto it = m.find(j);
            auto it2 = m.find(j2);
            if ((it != m.end() and it2 != m.end()) and (m[j].second and m[j2].second)) {
                m[j].first += 10;
                m[j2].first -= 10;
                if (m[j2].first < 1200) m[j2].first = 1200;
            } else cout << "jugador(s) no connectat(s)" << endl;
        } else {
            auto it = m.find(j);
            if (it != m.end()) cout << j << ' ' << m[j].first << endl;
        }
    }

    cout << endl << "RANKING" << endl;

    priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
    for (auto it = m.begin(); it != m.end(); ++it) pq.push(make_pair(it->second.first, it->first));
    while (not pq.empty()) {
        cout << pq.top().second << ' ' << pq.top().first << endl;
        pq.pop();
    }
}
