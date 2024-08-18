#include<bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define endl "\n"
#define pb push_back  
const int N=2e5+10;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
//int dx2[]={0,0,-1,1,1,1,-1,-1};
//int dy2[]={-1,1,0,0,1,-1,1,-1};
#define vi vector<int>
#define vp vector<pair<int,int>>
#define  mii map<int,int>
//priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
vector<vector<int>>adj(N);
vector<bool>visited(N,false);
vector<int>bridge;
void dfs(int node)
{
     visited[node]=true;
     for(auto i:adj[node])
     {
          if(!visited[i])
          {
               dfs(i);
          }
     }
}
void faster()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
}
#define testCase \
    int t;       \
    cin >> t;    \
    while (t--)
int32_t main()
{
     faster();
     int n,m;
     cin>>n>>m;
     while(m--)
     {
          int u,v;
          cin>>u>>v;
          adj[u].pb(v);
          adj[v].pb(u);
     }
     for(int i=1;i<=n;i++)
     {
          if(visited[i]==false)
          {
               bridge.pb(i);
               dfs(i);
          }
     }
     cout<<bridge.size()-1<<endl;
     for(int i=0;i<bridge.size()-1;i++)
     {
          cout<<bridge[i]<<' '<<bridge[i+1]<<endl;
     }
     

             
}