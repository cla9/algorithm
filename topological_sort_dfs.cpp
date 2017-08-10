#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
3 2
1 3
2 3

ans)
1 2 3
2 1 3

4 2
4 2
3 1

ans)
4 2 3 1
4 3 2 1

3 3
1 2
2 3
3 1

ans)
cycle
*/
void dfs(vector <vector<int>> & graph, vector<bool> & visited, vector<bool> & finished, int curr, bool & isCycle, stack<int> & st)
{
	visited[curr] = true;
	for (int next : graph[curr])
	{
		if (!visited[next])
			dfs(graph, visited, finished, next, isCycle, st);
		else if (!finished[next])
			isCycle = true;
	}
	finished[curr] = true;
	st.push(curr);
}
int main()
{
	int nV, nE;
	scanf("%d %d", &nV, &nE);
	vector<vector<int>> graph(nV);
	vector<bool> visited(nV, false);
	vector<bool> finished(nV, false);
	for (int i = 0; i < nE; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		s--; e--;
		graph[s].push_back(e);
	}
	stack<int> st;
	bool isCycle = false;
	for (int i = 0; i < nV; i++)
	{
		if (!visited[i])
		{
			dfs(graph, visited, finished, i, isCycle, st);
			if (isCycle) break;
		}
	}
	if (isCycle) puts("cycle");
	else
	{
		while (!st.empty())
		{
			printf("%d ", st.top() + 1);
			st.pop();
		}
	}
	return 0;
}