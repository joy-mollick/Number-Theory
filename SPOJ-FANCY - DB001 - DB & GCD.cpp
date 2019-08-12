

#include <bits/stdc++.h>

using namespace std;

int main()

{

    int tc,n,a,k;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        k=n;
        cin>>a;
        int gcd=a;
        n=n-1;
        while(n--)
        {
            cin>>a;
            gcd=__gcd(gcd,a);
        }
        if(gcd==1)
        {
            cout<<k<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}
