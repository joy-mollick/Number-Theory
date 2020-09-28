
/// Codeforces : 1316C - Primitive Primes.
/// Category : number theory + easy .


/// it is easy to see that in h(x) ,there are total multiplication of g(x)*f(x) terms
/// we multiply evry term of f(x) by g(x)
/// so it is optimal to choose the co-efficient of f(x) which isn't divisible by p
/// then find co-eficient of g(x) which isn't divisible by p
/// after multiplication this combination term will not be divisible by p
/// then their power will be x + y , x is xth term of f(x) and y is yth term of g(x)

#include<bits/stdc++.h>

using namespace std;

const int mx=200005;

typedef long long ll;

const ll mod=1e9+7;

/*

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

*/

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,p;
    cin>>n>>m>>p;
    int a[n];
    int b[m];

    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=0;i<m;i++) cin>>b[i];

    int x=0;
    int y=0;

    while(a[x]%p==0) x++;
    while(b[y]%p==0) y++;

    cout<<(x+y)<<endl;

	return 0;
}
