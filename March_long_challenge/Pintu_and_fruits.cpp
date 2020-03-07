#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    map<int,int> mp;
	    int f[n];
	    for(int i=0;i<n;i++)
	      cin>>f[i];
	    int p[m];
	    for(int i=0;i<n;i++)
	      {
	          cin>>p[i];
	          mp[f[i]]+=p[i];
	      }
	    int min=INT_MAX;
	    for(auto it=mp.begin();it!=mp.end();it++)
	    {
	        if(min>it->second)
	           min=it->second;
	    }
	    cout<<min<<"\n";
	}
	return 0;
}
