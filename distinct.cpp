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
int a[N],fre[N],res[N];
map<int,int>m;
int sqrtn;
struct Query{
     int l,r,idx;
};
vector<Query>q;
void faster()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
}
#define testCase \
    int t;       \
    cin >> t;    \
    while (t--)

bool comp(Query a,Query b)
{
     if(a.l/sqrtn==b.l/sqrtn)
     {
          return a.r>b.r;
     }
     return a.l/sqrtn<b.l/sqrtn;
}

int32_t main()
{
     faster();
     int n,t;
     cin>>n>>t;
     int c=1;
     for(int i=0;i<n;i++)
     {
          cin>>a[i];
          if(m[a[i]]==0)
          {
               m[a[i]]=c;
               c++;
          }
          a[i]=m[a[i]];
     }
     sqrtn=sqrt(n);
     q.resize(t);
     for(int i=0;i<t;i++)
     {
          cin>>q[i].l>>q[i].r;
          q[i].idx=i;
     }
     sort(q.begin(),q.end(),comp);
     int cur_r=-1,cur_l=0,cnt=0;
     int L,R;
      for(auto i:q)
      {
          L=i.l;
          R=i.r;
          L--;
          R--;
          while(cur_r<R)
          {
               cur_r++;
               fre[a[cur_r]]++;
               if(fre[a[cur_r]]==1)
               {
                    cnt++;
               }
          }
          while(cur_r>R)
          {
               fre[a[cur_r]]--;
               if(fre[a[cur_r]]==0)
               {
                    cnt--;
               }
               cur_r--;
          }
          while(cur_l<L)
          {
               fre[a[cur_l]]--;
               if(fre[a[cur_l]]==0)
               {
                    cnt--;
               }
               cur_l++;
          }
          while(cur_l>L)
          {
               cur_l--;
               fre[a[cur_l]]++;
               if(fre[a[cur_l]]==1)
               {
                    cnt++;
               }
          }
          res[i.idx]=cnt;
          
      }
      for(int i=0;i<t;i++)
      {
          cout<<res[i]<<endl;
      }


     
             
}