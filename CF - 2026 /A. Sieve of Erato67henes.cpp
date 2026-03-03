A. Sieve of Erato67henes
time limit per test1 second
memory limit per test256 megabytes
You are given n
 positive integers a1,a2,…,an
.

Please determine if it is possible to select any number of elements in a
, so that their product is 67
.

Note that you may not select zero elements, as the product of zero elements is not defined in this problem.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (1≤n≤5
).

The second line of each test case contains n
 positive integers a1,a2,…,an
 (1≤ai≤67
).

Output
If it is possible to select elements so that their product is 67
, output "YES" on one line. Otherwise, output "NO" on one line.

You can output the answer in any case. For example, the strings "yEs", "yes", and "Yes" will also be recognized as positive responses.

Example
InputCopy
2
5
1 7 6 7 67
5
1 3 5 7 8
OutputCopy
YES
NO
Note
In the first test case, you can select a1
 and a5
 to get a1⋅a5=1⋅67=67
.

In the second test case, it is impossible to select any number of elements so that their product is 67
.



#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool found = false;
        for (int i = 0; i < n; i++) {
            if (a[i] == 67) {
                found = true;
                break;
            }
        }

        if (found)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
```
