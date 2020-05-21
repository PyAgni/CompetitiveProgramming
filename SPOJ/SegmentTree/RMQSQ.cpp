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

ll qpow (ll n, ll m) {
	ll ret = 1;
	while (m) {
		if (m & 1) ret = ret * n % mod;
		n = n * n % mod;
		m >>= 1;
	}
	return ret;
}
ll inv (ll a) {
	return qpow(a, mod - 2);
}

int tree[4*N],arr[N+1];

void build(int node,int start,int end){
	if(start==end){
		tree[node]=arr[start];
	}

	else{
		int mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node] = min(tree[2*node],tree[2*node+1]);
	}
}


void update(int node,int start,int end,int idx,int val){
	if(start==end){
		arr[idx]=val;
		tree[node]=val;
	}
	else{
		int mid=(start+end)/2;
		if(idx>=start && idx<=mid)
			update(2*node,start,mid,idx,val);
		else
			update(2*node+1,mid+1,end,idx,val);
		tree[node]=min(tree[2*node],tree[2*node+1]);
	}
}

int query(int node,int start,int end,int l,int r){
	if(start>r || l>end)
		return INT_MAX;

	if(l<=start && r>=end)
		return tree[node];

	int mid=(start+end)/2;
	int p1=query(2*node,start,mid,l,r);
	int p2=query(2*node+1,mid+1,end,l,r);
	return min(p1,p2);
	
}

int main(){
    
	int n,q;
	cin>>n;
	repp(i,1,n) cin>>arr[i];
	build(1,1,n);

	// rep(i,1,3*n)
	// 	cout<<i<<" "<<tree[i]<<endl;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<query(1,1,n,a+1,b+1)<<endl;
	}
    
}
