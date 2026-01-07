D2. Removal of a Sequence (Hard Version)
time limit per test2 seconds
memory limit per test512 megabytes
This is the hard version of the problem. The difference between the versions is the constraint on x
; in this version, x≤1012
.

Polycarp has a sequence of all natural numbers from 1
 to 1012
. He decides to modify this sequence by performing the following action x
 times:

Simultaneously remove all numbers at positions y
, 2⋅y
, 3⋅y
, ..., m⋅y≤n
, where n
 is the length of the current sequence.
After that, Polycarp wants to find the k
-th number in the remaining sequence or determine that the length of the resulting sequence is less than k
.

Help Polycarp solve this problem!

Consider an example. Let x=2
, y=3
, k=5
, then:


The numbers crossed out with a red line were removed after the first operation, and the numbers crossed out with a blue line were removed after the second operation. Thus, the number at position k=5
 is the number 10
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤10
). The description of the test cases follows.

The only line of each test case contains three integers x
, y
, k
 (1≤x,y,k≤1012
).

Output
For each test case, output a positive integer that is at the k
-th position in the resulting sequence, or −1
 if the length of the resulting sequence is less than k
.

Example
InputCopy
6
2 3 5
2 5 1
20 2 1000000000000
175 10 28
1000000000 998244353 1999999999
1 1 1
OutputCopy
10
1
-1
2339030304
4672518823
-1

#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int INF = 1'000'000'000'000LL;
 
void solve(){
  int x, y, k;
  cin >> x >> y >> k;
 
  if (y == 1){
    cout << -1 << '\n';
    return;
  }
 
  for (int i = 0; i < x; ){
    int cur = (k - 1) / (y - 1);
    if (cur == 0){
      break;
    }
    int fk = (cur + 1) * (y - 1) + 1;
    int cnt = (fk - k + cur - 1) / cur;
    cnt = min(x - i, cnt);
    k += cnt * cur;
    if (k > INF){
      cout << -1 << '\n';
      return;
    } 
    i += cnt;
  }
 
  cout << k << '\n';
}
 
signed main()
{
#ifdef FELIX
    auto _clock_start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
 
#ifdef FELIX
    cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
        chrono::high_resolution_clock::now()
            - _clock_start).count() << "ms." << endl;
#endif
    return 0;
}
