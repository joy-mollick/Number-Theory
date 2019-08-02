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
    if(n==3)
    {
        cout<<"1"<<endl;
        cout<<"3"<<endl;
        return 0;
    }
    else if(n==5)
    {
        cout<<"2"<<endl;
        cout<<"3 2"<<endl;
        return 0;
    }
     cout<<3<<endl;
     cout<<"3 ";
     ll k=n-3;
      for(ll i=2;i<=k;i++)
      {
          if(prime(i)&&(prime(k-i)))
          {
              cout<<i<<" "<<(k-i)<<endl;
              break;
          }
      }
    }

