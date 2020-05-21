#include<bits/stdc++.h>
using namespace std;


bool ebne(string s,int n){

	if(s[n-1]=='0' || s[n-1]=='2' || s[n-1]=='4' || s[n-1]=='6' || s[n-1]=='8') return false;
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=(int)s[i]-'0';
	}
	if(sum%2==0)
		return true;
	else return false;
}


int reverse(int num) 
{ 
    int rev_num = 0; 
    while(num > 0) 
    { 
        rev_num = rev_num*10 + num%10; 
        num = num/10; 
    } 
    return rev_num; 
} 

int main(){

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		string tmp=s;
		bool f=false;
		for(int i=0;i<n;i++){
			if(ebne(tmp,n)){
				cout<<tmp<<"\n";
				f=true;
				break;
				
			}

			string temp;
			for(int j=0;j<n-i;j++){
				temp+=tmp[j];
			}
			tmp=temp;
			// cout<<tmp<<"\n";

		}
		tmp = s;
		reverse(tmp.begin(), tmp.end());
		// cout<<tmp;
		if(!f){
			for(int i=0;i<n;i++){
				string tmp1=tmp;
				reverse(tmp1.begin(), tmp1.end());
					if(ebne(tmp1,n)){
						string tmp2= tmp;
						reverse(tmp2.begin(), tmp2.end());
						cout<<tmp2<<"\n";
						f=true;
						break;
						
					}
					string temp;
			for(int j=0;j<n-i;j++){
				temp+=tmp[j];
			}
			tmp=temp;
		
				}
			}
		if(!f) cout<<-1<<endl;
	}


}