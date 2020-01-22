#include<bits/stdc++.h>

using namespace std;


// Basic probability and series reduction problem

typedef unsigned long long ll;

ll mod=1000000007 ;

/*

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
*/
// expected number of getting maximum dots
// we have to find out how many times ai can be stayed as maximum this is by (i)^n -(i-1)^n
// So , the total expected number is i * ( (i)^n -(i-1)^n ) / (m^n)
// Avoiding overflow , ((i/m)^n -((i-1)/m)^n)*i

int main()

{
    ios_base::sync_with_stdio(false);
     double m,n,ans=0.0;
    cin>>m>>n;
    for( double i=1.0;i<=m;i++)
    {
        ans=ans+(pow((i/m),n)-pow((i-1.0)/m,n))*i;
    }
    printf("%0.04lf\n",ans);
    return 0;
}
