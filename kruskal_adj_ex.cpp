#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Set
{
private:
	int n;
	int * p;
public:
	Set(int _n) : n(_n){
		p = new int[n];
		fill(p, p + n, -1);
	}
	~Set(){
		delete[] p;
		n = 0;
	}
public:
	int Find(int v){
		if (p[v] < 0) return v;
		p[v] = Find(p[v]);
		return p[v];
	}
	bool Merge(int v1, int v2){
		v1 = Find(v1);
		v2 = Find(v2);
		if (v1 == v2) return false;
		p[v1] += p[v2];
		p[v2] = v1;
		return true;
	}
};

class Edge{
public:
	int s;
	int e;
	int w;
public:
	Edge(int _s = 0, int _e = 0, int _w = 0) : s(_s), e(_e), w(_w){}
	bool operator<(const Edge & e)const { return w < e.w; }
};


int main(){
	int nV, nE;
	scanf("%d %d", &nV, &nE);
	Edge * edge = new Edge[nE];
	Set set(nV + 1);
	for (int i = 0; i < nE; i++){
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		edge[i] = Edge(s, e, w);
	}
	sort(edge, edge + nE);
	int res = 0;
	int numE = 0;
	for (int i = 0; i < nE; i++){
		if (set.Merge(edge[i].s, edge[i].e)){
			res += edge[i].w;
			if (++numE == nV - 1) break;
		}
	}
	printf("%d\n", res);
	delete[] edge;
}