
/// Time - 0.020s
/// Inclusion-Exclusion principle
/// Easy one 

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll arr[5];

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


ll solve(ll n)
{
       int set_sz=(1<<5);/// 2^m is the number of sets
        ll multiples_of_anyone_of_array=0;
        for(int mask=1;mask<set_sz;mask++)
        {
            ll mult=1ll;
            int bits=0;
            bool check=true;
            for(int i=0;i<5;i++)
            {
                if(((1<<i)&mask)) /// ith element is here
                {
                    bits++;/// how many elements we choose
                    mult=lcm(mult,arr[i]);///multiple of all prime elements of this set
                    if(mult>n) {check=false;break;}
                }
            }
            if(!check) continue;
            ll num_till_n=n/mult;/// how many multiples of multiple within n ?
            if(bits&1)/// inclusion, number of elements are odd
                multiples_of_anyone_of_array+=num_till_n;
            else /// exclusion ,number of elements are even
                multiples_of_anyone_of_array-=num_till_n;
        }
        return (n-multiples_of_anyone_of_array);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,a,d;
    int tc;
    cin>>tc;
    int caso=0;
    while(tc--)
    {
        cin>>n>>m>>a>>d;
        caso++;
        arr[0]=a;
        arr[1]=a+d;
        arr[2]=a+2ll*d;
        arr[3]=a+3ll*d;
        arr[4]=a+4ll*d;
        ll ans=solve(m)-solve(n-1);
        cout<<ans<<'\n';
    }
}
