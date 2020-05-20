
/// Time - 0.080s
/// Inclusion-Exclusion principle and bitmask technique 
/// You can use ven diagram to understand this well .

/// If check for four numbers diagram 
/// Then it is like , (a U b U c U d) = (a)+(b)+(c)+(d) - (a inter b) -(a inter c) - (b inter c) -(a inter d) - (b inter d) -(c inter d) + (a inter b inter c) + (a inter c inter d ) + (b inter c inter d) +(a inter b inter d) - (a inter b inter c inter d) .

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;


ll gcd(ll m, ll n)
{
    if(n == 0)
    return m;
    return gcd(n, m%n);
}
ll lcm(ll a, ll b)
{
    ll t=gcd(a, b);
    return (a*b)/t;/// from lcm formula lcm(a,b)=(a*b)/gcd(a,b)
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    while(cin>>n>>m)
    {
        ll arr[m];
        for(int i=0;i<m;i++) cin>>arr[i];
        /// now find how many numbers are divisible by anyone of from array of m
        int set_sz=(1<<m);/// 2^m is the number of sets
        ll multiples_of_anyone_of_array=0;
        for(int mask=1;mask<set_sz;mask++)
        {
            ll Lcm=1ll;
            int bits=0;
            for(int i=0;i<m;i++)
            {
                if(((1<<i)&mask)) /// ith element is here
                {
                    bits++;/// how many elements we choose
                    Lcm=lcm(Lcm,arr[i]);///lcm of all elements of this set 
                }
            }
            ll num_till_n=n/Lcm;/// how many multiples of multiple within n ?
            if(bits&1)/// inclusion, number of elements are odd
                multiples_of_anyone_of_array+=num_till_n;
            else /// exclusion ,number of elements are even
                multiples_of_anyone_of_array-=num_till_n;
        }
        ll ans=n-multiples_of_anyone_of_array;
        cout<<ans<<endl;
    }
}
