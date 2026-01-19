D2. Tree Coloring (Hard Version)
time limit per test2 seconds
memory limit per test512 megabytes

This is the Hard version of the problem. The difference between the versions is that in this version, you must find the minimum number of operations and find a way to color the tree using that many operations. You can hack only if you solved all versions of this problem.

You are given a rooted tree∗
 consisting of n
 vertices numbered from 1
 to n
, where the root has index 1
, and each vertex is initially white. Define di
 as the distance from the root to the i
-th vertex. You can perform the following operations any number of times:

Select a subset S
 of white vertices such that no two nodes in S
 are connected by an edge, or have the same distance to node 1
. Formally, S
 should satisfy for all x,y∈S
 and x≠y
, dx≠dy
, and there are no edges between x
 and y
.
Color the vertices in S
 black.
Your job is to find the minimum number of operations required to color the full tree black and find a way to perform the operations.

∗
A tree is a connected graph without cycles. A rooted tree is a tree where one vertex is special and called the root.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (2≤n≤2⋅105
) – the number of vertices in the tree.

The i
-th following n−1
 lines contain two integers ui
 and vi
 (1≤ui,vi≤n
, ui≠vi
) — the ends of the i
-th edge.

It is guaranteed that the given edges form a tree.

It is guaranteed that the sum of n
 over all test cases doesn't exceed 2⋅105
.

Output
For each test case:

Output your number of operations k
 on the first line (1≤k≤n
).
Then, output k
 lines. Each line should begin with an integer m
 representing the size of the operation's set (0≤m≤n
). After that, there should be m
 numbers u1,u2,…,um
 (1≤ui≤n
) representing the m
 nodes you color black in this operation.
You should guarantee that:

Each operation you make is valid.
You don't color the same vertex twice (in the same operation or in different operations).
At the end of all operations, all vertices are colored black.
The number of operations you performed is x
, where x
 is the minimum possible number of operations over all possible solutions.
If there are multiple possible solutions, output any.

Example
InputCopy
10
5
3 1
1 2
5 1
4 1
5
3 2
2 4
2 5
1 2
5
3 4
4 1
5 1
1 2
5
2 5
3 1
2 1
3 4
5
1 3
1 5
4 3
2 4
13
2 1
3 2
4 2
5 4
6 3
7 1
8 5
9 6
10 4
11 7
12 8
13 10
10
5 7
8 1
1 10
2 8
8 4
9 4
6 1
5 3
7 8
10
7 6
3 7
6 9
7 1
9 8
5 1
3 10
9 2
1 4
10
10 6
2 8
4 10
7 5
1 2
7 10
10 9
9 1
7 3
10
6 8
9 7
4 10
5 9
4 2
3 8
6 5
1 5
1 10
OutputCopy
5
1 3 
1 2 
1 5 
1 4 
1 1 
4
2 3 1 
1 4 
1 5 
1 2 
4
1 4 
2 5 3 
1 2 
1 1 
3
2 4 2 
2 5 3 
1 1 
3
2 3 2 
2 5 4 
1 1 
3
5 9 12 10 11 2 
4 8 6 4 1 
4 13 5 3 7 
4
4 2 9 3 10 
3 4 5 6 
2 7 1 
1 8 
4
2 7 9 
3 5 3 2 
4 4 6 10 8 
1 1 
4
4 6 3 8 9 
3 4 5 1 
1 7 
2 10 2 
3
4 7 3 4 5 
3 8 9 10 
3 2 6 1 
Note
In the first test case, d1=1
 and d2=d3=d4=d5=2
. We can show that we must perform at least 5
 operations because there are no two nodes that can be operated on simultaneously.

In the second test case, we can show that the least number of operations required to color the full tree is 4
. The example output shows one way to color it in 4
 operations.


#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> e[300005],v[300005],g[300005];
int n,d[300005],t[300005],id[300005],son[300005],snum[300005],fa[300005];
bool flag[300005];
void dfs(int pos,int fa)
{
	::fa[pos]=fa;
	d[pos]=d[fa]+1;
	t[d[pos]]++;
	g[d[pos]].push_back(pos);
	for(int x:e[pos])
	{
		if(x==fa)
			continue;
		snum[pos]++;
		dfs(x,pos);
	}
}
void test()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		e[i].clear(),g[i].clear(),v[i].clear(),d[i]=t[i]=id[i]=snum[i]=0;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	int mx=0,mt=0;
	for(int i=1;i<=n;i++)
		if(t[i]>=mx)
			mx=t[i],mt=i;
//	for(int i=1;i<=n;i++)
//		cerr<<i<<" "<<fa[i]<<" "<<d[i]<<"\n";
	int ans=mx;
	for(int i=1;i<=mx;i++)
		id[g[mt][i-1]]=i,v[i].push_back(g[mt][i-1]);
	for(int i=mt+1;i<=n;i++)
	{
		vector<int> vfa;
		for(int j:g[i-1])
		{
			son[j]=0;
			if(snum[j])
				flag[id[j]]=1;
		}
		int pos=1;
		for(int j:g[i])
		{
			if(!son[fa[j]])
				son[fa[j]]=j,vfa.push_back(fa[j]);
			else
			{
				while(flag[pos])
					pos++;
				assert(pos<=mx);
				id[j]=pos,v[pos].push_back(j),pos++;
			}
		}
		while(flag[pos])
			pos++;
		assert(pos<=mx);
		int lst=pos;
		for(int x:vfa)
		{
			id[son[x]]=lst;
			v[lst].push_back(son[x]);
			lst=id[x];
		}
		for(int j:g[i-1])
			flag[id[j]]=0;
	}
	for(int i=mt-1;i>=1;i--)
	{
		vector<int> vfa;
		for(int j:g[i])
			son[j]=0;
		for(int j:g[i+1])
		{
			flag[id[j]]=1;
			if(!son[fa[j]])
				son[fa[j]]=j,vfa.push_back(fa[j]);
		}
		assert(!vfa.empty());
		if(vfa.size()==1)
		{
			if(ans==t[i+1])
				ans++,id[vfa[0]]=ans,v[ans].push_back(vfa[0]);
			else
			{
				int pos=1;
				while(flag[pos])
					pos++;
				assert(pos<=ans);
				id[vfa[0]]=pos,v[pos].push_back(vfa[0]);
			}
		}
		else
		{
			for(int i=0;i<vfa.size();i++)
				id[vfa[i]]=id[son[vfa[(i+1)%vfa.size()]]],v[id[vfa[i]]].push_back(vfa[i]);
		}
		for(int j:g[i+1])
			flag[id[j]]=0;
		for(int x:vfa)
			flag[id[x]]=1;
		int pos=1;
		for(int x:g[i])
			if(!son[x])
			{
				while(flag[pos])
					pos++;
				assert(pos<=ans);
				id[x]=pos,v[pos].push_back(x);
				pos++;
			}
		for(int x:vfa)
			flag[id[x]]=0;
	}
	cout<<ans<<"\n";
	for(int i=1;i<=ans;i++)
	{
		cout<<v[i].size()<<" ";
		for(int x:v[i])
			cout<<x<<" ";
		cout<<"\n";
	}
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    	test();
}
