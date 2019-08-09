#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool prme_fct(ll n)
{
    int count=0;
    while(n%2==0)
    {
        n=n>>1;
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
            if(i%4==3)
            {
                if(count%2!=0)
                {
                    return false;
                }
            }
        }

    }
    if(n>1)
    {
       if(n%4==3){
        return false;}
    }

    return true;
}

int main()
{
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if((prme_fct(n)))
        {
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}
