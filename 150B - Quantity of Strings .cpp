#include<bits/stdc++.h>

using namespace std;


// Counting Pairs

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


int main()

{
    ios_base::sync_with_stdio(false);
    ll n,m,k;
    cin>>n>>m>>k;
    if(n==k)// how much palindrome of k length with m options
    {
        cout<<po(m,(n+1ll)/2ll)<<endl;
    }
    else if(k==1||k>n)//how much possible for n position with m options ,m^n
    {
        cout<<po(m,n)<<endl;
    }
    else if(k%2==0)//how many possible strings for first positions with m positions ,m
    {
        cout<<m<<endl;
    }
    else // how many possible strings for first and second positions ,m*m
    {
        cout<<po(m,2ll)<<endl;
    }
    return 0;
}
