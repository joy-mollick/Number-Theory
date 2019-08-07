#include<bits/stdc++.h>

using namespace std;

const int mx=1e7;
typedef unsigned long long ll;

 void sieve(ll n)
 {
    ll count=0;
    while(n%2==0)
    {
        count++;
        n=n>>1;
    }
    if(count>0)
    {
        cout<<"2^"<<count<<" ";
    }
    for(ll i=3;i*i<=n;i=i+2)
    {
        count=0;
        while(n%i==0)
        {
            count++;
            n=n/i;
        }
        if(count>0)
        {
            cout<<i<<"^"<<count<<" ";
        }
    }
    if(n>2)
    {
        cout<<n<<"^"<<1;
    }
 }

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    while(cin>>n && n!=0)
    {
        sieve(n);
        cout<<'\n';
    }
}
