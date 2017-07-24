#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

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
long findCutVex(vector<vector<pair<int, int>>> & graph, vector<bool> & apList, int curIdx, bool isRoot, int order, long * pOrder, int & num_of_child)
{
	long ret, m;
	pOrder[curIdx] = ret = ++order;
	for (int i = 0; i < graph[curIdx].size(); i++)
	{
		int nextIdx = graph[curIdx][i].first;
		if (!pOrder[nextIdx])
		{
			if (isRoot) num_of_child++;
			m = findCutVex(graph, apList, nextIdx, false, order, pOrder, num_of_child);
			ret = min(m, ret);
			if (m >= pOrder[curIdx] && !isRoot) apList[curIdx] = true;
		}
		else
			ret = min(ret, pOrder[nextIdx]);
	}
	return ret;
}
void FindCutVex(vector<vector<pair<int, int>>> & graph, vector<bool> & apList)
{
	long * pOrder = new long[graph.size()];
	fill(pOrder, pOrder + graph.size(), 0);
	for (int i = 1; i < graph.size(); i++)
	{
		if (!pOrder[i])
		{
			int num_of_child = 0;
			findCutVex(graph, apList, i, true, 0, pOrder, num_of_child);
			if (num_of_child > 1)
				apList[i] = true;
		}
	}
	delete[] pOrder;
}
int main()
{
	vector<vector<pair<int, int>>> graph;
	vector<bool> apList;
	int nV, nE;
	scanf("%d %d", &nV, &nE);
	graph.resize(nV + 1);
	apList.resize(nV + 1);
	fill(apList.begin(), apList.end(), false);
	for (int i = 0; i < nE; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		graph[s].push_back(make_pair(e, 1));
		graph[e].push_back(make_pair(s, 1));
	}
	FindCutVex(graph, apList);
	vector<int> res;
	for (int i = 0; i < apList.size(); i++)
	if (apList[i])
		res.push_back(i);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d ", res[i]);
	printf("\n");
	return 0;
}