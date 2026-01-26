H1. Bug Is Feature (Unconditional Version)
time limit per test2 seconds
memory limit per test256 megabytes

This is the unconditional version of the problem. The difference between the versions is that in this version, there is no "non-decreasing common difference" condition. You can hack only if you solved all versions of this problem.

Note that neither version is necessarily easier than the other, and they can be solved independently.

Bug and Feature are immersed in a game of Sequence. In this unique version of the Sequence game, a sequence begins with three positive integers a<b<c≤x
, forming an arithmetic progression (i.e., b−a=c−b
). During each turn, a player can selectively increase one of a
, b
, or c
 by a positive integer. After the move, the numbers must retain their arithmetic progression, possibly with a new order. Moreover, none of a
, b
, or c
 should exceed x
.

Not content with the conventional Sequence game, Bug and Feature decide to engage in a n
 series of Sequence games simultaneously. For the i
-th series, they are provided with five numbers ai<bi<ci≤li≤ri
. They will play a game with numbers ai<bi<ci≤x
 for every integer x
 in the range [li,ri]
 (resulting in a total of ∑ni=1(ri−li+1)
 games). Taking turns, they play all the games together, with Bug starting first and then Feature. In each turn, a player selects an unfinished game and makes a move in that game. The player who cannot make a move loses.

Now, the question is: if both players play optimally, who will emerge victorious?

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤105
). The description of the test cases follows.

The first line of each test case consists of a single integer n
 (1≤n≤2⋅105
) — the number of series of games that Bug and Feature wish to play.

Each of the next n
 lines contains five integers ai,bi,ci,li,ri
 — (1≤ai<bi<ci≤li≤ri≤1018
), representing the specifications of the i
-th series of games. ai
, bi
, and ci
 form an arithmetic progression. (ci−bi=bi−ai)

The sum of n
 over all test cases is at most 2⋅105
.

Output
For each test, output Bug
 if Bug wins, and Feature
 if Feature wins.

Example
InputCopy
5
1
1 3 5 5 6
1
2 4 6 8 10
2
4 6 8 10 11
4 8 12 16 19
1
1 2 3 3 3
1
1000000000000 2000000000000 3000000000000 4000000000000 5000000000000
OutputCopy
Bug
Bug
Feature
Feature
Feature
Note
In the first test case, there are 2
 instances of the game, corresponding to each value of x
 in the range 5
 to 6
. The sequence in each instance is initially 1,3,5
.

Bug can secure a winning strategy as follows:

In the instance with x=5
, Bug changes a
 from 1
 to 4
. Consequently, the sequence becomes 3,4,5
, and it is easy to verify that no further move is possible in this instance.

Next, Feature must play by changing the value of a
 from 1
 to 4
 in the instance with x=6
.

Then, Bug responds by changing b
 from 3
 to 6
 in the instance with x=6
. After this move, the sequence in that instance also becomes fixed, and no further operation can be performed.
#include <iostream>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;
 
inline ll lg2(ll x){return 63 - __builtin_clzll(x);}
constexpr inline ll period(ll k) {return 1LL<<(k+1);}
constexpr inline ll half_period(ll k) {return 1LL<<k;}
inline ll equivalent(ll x, ll k) {return x & (period(k)-1);}
inline bool count_period_parity(ll x, ll k) {return (x >> (k+1)) & 1;}
 
struct node {
    int u;
    node(bool zero, bool one, bool two) {
        u = ((int) zero << 0) + ((int) one << 1) + ((int) two << 2);
    }
    node(int x) {
        u = x;
    }
    bool has(int i) const {return u & (1<<i);}
    node Mex() const {
        return node(has(1) ^ has(2), has(0), false);
    }
    node MexMex() const {
        return node(false, has(2), has(0) ^ has(1));
    }
    node operator^(const node other) const {
        return node(u ^ other.u);
    }
    void operator^=(const node other) {
        u ^= other.u;
    }
    int get() const {
        return (u >> 1);
    }
};
 
const node full_period(true, true, false);
const node full_period_mex = full_period.Mex();
const node zero_node(false, false, false);
const node zero(true, false, false), one(false, true, false), two(false, false, true);
 
node grundy(ll x, ll k) {
    if(k)
        return equivalent(x, k) < half_period(k)? grundy(x, k-1).Mex() : grundy(x, k-1).MexMex();
    return x&1? one : zero;
}
 
node prefix_grundy(ll r, ll k) {
    node period_effect = (count_period_parity(r, k)? full_period : zero_node);
    r = equivalent(r, k);
    if(k == 0)
        return (r? full_period : zero) ^ period_effect;
    if(r < half_period(k))
        return prefix_grundy(r, k-1).Mex() ^ period_effect;
    return prefix_grundy(r - half_period(k), k-1).MexMex() ^ full_period_mex ^ period_effect;
}
 
inline node grundy(ll l, ll r, ll k) {
    return (l? prefix_grundy(l-1, k) : zero_node) ^ prefix_grundy(r, k);
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        node ans(0);
        for(ll a, b, c, l, r, lp, rp, d, k, i = 0; i < n; i++) {
            cin >> a >> b >> c >> l >> r;
            b -= a, c -= a, l -= a, r -= a, a = 0;
            l -= c, r -= c;
            k = lg2(b & -b), d = b >> k;
            if(l / d == r / d) {
                if((r - l + 1) & 1)
                    ans ^= grundy(l / d, k);
            } else {
                lp = (l+d-1) / d, rp = r / d;
                if(lp < rp) ans ^= grundy(lp, rp-1, k);
                if((lp*d-l)&1) ans ^= grundy(l / d, k);
                if((r-rp*d+1)&1) ans ^= grundy(r / d, k);
            }
        }
        cout << (ans.get()? "Bug" : "Feature") << '\n';
    }
    return 0;
}
