#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> v;
vector<bool> visited;

void RotateFunc(int pos, int dir) {
    visited[pos] = true;
    if (pos > 0 && !visited[pos - 1] && v[pos][6] != v[pos - 1][2])
        RotateFunc(pos - 1, -dir);
    if (pos < v.size() - 1 && !visited[pos + 1] && v[pos][2] != v[pos + 1][6])
        RotateFunc(pos + 1, -dir);
    
    if (dir == 1) {
        char temp = v[pos].back();
        v[pos] = temp + v[pos].substr(0, v[pos].size() - 1);
    } else {
        char temp = v[pos].front();
        v[pos] = v[pos].substr(1) + temp;
    }
}

int main() {
    int n, k;
    cin >> n;
    v.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cin >> k;

    for (int i = 0; i < k; i++) {
        int pos, dir;
        cin >> pos >> dir;
        RotateFunc(pos - 1, dir);
        visited.assign(n, false);  // Reset visited flags after each rotation.
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (v[i][0] == '1') {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}
