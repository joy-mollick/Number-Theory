/// Time-0.66s

#include<bits/stdc++.h>

 using namespace std;

 const int mx=1e6+1;

 typedef long long ll;

 ll phi[mx];

 void totient_sieve()

 {
     for(int i=1;i<mx;i++)
     {
         phi[i]=i;
     }
     for(int p=2;p<mx;p++)
     {
         if(phi[p]==p)
         {
             phi[p]=p-1;
             for(int i=2*p;i<mx;i=i+p)
             {
                 phi[i]=(phi[i]/p)*(p-1);
             }
         }
     }
     phi[1]=0ll;
 }

 ll totient(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

 int main()

 {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     totient_sieve();
     ll n;
     while(cin>>n&&n!=0ll)
     {
         if(n>=mx)
            cout<<totient(n)<<endl;

         else cout<<phi[n]<<endl;
     }
     return 0;
 }
