#include<bits/stdc++.h>
using namespace std;
int main(){
	int ele,n,i,j,k,start,end,sum;
	vector<int> ans;
	cout<<"Enter the size"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the sum"<<endl;
	cin>>ele;
	cout<<"Enter the elements of the array"<<endl;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			sum=0;
			for(k=i;k<=j;k++){
				sum=sum+arr[k];
			}
			if(sum==ele){
				start=i+1;
				end=j+1;
				break;
			}
		}
		if(sum==ele){
			break;
		}
	}
	
	ans.push_back(start);
	ans.push_back(end);
	
	for(i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
}
