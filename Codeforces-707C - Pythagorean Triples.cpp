#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

// According to euclid's theorem regarding pythagoreas triplet 


int main()

{
    ll x,a,b,c,n,m;
    cin>>x;
    if(x&1)
    {
         m= (x+1)>>1;
         n=x-m;
         a=(m*m-n*n);
         b=2ll*m*n;
         c=m*m+n*n;
    }
    else
        {
            ll mn=x>>1;
            m=mn;
            n=1;
            a=m*m-n*n;
            b=2ll*m*n;
            c=m*m+n*n;
        }
     if(a>0&&b>0&&c>0){
            if(a!=x) cout<<a<<" ";
             if(b!=x) cout<<b<<" ";
            if(c!=x)  cout<<c<<" ";
     }

        else cout<<"-1"<<endl;
}

