#include<bits/stdc++.h>

using namespace std;


// Parity Problem

typedef unsigned long long ll;

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


// Basic math problem 
// Every times the number of the triangles 4 times increased than previous .So after n days 4^n total triangles.
// (a) upwards + (b) downwards = 4^n . After some observation it can be said the ratio of a and b = (2^n + 1) / (2^n -1 ) 
// So , after some calculation -> it can be said a= (4^n +2^n) / 2 .


int main()

{
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll up=po(4ll,n)+po(2ll,n);
    ll down=po(2,mod-2);
    ll ans= (up*down)%mod;
    cout<<ans<<endl;
}
