E. Blackslex and Girls
time limit per test2 seconds
memory limit per test256 megabytes
After failing to pick up a girl using De Bruijn sequence of fixed-length bitstrings, Blackslex has turned his attention towards politics.

Due to his high charisma, he is now in charge of drawing borders for the n
 voting districts of his country. In Blackslex's country, there are x
 voters for party A and y
 voters for party B. Using his amazing drawing skills, he can allocate voters from any party into any district of his choice.

His history with bitstrings has led him to wonder if he can allocate voters such that the winner of each district follows a certain bitstring pattern. To avoid suspicion, he must also allocate at least pi
 voters into each district. Tell him if it is possible!

Formally, you are given a binary string s
 of length n
, an array p
 of length n
, and two integers x
 and y
.

You want to determine whether there exist two arrays of nonnegative integers a
 and b
 of length n
 that satisfy the following conditions:

a1+a2+⋯+an=x
b1+b2+⋯+bn=y
For every 1≤i≤n
, ai+bi≥pi
For every 1≤i≤n
:
If si=0
 then ai>bi
If si=1
 then bi>ai
Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains three integers n
, x
, and y
 (1≤n≤2⋅105
, 1≤x,y≤109
).

The second line contains a binary string s
 of length n
.

The third line contains n
 integers p1,p2,…,pn
 (1≤pi≤109
).

The sum of n
 across all test cases does not exceed 2⋅105
.

Output
For each test case, print (case-insensitive) YES if there exist arrays a,b
 satisfying all conditions, or NO otherwise.

Example
InputCopy
6
3 5 5
010
2 4 3
4 2 3
0001
1 1 1 1
2 4 2
00
3 3
4 23 20
1111
2 2 2 2
1 25 26
0
51
2 4 2
00
3 4
OutputCopy
YES
NO
YES
NO
NO
NO
Note
In the first test case, one of the possible distributions of voters is: a=[2,0,3]
 and b=[0,4,1]
.

In the third test case, one of the possible distributions of voters is: a=[2,2]
 and b=[1,1]
.

For the other test cases, it can be shown that there are no distributions of voters that satisfy the conditions.#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
void test_case_run() {
    int n;
    ll x, y;
    cin >> n >> x >> y;
    
    string s;
    cin >> s;
    s = '.'+s;
    
    ll p[n+1];
    for (int i = 1; i <= n; i++) cin >> p[i];
    
    if (accumulate(p+1, p+n+1, 0LL) > x+y) {
        cout << "NO\n";
        return;
    }
    
    if (s == "." + string(n, '0') || s == "." + string(n, '1')) {
        if (s == "." + string(n, '1')) {
            swap(x, y);
        }
        
        ll x_need = 0;
        for (int i = 1; i <= n; i++) {
            x_need += p[i]/2 + 1;
        }
        
        if (x < x_need || x < y+n) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
        
        return;
    }
    
    ll x_need = 0, y_need = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            x_need += p[i]/2 + 1;
        } else {
            y_need += p[i]/2 + 1;
        }
    }
    if (x >= x_need && y >= y_need) cout << "YES\n";
    else cout << "NO\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) test_case_run();
    
    return 0;
}
