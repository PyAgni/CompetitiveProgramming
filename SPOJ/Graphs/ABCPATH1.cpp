#include<bits/stdc++.h>
using namespace std;

// int vis[10001][10001];
// int path,maxx;
// int h,w;
// int x[]={1,1,1,0,-1,-1,-1,0};
// int y[]={-1,0,1,1,1,0,-1,-1,-1};
// bool f;
// int dp[51][51];
// bool isValid(int i,int j){
// 	return (i>=0 && i<h && j>=0 && j<w);
// }

// int dfs(int i,int j,vector<vector<int> > grid){
	
// 	// path++;
// 	// cout<<grid[i][j]<<" ";

// 	// if(grid[i][j]==1 && !f)
// 	// 	return maxx;
// 	// f=false;
// 	if(dp[i][j])
// 		return dp[i][j];
// 	int sol=1;
// 	for(int k=0;k<8;k++){
// 		int dx=i+x[k];
// 		int dy=j+y[k];

// 		if(isValid(dx,dy) && (grid[dx][dy]==1+grid[i][j]))
// 			{
// 				// vis[i][j]++;
// 				// path++;
// 				// maxx=max(maxx,path);
// 				// sol++;
// 				sol = max(sol,1+dfs(dx,dy,grid));
// 				// path--;
// 			}
// 	}
// 	dp[i][j]=sol;
// 	return sol;
// }


// int main(){

// 	// int h,w;
// 	// cin>>h>>w;
// 	int c=0;
// 	while(cin>>h>>w){
// 		if(!h && !w) break;
// 		// cout<<h<<w;
// 		memset(dp,0,sizeof dp);
// 		vector<vector<int> > grid(h);

// 		for(int i=0;i<h;i++)
// 		{
// 			string temp;
// 			cin>>temp;
// 			grid[i].resize(w);
// 			for(int j=0;j<w;j++){
// 				grid[i][j]=int(temp[j]-'A'+1);

// 			}
// 		}
// 		int ans=0;
// 		for(int i=0;i<h;i++)
// 			for(int j=0;j<w;j++){
				
// 				if(grid[i][j]==1)
// 					{
// 						memset(vis,0,sizeof(vis));
// 						path=1;
// 						maxx=1;
// 						f=true;
// 						int res =dfs(i,j,grid);
// 						if(res>ans)
// 							ans=res;
// 					}
				
// 			}

// 		cout<<"Case "<<++c<<": "<<ans<<endl;
// 	}
// 	// else
// 	// 	return 0;
// }



#define inf 1000000000
#define MAXN 51

using namespace std;

int H, W;
char mat[MAXN][MAXN];
int sol_mat[MAXN][MAXN];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int dfs(int row, int col, char letter) {
    if (sol_mat[row][col] != -1) return sol_mat[row][col];

    int curr_pos_sol = 1;
    for (int i = 0; i < 8; ++i) {
        if (row+dx[i] < 0 || row+dx[i] >= H || col+dy[i] < 0 || col+dy[i] >= W) continue;

        if (mat[row+dx[i]][col+dy[i]] == letter) {
            curr_pos_sol = max(curr_pos_sol, 1+dfs(row+dx[i], col+dy[i], letter+1));
        }
    }

    sol_mat[row][col] = curr_pos_sol;
    return curr_pos_sol;
}

int main() {
    int _case = 0;
    while (true) {
        scanf("%d%d", &H, &W);
        if (!H && !W) return 0;

        int sol = 0;
        ++_case;
        memset(sol_mat, -1, sizeof sol_mat);
        for (int i = 0; i < H; ++i) {
            scanf("%s", mat[i]);
        }

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (mat[i][j] != 'A') continue;

                sol = max(sol, dfs(i, j, 'A'+1));
            }
        }

        printf("Case %d: %d\n", _case, sol);
    }
    
    return 0;
}