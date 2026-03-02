G. Simons and Diophantus Equation
time limit per test6 seconds
memory limit per test512 megabytes

I walk alone, into distance, through the fading light, biding my time for the sunset's final light.
— SHUN, CHAKA
Simons has given you two integers n
 and m
.

Count the number of ordered tuples (i,j,k)
, such that:

0≤i,j,k≤m
, and
There exist two integers x
 and y
, such that (i⊕j)⋅x+(j⊕k)⋅y=n
, where ⊕
 denotes the bitwise XOR operation.
Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The only line contains two integers n
 and m
 (1≤n≤109
, 1≤m≤3⋅105
) — the given integers.

It is guaranteed that the sum of m
 over all test cases does not exceed 3⋅105
.

Output
For each test case, output a single integer — the number of ordered tuples (i,j,k)
 that satisfy the condition.

Example
InputCopy
5
3 2
4 6
1 1
7 20
720 2025
OutputCopy
18
254
6
5558
7864357450
Note
In the first test case, there are 18
 tuples that satisfy the conditions. For example:

(2,1,2)
 is a valid tuple because the equation (2⊕1)⋅x+(1⊕2)⋅y=3
 has an integer solution x=3
, y=−2
.
(1,1,0)
 is also a valid tuple because the equation (1⊕1)⋅x+(1⊕0)⋅y=3
 has an integer solution x=100
, y=3
.
(2,0,2)
 is not a valid tuple because the equation (2⊕0)⋅x+(0⊕2)⋅y=3
 has no integer solution.
(1,1,1)
 is not a valid tuple because the equation (1⊕1)⋅x+(1⊕1)⋅y=3
 has no integer solution.
(3,2,1)
 is not a valid tuple because 3>2
.

#include<bits/stdc++.h>
#define rep1(i, a, b) for(int i = a; i <= b; ++i)
#define rep2(i, a, b) for(int i = a; i >= b; --i)
#define pii pair <int, int>
#define ft first
#define sd second
#define ll long long
#define pb push_back
#define gmax(a, b) a = max(a, b)
#define gmin(a, b) a = min(a, b)
#define all(a) a.begin(), a.end()
#define debug cout << "------------------\n"
const int N = (1 << 21) + 10;
using namespace std;
int tot, ch[N][2], cnt[N], sz[N], fa[N]; ll f[N], sum[N];
int p[N], vis[N], miu[N];
void solve() {
    int n, m; cin >> n >> m;
    // get miu
    rep1(i, 0, tot) ch[i][0] = ch[i][1] = sz[i] = fa[i] = sum[i] = cnt[i] = 0;

    miu[1] = 1;
    tot = 0;
    rep1(i, 2, 2 * m) vis[i] = 0;
    rep1(i, 2, 2 * m) {
        if(!vis[i]) p[++tot] = i, miu[i] = -1;
        for(int j = 1; p[j] * i <= 2 * m && j <= tot; ++j) {
            vis[i * p[j]] = 1;
            if(i % p[j] == 0) break;
            miu[i * p[j]] = -miu[i];
        }
    }

    // get trie
    tot = 1;
    rep1(i, 0, m) {
        int nw = 1;
        rep2(j, 19, 0) {
            int &nxt = ch[nw][i >> j & 1];
            if(!nxt) nxt = ++tot, fa[nxt] = nw;
            nw = nxt;
        }
        while(nw) ++sz[nw], nw = fa[nw];
    }

    // get f(T)
    rep1(T, 1, 2 * m) {
        f[T] = 0;
        rep1(d, 1, 2 * m / T) {
            int nw = 1, bg = 0, v = (d * T) ^ m;
            rep2(i, 19, 0) {
                int x = v >> i & 1;
                if(m >> i & 1) {
                    int u = ch[nw][x ^ 1];
                    if(u) ++cnt[u], sum[u] += sz[u];
                }
                if(!ch[nw][x]) {bg = i + 1; break;}
                nw = ch[nw][x];
            }
            ll num = 0;
            if(!bg) ++cnt[nw], ++sum[nw], ++num;
            rep1(i, bg, 19) {
                nw = fa[nw];
                int x = v >> i & 1;
                if(m >> i & 1) {
                    int u = ch[nw][x ^ 1];
                    num += sz[u];
                }
                sum[nw] += num;
            }
        }
        rep1(d, 1, 2 * m / T) {
            int nw = 1, v = (d * T) ^ m;
            ll num = 0;
            rep2(i, 19, 0) {
                int x = v >> i & 1;
                num += cnt[nw];
                if(m >> i & 1) {
                    int u = ch[nw][x ^ 1];
                    if(u) f[T] += sum[u] + 1ll * num * sz[u];
                }
                nw = ch[nw][x];
                if(!nw) break;
            }
            if(nw) f[T] += sum[nw] + 1ll * num * sz[nw];
        }
        rep1(d, 1, 2 * m / T) {
            int nw = 1, bg = 0, v = (d * T) ^ m;
            rep2(i, 19, 0) {
                int x = v >> i & 1;
                int u = ch[nw][x ^ 1];
                cnt[nw] = sum[nw] = cnt[u] = sum[u] = 0;
                nw = ch[nw][x];
            }
            if(nw) cnt[nw] = sum[nw] = 0;
        }
    }

    ll ans = 0;
    rep1(d, 1, 2 * m) {
        if(n % d) continue;
        rep1(j, 1, 2 * m / d) {
            ans += miu[j] * f[j * d];
        }
    }

    // get i == j or j == k
    rep1(g, 1, 2 * m) {
        if(n % g) continue;
        int nw = 1, v = g ^ m;
        rep2(i, 19, 0) {
            int x = v >> i & 1;
            if(m >> i & 1) {
                int u = ch[nw][x ^ 1];
                ans += 2 * sz[u];
            }
            nw = ch[nw][x]; if(!nw) break;
        }
        if(nw) ans += 2;
    }

    cout << ans << '\n';
}
int main() {
    int T = 1; cin >> T;
    while(T--) solve();
    return 0;
}
