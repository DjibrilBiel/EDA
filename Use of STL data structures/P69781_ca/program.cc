#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int x, y, n;
    while (cin >> x >> y >> n) {
        unordered_map<int, int> m;
        int p;

        bool finish, limit;
        finish = limit = false;
        for (int i = 0; not finish and not limit; ++i) {
            m[n] = i;

            if (n % 2 == 0) n = n / 2 + x;
            else n = 3 * n + y;
            
            auto it = m.find(n);
            if (it != m.end()) {
                finish = true;
                p = i - it->second + 1;
            }

            limit = n > 100000000;
        }
        if (limit) cout << n << endl;
        else cout << p << endl;
    }
}