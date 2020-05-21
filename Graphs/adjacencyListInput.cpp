#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,M;
	cin>>N>>M;
	vector<int> ar[N+1];

	while(M--){
		cin>>a>>b;
		ar[a].push_back(b);
		ar[b].push_back(a);
	}
}
