
/// Time-0.008s
/// normal mod operation 

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll mod_power(ll a,ll b,ll mod)
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
    int t;
    cin>>t;
    ll n,K,mod,val;
    int caseno=0;
    while(t--)
    {
        cin>>n>>K>>mod;
        ll sum=0ll;
        for(int i=0;i<n;i++) {cin>>val;sum+=val;}
        sum=(sum%mod);
        ll res=(K*sum)%mod;/// inside last loop ,it will be calculated
        res=(mod_power(n,K-1,mod)*res)%mod;/// this is outer K-1 loops
        printf("Case %d: %llu\n", ++caseno, res);
    }
    return 0;
}
