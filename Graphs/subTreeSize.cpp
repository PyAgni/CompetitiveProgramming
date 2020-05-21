int dfs(int node){
	vis[node]++;
	curr_size=1;

	for(int child : ar[node]){
		if(!vis[child]){
			curr_size+=dfs(child);
		}
	}
	subTreeSize[node]=curr_size;
	return curr_size;
}