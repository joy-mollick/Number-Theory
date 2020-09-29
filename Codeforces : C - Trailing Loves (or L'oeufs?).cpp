
/// Codeforces : C - Trailing Loves (or L'oeufs?)
/// Category : number theory .


/// we have to find out the largest base^k that divides n!
/// if base is prime ,then it is easy to calculate n/b + n/b*b +n/(b*b*b)+.......
/// if base is not prime,then
/// make a vector of prime and its count in n.
/// then find ans=min(ans,calculate(n,pi)/countofpi_in_n)



#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

/// To find the power of a prime p in factorial N
ll findPowerOfP(ll n, ll p)
{
    ll counts = 0ll;
    while (n)
    {
        counts += (n / p);
        n=n/p;
    }
    return counts;
}

/// finding prime factors in base
/// and do calculation
ll cal(ll base,ll n)
{
    vector<pair<ll, ll> > ans;
    ll k=base;
    for (ll i = 2; k != 1 && i*i<=k ; i++)
    {
        if (k % i == 0)
        {
            ll count = 0;
            while (k % i == 0) {
                k = k / i;
                count++;
            }

            ans.push_back(make_pair(i, count));
        }
    }

    if(k>1) ans.push_back(make_pair(k,1ll));

    ll res = 0x3f3f3f3f3f3f3f3f,temp;
    for (int i = 0; i < ans.size(); i++)
    {
    ///calculating minimum power of all the prime factors of base
        temp= findPowerOfP(n,ans[i].first);
        temp/=ans[i].second;
        res = min(res,temp);
    }

    return res;

}


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,base;
    cin>>n>>base;

    cout<<cal(base,n)<<endl;

	return 0;
}
