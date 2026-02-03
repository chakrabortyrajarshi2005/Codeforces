E. New Year's Gifts
time limit per test2 seconds
memory limit per test512 megabytes
Monocarp has n
 friends and decided to give a New Year's gift to each of them. He has also prepared m
 boxes to place the gifts in; the beauty of the i
-th box is ai
. Every box can contain at most one gift.

Monocarp wants to give a gift worth at least yi
 coins to the i
-th friend. Additionally, he knows that the i
-th friend will be happy if at least one of the following conditions holds:

the gift is in a box with beauty at least xi
;
the gift is worth at least zi
 (zi>yi
).
Your task is to help Monocarp calculate the maximum possible number of friends he can make happy if he has k
 coins. Note that Monocarp must purchase a gift for each friend, and the gift may not necessarily come in a box.

Input
The first line contains a single integer t
 (1≤t≤104
) — the number of test cases.

The first line of each test case contains three integers n
, m
 and k
 (1≤n,m≤2⋅105
; 1≤k≤1015
).

The second line contains m
 integers a1,a2,…,am
 (1≤ai≤m
).

Then n
 lines follow; the i
-th of them contains three integers xi
, yi
 and zi
 (1≤xi≤m
; 1≤yi<zi≤109
).

Additional constraints on the input:

∑i=1nyi≤k
.
the sum of n
 over all test cases doesn't exceed 2⋅105
;
the sum of m
 over all test cases doesn't exceed 2⋅105
;
Output
For each test case, print a single integer — the maximum possible number of friends Monocarp can make happy if he has k
 coins.

Example
InputCopy
3
2 1 6
1
1 2 3
1 2 7
2 2 3
1 1
2 1 3
2 1 5
3 4 11
1 2 2 1
3 2 5
4 4 6
3 1 3
OutputCopy
2
0
2
Note
In the first example, Monocarp can make both friends happy as follows: give the first friend a gift for 3
 coins, and give the second friend a gift for 2
 coins in a box with 1
 beauty.

In the second example, Monocarp cannot make any of his friends happy, because he does not have enough money to buy a gift for zi
 coins for even one of them; also, all the boxes have less beauty than any of the xi
.

In the third example, Monocarp can make two friends (the 2
-nd friend and the 3
-rd friend) happy as follows: give the first friend a gift for 2
 coins, and give the second friend a gift for 6
 coins, and give the third friend a gift for 3
 coins.


#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
  int n, m;
  long long k;
  cin >> n >> m >> k;
  vector<vector<int>> ev(m);
  for (int i = 0; i < m; ++i) {
    int x; cin >> x;
    ev[x - 1].push_back(-1);
  }
  for (int i = 0; i < n; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    ev[x - 1].push_back(z - y);
    k -= y;
  }
  int ans = 0;
  multiset<int> s;
  for (int i = 0; i < m; ++i) {
    reverse(ev[i].begin(), ev[i].end());
    for (int x : ev[i]) {
      if (x == -1) {
        if (!s.empty()) {
          s.erase(--s.end());
          ++ans;
        }
      } else {
        s.insert(x);
      }
    }
  }
  while (!s.empty() && *s.begin() <= k) {
    k -= *s.begin();
    s.erase(s.begin());
    ++ans;
  }
  cout << ans << '\n';
}
 
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
    
}
