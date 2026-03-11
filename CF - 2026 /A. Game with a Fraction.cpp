#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
void solve(){
	int p, q;
	cin >> p >> q;
	if (p < q && min(p / 2, q / 3) >= q - p){
		cout << "Bob\n";
	}
	else{
		cout << "Alice\n";
	}
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
}A. Game with a Fraction
time limit per test2 seconds
memory limit per test256 megabytes
Alice and Bob have two integers p
 and q
, and they are playing a game with these numbers. The players take turns, with Alice going first. On their turn, a player can do one of two actions:

decrease p
 by one (this action is possible if p>0
);
decrease q
 by one (this action is possible if q>1
).
The game ends when p=0
 and q=1
.

Bob wins if at any point during the game the fraction pq
 is equal to in value the fraction 23
. Otherwise, Alice wins.

Given the initial values of p
 and q
, determine the winner of the game if both players play optimally.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

Each input case consists of a single line containing two integers p
 and q
 (1≤p,q≤1018
).

Output
For each input case, output:

"Alice" if Alice wins;
"Bob" if Bob wins.
Example
InputCopy
6
4 6
10 14
15 15
7 12
7000000000000000 10487275715782582
1000000000000000000 1000000000000000000
OutputCopy
Bob
Bob
Alice
Alice
Bob
Alice
Note
In the first input case, the fraction is already equal to 23
 by value, so Bob wins.

In the second input case, one possible sequence of the game is as follows:

initially p=10,q=14
;
after Alice's turn p=9,q=14
;
after Bob's turn p=9,q=13
;
after Alice's turn p=9,q=12
;
after Bob's turn p=8,q=12
.
Bob wins, as 812
 is equal to 23
. It can be shown that in this example, with optimal play from both players, Bob always wins.

For the third input case, Alice's optimal strategy will be to decrease q
 as long as possible. In this case, the game will end in favor of Alice regardless of Bob's actions.


