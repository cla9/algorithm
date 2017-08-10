#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
DFS 스패닝 트리를 이용하여 A번째 정점에서 부모로 가는 간선을 제외하고 나머지 간선에서 아직 방문안한 노드에서 얻어온 discover 번호가 나의 discover 번호보다 클 경우 단절선이 됩니다.
http://jason9319.tistory.com/119
 
7 8
1 4
4 5
5 1
1 6
6 7
2 7
7 3
2 3

2
1 6
6 7
*/
long _findAE(vector<vector<pair<int, int>>> & graph, long curIdx, long par, long order, vector<pair<int, int>> & apList, long * pOrder)
{
	long ret, m;
	pOrder[curIdx] = ret = ++order;
	for (pair<int, int> p : graph[curIdx])
	{
		long nextIdx = p.first;
		if (par == nextIdx)
			continue;
		if (!pOrder[nextIdx])
		{
			m = _findAE(graph, nextIdx, curIdx, order, apList, pOrder);
			ret = min(m, ret);
			if (m > pOrder[curIdx]) 
				apList.push_back(make_pair(min(curIdx, nextIdx), max(curIdx, nextIdx)));
		}
		else
			ret = min(pOrder[nextIdx], ret);
	}
	return ret;
}
void FindAE(vector<vector<pair<int, int>>> & graph, vector<pair<int, int>> & aeList)
{
	long * pOrder = new long[graph.size()];
	fill(pOrder, pOrder + graph.size(), 0);

	for (int i = 1; i < graph.size(); i++)
	if (!pOrder[i])
		_findAE(graph, i, 0, 0, aeList, pOrder);

	delete[] pOrder;
}

int main()
{
	vector<vector<pair<int, int>>> graph;
	int nV, nE;
	vector<pair<int, int>> aeList;
	cin >> nV >> nE;
	graph.resize(nV + 1);
	for (int i = 0; i < nE; i++)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(make_pair(e, 1));
		graph[e].push_back(make_pair(s, 1));
	}
	FindAE(graph, aeList);
	sort(aeList.begin(), aeList.end());
	printf("%d\n", aeList.size());
	for (pair<int, int> p : aeList)
		printf("%d %d\n", p.first, p.second);

	return 0;
}