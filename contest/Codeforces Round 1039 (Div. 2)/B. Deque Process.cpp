#include <iostream>
#include <deque>
#include <string>
#include <climits>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll count;
        cin >> count;

        deque<ll> data;
        for (ll i = 0; i < count; ++i) {
            ll temp;
            cin >> temp;
            data.push_back(temp);
        }

        string moves = "";
        bool alternate = false;

        while (data.size() > 1) {
            ll small = min(data.front(), data.back());
            ll large = max(data.front(), data.back());

            if (!alternate) {
                if (small == data.front()) {
                    moves += 'L';
                    data.pop_front();
                } else {
                    moves += 'R';
                    data.pop_back();
                }
                alternate = true;
            } else {
                if (large == data.front()) {
                    moves += 'L';
                    data.pop_front();
                } else {
                    moves += 'R';
                    data.pop_back();
                }
                alternate = false;
            }
        }

        if ((int)moves.size() != count) {
            moves += 'L';
        }

        cout << moves << endl;
    }


    return 0;
}
