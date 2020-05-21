#include <bits/stdc++.h>
#define pi acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int>vc;
vector<vc>graph;
int xr[]= {-1,-1,-1,0,0,1,1,1};
int yc[]= {-1,0,1,-1,1,-1,0,1};

char ss[51][51];
bool visit[51][51];
int r,c,cnt,Max;
bool flag;

int dfs(int row,int col)
{
    if(ss[row][col]=='A'&&flag==false) return Max;
    flag=false;
    for(int i=0; i<8; i++)
    {
        int x=row+xr[i];
        int y=col+yc[i];
        if(x>=0&&x<r&&y>=0&&y<c&&visit[x][y]==0&&ss[x][y]==(ss[row]

[col]+1))
        {
            // cout<<x<<y<<endl;
            visit[x][y]=1;
            cnt++;
            Max=max(Max,cnt);
            //  cout<<Max<<endl;
            dfs(x,y);
            cnt--;
          //  visit[x][y]=0;
            //  return Max;
        }

    }
    return Max;


}


int main()
{
    //   freopen("inp.txt","r",stdin);
    int cas=0;
    while(~scanf("%d %d",&r,&c))
    {
        if(!r&&!c) break;
        for(int i=0; i<r; i++) cin>>ss[i];
        int res=0;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(ss[i][j]=='A')
                {
                    memset(visit,0,sizeof(visit));
                    cnt=1;
                    Max=1;
                    flag=true;
                    int v=  dfs(i,j);
                    //  cout<<v<<endl;
                    res=max( res, v);
                }
            }
        }
        printf("Case %d: %d\n",++cas,res);
    }

    return 0;
}