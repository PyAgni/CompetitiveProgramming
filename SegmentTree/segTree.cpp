#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repp(i,a,b) for(int i=a;i<=b;i++)
int tree[2*N],A[N];
	// int arr[n+1];
void build(int node,int start,int end){
	if(start==end)
		tree[node]=A[start];		// May change for diff questions
	else{
		int mid = (start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node] = tree[2*node]+tree[2*node+1];	// For storing sum; Changed for diff question
	}
}


void update(int node,int start,int end,int idx,int val){
	if(start==end){
		A[idx]+=val;
		tree[node]+=val;
	}
	else{
		int mid = (start+end)/2;
		if(idx>=start && idx<=mid)
			update(2*node,start,mid,idx,val);
		else
			update(2*node+1,mid+1,end,idx,val);

		tree[node]=tree[2*node] + tree[2*node+1];

	}
}

int query(int node,int start,int end,int l,int r){
	if(l>end || r<start)
		return 0;
	if(l<=start && r>=end)
		return tree[node];

	int mid=(start+end)/2;
	int p1=query(2*node,start,mid,l,r);
	int p2=query(2*node+1,mid+1,end,l,r);

	return(p1+p2);
}

int main(){

	int n;
	cin>>n;
	rep(i,0,n) cin>>A[i];

	build(1,0,n-1);

	rep(i,1,3*n)
		cout<<tree[i]<<" ";
		cout<<endl;

	update(1,0,n-1,4,4);

	rep(i,1,3*n)
		cout<<tree[i]<<" ";
		cout<<endl;

	cout<<query(1,0,n-1,0,5)<<endl;
	cout<<query(1,0,n-1,0,3)<<endl;
	cout<<query(1,0,n-1,2,4)<<endl;

}