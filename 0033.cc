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

void solve() {
    int left(0), right(0), v;
    bool valid = true;
    for (int i = 0; i < 10; i++) {
        cin >> v;
        if (valid) {
            if (v < left && v < right) valid = false;
            else if (v < left) right = v;
            else if (v < right) left = v;
            else if (left <= right) right = v;
            else left = v;
        }
    }
    cout << (valid ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    for (int i = 0; i < N; i++) solve();

    return 0;
}