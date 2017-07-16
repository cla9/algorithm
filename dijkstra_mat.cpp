#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#include<functional>
using namespace std;

int main()
{
	int nV, dst;
	vector< vector<int> > graph;
	scanf("%d %d", &nV, &dst);
	graph.resize(nV + 1);
	for (int i = 0; i < nV; i++)
		graph[i].resize(nV);

	vector<bool> isVisited;
	vector<int> parent;
	vector<int> distance;

	parent.resize(nV);
	distance.resize(nV);
	isVisited.resize(nV);

	fill(distance.begin(), distance.end(), INT_MAX);
	fill(isVisited.begin(), isVisited.end(), false);
	fill(parent.begin(), parent.end(), -1);

	for (int i = 0; i < nV; i++)
		for (int j = 0; j < nV; j++)
			cin >> graph[i][j];

	//dist, idx
	priority_queue< pair<int, int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;
	pq.push(make_pair(0, 0));
	distance[0] = 0;

	while (!pq.empty())
	{
		pair<int, int> p = pq.top();
		pq.pop();

		if (isVisited[p.second]) continue;

		isVisited[p.second] = true;
		for (int i = 0; i < nV; i++)
		{
			int nextd = distance[p.second] + graph[p.second][i];
			if (!isVisited[i] && nextd < distance[i])
			{
				distance[i] = nextd;
				parent[i] = p.second;
				pq.push(make_pair(distance[i], i));
			}
		}
	}
	int idx = dst - 1;
	printf("%d\n", distance[idx]);

	cout << endl;
	vector<int> res;
	while (parent[idx] != -1)
	{
		res.push_back(idx);
		idx = parent[idx];
	}
	res.push_back(0);

	for (int i = res.size() - 1; i >= 0; i--)
		printf("%d ", res[i]+1);
	printf("\n");
	return 0;
}