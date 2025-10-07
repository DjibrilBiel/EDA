// Easy game?
// https://jutge.org/problems/P60219_en
// P60219_en:std:none:
// Created on 25/9/2025, 15:59:31 by Biel Martín de Diego

#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (string a, string b) const {
        if (a.size() != b.size()) return a.size() > b.size();
        return a > b;
    }
};

int main() {
    int game = 0;
    string w = "";
    bool first_time = true;
    while (w != "QUIT") {
        map<string, bool> S;
    
        if (first_time) first_time = false;
        else cout << endl;
        cout << "GAME #" << ++game << endl;

        while (cin >> w and w != "QUIT" and w != "END") S[w] = not S[w];

        priority_queue<string, vector<string>, cmp> pq;
        cout << "HAS:" << endl;
        for (auto it = S.begin(); it != S.end(); ++it) {
            if (it->second) cout << it->first << endl;
            else pq.push(it->first);
        } cout << endl << "HAD:" << endl;
        while (not pq.empty()) {
            cout << pq.top() << endl;
            pq.pop();
        }
    }
}
