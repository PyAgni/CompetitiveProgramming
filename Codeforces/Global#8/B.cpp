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
int count(string a, string b) 
{ 
    int m = a.length(); 
    int n = b.length(); 
  
    int dp[m + 1][n + 1] = { { 0 } };   
    for (int i = 0; i <= n; ++i) 
        dp[0][i] = 0;   
    for (int i = 0; i <= m; ++i) 
        dp[i][0] = 1;   
    for (int i = 1; i <= m; i++) 
    { 
        for (int j = 1; j <= n; j++) 
        { 
            if (a[i - 1] == b[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1] +  
                               dp[i - 1][j]; 
                  
            else
                dp[i][j] = dp[i - 1][j]; 
        } 
    } 
  
    return dp[m][n]; 
} 
  


int main(){
    
    // #ifndef ONLINE_JUDGE
    // freopen("/home/agni/Documents/CP/input", "r", stdin);
    // freopen("/home/agni/Documents/CP/output", "w", stdout);
    // #endif

    ll k;
    cin>>k;
    string s="codeforces";
    string s1="codeforces";
    // rep(i,0,200)
    // 	s1+=s;
    // cout<<s1;

    // cout<<count(s,s1);
    ll ctr,j=0;
    ll n = 100000;
    for(int i=0;i<10000;i++){
    	ctr = count(s,s1);
    	if(ctr<k){
    		s+=s1;
    		j++;
    	}
    	else
    		break;
    }
    // cout<<s;
    if(ctr==k){
    	cout<<s;
    	return 0;
    }

    string str = s.substr(0,(j*10));
    // cout<<str<<endl;
    for(int i=9;i>=0;i--){
    	string temp = s1.substr(i);

    	if(count(str+temp,s1)>=k){
    		cout<<str+temp;
    		break;
    	}
    }
    cout<<12;

	
    
}

//Input
/*

*/
