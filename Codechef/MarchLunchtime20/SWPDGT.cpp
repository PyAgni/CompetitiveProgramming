#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int t;
	cin>>t;
	while(t--){

		int a,b;
		cin>>a>>b;
		if(a>9 && b>9){
			vector<int> sum;
			sum.push_back(a+b);
			int q,w,e,r;
			w=a%10;
			a/=10;
			q=a;
			r=b%10;
			b/=10;
			e=b;

			// cout<<q<<w<<e<<r;
			
			int aa,bb,cc,dd;
			aa=10*e + w;
			bb=10*q + r;
			// cout<<aa<<" "<<bb<<endl;
			sum.push_back(aa+bb);

			aa=10*q+r;
			bb=10*e+w;
			// cout<<aa<<" "<<bb<<endl;
			sum.push_back(aa+bb);

			aa=10*r+w;
			bb=10*e+q;
			// cout<<aa<<" "<<bb<<endl;
			sum.push_back(aa+bb);

			aa=10*q+e;
			bb=10*w+r;
			// cout<<aa<<" "<<bb<<endl;
			sum.push_back(aa+bb);
			

			sort(sum.begin(), sum.end());
			cout<<sum[4]<<endl;

			// for(int i=0;i<sum.size();i++)
			// 	cout<<sum[i]<<" ";


		}

		else if(a<10 && b>9){
			int q,w,e,xx=b;
			q=a;
			e=b%10;
			b/=10;
			w=b;

			int aa,bb;
			aa=e + (10*w+q);
			bb=w + (10*q+e);

			cout<<max(a+xx,max(aa,bb))<<endl;

		}

		else if(b<10 && a>9){
			int temp =a;
			a=b;
			b=temp;
			int q,w,e,xx=b;
			q=a;
			e=b%10;
			b/=10;
			w=b;

			int aa,bb;
			aa=e + (10*w+q);
			bb=w + (10*q+e);

			cout<<max(a+xx,max(aa,bb))<<"\n";

		}

		else
			cout<<a+b<<"\n";


	}

}