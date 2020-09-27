
/// Codeforces : D. D - Multipliers
/// Category : number theory + combinatorics.

/// nice one ,man !!

/// a one prime number has contribution how many times in the product of all divisors ?
/// cnt(i) is the count of prime pi , sum is the total number of divisors 
/// now pi has how many  kinds ? pi^0 + pi^1 +pi^2 +....+pi^cnt(i) , so total pi*(pi+1)/2 kinds 
/// The number of divisors not containing pi as its part , sum/(pi+1) ,right? 
/// So, pi has the power in the product of all divisors will be ( pi^( pi*(pi+1)/2 ) )^ ( sum/(pi+1) )
/// i.e. ( pi^( pi*(pi+1)/2 ) )^ ( sum/(pi+1) ) = ( pi^( pi*(pi+1)/2 * ( sum/(pi+1) ) ) ) % mod 
/// but using Fermat's theorem , we can't do modulo with power part but ( pi*(pi+1)/2 * ( sum/(pi+1) ) ) ,power part can be so large 
/// So, we have to do modulo power part by (mod-1) . Now , it is guarantee that ( pi*(pi+1)/2 obviously not large but ( sum/(pi+1) 
/// so , instead of doing division part in ( sum/(pi+1) we will keep left side and right side prefix and suffix 

#include<bits/stdc++.h>

using namespace std;

const int mx=200005;

typedef __int64 ll;

ll cont[mx];

const ll mod=1e9+7;
const ll mods=mod-1ll;

ll pow(ll a,ll b,ll m)
{
    ll ans=1ll;
    while(b)
    {
        if(b&1ll) ans=(ans*a)%m;
        a=(a*a)%m;
        b=b>>1ll;
    }
    return (ans);
}

map<ll,ll>mp;
ll prime[mx];
ll pre[mx];
ll suff[mx];

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll tot=1ll;

    int m;
    cin>>m;

    ll prim;
    while(m--)
    {
        cin>>prim;
        mp[prim]++;
    }

    /// number of divisors
    int counts=1;

    for(map<ll,ll>::iterator it=mp.begin();it!=mp.end();it++)
    {
        prime[counts]=it->first;
        cont[counts]=it->second;
        counts++;
    }

    ll ans=1ll;
    pre[0]=1ll;
    for(int i=1;i<counts;i++)
    {
        pre[i]=pre[i-1]*(cont[i]+1)%(mod-1);
    }

    suff[counts]=1ll;
    for(int i=counts-1;i>=1;i--)
    {
        suff[i]=suff[i+1]*(cont[i]+1)%(mod-1);
    }

    for(ll i=1;i<counts;i++)
    {
      ll Num=cont[i];
      Num=(Num*(Num+1)/2)%(mod-1);
      ll suff_pref=(pre[i-1]*suff[i+1])%(mod-1);
      ll b=(suff_pref*Num)%(mod-1);
      ans=(ans*pow(prime[i],b,mod)%mod)%mod;
    }

    cout<<ans<<endl;

	return 0;
}
