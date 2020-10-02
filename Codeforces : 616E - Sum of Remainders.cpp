
/// Codeforces : 616E - Sum of Remainders.
/// Category : number theory + series reduction .

/// Nice one man !! 

/*

 n mod i = n - floor(n/i )* i, which converts f(n,m) into the following expression:
  f(n,m) = n mod 1+ n mod 2 + …n mod m
　　　     = n - floor(n/1) * 1 + n - floor(n/2) * 2+… n - floor(n /m) *n
         = n * m - sum(floor(n/i) * i) where i = 1~ m .
  Next we take n= 9 and k = 4 as an example to analyze n/i:
　　4/1　4/2　4/3　4/4　4/5　4/6　4/7　4/8　4/9
　　４　   ２　　１　  １　  ０　　０　  ０　　０　  ０

The following sum(floor(n/i) * i) = 4 * 1 + 2 * 2 + 1 *(3+ 4)+ 0 *(5+6+7+8 +9),

the parentheses are all arithmetic progressions it is obvious,
which can be handled by Gaussian summation.
So we need to know which consecutive quotients are the same?
Then, in the current i number, find the largest x that n/i wants to be equal, so that n / x = n / i.
Therefore x = n / floor(n / i), in order to avoid the calculated x exceeds m .
So accurately x = min(n / floor(n/i) , m);
So that the number between i~ x can be summed with Gaussian.

*/


#include<bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;

typedef long long ll;

const ll mod=1e9+7;


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

     ll n,m,ans=0,sum=0;
     cin>>n>>m;
     ans=((m%mod)*(n%mod))%mod;
     ll up=min(m,n);
    for(ll i=1,r;i<=up;i=r+1)
    {
        r=min(n/(n/i),up);
    	ll st=r+i,num=r-i+1;
    	if(st&1ll)  num/=2ll;
    	else     st/=2ll;
    	sum=(sum+(st%mod)*(num%mod)%mod*((n/i)%mod))%mod;
    }

    ans=((ans-sum)%mod+mod)%mod;

    cout<<ans<<endl;

	return 0;
}
