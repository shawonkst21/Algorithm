#include<bits/stdc++.h>
using namespace std;
using ll =long long;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define endl "\n"
//int dx[]={0,0,-1,1};
//int dy[]={-1,1,0,0};
void faster()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
}
int x,y,z;
#define testCase \
    int t;       \
    cin >> t;    \
    while (t--)
int32_t main()
{
     faster();
          ll n,e;
          cin>>n>>e;
          vector<ll>dis(n+10,LLONG_MAX);
          vector<vector<pair<ll,ll>>>v(n+10);
          while(e--)
          {
               ll a,b,c;
               cin>>a>>b>>c;
               v[a].push_back({b,c});
               v[b].push_back({a,c});
          }
          priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
          vector<ll>par(n+1,0);
          pq.push({0,1});
          dis[1]=0;
          while(!pq.empty())
          {
             auto x=pq.top();
             pq.pop();
             for(auto i:v[x.second])
             {
                 if(dis[i.first]>dis[x.second]+i.second)
                 {
                    dis[i.first]=dis[x.second]+i.second;
                    par[i.first]=x.second;
                    pq.push({dis[i.first],i.first});
                 }
             }
          }
          if(dis[n]==LLONG_MAX)
          {
               cout<<"-1"<<endl;
          }
          else
          {
               int temp=n;
               vector<ll>ans;
               while(par[temp]!=0)
               {
                    ans.push_back(temp);
                    temp=par[temp];
               }
               ans.push_back(1);
               reverse(ans.begin(),ans.end());
               for(auto i:ans)
               {
                    cout<<i<<' ';
               }cout<<endl;
          }


     
     
             
}