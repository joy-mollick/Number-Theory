#include<bits/stdc++.h>

using namespace std;


// Parity Problem

typedef unsigned long long ll;

ll mod=1000000007 ;

// When k=-1 and m,n parity is different so it is problem . 
// 2^((n-1)*(m-1)) . (2^((n-1)))^(m-1) 

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


int main()

{
    ios_base::sync_with_stdio(false);
    ll m,n;
    int k;
    cin>>n>>m>>k;
    ll x=n%2;
    ll y=m%2;
    if(k == -1 && x!=y)
    {
        cout<<"0"<<endl;
        return 0;
    }
    n--;
    m--;
    ll a=po(2ll,n);
    cout<<po(a,m)<<endl;
}
