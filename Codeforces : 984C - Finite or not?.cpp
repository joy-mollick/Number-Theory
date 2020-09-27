
/// Codeforces : 984C - Finite or not?
/// Category : number theory.

/// GCD magic ,man !!


#include<bits/stdc++.h>

using namespace std;

const int mx=200005;

typedef long long ll;

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

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin>>tc;
    ll p,q,b;

    while(tc--)
    {
        cin>>p>>q>>b;
        ll gcd=__gcd(p,q);
        ll denominator=q/gcd;
        /// we will deal with only (1/denominator)
        /// Is there any arbitrary k is available? for which b^k % denominator =0 .
        /// then it is finite otherwise infinite
        while(b!=1ll)
        {
            while(denominator%b==0) denominator/=b;
            b=__gcd(denominator,b);

        }
        if(denominator==1) cout<<"Finite"<<endl;
        else cout<<"Infinite"<<endl;
    }

	return 0;
}
