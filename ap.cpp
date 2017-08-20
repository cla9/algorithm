#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>
/*
7 7
1 4
4 5
5 1
1 6
6 7
2 7
7 3

´ä
3
1 6 7

*/
using namespace std;

vector<vector<int>> graph;
vector<int> order;
vector<bool> apList;
int num;

int dfs(int curr, bool isRoot, int & num_of_child)
{
	int ret, m;
	ret = order[curr] = ++num;
	for (int next : graph[curr])
	{
		if (!order[next])
		{
			if (isRoot) num_of_child++;
			m = dfs(next, false, num_of_child);
			ret = min(ret, m);
			if (m >= order[curr] && !isRoot) apList[curr] = true;
		}
		else
			ret = min(ret, order[next]);
	}
	return ret;
}

int main()
{
	int nV, nE;
	scanf("%d %d", &nV, &nE);
	graph.resize(nV);
	order.resize(nV);
	apList.resize(nV);
	fill(apList.begin(), apList.end(), false);
	fill(order.begin(), order.end(), 0);
	for (int i = 0; i < nE; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		s--; e--;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	int num_of_child = 0;
	for (int i = 0; i < nV; i++)
	{
		if (!order[i])
		{
			num_of_child = 0;
			dfs(i, true, num_of_child);
			if (num_of_child > 1) apList[i] = true;
		}
	}
	vector<int> res;
	for (int i = 0; i < nV; i++)
	if (apList[i])
		res.push_back(i);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d ", res[i] + 1);
	puts("");
	return 0;
}