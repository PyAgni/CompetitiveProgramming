#include<bits/stdc++.h>
using namespace std;

bool freqq(string s,int x){
	int freq[s.size()]={0};
	for(int i=0;i<s.length();i++){
		freq[s[i]-'a']++;
	}

	for(int i=0;i<s.size();i++){
		if(i!=x)
			return false;
	}
	return true;
}

int main(){
	
	int t;
	cin>>t;
	while(t--){

		string s;
		cin>>s;
		int k,x;
		cin>>k>>x;
		vector<string> prefix;
		for(int i=0;i<s.length();i++){
			string ss="";
			for(int j=0;j<i;j++){
				// cout<<s[j];
				// ss+=char(s[j]);
				ss.push_back(s[j]);
				
			}
			prefix.push_back(ss);
			// cout<<s;
			// cout<<endl<<endl;
		}
		for(int i=1;i<prefix.size();i++){

			int freq[prefix[i].size()]={0};
			for(int i=1;i<prefix[i].length();i++){
				freq[s[i]-'a']++;
			}
			for(int i=0;i<prefix[i].size();i++)
				cout<<freq[i]<<" ";

			// cout<<prefix[i]<<" ";
			// if(freqq(prefix[i],x))
			// 	cout<<1;
			// else cout<<2;
			cout<<endl;
		}
		// cout<<prefix[i]<<endl;


	}


}