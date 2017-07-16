#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<int>> & vecs, vector<bool> & visit, int i)
{
	visit[i] = true;
	cout << i << " ";
	int size = vecs[i].size();
	for (int j = 0; j < size; j++)
	{
		if (vecs[i][j] != 0 && !visit[j])
			dfs(vecs, visit, j);
	}
}

int main()
{
	int nV = 6, nE = 8;
	vector<vector<int>> vecs;
	vector<bool> visit;
	vecs.resize(nV + 1);
	visit.resize(nV + 1);
	for (int i = 1; i <= nV; i++)
	{
		vecs[i].resize(nV + 1);
		fill(vecs[i].begin(), vecs[i].end(), 0);
	}
	fill(visit.begin(), visit.end(), false);
	for (int i = 0; i < nE; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		vecs[s][e] = vecs[e][s] = w;
	}
	dfs(vecs, visit, 1);
	return 0;
}