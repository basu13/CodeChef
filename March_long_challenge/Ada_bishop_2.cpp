/*
author= @rp!t Jain
*/
#include<bits/stdc++.h>
#define mod 1000000007
#define fr first
#define sec second
#define ll long long
#define PI 3.1415926535
#define pb push_back
#define mpr make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

ll fac[200005];
void pre(){ fac[0]=1; fac[1]=1; for(int i=2;i<200005;i++) fac[i]=(i*fac[i-1])%mod;}
ll power(ll a,ll b){ll res=1;while(b){if(b&1) res=(res*a)%mod;a=(a*a)%mod;b=b/2;}return res%mod;}
ll ncr(ll n,ll r){return ((fac[n]*power(fac[r],mod-2))%mod*power(fac[n-r],mod-2))%mod;}
ll prime[2000005];
void soe()
{
    for(int i=0;i<2000005;i++)
        prime[i]=true;
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i<2000005;i++)
    {
        if(prime[i]==true)
        {
            for(int j=i*2;j<2000005;j+=i)
               prime[j]=false;
        }
    }
}
bool chess[8][8];
bool valid(int i,int j)
{
    if(i>=0 && j>=0 && i<8 && j<8)
        return true;
    return false;
}
void solve(vector<pair<int,int> > &v,int n,int m)
{
    int c=0,i=n,j=m;
    if(i!=j)
    {
    v.pb(mpr(i,j));
    while(i!=j)
        {
            if(i>j)
            {
                i--;
                j++;
            }
            else
            {
                i++;
                j--;
            }
        }
    }
    if(i==j && i!=0)
    {
         v.pb(mpr(i,j));
       i=0;
       j=0;
    }

    v.pb(mpr(i,j));
    while(valid(i,j))
       {
           if(chess[i][j]==false)
           {
               c++;
               chess[i][j]=true;
           }
           i++;
           j++;
       }
       i--;
       j--;

    //cout<<i<<" "<<j<<"\n";
    while(c<32)
    {
       v.pb(mpr(i,j));
       i--;
       j--;
       v.pb(mpr(i,j));

       /// left
       while(valid(i+1,j-1))
       {
           if(chess[i+1][j-1]==false)
           {
               c++;
               chess[i+1][j-1]=true;
           }
           i++;
           j--;
       }
       v.pb(mpr(i,j));
       /// up
       while(valid(i-1,j-1))
       {
           if(chess[i-1][j-1]==false)
           {
               c++;
               chess[i-1][j-1]=true;
           }
           i--;
           j--;
       }
       v.pb(mpr(i,j));
       /// Right
       while(valid(i-1,j+1))
       {
           if(chess[i-1][j+1]==false)
           {
               c++;
               chess[i-1][j+1]=true;
           }
           i--;
           j++;
       }
       v.pb(mpr(i,j));
       /// Down
       while(valid(i+1,j+1))
       {
           if(chess[i+1][j+1]==false)
           {
               c++;
               chess[i+1][j+1]=true;
           }
           i++;
           j++;
       }
       v.pb(mpr(i,j));
       ///Back to diagonal
       while(i!=j)
       {
           i++;
           j--;
       }
       //v.pb(mpr(i,j));
    }
    /*for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            cout<<chess[i][j]<<" ";
        cout<<"\n";
    }*/
}
int main()
{
    fast;
    long t;
    cin>>t;
    //t=1;
    while(t--)
    {
      int n=1,m=1;
      cin>>n>>m;
      for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
          chess[i][j]=false;
      vector<pair<int,int> > res;
      n--;
      m--;
      solve(res,n,m);
      cout<<res.size()<<"\n";
      for(int i=0;i<res.size();i++)
      {
          cout<<res[i].fr+1<<" "<<res[i].sec+1<<"\n";
      }
    }

}
