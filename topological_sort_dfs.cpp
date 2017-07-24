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
*/
void dfs(vector<vector<pair<int, int>>> & graph, vector<bool> & isVisited, vector<bool> & finished, stack<int> & st, bool & mCycle, int i)
{
	isVisited[i] = true;
	for (int j = 0; j < graph[i].size(); j++)
	{
		int next = graph[i][j].first;

		if (!isVisited[next])
			dfs(graph, isVisited, finished, st, mCycle, next);
		else if (!finished[next])
			mCycle = true;
	}
	finished[i] = true;
	st.push(i);
}
int main()
{
	vector<vector<pair<int, int>>> graph;
	vector<bool> visited;
	vector<bool> finished;
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
		graph[s].push_back(make_pair(e, 1));
	}

	bool mCycle;
	stack<int> st;
	for (int i = 0; i < nV; i++)
	{
		mCycle = false;
		if (!visited[i])
		{
			dfs(graph, visited, finished, st, mCycle, i);
			if (mCycle)	break;
		}
	}

	if (mCycle) puts("cycle");
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