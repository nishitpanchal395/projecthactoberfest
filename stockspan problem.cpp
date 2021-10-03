#include<bits/stdc++.h>
using namespace std;
int main(){
	int n = 6;
	int arr[n] = {100,80,70,60,75,85};
	stack<pair<int,int> > s;
	vector<int> v;
	for(int i=0; i<n; i++){
		if(s.size() == 0){
			v.push_back(1);
		}else{
			while(s.size() > 0 && s.top().first <= arr[i]){
				s.pop();
			}
			if(s.size() == 0){
				v.push_back(i+1);
			}else{
				v.push_back(i-s.top().second);
			}
		}
		s.push({arr[i],i});
	}
	for(int i=0; i<n;i++){
		cout<<v[i]<<" ";
	}
	return 0;
}
