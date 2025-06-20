#include <bits/stdc++.h>
using namespace std;

int main() {
    int ladder, snakes;
    cin >> ladder;

    map<int, int> lad, snak;
    for (int i = 0; i < ladder; ++i) {
        int u, v;
        cin >> u >> v;
        lad[u] = v;
    }

    cin >> snakes;
    for (int i = 0; i < snakes; ++i) {
        int u, v;
        cin >> u >> v;
        snak[u] = v;
    }

    vector<int> vis(101, 0);
    queue<int> q;
    q.push(1);
    vis[1] = 1;

    int moves = 0;
    bool found = false;

    while (!q.empty() && !found) {
        int sz = q.size();
        while (sz--) {
            int curr = q.front();
            q.pop();

            for (int die = 1; die <= 6; ++die) {
                int next = curr + die;
                if (next > 100) continue;

                // Ladder or snake overrides the move
                if (lad.count(next)) next = lad[next];
                else if (snak.count(next)) next = snak[next];

                if (!vis[next]) {
                    vis[next] = 1;
                    if (next == 100) {
                        found = true;
                        break;
                    }
                    q.push(next);
                }
            }
            if (found) break;
        }
        moves++;
    }

    cout << (found ? moves : -1);
    return 0;
}
