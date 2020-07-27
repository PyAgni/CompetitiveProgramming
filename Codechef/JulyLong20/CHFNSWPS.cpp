#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vec;
typedef std::vector<ld> vecld;
typedef std::vector< std::vector<ll> > vecvec;
typedef std::pair<ll, ll> pr;
typedef std::vector< pr > vpr;

typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

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
#define max3(a, b, c)   max(max(a, b), c)
#define min3(a, b, c)   min(min(a, b), c)
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

template <typename Map>
bool compare(Map const &map1, Map const &map2) {
    return map1.size() == map2.size()
        && std::equal(map1.begin(), map1.end(), map2.begin());
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("/home/agni/Documents/CP/input", "r", stdin);
    freopen("/home/agni/Documents/CP/output", "w", stdout);
    #endif

		// for(auto i = map_a.begin(), j = map_b.begin(); 
		// 	i!=map_a.end() || j!=map_b.end();){
		// 	// cout<<1;
		// 	ll total = (i->second)+(j->second);
		// 	cout<<total<<"x";
		// 	++i,++j;
		// 	if(total&1){
		// 		flag=true;
		// 		// cout<<1;
		// 		break;
		// 	}
		// }
    fio;
	tin{
		ll n;
		cin>>n;
		vec a(n),b(n);
		read(a);
		read(b);
		set<ll> st;

		map<ll,ll> map_a,map_b;
		rep(i,0,n){
			map_a[a[i]]++;
			map_b[b[i]]++;
			st.insert(a[i]);
			st.insert(b[i]);
		}

		// if(compare(map_a, map_b)){
		// 	cout<<0<<endl;
		// 	continue;
		// }
		bool flag = false;

		// rep(i,0,10000){
		// 	ll total = map_a[i]+map_b[i];
		// 	if(total&1){
		// 		flag=true;
		// 		break;
		// 	}
		// }

		// if(flag){
		// 	cout<<-1<<endl;
		// 	continue;
		// }

		// sort(all(a));
		// sort(all(b));

		ll minn = LONG_MAX;

		vec temp_a,temp_b;
		for(auto i :st){
			ll ctr1=map_a[i];
			ll ctr2=map_b[i];

			ll total = ctr1+ctr2;
			if((ctr1+ctr2)!= ((total>>1) << 1)){
				flag=true;
				break;
			}

			if(minn>i)
				minn=i;

			if(ctr1<ctr2){
				for(ll j=0; j< ((ctr2-ctr1)>>1); j++){
					temp_b.pb(i);
				}
			}
			else if(ctr1>ctr2){
				for(ll j=0; j< ((ctr1-ctr2)>>1); j++){
					temp_a.pb(i);
				}
			}

		}
		sort(all(temp_a));
		sort(all(temp_b));

		if(temp_a.size()!=temp_b.size())
			flag=true;
		
		if(flag){
			cout<<-1<<endl;
			continue;
		}		

		minn*=2;

		ll sml_a=0,sml_b=0;

		for(auto i: temp_a) {
			if(i>minn)
				break;
			sml_a+=1;
		}

		for(auto i: temp_b) {
			if(i>minn)
				break;
			sml_b+=1;
		}

		ll bgr_a = temp_a.size() - sml_a;
		ll bgr_b = temp_b.size() - sml_b;
		
		ll cost=0;

		if(sml_a <= bgr_b){
			rep(i,0,sml_a){
				cost+=temp_a[i];
			}
			rep(i,0,sml_b){
				cost+=temp_b[i];
			}
			cost += (minn*(bgr_a- sml_b));
		}
		else{
			rep(i,0,bgr_b){
				cost+=temp_a[i];
			}
			rep(i,0,bgr_a){
				cost+=temp_b[i];
			}
			ll i=bgr_b;
			ll j=bgr_a;
			rep(k,0,(sml_b- bgr_a)){
				if(temp_a[i]<temp_b[j]){
					cost+=temp_a[i];
					i++;
				}
				else{
					cost+=temp_b[j];
					j++;
				}
			}
		}

		cout<<cost<<endl;









		// bool cse = 0;

		// if(map_a[minn]==map_b[minn]){
		// 	cse=1;
		// }

		// ll swp = 0;
		// for(int i=0;i<10000;i++){
		// 	swp+=abs(map_a[i]-map_b[i]);
		// }
		// swp/=4;
		// // ll itr=0,ctr=0;
		// if(cse){
		// 	cout<<swp*2<<endl;
		// }
		// else{
		// 	if(map_a[minn]==n || map_b[minn]==n){
		// 		cout<<swp<<endl;
		// 	}
		// 	else
		// 	cout<<swp+1<<endl;
		// }
		

		// cout<<ctr<<endl;

	}
    
}

//Input
/*

*/
