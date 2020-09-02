#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <bitset>
#include <functional>

#ifdef __APPLE__
#define cin fin
std::ifstream cin("__sample.in");
#endif

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int INT_INF = 0x3f3f3f3f;
const int d4r[] = {0, 1, 0, -1}, d4c[] = {1, 0, -1, 0};

char grid[100][100];
bool vis[100][100];
int W, H;

void dfs(int i, int j, char c) {
    vis[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int ii = i + d4r[k], jj = j + d4c[k];
        if (ii < 0 || ii >= H || jj < 0 || jj >= W || grid[ii][jj] != c || vis[ii][jj]) continue;
        dfs(ii, jj, c);
    }
}

void solve() {
    int ret = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!vis[i][j]) {
                ret++;
                dfs(i, j, grid[i][j]);
            }
        }
    }
    cout << ret << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> H >> W) {
        if (W == 0 && H == 0) break;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> grid[i][j];
            }
        }
        solve();
    }

    return 0;
}