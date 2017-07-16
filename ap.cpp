#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
http://jason9319.tistory.com/119
*/
long _findAP(vector<vector<pair<int, int>>> & graph, long curIdx, long rootIdx, long order, vector<bool> & apList, long * pOrder, long & numChild)
{
	long ret, m;
	pOrder[curIdx] = ret = ++order;
	for (pair<int, int> p : graph[curIdx])
	{
		int j = p.first;
		if (!pOrder[j])
		{
			if (curIdx == rootIdx) numChild++;
			m = _findAP(graph, j, rootIdx, order, apList, pOrder, numChild);
			ret = min(m, ret);
			if (m >= pOrder[curIdx] && curIdx != rootIdx) apList[curIdx] = true;
		}
		else
			ret = min(pOrder[j], ret); 
	}
	return ret;
}
void FindAP(vector<vector<pair<int,int>>> & graph, vector<bool> & apList)
{
	long * pOrder = new long[graph.size()];
	fill(pOrder, pOrder + graph.size(), 0);

	for (int i = 1; i < graph.size(); i++)
	{
		if (!pOrder[i])
		{
			long numChild = 0;
			_findAP(graph, i, i, 0, apList, pOrder, numChild);
			if (numChild > 1)
				apList[i] = true;
		}
	}
	delete[] pOrder;
}

int main()
{
	vector<vector<pair<int, int>>> graph;
	int nV, nE;
	vector<bool> apList;
	cin >> nV >> nE;
	graph.resize(nV + 1);
	apList.resize(nV + 1);
	fill(apList.begin(), apList.end(), false);
	for (int i = 0; i < nE; i++)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(make_pair(e, 1));
		graph[e].push_back(make_pair(s, 1));
	}
	FindAP(graph, apList);
	
	vector<int> res;
	for (int i = 1 ; i < nV + 1; i++)
		if (apList[i])
			res.push_back(i);
	
	cout << res.size() << endl;
	for (int idx : res)
		cout << idx << " ";
	cout << endl;
	return 0;
}