#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

/*

ll mod=1000000007 ;

ll po(ll a,ll b)
{
   ll ans=1ll;
   while(b)
   {
       if(b&1ll){
        ans=(ans*a)%mod;}
       b=b>>1ll;
       a=(a*a)%mod;
   }
   return (ans%mod);
}
*/


int main()

{
    ios_base::sync_with_stdio(false);
    int n,x;
    cin>>n>>x;
    int a;
    ll result=0;
    map<int,int>m;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        int curr_xr=a^x;
        if(m.find(curr_xr)!=m.end())
            result=result+m[curr_xr];

        m[a]++;
    }
    cout<<result<<endl;
}
