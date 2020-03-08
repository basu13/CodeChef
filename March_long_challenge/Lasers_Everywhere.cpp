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
double n,point[100005];
vector<pair<double,double> > line;
void help()
{
    for(int i=2;i<=n;i++)
    {
        double dy=point[i]-point[i-1];
        double dx=1;
        double m=dy/dx;
        double c=point[i-1]-m*(i-1);
        line.pb(mpr(m,c));
    }
}
ll solve(double x1,double x2,double y)
{
    ll res=0;
    for(int i=1;i<line.size();i++)
    {
        double m=line[i].fr;
        double c=line[i].sec;
        if(m!=0)
        {
           double x=(y-c)/m;
           //cout<<x<<" "<<y<<"\n";
           /*if(x>=x1 && x<=x2)
              if(x>=i+1 && x<=i+2)
                if(y!=point[i+1] && y!=point[i+2])
                      res++;*/
               if(x>=x1 && x<=x2 && x>=i && x<=i+1)
               if(((i)!=x2 || y!=point[i]) && ((i+1)!=x1 || y!=point[i+1]))
               {
                   //cout<<x<<" "<<y<<"\n";
                   //cout<<i<<" ";
                   res++;
               }
        }
        else
        {
            if(c==y)
                res++;
        }

    }
    return res;
}
int main()
{
    fast;
    long t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll q;
        cin>>q;
        line.clear();
        line.pb(mpr(0,0));
        for(int i=1;i<=n;i++)
            cin>>point[i];
        help();
        /*for(int i=0;i<line.size();i++)
            cout<<line[i].fr<<" "<<line[i].sec<<"\n";*/
        for(int i=0;i<q;i++)
        {
            double x1,x2,y;
            cin>>x1>>x2>>y;
            cout<<solve(x1,x2,y)<<"\n";
        }

    }

}

