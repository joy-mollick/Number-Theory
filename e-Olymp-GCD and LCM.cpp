#include<bits/stdc++.h>

using namespace std;

const int mx=2000001;
typedef  long long ll;



int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll A,B;
    scanf("%lld%lld",&A,&B);
    ll cont=0ll;
    ll val=A*B;
    for(ll i=1;i*i<=val;i++)
    {
        if(val%i==0){
        ll gcd=__gcd(i,val/i);
        ll lcm=val/gcd;
        if(gcd==A && lcm==B)
        {
            cont++;
        }
        }
    }
    printf("%lld\n",2ll*cont);
}
