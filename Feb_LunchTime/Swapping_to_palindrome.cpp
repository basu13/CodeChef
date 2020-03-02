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
string check(string s,int n)
{
    int res=0;
    int l=0,r=0;
    int i=0,j=n-1;
    while(i<=j)
    {
        if(s[i]==s[j])
        {
            i++;
            j--;
            l=0;
            r=0;
            continue;
        }
        else if(s[i]==s[j-1] && r==0)
        {
            swap(s[j],s[j-1]);
            i++;
            j--;
            r=1;
            l=0;
            res++;
        }
        else if(s[i+1]==s[j] && l==0)
        {
            swap(s[i],s[i+1]);
            i++;
            j--;
            l=1;
            r=0;
            res++;
        }
        else
            break;
      }
      for(i=0,j=n-1;i<=j;i++,j--)
        if(s[i]!=s[j])
          return "NO";
      return "YES\n"+to_string(res);

}
int main()
{
    fast;
    long t;
    cin>>t;
    while(t--)
    {
       ll n;
       cin>>n;
       string s;
       cin>>s;
       cout<<check(s,n)<<"\n";
    }

}

