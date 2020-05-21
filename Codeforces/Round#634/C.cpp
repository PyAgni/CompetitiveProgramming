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



int main(){
    
    tin{
    	ll n;
    	cin>>n;
    	ll arr[n];
    	set<ll> st;
    	ll freq[200001]={0};
    	rep(i,0,n) {
    		cin>>arr[i];
    		st.insert(arr[i]);
    		freq[arr[i]]++;
    	}
    	if(n==1)
    	{
    		cout<<0<<"\n";
    		continue;
    	}
    	if(st.size()==n){
    		cout<<1<<"\n";
    		continue;
    	}
    	if(st.size()==1){
    		cout<<1<<"\n";
    		continue;

    	}	
    	// rep(i,0,10)
    	// 	cout<<freq[i]<<" ";

    	sort(freq,freq+n+1,greater<int>());
    	ll ans = 1;

    	for(int i=0;arr[i]!=0;i++){
    		if(freq[i]>st.size())
			{
				ans=max(ans,ll(st.size()));
				break;
			}
    		else if(freq[i]<st.size()){
    			ans=max(ans,freq[i]);
    			break;
    		}
    		else if(freq[i]==st.size()){
    			ans=max(ans,freq[i]-1);
    			break;
    		}

    	}
    	cout<<ans<<"\n";


    }
	
    
}
