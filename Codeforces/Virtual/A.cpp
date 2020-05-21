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
#define MOD 1e9+7
#define N 100005

int main(){
    
	ll n,x,y;
	cin>>n>>x>>y;
	ll arr[n+1];
	repp(i,1,n) cin>>arr[i];

	// ll min=arr[0];
	// bool e=true,f=false;
	// ll idx,idx1;
	repp(i,1,n){
		bool ff=true;
		// for(ll j=max(i-x,1LL);j<=i+y,j<=n;j++){

		// 		{if(arr[i]>=arr[j]){
		// 					ff=false;
		// 					break;
		// 				}}
		// }
		
		repp(j,1,x)
			if(i-j>0)
				if(arr[i-j]<=arr[i])
					ff=false;

		repp(j,1,y)
			if(i+j<=n)
				if(arr[i+j]<=arr[i])
					ff=false;

		if(ff){
			cout<<i<<endl;
			return 0;
		}


		// if(arr)
		// ll curr=arr[i];
		// rep(j,i,i+y)
		// ll ctr=0;
		// for(int j=i;j<=(i+y),j<=n;j++)
		// 	{
				
		// 		if(arr[j]>arr[i])
		// 			{	
		// 				ctr++;
		// 			}
		// 	}
		// 	if(ctr==y)
		// 		{
		// 			f=true;
		// 			idx=i;}

		// 	ll ctr1=0;
		// 	for(int j=i;j>=(i-x),j>=0;j--){
		// 		if(arr[j]>arr[i]){
		// 			ctr1++;
		// 		}
		// 	}
		// 	if(ctr1==x)
		// 	{
		// 		idx1=i;
		// 		e=true;
		// 	}


		// // if(idx)
		// 	cout<<idx<<" "<<idx1<<endl;
		// 	if((e && f) && idx==idx1)
		// 	{
		// 		cout<<idx;
		// 		return 0;
		// 	}
		// 	else{
		// 		f=false,e=false;
		// 		idx=-1,idx1=-1;
		// 	}

	}

    
}
