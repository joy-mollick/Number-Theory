#include<bits/stdc++.h>

using namespace std;


// Counting Pairs

typedef unsigned long long ll;

ll mod=1000000007 ;

ll po(ll a,ll b)
{
   ll ans=1ll;
   while(b)
   {
       if(b&1)
        ans=(ans*a)%mod;
       b=b>>1;
       a=(a*a)%mod;
   }
   return (ans%mod);
}


int main()

{
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll ans=1ll;
    ans=(n*(n-1)*(n-2)*(n-3)*(n-4))/120ll;// Choose 5 paths from n
    ans=ans*(n*(n-1)*(n-2)*(n-3)*(n-4));// Now place 5 benches among here so that no path contains more than one bench
    cout<<ans<<endl;
    return 0;
}
