E. No Effect XOR
time limit per test2 seconds
memory limit per test256 megabytes

In the jungle, there is a lake with infinite lily pads on it. The lily pads are numbered with non-negative integers 0,1,2,3,…
. The lily pads with numbers between l
 and r
 inclusive are called suitable, while all other lily pads are not suitable for the frogs to sit on.

Currently, a single frog is sitting on each suitable lily pad.

Ostad is watching the lake and wants to reorder the frogs. To do so, Ostad can pick a positive integer x
 and announce it to the frogs. After hearing the number, the frog sitting on the i
-th lily pad will jump to the (i⊕x)
-th one, where ⊕
 denotes the bitwise XOR operation.

Ostad likes the frogs, and therefore he wants to pick the number x
 in such a way that all frogs stay within the range of suitable lily pads.

Help Ostad by counting how many different numbers x
 Ostad can choose such that no frog jumps outside the suitable segment of the lily pads.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤105
). The description of the test cases follows.

For each test case, there is a single line containing two integers l
 and r
 (1≤l≤r≤1015
).

Output
For each test case, output a single integer denoting the number of valid values for x
.

Example
InputCopy
5
1 2
3 3
2 4
4 7
24189255811072 59373627899903
OutputCopy
1
0
0
3
2199023255551
Note
In the first test case, x=3
 is the only number that Ostad can choose, as 1⊕3=2
 and 2⊕3=1
, which are within the range [1,2]
.

There are no valid choices for Ostad in the second and third test cases. For the second case, since we require x>0
, the only frog that we have will leave the range. Similarly, in the third case, no valid x
 exists to keep the frogs within the desired range.

In the fourth test case, Ostad can choose 1
, 2
, or 3
.

Link to the visualizer


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
inline ll maxPower2Multiple(const ll &a) {return a&-a;}
inline ll prefixAnswer(const ll &a) {return maxPower2Multiple(a);}
inline bool isPerfect(const ll &a) {return a == maxPower2Multiple(a);}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        ll l, r;
        cin >> l >> r;
        ll both = 1LL<<60;
        while((both&l) == (both&r) && both > 0) {
            if(both&l) l -= both, r -= both;
            both >>= 1;
        }
        if(l and isPerfect(l+r+1))
            cout << 2LL*min(prefixAnswer(l), prefixAnswer(r+1LL))-1LL << '\n';
        else if(l)
            cout << min(prefixAnswer(l), prefixAnswer(r+1LL))-1LL << '\n';
        else
            cout << prefixAnswer(r+1LL)-1LL << '\n';
    }
    return 0;
}
