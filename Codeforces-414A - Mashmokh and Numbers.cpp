#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const int extra=1e9;

int main()

{
    int n,k;
    cin>>n>>k;
    if((n/2)>k)
    {
        cout<<"-1"<<endl;
    }
    else if(n==1&&k==0)
    {
        cout<<"1"<<endl;
    }
    else if(n==1)
    {
        cout<<"-1"<<endl;
    }
    else{
         int times=(n-2)/2;
        int x=(k-times);
          cout<<x<<" "<<(2*x)<<" ";
          int i=(2*x)+1;
          while(times--)
          {
              cout<<i<<" "<<(i+1)<<" ";
              i=i+2;
          }
          if(n&1)
          {
              cout<<extra<<endl;
          }
    }

}
