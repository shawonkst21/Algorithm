#include<bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define endl "\n"
#define pb push_back  
const int N=1e5+10;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
//int dx2[]={0,0,-1,1,1,1,-1,-1};
//int dy2[]={-1,1,0,0,1,-1,1,-1};
#define vi vector<int>
#define vp vector<pair<int,int>>
#define  mii map<int,int>
//priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
 vi dis;
 vi par;
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
     vector<vector<int>>v;
     while(m--)
     {
          int x,y,z;
          cin>>x>>y>>z;
          v.pb({x,y,z});
     }
      dis.resize(n+1,INT_MAX);
      par.resize(n+1,-1);
     int temp;
     dis[1]=0;
     for(int i=0;i<n;i++)
     {
          temp=-1;
          for(auto i:v)
          {
               int x=i[0];
               int y=i[1];
               int z=i[2];
               if( dis[y]>dis[x]+z)
               {
                    dis[y]=dis[x]+z;
                    par[y]=x;
                    temp=y;
               }
          }
     }
     if(temp==-1)
     {
          no;
     }
     else
     {
          yes;
          for(int i=1;i<=n;i++)
          {
               temp=par[temp];
          }
          vector<int>ans;
          for(int i=temp;;i=par[i])
          {
               ans.pb(i);
               if(i==temp && ans.size()>1)
               {
                    break;
               }
          }
          reverse(ans.begin(),ans.end());
          for(auto i:ans)
          {
               cout<<i<<' ';
          }
     }
 
 
}
