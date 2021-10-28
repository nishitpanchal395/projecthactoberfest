#include<bits/stdc++.h>
using namespace std;
class edge{
public:
  int source;
  int dest;
  int weight;
};
bool compare(edge e1,edge e2){
	return e1.weight<e2.weight;
}

int find(int v,int *parent){
	if(parent[v]==v){
		return v;
	}
	return find(parent[v],parent);
}

void krushkal(edge *input,int n,int E){
	sort(input,input+E,compare);

	edge *output=new edge[n-1];
	int *parent=new int[n];
	for(int i=0;i<n;i++){
		parent[i]=i;
	}

	int count=0;
	int i=0;
	while(count!=n-1){
		edge edgecurrent=input[i];

		int sourceparent=find(edgecurrent.source,parent);
		int destparent=find(edgecurrent.dest,parent);
		if(sourceparent!=destparent){
			output[count]=edgecurrent;
			count++;
			parent[sourceparent]=destparent;
		}
		i++;
	}

	for(int i=0;i<n-1;i++){
		cout<<output[i].source<<" "<<output[i].dest<<" "
		<<output[i].weight<<endl;
	}

}
int main(){
	int n,E;
	cin>>n>>E;
	edge *input=new edge[E];
	for(int i=0;i<E;i++){
		int s,d,w;
		cin>>s>>d>>w;
		input[i].source=s;
		input[i].dest=d;
		input[i].weight=w;
	}

	krushkal(input,n,E);
}
