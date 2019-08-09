#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

ll pow(ll a,ll p)
{
    ll sum=1;
    while(p)
    {
        if(p%2ll==1ll)
        {
            sum=sum*a;
        }
        p=p>>1ll;
        a=a*a;
    }
    return sum;
}


int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,sum=0;
    cin>>n;
    sum=pow(2,n+1)-2ll;
    cout<<sum<<endl;
}
