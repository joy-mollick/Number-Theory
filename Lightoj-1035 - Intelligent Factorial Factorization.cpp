#include <bits/stdc++.h>

 using namespace std;

 typedef long long ll;

 const ll mod=1000000007;

 ll res=1ll;

 ll po(ll a,ll b)
 {
     ll ans=1ll;
     while(b)
     {
         if(b&1) ans=(ans*a)%mod;

         b=b>>1;
         a=(a*a)%mod;
     }
     return (ans%mod);
 }

 void sod(ll n,ll p)
 {
     ll curr_sum = 1;
     ll curr_term = 1;
     ll cont=0ll;
     while(n%2==0)
     {
         cont++;
         n=n>>1;
     }
     if(cont!=0){
     cont=(cont*p)+1;
     res=(res*(((po(2ll,cont)-1ll)+mod)%mod))%mod;
     res=(res*(po(2ll-1,mod-2)%mod))%mod;
     }
    for (ll i = 3ll; i*i <= (n); i=i+2ll)
    {
        curr_sum=1ll;
        curr_term=1ll;
        cont=0ll;
        while (n % i == 0) {
            n = n / i;
            cont ++;
        }
        if(cont!=0){
     cont=(cont*p)+1;
     res=(res*(((po(i,cont)-1ll)+mod)%mod))%mod;
     res=(res*(po(i-1,mod-2)%mod))%mod;}

    }
    cont =1ll;
    curr_term=1ll;
    if (n >= 2){
           cont=(cont*p)+1;
     res=(res*(((po(n,cont)-1ll)+mod)%mod))%mod;
     res=(res*(po(n-1,mod-2)%mod))%mod;
     }

    res=(res%mod);
 }

 int main()

 {
     int tc,s=1;
     scanf("%d",&tc);
     ll n,m;
     while(tc--)
     {
     scanf("%lld%lld",&n,&m);
     res=1ll;
     sod(n,m);
     printf("Case %d: %lld\n",s,res);
     s++;
     }
 }
