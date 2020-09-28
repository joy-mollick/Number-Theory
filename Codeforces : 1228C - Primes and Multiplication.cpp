
/// Codeforces : 1228C - Primes and Multiplication.
/// Category : number theory +observation .

/// man !!
/// if you take example by hand on paper ,then you can see 
/// that how many times a prime factor will appear in original product 
/// like 10 and 3 ,only  g(3,3) * g(6,3) *g(9,3) will give u result
///                         3   *   3    * 9 = 81 = 3^4 
/// which actually means how many times 3 appears before 10 !
/// ans=0 , 10/3=3 ans+=3 ,10/3=3 , 3/3 =1 ans+=1 ans=4 , so 3 appears exactly 4 times as multiple in the numbers below 10 
/// which will give contribution 3^4 ...........


#include<bits/stdc++.h>

using namespace std;

const int mx=200005;

typedef long long ll;

const ll mod=1e9+7;

ll pow(ll a,ll b,ll m)
{
    ll ans=1ll;
    while(b)
    {
        if(b&1ll) ans=(ans*a)%m;
        a=(a*a)%m;
        b=b>>1ll;
    }
    return (ans%mod);
}

ll func(ll x,ll p)
{
   ll res=0ll;
   while(x)
   {
       res+=(x/p);
       x=x/p;
   }
   return pow(p,res,mod);
}

vector<ll>primes;
void fun(ll x)
{
    bool ok=false;
    for(ll i=2;i<=sqrt(x);i++)
    {
        ok=false;
        while(x%i==0) ok=true,x=x/i;
        if(ok) primes.push_back(i);
    }
    if(x>1) primes.push_back(x);
}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll x,n;
    cin>>x>>n;
    fun(x);
    ll ans=1ll;
    int sz=(int)primes.size();
    for(ll i=0;i<sz;i++) ans=(ans*func(n,primes[i]))%mod;

    cout<<(ans%mod)<<endl;

	return 0;
}
