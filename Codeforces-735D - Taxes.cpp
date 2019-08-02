#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

bool prime(ll n)

{
    if (n == 0 || n == 1)
        return false;

    for(ll i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}


int main()

{
    ll n;
    cin>>n;
    if(prime(n)||n==1)
    {
        cout<<"1"<<endl;
    }
    else if(n%2==0)
    {
        cout<<"2"<<endl;
    }
    else{
            if(prime(n-2))
        cout<<"2"<<endl;

    else cout<<"3"<<endl;
    }
}
