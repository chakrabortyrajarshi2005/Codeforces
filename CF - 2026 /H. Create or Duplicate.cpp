H. Create or Duplicate
time limit per test6 seconds
memory limit per test1024 megabytes

Santa realized that hand-drawing circles takes too long, so he has turned to magic to meet his production quotas.

There are three types of presents with distinct values a
, b
, and c
. Initially, Santa has exactly one present of each type.

You are given two integers m
 and k
, representing Santa's favorite number and the cost of duplication, respectively. Santa can cast the following two types of spells any number of times (possibly zero):

Create — Choose a type of present and create one additional present of that type. This spell costs x
 mana, where x∈{a,b,c}
 is the value of the chosen type.
Duplicate — Choose a type of present and duplicate all presents of that type. This spell costs k
 mana.
Santa wants to perform a sequence of spells such that the sum of the values of all presents is a multiple of m
 after the spells.

Determine the minimum amount of mana Santa needs to achieve this. It can be shown that, under the given constraints, such a sequence of spells always exists.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The only line of each test case contains five integers a
, b
, c
, m
, and k
 (1≤a<b<c<m≤5⋅105
, 1≤k≤5⋅105
).

It is guaranteed that the sum of m
 over all test cases does not exceed 5⋅105
.

It is guaranteed that the sum of k
 over all test cases does not exceed 5⋅105
.

Output
For each test case, output a single integer — the minimum amount of mana Santa needs to make the sum of the values of all presents a multiple of m
.

Example
InputCopy
7
1 2 3 21 4
3 4 5 12 34
3 12 14 18 1
6 7 8 10 3
100 103 282 488 221
307 2000 5096 12018 5764
194093 292793 395323 475619 490151
OutputCopy
10
0
17
9
1227
35116
7050242
Note
Let ℓ
 be the list of values of presents and sum(ℓ)
 be the sum of all elements in ℓ
.

In the first test case, below is an optimal sequence of operations:

#	Operation	Value	ℓ
 after operation	sum(ℓ)
Cost
0	—	—	[1,2,3]
6
—
1	Create	3
[1,2,3,3]
9
3
2	Create	3
[1,2,3,3,3]
12
3
3	Duplicate	3
[1,2,3,3,3,3,3,3]
21
4
21=7⋅3
Total: 10
In the second test case, it is optimal to not perform any operations because 3+4+5=12
 is already a multiple of 12
.

In the third test case, below is an optimal sequence of operations:

#	Operation	Value	ℓ
 after operation	sum(ℓ)
Cost
0	—	—	[3,12,14]
29
—
1	Duplicate	12
[3,12,12,14]
41
1
2	Duplicate	14
[3,12,12,14,14]
55
1
3	Create	14
[3,12,12,14,14,14]
69
14
4	Duplicate	3
[3,3,12,12,14,14,14]
72
1
72=18⋅4
Total: 17

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
const ll MOD = 998244353;
const ll MAXX = 1e16;
const int INF = 1e9 + 7;
void solve() {
    int a, b, c, m , k;
    cin >> a >> b >> c >> m >> k;

    auto F = [&] (vl& dist, int p) {
        dist.assign(m, MAXX);
        dist[p] = 0;
        priority_queue<pll, vector<pll>, greater<>> pq;
        pq.push({0, p});
        while (!pq.empty()) {
            auto [D, u] = pq.top();
            pq.pop();
            int x = (u + p) % m;
            int y = (2 * u) % m;
            if (dist[x] > D + p) {
                dist[x] = D + p;
                pq.push({D + p, x});
            }
            if (dist[y] > D + k) {
                dist[y] = D + k;
                pq.push({D + k, y});
            }
        }
    };
    vl dista(m), distb(m), distc(m);
    F(dista, a); F(distb, b); F(distc, c);

    vl D(m, MAXX);
    priority_queue<pll, vector<pll>, greater<>> pq;
    for (int i = 0; i < m; i++) {
        D[i] = min(distb[(i + m - a) % m], dista[(i + m - b) % m]);
        pq.push({D[i], i});
    }
    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();
        int x = (u + a) % m;
        int y = (u + b) % m;
        int z = (2 * u) % m;
        if (D[x] > dist + a) {
            D[x] = dist + a;
            pq.push({dist + a, x});
        }
        if (D[y] > dist + b) {
            D[y] = dist + b;
            pq.push({dist + b, y});
        }
        if (D[z] > dist + 2 * k) {
            D[z] = dist + 2 * k;
            pq.push({dist + 2 * k, z});
        }
    }
    ll ans = MAXX;
    for (int i = 0; i < m; i++) {
        ans = min(ans, D[i] + distc[(m - i) % m]);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
