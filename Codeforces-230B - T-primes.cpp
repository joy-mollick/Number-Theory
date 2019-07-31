
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

const int mx=1e6+1;

bool prime[mx];

void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=mx; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=mx; i += p)
                prime[i] = false;
        }
    }
    prime[2]=true;
}
bool square(ll p)
{
    ll sq=sqrt(p);
    if(sq*sq==p)
        return true;
    else
        return false;
}
int main()

{
    SieveOfEratosthenes();
    int t;
    cin>>t;
    ll m;
    while(t--)
    {
        cin>>m;
        ll pr=sqrt(m);
        int in=(int)pr;
        if((square(m)&&prime[in]&&m!=1))
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
