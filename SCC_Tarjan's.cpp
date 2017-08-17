#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
/*
7 9
1 4
4 5
5 1
1 6
6 7
2 7
7 3
3 7
7 2

ans)
3
1 4 5 -1
2 3 7 -1
6 -1
*/
using namespace std;
vector<vector<int>> graph;
vector<vector<int>> res;
vector<int> order;
vector<int> scc;
stack<int> st;
int num;

int dfs(int curr)
{
	int ret;
	ret = order[curr] = ++num;
	st.push(curr);
	for (int next : graph[curr])
	{
		if (!order[next])	 ret = min(ret, dfs(next));
		else if (!scc[next]) ret = min(ret, order[next]);
	}
	if (ret == order[curr])
	{
		res.push_back(vector<int>());
		int sccNum = res.size() - 1;
		int top = -1;
		while (top != curr)
		{
			top = st.top();
			st.pop();
			scc[top] = sccNum;
			res[sccNum].push_back(top);
		}
		sort(res[sccNum].begin(), res[sccNum].end());
	}
	return ret;
}

int main()
{
	int nV, nE;
	scanf("%d %d", &nV, &nE);
	graph.resize(nV);
	order.resize(nV);
	scc.resize(nV);
	fill(order.begin(), order.end(), 0);
	fill(scc.begin(), scc.end(), 0);
	for (int i = 0; i < nE; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		s--; e--;
		graph[s].push_back(e);
	}
	for (int i = 0; i < nV; i++)
		if (!order[i])
			dfs(i);
	
	sort(res.begin(), res.end(), [](const vector<int> & i, const vector<int> & j){return i[0] < j[0]; });
	printf("%d\n", res.size());
	for (vector<int> & i : res)
	{
		for (int j : i)
			printf("%d ", j + 1);
		puts("-1");
	}
	return 0;
}