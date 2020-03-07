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
ll n,m;
multiset<int> aa,ba;
multiset<int> ad,bd;
ll suma=0,sumb=0;
void calc()
{
    int t=1;
    ll dp[100005],ans[100005];
    dp[0]=sumb-suma;
    while(true)
    {
        if(t&1)
        {
            if(aa.empty() || bd.empty())
            {
                ans[t]=-dp[t-1];
                break;
            }
            int x=*aa.begin(),y=*bd.rbegin();
            aa.erase(aa.lower_bound(x));
            ad.insert(x);
            bd.erase(bd.lower_bound(y));
            sumb-=y;
            dp[t]=suma-sumb;
        }
        else
        {
            if(ba.empty() || ad.empty())
            {
                ans[t]=-dp[t-1];
                break;
            }
            int x=*ba.begin(),y=*ad.rbegin();
            ba.erase(ba.lower_bound(x));
            bd.insert(x);
            ad.erase(ad.lower_bound(y));
            suma-=y;
            dp[t]=sumb-suma;
        }
        t++;
    }

    for(int i=t-1;i>=1;i--)
    {
        ans[i]=max(-dp[i-1],-ans[i+1]);
    }
    /* for(int i=0;i<t;i++)
        cout<<dp[i]<<" ";
    cout<<"\n";
     for(int i=0;i<t;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";*/
    cout<<ans[1]<<"\n";

}
int main()
{
    fast;
    long t;
    cin>>t;
    while(t--)
    {
        aa.clear();
        ad.clear();
        ba.clear();
        bd.clear();
        suma=0;
        sumb=0;
        string sa,sb;
        cin>>n>>m;
        ll a[n],b[m];
        for(int i=0;i<n;i++)
           {
                cin>>a[i];
                suma+=a[i];
           }

        cin>>sa;
        for(int i=0;i<m;i++)
            {
                cin>>b[i];
                sumb+=b[i];
            }
        cin>>sb;
        for(int i=0;i<n;i++)
        {
            if(sa[i]=='A')
                aa.insert(a[i]);
            else
                ad.insert(a[i]);
        }
        for(int i=0;i<m;i++)
        {
            if(sb[i]=='A')
                ba.insert(b[i]);
            else
                bd.insert(b[i]);
        }

        calc();
    }

}
