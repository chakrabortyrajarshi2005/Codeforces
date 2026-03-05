D. Two Arrays
time limit per test3 seconds
memory limit per test512 megabytes
The median of the sequence [s1,s2,…,sk]
 is defined as the element that appears at position ⌊k+12⌋
 when the sequence is sorted in non-decreasing order. For example, the median of the sequence [4,5,6,1,2,2]
 is 2
; the median of the sequence [3,6,3,4,5]
 is 4
.

You are given two arrays [a1,a2,…,an]
 and [b1,b2,…,bm]
, sorted in non-decreasing order. Both arrays have odd lengths.

In one operation, you can do the following:

choose one of the arrays and mark an odd number of elements in it;
calculate x
 — the median of the marked elements;
remove all marked elements;
insert x
 into any position of the array on which the operation was performed.
Your task is to determine whether it is possible to make the arrays equal.

Input
The first line contains one integer t
 (1≤t≤104
) — the number of test cases.

Each test case consists of three lines:

the first line contains two integers n
 and m
 (1≤n,m≤3⋅105
);
the second line contains n
 integers a1,a2,…,an
 (1≤a1≤a2≤⋯≤an≤109
);
the third line contains m
 integers b1,b2,…,bm
 (1≤b1≤b2≤⋯≤bm≤109
).
Additional constraints on the input:

the sum of (n+m)
 across all test cases does not exceed 3⋅105
;
in every test case, nmod2=1
 and mmod2=1
.
Output
For each test case, output YES if it is possible to make the arrays equal, or NO if it is not possible.

Example
InputCopy
3
5 3
1 2 3 4 5
1 3 7
3 5
11 17 19
19 20 26 29 37
1 7
11
1 2 7 9 11 15 17
OutputCopy
YES
NO
YES
Note
In the first example, the arrays can be made equal by applying the following sequence of operations:

for the array a=[1,2,3,4,5]
, mark the 2
-nd, 4
-th, and 5
-th elements. Their median is 4
. We insert it at the end of the array, resulting in a=[1,3,4]
;
for the array b=[1,3,7]
, mark all elements. Their median is 3
. We get the array b=[3]
;
for the array a=[1,3,4]
, mark all elements. Their median is 3
. We get the array a=[3]
;
now the arrays a
 and b
 are equal.

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Helper function to read a line and parse integers into a vector
vector<int> readInts() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> result;
    int num;
    while (iss >> num) {
        result.push_back(num);
    }
    return result;
}

void solve() {
    string line;
    // Read the first line (st.nextToken() calls)
    getline(cin, line); 
    
    // Read arrays a and b
    vector<int> a = readInts();
    vector<int> b = readInts();

    // Trimmed ranges: subList(1, size - 1) means removing first and last elements
    // In C++, we can use unordered_set to find common elements efficiently
    unordered_set<int> aSet;
    if (a.size() > 1) {
        for (size_t i = 1; i < a.size() - 1; ++i) aSet.insert(a[i]);
    } else {
        for (int x : a) aSet.insert(x);
    }

    bool ok = false;
    if (b.size() > 1) {
        for (size_t i = 1; i < b.size() - 1; ++i) {
            if (aSet.count(b[i])) {
                ok = true;
                break;
            }
        }
    } else {
        for (int x : b) {
            if (aSet.count(x)) {
                ok = true;
                break;
            }
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}

int main() {
    int t;
    if (!(cin >> t)) return 0;
    string dummy;
    getline(cin, dummy); // Consume the newline after reading t

    while (t--) {
        solve();
    }
    return 0;
}
