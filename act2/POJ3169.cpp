#include <cstdio>
#include <iostream>

using namespace std;

const int INF = 999999;
const int MAX_ML = 10000;
const int MAX_MD = 10000;
const int MAX_N = 1000;

int N, ML, MD;

int AL[MAX_ML] = {1,2}, BL[MAX_ML]= {3,4}, DL[MAX_ML]= {10,20};
int AD[MAX_MD] = {2}, BD[MAX_MD] = {3}, DD[MAX_MD] = {3};

int d[MAX_N];
bool updated;

void update(int& x, int y)
{
  if (x > y){
	x = y;
	updated = true;
  }
}

void bellmanford()
{
  for(int k = 0;k <= N;k++){
	updated = false;
	for(int i = 0; i + 1 < N; i++){
	  if(d[i + 1] < INF) update(d[i], d[i + 1]);
	}
	for(int i = 0; i < ML; i++){
	  if(d[AL[i] - 1] < INF) update(d[BL[i] - 1], d[AL[i] - 1] + DL[i]);
	}
	for(int i = 0; i < MD; i++){
	  if(d[BD[i] - 1] < INF) update(d[AD[i] - 1], d[BD[i] - 1] - DD[i]);
	}
  }
}

void solve()
{
  fill(d, d + N, 0);
  bellmanford();
  if(updated){
	printf("-1\n");
	return;
  }

  fill(d, d + N, INF);
  d[0] = 0;
  bellmanford();
  int res = d[N - 1];
  if(res == INF) res = -2;
  printf("%d\n", res);
}

int main()
{
  N = 4;
  ML = 2;
  MD = 1;

  solve();
}
