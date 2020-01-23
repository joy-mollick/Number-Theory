#include<bits/stdc++.h>

using namespace std;


// Basic probability and series reduction problem

typedef unsigned long long ll;

ll mod=1000000007 ;
/*

ll po(ll a,ll b)
{
   ll ans=1ll;
   while(b)
   {
       if(b&1)
        ans=(ans*a)%mod;
       b=b>>1;
       a=(a*a)%mod;
   }
   return (ans%mod);
}
*/

// Even length doesn't increase the distinct numbers but odd length increases 

int main()

{
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    ll ans=1ll;
    ll res;
    ll times=0;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]-'0'+s[i+1]-'0'==9)
        {
            times++;
        }
        else
        {
            if(times%2==0)
            {
                times++;
                ans=ans*(times+1)/2;
            }
            times=0;
        }
    }
    if(times!=0&&times%2==0)
    {

                times++;
                ans=ans*(times+1)/2;
    }
    cout<<ans<<endl;
    return 0;
}
