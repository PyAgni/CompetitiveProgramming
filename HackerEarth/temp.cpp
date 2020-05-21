

    #include<bits/stdc++.h>
    #define siz 100005
    using namespace std;
    vector<int>v[siz];
    bool vis[siz];
    int n,num[siz],parent[siz],low[siz];
    stack<int>st;
    set<pair<int,int> >ans;
    set<pair<int,int> >::iterator it;
    void dfs(int u)
    {
    	static int time=1;
    	int children=0;
    	vis[u]=1;
    	num[u]=low[u]=time++;
    	for(int i=0;i<v[u].size();i++)
    	{
    		int curr=v[u][i];
    		if(!vis[curr])
    		{
    			children++;
    			parent[curr]=u;
    			dfs(curr);
    			low[u]=min(low[u],low[curr]);
    			if(low[curr]>num[u]){ans.insert(make_pair(u,curr));ans.insert(make_pair(curr,u));}
    		}
    		else if(curr!=parent[u])
    			low[u]=min(low[u],num[curr]);
    	}
    }
    int main()
    {
    	int n,m,q;
    	scanf("%d%d",&n,&m);
    	int i,a[siz],b[siz];
    	for(i=0;i<m;i++)
    	{
    		scanf("%d%d",&a[i],&b[i]);
    		v[a[i]].push_back(b[i]);
    		v[b[i]].push_back(a[i]);
    	}
    	for(i=1;i<=n;i++)
    		if(!vis[i])
    			dfs(i);
    	scanf("%d",&q);
    	while(q--)
    	{
    		int x;
    		scanf("%d",&x);x--;
    		if(ans.find(make_pair(a[x],b[x]))!=ans.end())printf("Unhappy\n");
    		else printf("Happy\n");
    	}
    	return 0;
    }

