#pragma warning(disable:4996)
#include<iostream>
#include<vector>

using namespace std;

int dfs(vector<vector<pair<int, int>>> & graph, vector<bool> & isVisitied, int i)
{
	int res = 1;
	isVisitied[i] = true;
	printf("%d ", i);
	for (int j = 0; j < graph[i].size(); j++)
	{
		pair<int, int> p = graph[i][j];
		if (!isVisitied[p.first])
			res += dfs(graph, isVisitied, p.first);
	}
	return res;
}

int main()
{
	vector< vector<pair<int, int>>> graph;
	vector<bool> isVisited;
	int nV, nE;
	scanf("%d %d", &nV, &nE);
	graph.resize(nV + 1);
	isVisited.resize(nV + 1);
	fill(isVisited.begin(), isVisited.end(), false);
	for (int i = 0; i < nE; i++)
	{
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		graph[s].push_back(make_pair(e, w));
		graph[e].push_back(make_pair(s, w));
	}

	int cnt = 0;
	for (int i = 1; i <= nV; i++)
	{
		if (!isVisited[i])
		{
			int res = dfs(graph, isVisited, i);
			printf("\n%d\n", res);
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}