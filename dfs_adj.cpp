#include<vector>
#include<iostream>

using namespace std;

void dfs(vector<vector<pair<int, int>>> & vecs, vector<bool> & visit, int i)
{
	visit[i] = true;
	cout << i << " ";
	for (pair<int, int> p : vecs[i])
	{
		if (!visit[p.first])
			dfs(vecs, visit, p.first);
	}
}

int main()
{
	vector< vector < pair<int, int> > > vecs;
	vector<bool> visit;
	int nV = 6, nE = 8;
	vecs.resize(nV+1);
	visit.resize(nV + 1);
	fill(visit.begin(), visit.end(), false);

	for (int i = 0; i < nE; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		vecs[s].push_back(make_pair(e, w));
		vecs[e].push_back(make_pair(s, w));
	}
	dfs(vecs, visit, 1);
	return 0;
}