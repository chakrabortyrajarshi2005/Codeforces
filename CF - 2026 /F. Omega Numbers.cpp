F. Omega Numbers
time limit per test3 seconds
memory limit per test512 megabytes
For a given number n
, consider the function ω(n)
, which is equal to the number of unique prime numbers in the prime factorization of the number n
.

For example, ω(12)=ω(22⋅3)=2
. And ω(120)=ω(23⋅3⋅5)=3
.

For an array of natural numbers a
 and a natural number k
, we define f(a,k)=∑i<jω(ai⋅aj)k
 for all i<j
.

You are given an array of natural numbers a
 of length n
 and a natural number k
. Calculate f(a,k)
 modulo 998244353
.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains 2 integers n
 and k
 (1≤n≤2⋅105,1≤k≤109
) —the length of the array a
 and the exponent of the operation, respectively.

The second line of each test case contains n
 natural numbers a1,a2,…,an
 (1≤ai≤n
) —the array a
.

It is guaranteed that the sum of n
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output a single line containing an integer — the value of the function f(a,k)
 modulo 998244353
.

Example
InputCopy
3
4 1
3 3 3 3
4 1
1 1 1 1
4 2
1 2 3 4
OutputCopy
6
0
12
Note
Explanation of the first test case example:

For any pair (i,j
), the value ω(x)
 for the product is ω(32)=1
. There are a total of 6
 pairs, and the exponent is 1
. The final answer is 6
.

Explanation of the second test case example:

In any pair of the second test case, the product of the numbers in the pair equals 1
, so the number of primes in it is 0
. Therefore, the final answer is also 0
.

Explanation of the third test case example:

Consider all pairs (i,j
):

(1,2
): the product of the numbers at positions 1
 and 2
 equals a1⋅a2=1⋅2
, ω(2)=1
.
(1,3
): the product of the numbers at positions 1
 and 3
 equals a1⋅a3=1⋅3
, ω(3)=1
.
(1,4
): the product of the numbers at positions 1
 and 4
 equals a1⋅a4=1⋅4
, ω(22)=1
.
(2,3
): the product of the numbers at positions 2
 and 3
 equals a2⋅a3=2⋅3
, ω(2⋅3)=2
.
(2,4
): the product of the numbers at positions 2
 and 4
 equals a2⋅a4=2⋅4
, ω(23)=1
.
(3,4
): the product of the numbers at positions 3
 and 4
 equals a3⋅a4=3⋅4
, ω(3⋅22)=2
.
In the answer, the values of ω(x)
 are raised to the power of 2
, so 12+12+12+22+12+22=12
.#include <bits/stdc++.h>
 
using std::cin;
using std::cout;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using ll = long long;
 
const auto ready = []()
    {
        cin.tie(0);
        std::ios_base::sync_with_stdio(false);
        return true;
    }();
 
ll binpow(ll a, ll p, ll mod)
{
    ll res = 1;
    ll mult = a;
    while (p) {
        if (p & 1) res = res * mult % mod;
        mult = mult * mult % mod;
        p >>= 1;
    }
    return res;
}
 
const ll mod = 998244353;
const int max_a = 2e5 + 10;
const int max_len = 6;
vi fi_div(max_a);
vi num_len(max_a);
 
void precalc() {
    // Here we precompute the number of unique primes in each number, i.e. w(n)
    for (int i = 2; i < max_a; ++i) {
        if (fi_div[i] == 0) {
            for (int j = i; j < max_a; j += i) {
                if (fi_div[j] == 0) fi_div[j] = i;
            }
        }
    }
 
    for (int i = 2; i < max_a; ++i) {
        int x = i;
        int len = 0;
        while (x > 1) {
            ++len;
            int tmp = fi_div[x];
            while (fi_div[x] == tmp) x /= tmp;
        }
        num_len[i] = len;
    }
}
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    vi vec(n);
    for(int i = 0; i < n; ++i) cin >> vec[i];
 
    vvi cnt(n + 1, vi(max_len + 1));
 
    for(int i = 0; i < n; ++i) {
        int x = vec[i];
        cnt[vec[i]][num_len[x]] += 1;
    }
    
    // Here we calcualte auxilary dp - cnt[x][len] - how many numbers with w(n) = len are divisible by x
    for (int i = 1; i < n + 1; ++i) {
        vi dp(max_len + 1);
 
        for (int j = i; j < n + 1; j += i) {
            for(int s =0 ; s < max_len + 1; ++s) dp[s] += cnt[j][s];
        }
        cnt[i] = dp;
    }
    
    vvi dp(n + 1, vi(2 * max_len + 1));
    ll ans = 0LL;
    
    // Here we calcualte dp[g][len]
    for (int g = n; g >= 1; --g) {
        // Account for cases len_a != len_b
        for (int len1 = 0; len1 <= max_len; ++len1) {
            for (int len2 = len1 + 1; len2 <= max_len; ++len2) {
                dp[g][len1 + len2] += 1LL * cnt[g][len1] * cnt[g][len2] % mod;
                dp[g][len1 + len2] %= mod;
            }
        }
        // Account for cases len_a = len_b
        for (int len = 0; len <= max_len; ++len) {
            dp[g][len + len] += 1LL * cnt[g][len] * (cnt[g][len] - 1) / 2 % mod;
            dp[g][len + len] %= mod;
        }
        
        // Subtruct states with where gcd is multiple of current g
        for (int j = 2 * g; j < n + 1; j += g) {
            for(int s = 0; s < 2 * max_len + 1; ++s) {
                dp[g][s] -= dp[j][s];
                dp[g][s] %= mod;
            }
        }
        
        for(int s = 0; s <  2 * max_len + 1; ++s) {
            dp[g][s] %= mod;
            dp[g][s] += mod;
            dp[g][s] %= mod;
        }
    
        // Add k-th powers to the answer
        int gcd_len = num_len[g];
        for (int len = 0; len < 2 * max_len + 1; ++len) {
            int rad = len - gcd_len;
            ans += dp[g][len] % mod * binpow(rad, k, mod) % mod;
            ans %= mod;
        }
 
    }
    cout << ans << "\n";
}
 
int main()
{
    precalc();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
