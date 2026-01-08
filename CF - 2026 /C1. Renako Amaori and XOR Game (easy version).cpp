C1. Renako Amaori and XOR Game (easy version)
time limit per test2 seconds
memory limit per test256 megabytes
Yup. I couldn't do this any longer. No. Freaking. Way.
— Renako Amaori
This is the easy version of the problem. The only difference between the easy and hard versions is that in the easy version, ai,bi≤1
.

Renako is stuck between a rock and a hard place... and by that, of course, I mean Ajisai and Mai! Both of them want to hang out with her, and she just can't decide! So Ajisai and Mai have decided to play the XOR game.

Ajisai and Mai are given arrays a
 and b
 of length n
 (0≤ai,bi≤1
). They will play a game that lasts for n
 turns, where Ajisai moves on odd-numbered turns and Mai moves on even-numbered turns. On the i
-th turn, the player to move may choose to swap ai
 and bi
, or pass.

Note that if a swap occurs, the index that is being swapped must match the turn number. For example, on the first turn, Ajisai may choose to swap a1
 and b1
, or pass. On the second turn, Mai may choose to swap a2
 and b2
, or pass. This continues for n
 turns. Thus, only Ajisai can swap odd indices, and only Mai can swap even indices.

At the end of the game, Ajisai achieves a score of a1⊕a2⊕⋯⊕an
, and Mai achieves a score of b1⊕b2⊕⋯⊕bn
∗
. The player with the higher score wins. If the players have the same score, the game ends in a tie.

Determine the outcome of the game with optimal play. More formally, one player is considered to win with optimal play if there exists a strategy for them such that they always win, regardless of their opponent's choices. The game is considered a tie with optimal play if neither player has such a strategy.

∗
⊕
 denotes the bitwise XOR operation

Input
The first line contains a single integer t
 (1≤t≤104
)  — the number of test cases.

The first line of each test case contains a single integer n
 (1≤n≤2⋅105
).

The second line of each test case contains n
 integers, a1,a2,…,an
 (0≤ai≤1
).

The third line of each test case contains n
 integers, b1,b2,…,bn
 (0≤bi≤1
).

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output on a single line "Ajisai" if Ajisai wins with optimal play, "Mai" if Mai wins with optimal play, or "Tie" if the game ends in a tie with optimal play.

You may output the answer in any case (upper or lower). For example, the strings "mAi", "mai", "MAI", and "maI" will be recognized as "Mai".

Example
InputCopy
6
4
1 0 0 1
1 0 1 1
6
0 1 1 1 1 0
0 0 1 0 1 1
4
0 0 1 0
1 0 1 1
5
1 0 1 1 1
0 1 1 1 0
6
1 1 1 1 1 1
1 1 1 1 1 1
5
0 1 0 0 1
1 0 0 1 1
OutputCopy
Ajisai
Mai
Tie
Ajisai
Tie
Mai
Note
In the first example, one way the game might play out is as follows:

On turn 1, Ajisai chooses to swap a1
 and b1
. Now the arrays are a=[1,0,0,1]
 and b=[1,0,1,1]
.

On turn 2, Mai chooses to pass.

On turn 3, Ajisai chooses to swap a3
 and b3
. Now the arrays are a=[1,0,1,1]
 and b=[1,0,0,1]
.

On turn 4, Mai chooses to swap a4
 and b4
. Now the arrays are a=[1,0,1,1]
 and b=[1,0,0,1]
.

Now, Ajisai's final score is 1⊕0⊕1⊕1=1
 and Mai's final score is 1⊕0⊕0⊕1=0
. Therefore, Ajisai wins the game.

It is not guaranteed that the above description is representative of optimal play.


Codeforces Round 1065 (Div. 3)
Finished
Practice
Add to favourites
→ Virtual participation
Virtual contest is a way to take part in past contest, as close as possible to participation on time. It is supported only ICPC mode for virtual contests. If you've seen these problems, a virtual contest is not for you - solve these problems in the archive. If you just want to solve some problem from a contest, a virtual contest is not for you - solve this problem in the archive. Never use someone else's code, read the tutorials or communicate with other person during a virtual contest.
→ Clone Contest to Mashup
You can clone this contest to a mashup.

→ Submit?
Language:	
GNU G++23 14.2 (64 bit, msys2)
Choose file:	No file chosen
→ Last submissions
Submission	Time	Verdict
356986671	Jan/08/2026 19:12	Happy New Year!
356986323	Jan/08/2026 19:09	Sleigh can't be assembled CE
→ Problem tags
bitmasksgamesgreedy*1100
No tag edit access
→ Contest materials
Announcement (en)
Tutorial (en)

#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n, x = 0, idx;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        x ^= a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
        x ^= b[i];
    }
    if(!x){
        cout << "Tie" << '\n';
        return;
    }
    for(int i=0; i<n; i++)
        if(a[i] ^ b[i])
            idx = i;
    cout << (idx & 1 ? "Mai" : "Ajisai") << '\n';
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
}
