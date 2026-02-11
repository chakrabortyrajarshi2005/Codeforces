B. The Curse of the Frog
time limit per test1 second
memory limit per test256 megabytes
On an infinite number line, at point 0
, sits a frog. After many years of meditation, the frog has mastered n
 unique types of magical jumps. The i
-th type of jump allows it to jump forward by no more than ai
 units. In other words, if it was at integer point k
, after the jump it can land at any integer point from k
 to k+ai
.

But magic always comes with a price; it has been cursed. Before each bi
-th attempt (before bi
-th, 2bi
-th, 3bi
-th etc. attempt among the jumps of type i
) to use the i
-th type of jump, the frog rolls back ci
 units! In other words, if it was at point k
, it will first find itself at point k−ci
, and after the jump, it can land at any integer point from k−ci
 to k−ci+ai
.

The frog's goal is to reach the point with the number x
, using jumps while minimizing the number of rollbacks. Help the frog — find the minimum number of rollbacks it will have to endure on its way to the goal, or determine that it cannot reach point x
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

In the first line of each test case, there are 2
 integers n
 and x
 (1≤n≤105
, 1≤x≤1018
) — the number of types of jumps the frog can make and its final target.

In the following n
 lines, the description of the jump types is provided; the i
-th line contains 3
 integers ai
, bi
, and ci
 (1≤ai,bi,ci≤106
).

It is guaranteed that the sum of n
 across all test cases does not exceed 105
.

Output
For each test case, if the frog can reach point x
, find the smallest number of rollbacks it must endure to do so. If it cannot reach point x
, output −1
.

Example
InputCopy
6
1 1
3 3 3
1 7
4 2 5
2 4
1 2 3
2 2 4
5 8
12 1 11
10 1 4
1 1 3
1 2 5
2 1 7
1 1000000000000000000
1000000 4 654321
1 10
2 2 1
OutputCopy
0
1
-1
2
298892990032
3
Note
In the first test case, the frog can jump forward by 1
 unit and will end up at point 1
. Thus, the answer is 0
.

In the third test case, it can be shown that the frog cannot reach point 4
.

In the fourth test case, the frog can reach point 8
, for example, as follows: jump using the 1
-st type by 12
, jump using the 4
-th type by 1
, and jump using the 2
-nd type by 10
. Then it will sequentially be at the following points 0→(rollback)−11→1→2→(rollback)−2→8
.

In the sixth test case, the frog can reach point 10
, for example, as follows: jump 6
 times by 2
 and 1
 time by 1
. Then it will sequentially be at#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define rall(a), a.rbegin(), a.rend()

const int mod = 1e9+7;
const int inf = 1e9;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    int start = 0;
    int mx = -inf;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, a[i] * b[i] - c[i]);
        start += a[i] * (b[i] - 1);
    }
    x -= start;
    if (x <= 0) {
        cout << 0;
        return;
    }
    if (mx <= 0) {
        cout << -1;
        return;
    }
    cout << (x + mx - 1) / mx;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
        cout << '\n';
    }
}
