#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;
    char c;
    
    while (cin >> c) {
        if (c == 'S') {
            int x;
            cin >> x;
            pq.push(x);
        } else if (c == 'A') {
            if (pq.empty()) cout << "error!" << endl;
            else cout << pq.top() << endl;
        } else if (c == 'R') {
            if (pq.empty()) cout << "error!" << endl;
            else pq.pop();
        } else if (c == 'I') {
            int x;
            cin >> x;
            if (pq.empty()) cout << "error!" << endl;
            else {
                int tmp = pq.top();
                tmp += x;
                pq.pop();
                pq.push(tmp);
            }
        } else if (c == 'D') {
            int x;
            cin >> x;
            if (pq.empty()) cout << "error!" << endl;
            else {
                int tmp = pq.top();
                tmp -= x;
                pq.pop();
                pq.push(tmp);
            }
        }
    }
}