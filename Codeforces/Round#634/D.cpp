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
		vector<string> ans;
		rep(i,0,9){
			string s;
			cin>>s;

			if(i==0)	s[0]+= s[0]!='9'?1:-1;
			if(i==1)	s[4]+= s[4]!='9'?1:-1;
			if(i==2)	s[8]+= s[8]!='9'?1:-1;			
			if(i==3)	s[1]+= s[1]!='9'?1:-1;
			if(i==4)	s[6]+= s[6]!='9'?1:-1;
			if(i==5)	s[5]+= s[5]!='9'?1:-1;			
			if(i==6)	s[2]+= s[2]!='9'?1:-1;
			if(i==7)	s[3]+= s[3]!='9'?1:-1;
			if(i==8)	s[7]+= s[7]!='9'?1:-1;

			ans.pb(s);
		}

		rep(i,0,9)
			cout<<ans[i]<<endl;
	}
    
}
