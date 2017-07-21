#pragma warning(disable:4996)
#include<iostream>
#include<vector>

#define MAX 1e9
/*
5 10
5
1 2 2
1 3 2
1 4 5
1 5 9
2 3 3
2 4 4
2 5 8
3 4 7
3 5 6
4 5 5
답
8
1 3 5

음수 사이클 존재 경우
5 5
5
1 2 2
3 2 -1
4 3 -4
2 4 3
2 5 1
*/
using namespace std;

int main()
{
	vector<vector<int>> graph;
	vector<int> parent;
	vector<int> dist;
	int nV, nE;
	int dst;
	scanf("%d %d", &nV, &nE);
	scanf("%d", &dst);
	graph.resize(nV);
	parent.resize(nV);
	dist.resize(nV);
	fill(parent.begin(), parent.end(), -1);
	fill(dist.begin(), dist.end(), MAX);
	for (int i = 0; i < nV; i++)
	{
		graph[i].resize(nV);
		fill(graph[i].begin(), graph[i].end(), 0);
	}
	for (int i = 0; i < nE; i++)
	{
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		graph[s-1][e-1] = w;
	}
	dist[0] = 0;
	bool mCycle = false;
	for (int i = 0; i < nV; i++)
	{
		for (int j = 0; j < nV; j++)
		{
			for (int k = 0; k < nV; k++)
			{
				if (dist[j] != MAX && dist[k] > dist[j] + graph[j][k])
				{
					dist[k] = dist[j] + graph[j][k];
					parent[k] = j;
					if (i == nV - 1) mCycle = true;
				}
			}
		}
	}
	if (mCycle) printf("minus cycle\n");
	else
	{
		int idx = dst - 1;
		printf("%d\n", dist[idx] == MAX ? -1 : dist[idx]);
		vector<int> res;
		while (parent[idx] != -1)
		{
			res.push_back(idx);
			idx = parent[idx];
		}
		res.push_back(idx);
		for (int i = res.size() - 1; i >= 0; i--)
			printf("%d ", res[i] + 1);
		printf("\n");
	}

	return 0;
}
