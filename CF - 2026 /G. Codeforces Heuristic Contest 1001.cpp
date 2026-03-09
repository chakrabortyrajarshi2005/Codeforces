G. Codeforces Heuristic Contest 1001
time limit per test9 seconds
memory limit per test1001 megabytes
There is a graph of n2
 vertices, where vertices are labeled by integer pairs (r,c)
 such that 1≤r,c≤n
. Vertices (r1,c1)
 and (r2,c2)
 are directly connected if and only if (r1−r2)2+(c1−c2)2=13
. This graph is called the Zebra Graph of dimensions n×n
.

Please find a subset of vertices S
 in the Zebra Graph of dimensions n×n
, which satisfies the following condition.

The graph induced∗
 by the subset S
 is isomorphic to a cycle graph of at least ⌊n2e⌋
 vertices†
.
It can be shown that such a subset of vertices exists under the constraints of this problem.

∗
The induced graph of a subset of vertices X
 is a graph that contains all vertices in X
 and all edges whose both endpoints are in X
.

†
Here, e
 is the mathematical constant equal to the limit limn→∞(1+1n)n≈2.71828182
. Note that the value of 1e
 is approximately 0.36787944
.

Input
The first and only line of input contains a single integer n
 (n∈{5,1001}
).

There are only two input files for this problem:

The first input file (the example input) has n=5
;
The second input file has n=1001
.
Hacks are disabled for this problem.

Output
Output n
 lines, each containing a string si
 of length n
 denoting the i
-th row of the graph. If the vertex (r,c)
 is an element of S
, then the c
-th letter of sr
 should be '1'. Otherwise, the c
-th letter of sr
 should be '0'.

If there are multiple solutions, print any of them.

Example
InputCopy
5
OutputCopy
01110
11011
10001
11011
01110
Note
For the example output, the induced graph corresponding to the subset S
 is shown below.


This graph is isomorphic to the cycle graph C16
 consisting of 16
 vertices. As 16≥⌊n2e⌋=9
, the output satisfies the problem's condition.



#include<bits/stdc++.h>
using namespace std;
#define UL unsigned long long
#define L long long
#define LD long double
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define RREP(i, a, b) for(int i = (a); i > (b); --i)
#define SZ(x) ((int)(x).size())
#define COUT cout <<
#define END << "\n";

char o = '1', z = '0';

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  if (n == 5) {
    COUT "01110\n11011\n10001\n11011\n01110" END
    return 0;
  }
  vector<string> res(n, string(n, z));
  bool dir = true;
  int i = -1, j = 13;
  while (i+j <= 1982) {
    while (dir ? (j >= 0 && i < n-7) : (i >= 6 && j < n-11)) {
      if (dir) {
        res[i+1][j] = o;
        res[i+4][j+2] = o;
        i++; j--;
      } else {
        res[i][j+1] = o;
        res[i+2][j+4] = o;
        i--; j++;
      }
    }
    if (dir) {
      res[i+6][j+1] = o;
      i += 4;
      j += 3;
    } else {
      if (j < n-11) {
        res[i+3][j+3] = z;
        res[i-1][j+3] = o;
      } else {
        res[i+1][j+6] = o;
        res[i+4][j+4] = o;
      }
      i++;
      j++;
    }
    dir = !dir;
  }
  res[n-8][n-4] = o;
  j=n-1;
  i=n-10;
  while (i >= 4) {
    res[i][j] = o;
    j = (j == n-1) ? n-3 : n-1;
    i -= 3;
  }
  res[6][n-6] = res[3][n-8] = o;
  j=n-10;
  i=0;
  while (j > 12) {
    res[i][j] = o;
    i = 2-i;
    j -= 3;
  }

  for (string&s : res) COUT s END
}
