#include<bits/stdc++.h>
using namespace std;

int vis[10001],dist[10001];
vector<int> ar[10001];

bool isPrime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0)
			return false;
	}
	return true;
}

bool isValid(int a,int b){
	int ctr=0;
	while(a>0){
		if(a%10 != b%10)
			ctr++;
		a/=10;
		b/=10;
	}
	if(ctr==1)
		return true;
	else
		return false;
}


void buildGraph(){

	for(int i=1000;i<=9999;i++){
		for(int j=i+1;j<=9999;j++){
			if(isPrime(i) && isValid(i,j) && isPrime(j))
				ar[i].push_back(j),ar[j].push_back(i);
		}
	}

}

void bfs(int node){
	queue<int> q;
	q.push(node);
	vis[node]++;
	dist[node]=0;

	while(!q.empty()){
		int curr=q.front();
		q.pop();

		for(int child : ar[curr]){
			if(!vis[child]){
				vis[child]++;
				dist[child] = dist[curr]+1;
				q.push(child);

			}
		}
	}
}

int main(){

	int t;
	cin>>t;

	buildGraph();

	while(t--){
		int a,b;
		cin>>a>>b;

		for(int i=1000;i<=9999;i++)
			vis[i]=0,dist[i]=-1;

		bfs(a);
		
		// for(int i=1000;i<9000;i++)
		// 	if(isPrime(i))
		// 		cout<<i<<" "<<dist[i]<<"\n";

		if(dist[b]==-1)
			cout<<"Impossible"<<endl;
		else
			cout<<dist[b]<<endl;
	}

}