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
    
    tin{
    	ll n;
    	cin>>n;
    	ll arr[n];
    	rep(i,0,n){
    		cin>>arr[i];
    	}
    	sort(arr,arr+n);

    	if(n&1){
    		cout<<arr[n/2]<<" ";
    	}
    	else{
    		cout<<arr[n/2-1]<<" "<<arr[n/2]<<" ";
    	}
    	ll itr = n/2 +1;
    	for(int i=itr;i<n;i++){
    		cout<<arr[n-i-1]<<" "<<arr[i]<<" ";
    	}
    	cout<<"\n";
    }
	
    
}

