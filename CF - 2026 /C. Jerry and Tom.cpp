C. Jerry and Tom
time limit per test3 seconds
memory limit per test256 megabytes

Jerry and Tom are playing a game on a directed graph G
 with n
 vertices, numbered from 1
 to n
. For every vertex 1≤u<n
, there is a directed edge from u
 to u+1
. In addition, there are m
 extra directed edges. The i
-th extra edge goes from ui
 to vi
, where 1≤ui<vi≤n
.

The graph G
 has the following special property: there do not exist two directed edges (ui→vi)
 and (uj→vj)
 such that ui<uj<vi<vj
.

At the beginning of the game, Jerry and Tom stand on vertices x
 and y
, respectively, where x≠y
. The game proceeds in turns. In each turn, the players behave according to the following rules, with Jerry going first, followed by Tom:

Jerry must choose one outgoing edge from his current vertex and move along it to its end. If his current vertex has no outgoing edges, he stays where he is.
Tom may choose one outgoing edge from his current vertex and move along it to its end, or choose not to move and stay where he is.
If at the end of any turn, Jerry and Tom are at the same vertex (including at vertex n
), the game ends immediately and Tom wins. Otherwise, if Jerry is initially at vertex n
, or reaches vertex n
 at the end of any turn, Jerry wins.

Note that if after a turn, both Jerry and Tom are at vertex n
, then Tom wins.

Throughout the entire game, both players know each others' locations.

It can be proven that the game will end in a finite number of turns.

For a pair of integers 1≤x,y≤n
, x≠y
, define f(x,y)
 as follows:

Jerry and Tom will play a game, where Jerry starts at vertex x
 and Tom starts at vertex y
. Tom wants to win, but he also wants to minimise the number of times he actually moves (that is, the number of turns in which he changes his vertex; staying still does not count as a move). Assuming both players play optimally, let f(x,y)=0
 if Tom cannot win; otherwise, let f(x,y)
 be the minimum number of moves Tom has to make in order to force a win. If Tom wins under optimal play, Jerry will still try to maximize the number of moves Tom has to make.
Compute
∑1≤x,y≤n,x≠yf(x,y).

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains two integers n
 and m
 (2≤n≤2⋅105
, 0≤m≤n−2
), representing the number of vertices and the number of extra edges, respectively.

The i
-th of the next m
 lines contains two integers ui
 and vi
 (1≤ui,vi≤n
, ui+1<vi
), representing an extra edge. It is guaranteed that for any ordered pair of vertices (u,v)
, there exists at most one edge from u
 to v
. It is guaranteed that there do not exist two directed edges (ui→vi)
 and (uj→vj)
 such that ui<uj<vi<vj
.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output an integer representing the value of the expression.

Example
InputCopy
5
2 0
3 1
1 3
4 2
2 4
1 4
5 1
1 4
8 3
1 4
5 8
2 4
OutputCopy
0
2
6
3
23
Note
In the first test case:

x=1
, y=2
: Jerry is forced to move to 2
 on the first turn. Then, Tom can wait at 2
. At the end of the first turn, both Jerry and Tom are at 2
, and thus, f(1,2)=0
 as Tom can win without ever moving.
x=2
, y=1
: Jerry is at n=2
 at the beginning; Tom cannot force a win. Thus, f(2,1)=0
.
In the third test case, the pairs of (x,y)
 such that Tom wins are as follows:

For x=1,2,3
 and y=4
. No matter where Jerry moves to, Tom can stay at 4
 until Jerry reaches 4
. Tom can win without ever moving. f(1,4)=f(2,4)=f(3,4)=0
.
For x=1,2
 and y=3
, no matter where Jerry moves to on the first turn, Tom has to move to 4
 on the first turn to guarantee a win. For example, if Jerry starts at 1
 and moves to 4
 through the edge (1→4)
, but Tom chooses to stay at 3
 on the first turn, Jerry reaches 4
 at the end of the first turn, winning the game. Thus, f(1,3)=f(2,3)=1
.
For x=1,3
 and y=2
, Tom also has to move to 4
 on the first turn to guarantee a win; f(1,2)=f(3,2)=1
.
For x=2,3
 and y=1
, Tom still has to move to 4
 on the first turn to guarantee a win; f(2,1)=f(3,1)=1
.#include <bits/stdc++.h>
 
using namespace std;
 
using i64 = long long;
 
i64 solve_tree(int n, int r, vector<vector<int>> g) {
    vector<int> dep(n), sz(n, 1), pa(n);
    i64 ans = 0;
    auto dfs = [&](auto &&self, int u, int p) -> map<int, int> {
        pa[u] = p;
        map<int, int> mp;
        mp[dep[u]] = 1;
        for (auto v : g[u]) if (v != p) {
            dep[v] = dep[u] + 1;
            auto nmp = self(self, v, u);
            if (mp.size() < nmp.size()) swap(mp, nmp);
            for (auto &[d, f] : nmp) {
                ans += 1LL * f * mp[d] * (d - dep[u]);
                mp[d] += f;
            }
            sz[u] += sz[v];
        }
        return mp;
    };
    dfs(dfs, r, -1);
    for (int u = 0; u < n; u++) {
        i64 s = 1LL * sz[u] * (sz[u] - 1) / 2;
        for (auto v : g[u]) if (v != pa[u]) s -= 1LL * sz[v] * (sz[v] - 1) / 2;
        ans -= 1LL * dep[u] * s;
    }
    sort(dep.begin(), dep.end());
    for (int u = 0; u < n; u++) ans += 1LL * dep[u] * (n - u - 1);
    return ans;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n - 1; i++) a[i] = i + 1;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        a[u] = max(a[u], v);
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) g[a[i]].push_back(i);
    cout << solve_tree(n, n - 1, g) << "\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--) solve();
}
