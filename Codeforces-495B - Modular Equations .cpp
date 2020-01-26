#include<bits/stdc++.h>

using namespace std;

//Basic modulo
//a mod x = b ; 0 = (b-a) mod x ; 0 = b mod x - a mod x ;(b-a)mod x=0 ; |b-a| should be divisible by that x greater than b.


int main()

{
    int a,b;
    cin>>a>>b;
    int x;
    if(a<b) cout<<"0"<<endl;
    else if(a==b) cout<<"infinity"<<endl;
    else
    {
        int m=a-b;
        int ans=0;
        for(int i=1;i<=sqrt(m);i++)
        {
            if(m%i==0){
            if((i*i)!=m)
            {
                if(i>b) ans++;
                if((m/i)>b) ans++;
            }
            else
            {
                if(i>b)
                {
                    ans++;
                }
            }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
