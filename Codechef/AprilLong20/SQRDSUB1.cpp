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
    // fio;

	tin{
		ll n;
		cin>>n;
		ll arr[n],pre[n]={0};
		rep(i,0,n){
			cin>>arr[i];
			if(arr[i]&1){
				if(i>0)
				{
					if(arr[i-1]>0 && arr[i-1]&1)
						pre[i]=pre[i-1]+1;
					else
						pre[i]=1;
				}
				else
					pre[i]=1;
			}
			if(arr[i]%4==0)
				pre[i]=-2;
			if(arr[i]%4==2)
				pre[i]=-1;

		}

		// ll ans = (n*(n+1))/2;
		// // rep(i,0,n)
		// // 	cout<<pre[i]<<" ";
		// // cout<<endl;
		// rep(i,0,n){
		// 	// cout<<pre[i]<<" ";

		// 	if(pre[i]==-1){
		// 		// cout<<"pre- "<<i<<"\n";
		// 		ll temp=-1;
		// 		if(i>0 && pre[i-1]>0)
		// 			temp=pre[i-1];
		// 		ll temp1=-1;
		// 		rep(j,i+1,n){
		// 			if(pre[j]<0){
		// 				i=j-1;
		// 				break;
		// 			}
		// 			else
		// 				temp1=pre[j];
		// 		}
		// 		// cout<<i<<" "<<temp<<" "<<temp1<<endl;
		// 		if(temp1>0 && temp>0)
		// 			ans-=((temp+1)*(temp1+1));
		// 		else if(temp1>0 && temp<0)
		// 			ans-=(temp1+1);
		// 		else if(temp1<0 && temp>0)
		// 			ans-=(temp+1);
		// 		else if(temp1<0 && temp<0)
		// 			ans-=1;

		// 	}
		// }
		// cout<<ans<<"\n";
		ll ctr=0,ctr1=0;
		bool f=false;

		// ll ans = (n*(n+1))/2;

		// ll pre[]

		// rep(i,0,n){
		// 	if(arr[i]&1)
		// 		{
		// 			if(!f)
		// 				ctr++;
		// 			else
		// 				ctr1++;
		// 		}

		// 	if(arr[i]%4 == 2){
		// 		if(!f){
		// 			f=true;
		// 		}
		// 		else{

		// 		}
		// 	}

		// 	if(arr[i]%4==0){
		// 		ctr=0;
		// 		ctr1=0;
		// 		f=false;
		// 		// continue;
		// 	}
		// }

		rep(i,0,n){
			bool f=true;
			for(int j=i;j<n && f==true;j++){
				ll prod=1;
				repp(k,i,j){
					// cout<<arr[k]<<" ";
					if(!(arr[k]%4)){
						// cout<<n-k<<" ";
						ctr+=(n-k);
						f=false;
						break;
					}
					// if(arr[k]%4==2){
					// 	f=false;
					// 	break;
					// }
					prod*=arr[k];
					
				}
				if(prod&1 || !(prod%4)){
					// cout<<"pro- "<<i<<" "<<prod;
					if(f){
						ctr++;
					}
				}
				// cout<<endl;
				}
				
				// 	
				
			}
		

		cout<<ctr<<"\n";

		
	}
    
}
