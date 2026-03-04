C. Test Generator
time limit per test2 seconds
memory limit per test512 megabytes
You are developing a test generator. It takes two integers s
 and m
 as input. You need to construct an array of non-negative integers a=[a1,a2,…,an]
 such that:

∑i=1nai=s
;
for each i
, the condition ai&m=ai
 holds, where &
 denotes the bitwise AND operator.
In other words, in each number ai
, the bits that are set to one can only be in the positions where the bits in the number m
 are also set to one.

Determine whether there exists at least one such array. If it exists, find the minimum possible length n
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

Each test case consists of a single line containing two integers s
 and m
 (1≤s,m≤1018
) — parameters of the generator.

Output
For each test case, print one integer:

if such an array does not exist, print −1
;
otherwise, print the minimum possible value of n
 — the length of the array.
Example
InputCopy
6
13 5
13 3
13 6
1000000007 2776648
99999999999 1
998244353 1557287
OutputCopy
3
5
-1
-1
99999999999
642
Note
Let's analyze some examples:

For s=13,m=5
, the answer is 3
, as there is a suitable array a=[5,4,4]
;
For s=13,m=3
, the answer is 5
, as there is a suitable array a=[3,3,3,3,1]
;
For s=13,m=6
, the answer is −1
, as there is no suitable array.#include<bits/stdc++.h>
#define int long long
using namespace std;
 
bool get(int x, int a, int lim){
	int f = 0;
	for (int i = 59; i >= 0; i--){
		f <<= 1;
		if (((x >> i) & 1) == 1){
			f++;
		} 
		if (((a >> i) & 1) == 1){
			f -= min(lim, f);
		}
	}
	return (f == 0);
}
 
void solve(){
	int x, a;
	cin >> x >> a;
 
	if (!get(x, a, 1ll << 60)){
		cout << -1 << '\n';
		return;
	}
 
	int l = 0, r = (1ll << 60);
	while(l <= r){
		int m = l + (r - l) / 2;
		if (get(x, a, m)){
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}
 
	cout << l << '\n';
}
 
signed main()
{
#ifdef FELIX
	auto _clock_start = chrono::high_resolution_clock::now();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	int tests = 1;
	cin >> tests;
	for (int test = 0; test < tests; test++){
		solve();
	}
#ifdef FELIX
	cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
		chrono::high_resolution_clock::now()
			- _clock_start).count() << "ms." << endl;
#endif
	return 0;
}
