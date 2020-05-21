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
#define MOD 998244353
#define N 100005

vector<vector<pair<int ,int> > > vvp(3,vector<pair<int ,int> >(4)),vvp1(3,vector<pair<int ,int> >(4));
	// &
	vvp[0][0]={9,16};
	vvp[0][1]={1,16};
	vvp[0][2]={3,16};
	vvp[0][3]={3,16};
	// ||
	vvp[1][0]={1,16};
	vvp[1][1]={9,16};
	vvp[1][2]={1,4};
	vvp[1][3]={1,8};
	// ^
	vvp[2][0]={1,4};
	vvp[2][1]={1,4};
	vvp[2][2]={1,4};
	vvp[2][3]={1,4};

	// &
	vvp1[0][0]={1,4};
	vvp1[0][1]={1,4};
	vvp1[0][2]={1,2};
	vvp1[0][3]={1,2};
	// ||
	vvp1[1][0]={1,4};
	vvp1[1][1]={1,2};
	vvp1[1][2]={1,4};
	vvp1[1][3]={1,2};
	// ^
	vvp1[2][0]={1,4};
	vvp1[2][1]={1,4};
	vvp1[2][2]={1,2};
	vvp1[2][3]={1,2};

	map<char, int> mapp;
	mapp['&']=0;
	mapp['|']=1;
	mapp['^']=2;


ll qpow (ll n, ll m) {
	ll ret = 1;
	while (m) {
		if (m & 1) ret = ret * n % MOD;
		n = n * n % MOD;
		m >>= 1;
	}
	return ret;
}
ll inv (ll a) {
	return qpow(a, MOD - 2);
}


ll precedance(char op){
	if(op=='&')
		return 3;
	if(op=='^')
		return 2;
	if(op=='|')
		return 1;
}

// pair<int,int> applyOp(char op){
// 	switch(op){
// 		case '&':{

// 		}
// 	}
// }

void evaluate(string expression){
	int i;

	stack<int> values;
	stack<char> ops;
	stack<vector<pair<int,int> > > prob;

	rep(i,0,expression.length()){
		if(expression[i]=='(')
			ops.push('(');
		else if(expression[i]=='#')
			values.push('#');
		else if(expression[i]==')'){
			if(!prob.empty()){
				// prob = applyOp
			}
		}
	}
}

int main(){
    
	tin{

		string s;
		cin>>s;
		if(s.length()==1){
			rep(i,0,4)
				cout<<inv(4)<<" ";
			cout<<"\n";
			continue;
		}

		

		// cout<<map[s[2]];
		stack<char> opr,exp,val;

		rep(i,0,s.length()){
			if(s[i]=='#'){

			}
			else if(s[i]!=')')
				opr.push(s[i]);
			else{

			}
		}




	}
    
}
