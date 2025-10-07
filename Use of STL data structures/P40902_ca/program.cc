#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> casino;

    string name, inst;
    while (cin >> name >> inst) {
        map<string, int>::iterator it = casino.find(name);
        if (inst == "enters") {
            if (it == casino.end()) casino[name];
            else cout << name << " is already in the casino" << endl;
        } else if (inst == "leaves") {
            if (it == casino.end()) cout << name << " is not in the casino" << endl;
            else {
                cout << name << " has won " << casino[name] << endl;
                casino.erase(name);
            }
        } else {
            int x;
            cin >> x;
            if (it == casino.end()) cout << name << " is not in the casino" << endl;
            else casino[name] += x;
        }
    }

    cout << "----------" << endl;

    for (map<string, int>::iterator it = casino.begin(); it != casino.end(); ++it) cout << it->first << " is winning " << it->second << endl;
}