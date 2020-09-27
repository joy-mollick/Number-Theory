
/// Codeforces : 17D - Notepad.
/// Category : number theory + combinatorics + Extended Euler's Theorem.

/// Classical one ,man !!

/// (b-1) * b^(n-1) % c is our desired answer
/// But (n-1) and b can be so large
/// c may be not prime ,so how we do modulo ?

/// Here we will take a new technique
/// obviously we have to do modulo (n-1) and b
/// a^b ≡ a^(b%φ(m)+φ(m))(mod m) when b>=φ(m) it is not necessary m and a co-prime
/// a^b ≡ a^(b%φ(m))(mod m) when b<φ(m).

/// So , now b^(n-1) % c can be treated as like above
///  b^((n-1)% φ(c)+φ(c)) mod(c) ,if (n-1)>=φ(c)
///   b^((n-1)% φ(c)) mod(c) when (n-1)< φ(c) .



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

/// totient function
ll phi(ll n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;

    return result;
}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll c,Phi;
    string s1,s2;

    cin>>s1>>s2>>c;

    Phi=c;
    ll b=0ll;
    ll n_1=0ll;

    /// finding b%c
    for(int i=0;i<(int)s1.size();i++)
    {
        b=b*10+(s1[i]-'0');
        b%=c;
    }
    /// make string of n-1
    for(int i=(int)s2.size()-1;i>=0;i--)
    {
        if(s2[i]=='0') s2[i]='9';
        else
        {
            s2[i]--;
            break;
        }
    }

    Phi=phi(c);
    bool flag=0;

    /// taking number (n-1)
    for(int i=0;i<(int)s2.size();i++)
    {
        n_1=n_1*10+(s2[i]-'0');
        if(n_1>=Phi) flag=1;
        n_1%=Phi;
    }

    if(flag) n_1+=Phi;
    ll ans=((b-1ll)*pow(b,n_1,c))%c;
    if(ans<0) ans=(ans+c)%c;

    if(ans) cout<<ans<<endl;
    else cout<<c<<endl;

	return 0;
}
