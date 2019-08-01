#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll sum=0;


int main()

{
    ll a,b,x;
    cin>>a>>b;
    if(a==b)
    {
        cout<<"1"<<'\n';
        return 0;
    }
    while(true)
    {
        if(b==0)
        {
            break;
        }
        sum=sum+(a/b);
        x=a;
        a=b;
        b=x%b;
    }
    cout<<sum<<endl;
}
