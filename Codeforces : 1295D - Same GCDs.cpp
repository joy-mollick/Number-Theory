
/// Codeforces : 1295D - Same GCDs.
/// Category : number theory + calculation .
/// Nice Classical One

/// how many x can be available? for which gcd(a,m) = gcd(a+x,m) = g. where 0<=x<m.
/// so, a=g*k & m=g*l ; gcd(g*k,g*l) = g.if we want to make gcd(a+x,m) equal to g.
/// Then, x is obviously multiple of g i.e. in the form of g*X.
/// gcd(g*k+g*X , g*l) = g => gcd(k+X,l)=1 . 0<=x<m ; 0<= g*X < g*l ; 0<=X<l.
/// how many X (0<=X<l) can be possible with which l will be co-prime.
/// now gcd( (k+X)%l, l) =1 , which is equivalent to gcd(k+X,l)=1 .
/// So ,every time [ (k+X)%l ] will give you 0,1,2,3,....l-1 .
/// In directly ,I have to find out number of [ (k+X)%l ] co-prime to l.
/// ans is phi(l). l=m/g.

#include<bits/stdc++.h>


using namespace std;

const int mx=501;

typedef long long ll;

ll phi(ll n)
{
    ll result = n; // Initialize result as n

    // Consider all prime factors of n and subtract their
    // multiples from result
    for (ll p = 2; p * p <= n; ++p) {

        // Check if p is a prime factor.
        if (n % p == 0) {

            // If yes, then update n and result
            while (n % p == 0)
            {
                n /= p;
            }

            result -= result / p;
        }
    }

    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result -= result / n;

    return result;
}


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;

    while(tc--)
    {
    ll a,m,g;
    cin>>a>>m;
    g=__gcd(a,m);

    ll l=m/g;
    cout<<phi(l)<<"\n";
    }

    return 0;
}
