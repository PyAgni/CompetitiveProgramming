#include<bits/stdc++.h>
using namespace std;

int vis[10001][10001];
int path,maxx;
int h,w;
int x[]={1,1,1,0,-1,-1,-1,0};
int y[]={-1,0,1,1,1,0,-1,-1,-1};
bool f;
int dp[51][51];
bool isValid(int i,int j){
	return (i>=0 && i<h && j>=0 && j<w);
}

int dfs(int i,int j,vector<vector<int> > grid){
	
	// path++;
	// cout<<grid[i][j]<<" ";

	// if(grid[i][j]==1 && !f)
	// 	return maxx;
	// f=false;
	if(dp[i][j])
		return dp[i][j];
	// 
	vis[i][j]++;
	for(int k=0;k<8;k++){
		int dx=i+x[k];
		int dy=j+y[k];

		if(isValid(dx,dy) && !vis[dx][dy] && (grid[dx][dy]==1+grid[i][j]))
			{
				
				path++;
				maxx=max(maxx,path);
				dfs(dx,dy,grid);
				path--;
			}
	}
	dp[i][j]=maxx;
	return maxx;
}


int main(){

	// int h,w;
	// cin>>h>>w;
	int c=0;
	while(cin>>h>>w){
		if(!h && !w) break;
		// cout<<h<<w;
		memset(dp,0,sizeof dp);
		vector<vector<int> > grid(h);

		for(int i=0;i<h;i++)
		{
			string temp;
			cin>>temp;
			grid[i].resize(w);
			for(int j=0;j<w;j++){
				grid[i][j]=int(temp[j]-'A'+1);

			}
		}
		int ans=0;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++){
				
				if(grid[i][j]==1 && !vis[i][j])
					{
						path=1;
						maxx=1;
						f=true;
						vis[i][j]++;
						ans =max(ans,dfs(i,j,grid));
						// if(res>ans)
						// 	ans=res;
					}
				
			}

		cout<<"Case "<<++c<<": "<<ans<<endl;
	}
	// else
	// 	return 0;
}