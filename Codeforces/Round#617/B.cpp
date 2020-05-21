#include<bits/stdc++.h>
using namespace std;

long long int solve(int n){
	if(n<10) return n;
	if(n==10) return 11;
	return (n- n%10)+solve((n-(n%10))/10 + n%10);
}

int main(){
	
	int t;
	cin>>t;
	while(t--){
		long int s;
		cin>>s;
		cout<<solve(s);

}
}