/*
Kahn Algorithm to find Topological Sort in Directed Acyclic Graph
IF the graph is not Aycyclic prints IMPOSSIBLE
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100010];
void solve()
{
   int n,m;
   cin>>n>>m;
   vector<int> in(n+1);
   for(int i=0;i<m;i++)
   {
       int x,y;
       cin>>x>>y;
       adj[x].push_back(y);
       in[y]++;
   }
   stack<int> s;
   for(int i=0;i<n;i++)
   {
       if(in[i+1]==0)
       s.push(i+1);
   }
   vector<int> ans;
   while(!s.empty())
    {
        int no=s.top();
        s.pop();
        ans.push_back(no);
        for(auto x:adj[no])
        {
            in[x]--;
            if(in[x]==0)
            s.push(x);
        }
    }
    if(ans.size()!=n)
    cout<<"IMPOSSIBLE";
    else
    {
        for(auto x:ans)
        cout<<x<<" ";
    }
}
int main()
{ 
	solve();
	return 0;
}
