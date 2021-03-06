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

int main()
{
    fast;
    long t;
    cin>>t;
    while(t--)
    {
      ll n,k;
      cin>>n>>k;
      ll a[n];
      for(int i=0;i<n;i++)
        cin>>a[i];
      map<int,int> m;
      ll res=0,j=0;
      for(int i=0;i<n;i++)
      {
          m[a[i]]++;
          while(m.size()==k && j<=i)
          {
              m[a[j]]--;
              if(m[a[j]]==0)
                m.erase(a[j]);
              j++;
          }
          res=max(res,i-j+1);
      }

      cout<<res<<"\n";
    }

}

