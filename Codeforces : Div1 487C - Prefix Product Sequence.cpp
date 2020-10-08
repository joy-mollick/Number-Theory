
/// Codeforces : Div1 487C - Prefix Product Sequence
/// Category : number theory .



#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

/// One thing , that when n is not prime
/// Then , (n-1)! will be divisible by n implies that (n-1)!%n=0
/// n%n will also give modulo zero
/// When n is not prime ,then answer is no

/// when n is prime ,then .
/// we will make modulo just like 1 2 3 ......0
/// First and last elements are fixed.
/// For every term we have to find arbitrary x which is below n ,(prev_mod*x)%n=i
/// So,every time prev_mod is (i-1).
/// ((i-1)*x)%n=i
/// (x%n)=(i/(i-1)%mod)
/// (x%n)=i*(inv(i))%mod
/// x = i*(inv(i))%mod.
/// now (x) is our answer

ll po(ll a,ll b,ll mod)
{
    ll ans=1ll;
    while(b)
    {
        if(b&1ll) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b=b>>1ll;
    }
    return (ans%mod);
}

bool prime(ll num)
{
    for(ll i=2;i*i<=num;i++)
    {
        if(num%i==0) return false;
    }
    return true;
}


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;

    if(n == 4)
    {
        cout<<"YES\n";
        cout<<"1\n3\n2\n4"<<endl;
        return 0;
    }

    else if(n == 1)
    {
        cout<<"YES\n1\n"<<endl;
        return 0;
    }

    else if(!prime(n))
    {
        printf("NO\n");
        return 0;
    }

    /// first and last one is fixed
    cout<<"YES\n1\n";

    for(ll i = 2; i < n; i++)
    {
        ll inv=po(i - 1, n - 2, n);
        ll x= (i*inv)%n;
        cout<<x<<endl;
    }

    cout<<n<<endl;

    return 0;
}
