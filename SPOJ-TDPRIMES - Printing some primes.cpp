
/// Time-1.10s
/// Using sieve algorithm

#include<bits/stdc++.h>

 using namespace std;

 typedef long long ll;

 const int mx=100000000;

 bool prime[mx+1];/// for normal sieve

 void normal_sieve()
 {
      /// normal sieve O(nloglogn) complexity
     memset(prime,true,sizeof(prime));///mark them as true.
     for (ll i = 2; i <= mx; ++i) {
        if (prime[i]) {
            for (ll j = i * i; j <= mx; j += i)
                prime[j] = false;
        }
    }
 }

 int main()
 {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     normal_sieve();
     int cont=1;/// 2 is already counted
     cout<<"2"<<'\n';
     for(int i=3;i<=mx;i+=2)
     {
         if(prime[i])
         {
             cont++;
             if(cont%100==1)
             {
                 cout<<i<<'\n';
             }
         }
     }
     return 0;
 }
