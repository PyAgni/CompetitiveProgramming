bool dfs(int node, int color){
	vis[node]=1;
	col[node]=color;

	for(int child : ar[node]){

		if(!vis[child]){
			if(dfs(child,!color) == false)
				return false;
		}

		else if(col[child]==col[node])
			return false;
	}

	return true;
}