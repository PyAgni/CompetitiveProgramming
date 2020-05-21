#include<bits/stdc++.h>
using namespace std;


bool comp(const pair<int,int> &a,  
               const pair<int,int> &b) 
{ 
       return (a.first > b.first); 
} 

int main(){
	
	int t,total=0;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[4][4];
		memset(arr,0,sizeof(arr));
		for(int i=0;i<n;i++){
			int t;
			char m;
			cin>>m>>t;
			if(m=='A'){
				if(t==12){
					arr[0][0]++;
				}
				if(t==3){
					arr[0][1]++;
				}
				if(t==6){
					arr[0][2]++;
				}
				if(t==9){
					arr[0][3]++;
				}

			}
			if(m=='B'){
				if(t==12){
					arr[1][0]++;
				}
				if(t==3){
					arr[1][1]++;
				}
				if(t==6){
					arr[1][2]++;
				}
				if(t==9){
					arr[1][3]++;
				}

			}
			if(m=='C'){
				if(t==12){
					arr[2][0]++;
				}
				if(t==3){
					arr[2][1]++;
				}
				if(t==6){
					arr[2][2]++;
				}
				if(t==9){
					arr[2][3]++;
				}

			}
			if(m=='D'){
				if(t==12){
					arr[3][0]++;
				}
				if(t==3){
					arr[3][1]++;
				}
				if(t==6){
					arr[3][2]++;
				}
				if(t==9){
					arr[3][3]++;
				}

			}
		}

		int ans=0;
		for(int i=0;i<4;i++){
			int chk=0;
			for(int j=0;j<4;j++){
				if(arr[i][j])
					chk++;
			}
			if(!chk)
				ans-=100;
		}
		
		vector<int> result,idx;
		vector<pair<int,int> > vpr;
		for(int i=0;i<4;i++){
			int maxx=0;
			
			for(int j=0;j<4;j++){

				vpr.push_back(make_pair(arr[j][i],j));
				
			}
			

		}
		sort(vpr.begin(),vpr.end(), comp);

		int ctr=3;
		result.push_back(vpr[0].first);
		idx.push_back(vpr[0].second);

		for(int i=1;ctr>0;i++){
			if(find(idx.begin(),idx.end(),vpr[i].second)==idx.end()){
				result.push_back(vpr[i].first);
				idx.push_back(vpr[i].second);
				ctr--;
			}
		}

		sort(result.begin(), result.end());
		ans+=result[0]*25 + result[1]*50 + result[2]*75 +result[3]*100;
		cout<<ans<<endl;
		total+=ans;

		}

		cout<<total;

		
}
