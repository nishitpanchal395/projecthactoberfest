/*
Floyd-Warshall Algorithm to Find Shortest Path between All pair vertices

*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<pair<ll,ll>> adj[510];
vector<vector<ll>> dp(510,vector<ll> (510,1e12));
void solve()
{
    ll n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<m;i++)
    {
        ll x,y,c;
        cin>>x>>y>>c;
        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
        dp[x][y]=min(dp[x][y],c);
        dp[y][x]=dp[x][y];
    }
    
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            { 
            if(i==j)
            dp[i+1][j+1]=0;
            else
            {
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i+1][k+1]+dp[k+1][j+1]);
            }
            }
        }
    }
    //queries to test the algorithm if path bewteen two nodes does not exists then prints -1
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        if(dp[x][y]==1e12)
        cout<<"-1\n";
        else
        cout<<dp[x][y]<<"\n";
    }
}
int main()
{ 
	solve();
	return 0;
}
