#include<bits/stdc++.h>

using namespace std;


// Basic combinatorics problem and inverse modulo

typedef unsigned long long ll;

ll mod=1000000007 ;

// for first k positions , one is fixed for 1 numbered plaque so , for others k-1 positions k^(k-1) and rest of this  for (n-k) positions (n-k)^(n-k)

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
    ll n,k;
    cin>>n>>k;
    ll ans=(po(k,k-1)*po(n-k,n-k))%mod;
    cout<<ans<<endl;
    return 0;
}
