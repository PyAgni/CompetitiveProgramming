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
    	ll n,ctr=0;
    	cin>>n;
    	ll arr[n];
    	rep(i,0,n){
    		cin>>arr[i];
    		if(i>0 && arr[i]>arr[i-1]){
    			ctr++;
    		}
    	}
    	
    	if(ctr==n-1 || n==1){
    		cout<<"0\n";
    		continue;
    	}
    	else{


    		ll fir,ctr1=0,ff;
    		rep(i,1,n)
    		{
    			if(arr[i]<arr[i-1])
    				{
    					fir=arr[i];
    					ff=i;
    					// cout<<22;
    					break;
    				}
    		}
    		vec v;
    		rep(i,ff,n){

    			if(arr[i]<fir)
    			{
    				ctr1+=abs(arr[i]-fir);
    				cout<<arr[i];
    			}
    			if(arr[i]>fir){
    				fir=arr[i];
    				ctr1--;
    				v.pb(ctr1);
    				ctr1=0;

    			}
    		}
    		// cout<<ctr-ff
    		ll anss=0;
    		rep(i,0,v.size()){
    			anss+=v[i];
    		}
    		cout<<anss<<"\n";


    	}
    }
	
    
}
