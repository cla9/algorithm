#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<stack>
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
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<bool> finished;
stack<int> st;
bool isCycle = false;
void dfs(int curr)
{
	visited[curr] = true;
	for (int next : graph[curr])
	{
		if (!visited[next])
			dfs(next);
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
	graph.resize(nV);
	visited.resize(nV);
	finished.resize(nV);
	fill(visited.begin(), visited.end(), false);
	fill(finished.begin(), finished.end(), false);

	for (int i = 0; i < nE; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		s--; e--;
		graph[s].push_back(e);
	}
	for (int i = 0; i < nV; i++)
	if (!visited[i])
		dfs(i);
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