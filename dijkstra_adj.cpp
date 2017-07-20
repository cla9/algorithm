#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#include<limits.h>
using namespace std;
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
*/
int main()
{
	
	vector<vector<pair<int, int>>> graph;
	int nV, nE, dst;
	scanf("%d %d", &nV, &nE);
	scanf("%d", &dst);
	graph.resize(nV);
	for (int i = 0; i < nE; i++)
	{
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		s--; e--;
		//다익 스트라는 유향그래프에서 쓰는 것이 좋다.
		graph[s].push_back(make_pair(e, w));
	}
	
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<bool> isVisitied;
	vector<int> dist;
	vector<int> parent;
	dist.resize(nV);
	isVisitied.resize(nV);
	parent.resize(nV);
	fill(isVisitied.begin(), isVisitied.end(), false);
	fill(dist.begin(), dist.end(), INT_MAX);
	fill(parent.begin(), parent.end(), -1);
	dist[0] = 0;

	//dist, idx
	pq.push(make_pair(0,0));

	while (!pq.empty())
	{
		pair<int, int> p = pq.top();
		pq.pop();

		int curr = p.second;
		
		if (isVisitied[curr]) continue;

		isVisitied[curr] = true;
		//인접 리스트 조사
		for (int i = 0; i < graph[curr].size(); i++)
		{
			int next = graph[curr][i].first;
			int nextd = graph[curr][i].second ;

			if (!isVisitied[next] && dist[next] > dist[curr] + nextd)
			{
				dist[next] = dist[curr] + nextd;
				parent[next] = curr;
				pq.push(make_pair(dist[next], next));
			}
		}
	}

	int idx = dst - 1;
	printf("%d\n", dist[idx]);
	vector<int> res;
	while (parent[idx] != -1)
	{
		res.push_back(idx);
		idx = parent[idx];
	}
	res.push_back(idx);

	for (int i = res.size()-1; i >=0; i--)
		printf("%d ", res[i] + 1);
	printf("\n");
	return 0;
}