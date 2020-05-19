
/// Time-0.667s
/// combinatorics problem and bigmod and fermat's theorem 

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const int mx=2000005;
ll mod=1000000007;

ll fact[mx];

void cal()
{
    fact[0]=1ll;
    for(int i=1;i<mx;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
}

ll mod_power(ll a,ll b)
{
    ll res=1ll;
    while(b)
    {
        if(b&1ll) res=(res*a)%mod;
        a=(a*a)%mod;
        b=b>>1ll;
    }
    return (res%mod);
}

int main()

{
    ios::sync_with_stdio(false);
    cal();
    int t;
    ll n,k;
    cin>>t;
    int caseno=0;
    while(t--)
    {
        caseno++;

        /// (n+k-1)! % mod [ numerator]
        /// ---------------------------
        /// (n! *(k-1)!) %mod  [ denominator]
        /// According to fermat theorem  a^(b-1) % b = 1 ,so a^(-1)%mod = a^(mod-2) %mod=a^(mod-1)%mod *a^(-1) %mod=a^(-1)%mod.
        /// (n+k-1)!%mod * (n!*(k-1)!)^(mod-2) %mod

        cin>>n>>k;/// n stars and k-1 bars
        ll numerator=fact[n+k-1]%mod;
        ll denominator=(fact[n]*fact[k-1])%mod;
        ll ans=(numerator * mod_power(denominator,mod-2))%mod;
        cout<<"Case "<<caseno<<": "<<ans<<endl;
    }
    return 0;
}
