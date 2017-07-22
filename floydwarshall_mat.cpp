#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#define MAX 1e9
using namespace std;

int main()
{
	vector<vector<int>> graph;
	vector<vector<int>> parent;
	int nV, nE, dst;
	scanf("%d %d", &nV, &nE);
	scanf("%d", &dst);

	graph.resize(nV);
	parent.resize(nV);
	for (int i = 0; i < nV; i++)
	{
		graph[i].resize(nV);
		fill(graph[i].begin(), graph[i].end(), MAX);
		graph[i][i] = 0;

		parent[i].resize(nV);
		fill(parent[i].begin(), parent[i].end(), -1);
	}

	for (int i = 0; i < nE; i++)
	{
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		s--; e--;
		graph[s][e] = w;
		parent[s][e] = s;
	}

	for (int i = 0; i < nV; i++)
	{
		for (int j = 0; j < nV; j++)
		{
			for (int k = 0; k < nV; k++)
			{
				if (graph[i][k] > graph[i][j] + graph[j][k])
				{
					graph[i][k] = graph[i][j] + graph[j][k];
					parent[i][k] = parent[j][k];
				}
			}
		}
	}
	
	bool mCycle = false;
	for (int i = 0; i < nV; i++)
	{
		if (graph[i][i])
		{
			mCycle = true;
			break;
		}
	}

	if (mCycle) printf("minus cycle\n");
	else
	{
		int idx = dst - 1;
		printf("%d\n", graph[0][idx]);
		vector<int> res;
		while (parent[0][idx] != -1)
		{
			res.push_back(idx);
			idx = parent[0][idx];
		}
		res.push_back(idx);
		for (int i = res.size() - 1; i >= 0; i--)
			printf("%d ",res[i]+1);
		printf("\n");
	}
}