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
#define endl "\n"
#define deb(x) cerr<< #x << " " << x << endl
#define sz(a) (ll)((a).size())
#define pb emplace_back
#define trvect(c,i) for(vector<ll>::iterator i = (c).begin(); i != (c).end(); i++)
#define trset(c,i) for(set<ll>::iterator i = (c).begin(); i != (c).end(); i++)
#define trmap(c,i) for(map<ll,ll>::iterator i = (c).begin(); i != (c).end(); i++)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repp(i,a,b) for(ll i=a;i<=b;i++)
#define present(c,x) ((c).find(x) != (c).end())
#define all(x) x.begin(), x.end()
#define rall(v) v.rbegin(),v.rend()
#define rsort(v) sort(all(v),greater<int>())
#define mst(x) memset(x, 0, sizeof(x))
#define ff first
#define ss second
#define mp make_pair
#define sq(a) (a)*(a)
#define cube(a) (a)*(a)*(a)
#define cnti(x) (__builtin_popcount(x)) //number of set bits in x
#define N 100005
#define pi 2*acos(0.0)
ll mod = 1e7+7;

// --------------------------- Inputs ---------------------------------------------- //

template<typename... T>
void read(T&... args){
	((cin>>args), ...);
}

template <typename T , typename T0>
void read(pair< T , T0 > &p){
	cin >> p.ff >>p.ss;
}

template <typename T>
void read(vector< T > &oneD){
	for(ll i=0;i<oneD.size();i++){
		read(oneD[i]);
	}
}

template <typename T>
void read(T oneD[] , int n){
	for(ll i=0;i<n;i++){
		read(oneD[i]);
	}
}

// --------------------------- Outputs --------------------------------------------- //

template<typename... T>
void write(T... args){
	((cout<<args<<" "), ...);
	cout<<endl;
}

template <typename T , typename T0>
void write(pair< T , T0 > &p){
	write(p.ff);
	write(p.ss);
	cout << endl;
}

template <typename T>
void write(vector< T > &oneD){
  for(ll i=0;i<oneD.size();i++){
    cout<<oneD[i]<<" ";
  }
  cout<<endl;
}

template <typename T ,typename T0>
void write(vector< pair< T, T0 > > &oneD){
  for(ll i=0;i<oneD.size();i++){
    write(oneD[i].ff,oneD[i].ss);
  }
} 

template <typename T>
void write(T oneD[] ,int n){
	for(ll i=0;i<n;i++){
		cout<<oneD[i]<<" ";
	}
	cout << endl;
}

template <typename T , typename T0>
void write(map< T , T0 > &mpp){
	for(auto it : mpp){
		write(it.ff);
		cout << ": ";
		write(it.ss);
		cout << "\n";
	}
	cout<<endl;
}
// -------------------------------------------------------------------------------- //



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

// ------------------------------------------------------------------------------- //



int main(){
    tin{
    	ll n0,n1,n2;
    	cin>>n0>>n1>>n2;

    	// if(n1==0){
    	// 	if(n0!=0){
    	// 		repp(i,1,n0+1)
    	// 			cout<<"0";
    	// 	}
    	// 	cout<<endl;
    	// 	continue;
    	// }
    	if (n1 == 0) {
			if (n0 != 0) {
				cout << string(n0 + 1, '0') << endl;
			} else {
				cout << string(n2 + 1, '1') << endl;
			}
			continue;
		}

    	else{
    		repp(i,1,n2)
    			cout<<"1";

    		if(n1&1){
    			ll x = (n1+1)/2;
    			repp(i,1,x)
    				cout<<"10";
    			repp(i,1,n0)
    				cout<<"0";
    		}
    		else{
    			ll x = n1/2;
    			repp(i,1,x)
    				cout<<"10";
    			cout<<1;
    			if(n0>0)
    			repp(i,1,n0+1)
    				cout<<"0";
    		}
    		cout<<endl;
    	}
    }
// 	tin{
// 		ll n0,n1,n2;
// 		cin>>n0>>n1>>n2;
// 		if(n2>0)
// 		{
// 			repp(i,1,n2+1)
// 				cout<<"1";
		
// 			if(n1>0){
// 				cout<<"0";
// 				// n1--;
// 				if(n1&1){
// 					ll x = (n1+1)/2;
// 					x--;
// 					repp(i,1,x)
// 						cout<<"10";

// 					if(n0>0){
// 						repp(i,1,n0)
// 							cout<<"0";
// 						// cout<<endl;
// 					}
// 				}
// 				else{
// 					ll x = n1/2;
// 					x--;
// 					repp(i,1,x)
// 						cout<<"10";
// 					// cout<<"1";

// 					if(n0>0){
// 					repp(i,1,n0)
// 						cout<<"0";
// 					// cout<<endl;
// 					}
// 					cout<<"1";
// 				}

// 			}
// 			else{
// 				if(n0>0){
// 					rep(i,1,n0+1)
// 						cout<<"0";
// 					}
// 				// cout<<endl;
// 			}



// 		}

// 		if(n2==0){
// 			if(n1>0){
// 				if(n1&1){
// 					ll x = (n1+1)/2;
// 					// x--;
// 					repp(i,1,x)
// 						cout<<"10";

// 					if(n0>0){
// 						repp(i,1,n0)
// 							cout<<"0";
// 						// cout<<endl;
// 					}
// 				}
// 				else{
// 					ll x = n1/2;
// 					// x--;
// 					repp(i,1,x)
// 						cout<<"10";
// 					cout<<"1";

// 					if(n0>0){
// 					repp(i,0,n0+1)
// 						cout<<"0";
// 					// cout<<endl;
// 					}
// 				}
// 			}
// 			else{
// 				if(n0>0){
// 					repp(i,1,n0+1)
// 						cout<<"0";
// 					// cout<<endl;
// 				}
// 			}

			
// 		}

// cout<<endl;

// 	}
    
}
