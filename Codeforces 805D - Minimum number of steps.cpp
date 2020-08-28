
/// Codeforces: 805D - Minimum number of steps.
/// Category: greedy + combinatorics + observation.

/*
  ab will be replaced by bba, which implies all a will go at the last. and total 2^n b will be at the first,where n is the number of a before b.
  So, the number of steps are (2^n) -1 (one extra b is here at first time , so step is [ number of b at first (2^n) , minus(-) 1] ) ,for every na + one b ,structure .
  And in each process a will not increase , so this count of a will be
  taken into account when next b will found . precalculate pow of 2 ,previously.
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod=1e9+7;

const int mx=1000001;

ll po[mx];

int main()

{
   ll mul=1ll;
   /// pre-calculation.
   po[0]=1ll;
   for(ll i=1;i<mx;i++)
   {
       mul*=2ll;
       mul%=mod;
       po[i]=mul;
   }
   string s;
   cin>>s;
   ll cont_a=0ll;
   int sz=(int)s.size();
   ll ans=0ll;
   for(int i=0;i<sz;i++)
   {
       if(s[i]=='a') cont_a++;
       else
       {
           ans=(ans+po[cont_a]-1ll)%mod;
       }
   }
   cout<<ans<<endl;
   return 0;
}
