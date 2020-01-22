#include<bits/stdc++.h>

using namespace std;


// Counting problems and reduction of power series 

typedef unsigned long long ll;

ll mod=1000000007 ;

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

// 2^i+2^(n+i)+2^(2n+i)+2^(3n+i) +....+2^((k-1)n +i), for k copies 
// 2^i ( 2^0 + 2^n + 2^2n + 2^3n + ..... + 2^(k-1)n ) 
//  ( 2^0 + 2^n + 2^2n + 2^3n + ..... + 2^(k-1)n ) can be reduced to 2^(kn)-1 /(2^n -1 ) by reduction of power series 
// for every position i , 2^i * ( (2^(kn) -1 ) /(2^n -1 )) ,we have to calculate for all k copies .

int main()

{
    ios_base::sync_with_stdio(false);
    string s;
    ll k,S;
    cin>>s;
    cin>>k;
    ll n=s.size();
    ll a=(po(2ll,(k*n))-1ll+mod)%mod;// find ( 2^kn -1 )
    ll b=(po((po(2ll,n)-1ll+mod)%mod,mod-2)+mod)%mod;// mod Inverse (2^n -1 ) by fermats theorem 
    S=(a*b)%mod;// This should be found before 
    ll multi=0ll;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0'||s[i]=='5')
        {
            multi=(multi+po(2ll,i))%mod;//This the position where 5 or 0 placed 
        }
    }
    ll ans=(S*multi)%mod;//Total possible 
    ans=(ans+mod)%mod;
    cout<<ans<<endl;
    return 0;
}
