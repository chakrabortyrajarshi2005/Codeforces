G. Grid Path
time limit per test3 seconds
memory limit per test512 megabytes
You are given a grid with n
 rows (numbered from 1
 to n
 from top to bottom) and m
 columns (numbered from 1
 to m
 from left to right). You are controlling a chip that is initially in the cell (1,1)
. In one move, the chip can move left, right, or down (if the current cell is (x,y)
, it can go to (x,y−1)
, (x,y+1)
, or (x+1,y)
). The chip cannot leave the grid.

You can make any number of moves (possibly zero). Let's define the path of a chip as the set of cells it visits at least once. Note that the order of visited cells doesn't matter.

Your task is to calculate the number of possible paths. Since the answer might be large, print it modulo mod
.

Input
The only line contains three integers n
, m
, and mod
 (1≤n≤108
; 1≤m≤150
; 2≤mod≤109
).

Output
Print a single integer — the number of possible paths, taken modulo mod
.

Examples
InputCopy
2 2 100
OutputCopy
7
InputCopy
1 5 777
OutputCopy
5
InputCopy
5 3 998244353
OutputCopy
1695
InputCopy
100000000 150 1000000000
OutputCopy
89058885


Codeforces (c) Copyright 2010-2026 Mike Mirzayanov
The only programming contests Web 2.0 platform
Server time: Mar/27/2026 22:40:49UTC+5.5 (g1).
Desktop version, switch to mobile version.
Privacy Policy | Terms and Conditions
Supported by
TON#include <bits/stdc++.h>
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); ++i)
 
const int K = 301;
 
using mat = vector<vector<int>>;
 
int n, m, mod, k;
 
int add(int x, int y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
 
int mul(int x, int y) {
  return x * 1LL * y % mod;
}
 
unsigned long long aux[K][K];
 
mat mul(mat a, mat b) {
  mat b2(k, vector<int>(k));
  forn(x, k) forn(y, k) b2[x][y] = b[y][x];
  mat c(k, vector<int>(k));
  forn(x, k) forn(y, k) {
    aux[x][y] = 0;
    forn(z, k) {
      aux[x][y] += a[x][z] * 1ll * b2[y][z];
      if((z & 15) == 15)
        aux[x][y] %= mod;
    }
    c[x][y] = aux[x][y] % mod;
  }
  return c;
}
 
mat binpow(mat a, int b) {
  mat c(k, vector<int>(k));
  forn(i, k) c[i][i] = 1;
  while (b) {
    if (b & 1) c = mul(c, a);
    a = mul(a, a);
    b >>= 1;
  }
  return c;
}
 
int main() {
  cin >> n >> m >> mod;
  k = 2 * m + 1;
  mat a(k, vector<int>(k));
  a[k - 1][k - 1] = 1;
  forn(i, m) forn(f, 2) {
    for (int l = f ? 0 : i; l <= i; ++l) {
      for (int r = i; r < m; ++r) {
        a[i * 2 + f][k - 1] = add(a[i * 2 + f][k - 1], 1);
        for (int j = l; j <= r; ++j) {
          a[i * 2 + f][j * 2 + (j == l)] = add(a[i * 2 + f][j * 2 + (j == l)], 1);
        }
      }
    }
  }
  auto res = binpow(a, n);
  cout << res[1][k - 1] << endl;
}
