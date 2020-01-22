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

// it is summation of infinite series of probability 
// (a/b)+(1-c/d)*(1-a/b)*(a/b)+(1-c/d)*(1-a/b)*(1-c/d)*(1-a/b)*(a/b)+..........
// sntwin=(1-a/b) && zntwin=(1-c/d) && swin = (a/b) 
// like ar^0 +ar^1 +ar^2 +ar^3 +..........infinite series whose sum is a*(1/(1-r)).So here , a= swin , r=zntwin*sntwin.

int main()

{
    ios_base::sync_with_stdio(false);
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    double swin=(a/b);
    double sntwin=1.0-(a/b);
    double zntwin=1.0-(c/d);
    double r=sntwin*zntwin;
    double infinite_sum=1.0/(1.0-r);
    double answer=swin*infinite_sum;
    printf("%0.06lf\n",answer);
    return 0;
}
