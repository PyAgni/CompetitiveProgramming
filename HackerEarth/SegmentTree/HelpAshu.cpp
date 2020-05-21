#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vec;
typedef std::vector<ld> vecld;
typedef std::vector< std::vector<ll> > vecvec;
typedef std::pair<ll, ll> pr;
typedef std::vector< pr > vpr;

#define tin ll t;cin>>t;while(t--)
#define fio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define sz(a) (ll)((a).size())
#define pb push_back
#define trvect(c,i) for(vector<ll>::iterator i = (c).begin(); i != (c).end(); i++)
#define trset(c,i) for(set<ll>::iterator i = (c).begin(); i != (c).end(); i++)
#define trmap(c,i) for(map<ll,ll>::iterator i = (c).begin(); i != (c).end(); i++)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repp(i,a,b) for(ll i=a;i<=b;i++)
#define present(c,x) ((c).find(x) != (c).end())
#define ff first
#define ss second
#define mp make_pair
#define sq(a) (a)*(a)
#define cube(a) (a)*(a)*(a)
#define cnti(x) (__builtin_popcount(x)) //number of set bits in x
#define mod 1000000007
#define N 100005

int arr[N];
vector<pair<int,int> > tree(4*N,{0,0});

void build(int node,int start,int end){
	if(start==end){
		if(arr[start]&1)
			tree[node].ff=1,tree[node].ss=0;
		else
			tree[node].ss=1,tree[node].ff=0;
	}
	else{
		int mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node].ff=tree[2*node].ff+tree[2*node+1].ff;
		tree[node].ss=tree[2*node].ss+tree[2*node+1].ss;
	}
}

void update(int node,int start,int end,int idx,int val){
	if ((start > end) | (start > idx) | (end < idx)) {
		return;
	}
	if(start==end){
		if(arr[start]&1 && val&1)
			return;
		if(!(arr[start]&1) && !(val&1))
			return;
		else{
			if(val&1){
				tree[node].ff=1;
				tree[node].ss=0;
				// cout<<"update1"<<node<<"\n";
			}
			else{
				tree[node].ss=1;
				tree[node].ff=0;
				// cout<<"update2 "<<node<<" "<<start<<"\n";
			}
			arr[idx]=val;
		}
	}
	else{
		int mid=(start+end)/2;
		if(idx>=start && idx<=mid)
			update(2*node,start,mid,idx,val);
		else
			update(2*node+1,mid+1,end,idx,val);
		tree[node].ff=tree[2*node].ff+tree[2*node+1].ff;
		tree[node].ss=tree[2*node].ss+tree[2*node+1].ss;
	}
}

int query(int node,int start,int end,int l,int r,int q_type){
	if ((start > end) | (start > r) | (end < l)) {
		return 0;
	}
	if(start>=l && end<=r){
		if(q_type==1)
			return tree[node].ss;
		else
			return tree[node].ff;
	}

	int mid=(start+end)/2;
	int p1=query(2*node,start,mid,l,r,q_type);
	int p2=query(2*node+1,mid+1,end,l,r,q_type);

	return(p1+p2);
}

// int query2(int node,int start,int end,int l,int r){
// 	if(l>end || r<start)
// 		return 0;
// 	if(l<=start && r>=end)
// 		return tree[node].ff;

// 	int mid=(start+end)/2;
// 	int p1=query2(2*node,start,mid,l,r);
// 	int p2=query2(2*node+1,mid+1,end,l,r);
// 	return (p1+p2);

// }


int main(){
    
	int n,q,a,x,y;
	cin>>n;
	repp(i,1,n)
		cin>>arr[i];

	build(1,1,n);
// cout<<endl;
// repp(i,1,2*n+5)
// 	cout<<i<<" "<<tree[i].ff<<" "<<tree[i].ss<<endl;
	cin >> q;
	while (q--) {
		cin >> a >> x >> y;
		if (a==0) {
			update(1, 1, n, x, y);
		} else {
			cout << query(1, 1, n, x, y, a) << endl;
		}
	}

	// rep(i,0,20)
	// 	cout<<tree[i].ff<<" "<<tree[i].ss<<endl;
    
}
