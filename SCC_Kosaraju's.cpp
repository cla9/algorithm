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
vector<vector<int>> rgraph;
vector<vector<int>> scc;
vector<bool> visited;
stack<int> st;

void dfs( int curr)
{
	visited[curr] = true;
	for (int next : graph[curr])
		if (!visited[next])
			dfs(next);
	st.push(curr);
}

void calcScc(int curr, int pos)
{
	visited[curr] = true;
	scc[pos].push_back(curr);
	for (int next : rgraph[curr])
		if (!visited[next])
			calcScc(next, pos);
}

int main()
{
	int nV, nE;
	scanf("%d %d", &nV, &nE);
	
	graph.resize(nV);
	rgraph.resize(nV);
	visited.resize(nV);
	fill(visited.begin(), visited.end(), false);
	for (int i = 0; i < nE; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		s--; e--;
		graph[s].push_back(e);
		rgraph[e].push_back(s);
	}

	for (int i = 0; i < nV; i++)
		if (!visited[i])
			dfs(i);
	fill(visited.begin(), visited.end(), false);
	while (!st.empty())
	{
		int top = st.top(); 
		st.pop();
		if (!visited[top])
		{
			scc.push_back(vector<int>());
			calcScc(top, scc.size() - 1);
		}
	}

	for (int i = 0; i < scc.size(); i++)
		sort(scc[i].begin(), scc[i].end());
	sort(scc.begin(), scc.end(), [](const vector<int> & i, const vector<int> & j){ return i[0] < j[0]; } );
	printf("%d\n", scc.size());
	for (vector<int> & i : scc)
	{
		for (int j : i)
			printf("%d ", j + 1);
		puts("-1");
	}
	return 0;
}