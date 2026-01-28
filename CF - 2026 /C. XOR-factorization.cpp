C. XOR-factorization
time limit per test2 seconds
memory limit per test256 megabytes

Ostad thinks that the usual way of factoring numbers is too mathematical, so he invented a new notion called XOR-factorization, which is more computer-science-like. For a given integer n
, a sequence of integers a1,a2,…,ak
 with 0≤ai≤n
 for all i
 is called a XOR-factorization of n
 if and only if
a1⊕a2⊕⋯⊕ak=n,
where ⊕
 denotes the bitwise XOR operation.

You are given integers n
 and k
. Find a XOR-factorization a1,a2,…,ak
 of n
 that maximizes the sum a1+a2+⋯+ak
.

It can be proven that under the problem conditions, a XOR-factorization always exists.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

Each of the next t
 lines contains two integers n
 and k
 (1≤n≤109
, 1≤k≤105
).

It is guaranteed that the sum of k
 over all test cases does not exceed 105
.

Output
For each test case, output k
 integers a1,a2,…,ak
 such that 0≤ai≤n
.

We can show that an answer always exists. If there are multiple valid answers, you may print any of them in any order.

Example
InputCopy
4
5 4
4 3
8 2
1 1
OutputCopy
1 4 5 5
4 4 4
0 8
1
Note
In the first test case, we can factor 5
 as 1⊕4⊕5⊕5
 with a sum of 15
, and it can be shown that no other XOR-factorization has a higher sum.

In the second test case, we can factor 4
 as 4⊕4⊕4
 with a sum of 12
, which is trivially the maximum possible.



#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int a[k]{}, p = 0;
        if(k&1)
            for(int i = 0; i < k; i++)
                a[i] = n;
        else {
            for(int i = 30; i >= 0; i--) {
                if(n >> i & 1) {
                    for(int j = 0; j < k; j++)
                        if(j != min(p, k-1))
                            a[j] += (1 << i);
                    if(p < k)
                        p++;
                } else
                    for(int j = 0; j < p/2*2; j++)
                        a[j] += (1 << i);
            }
        }
        for(int i = 0; i < k; i++)
            cout << a[i] << (i+1 == k? '\n':' ');
    }
    return 0;
}
