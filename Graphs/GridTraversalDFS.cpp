#include<bits/stdc++.h>
using namespace std;

int n,m;
int vis[10001][10001];
// int grid
int x[]={0,1,1,1,0,-1,-1,-1};
int y[]={-1,-1,0,1,1,1,0,-1};


bool isValid(int i,int j){
	return (i>=0 && i<n && j>=0 && j<m);
}

void dfs(int i,int j,int *grid){
	vis[i][j]++;

	int dx,dy;
	cout<<grid[i]<<" "<<grid[j]<<" ";
	for(int k=0;k<8;k++){
		dx=i+x[k];
		dy=j+y[k];

		if(isValid(dx,dy) && !vis[dx][dy])
			{	
				//do something
				dfs(dx,dy,grid);
			};
	}
}

int main(){
	cin>>n>>m;

	int grid[n][m];
	// int **grid;
	// grid = 
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>grid[i][j];

	dfs(0,0,(int *)grid);
}