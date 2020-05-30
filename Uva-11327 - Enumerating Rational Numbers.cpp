
/// Time-0.090s
/// Totient Function and binary_search 
/// Nice one 

#include<bits/stdc++.h>

 using namespace std;

 typedef long long ll;

 const int mx=200003;

 int phi[mx];
 ll prefix_sum_of_totient[200003];

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
 }


void cal()
{
    ll sum=0ll;
    prefix_sum_of_totient[0]=0ll;
    prefix_sum_of_totient[1]=2ll;
    for(int i=2;i<mx;i++)
    {
        prefix_sum_of_totient[i]=prefix_sum_of_totient[i-1]+(ll)phi[i];
    }
}

 int main()

 {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     totient_sieve();
     cal();
     ll n;
     while(cin>>n && n!=0ll)
     {
         if(n==1)
         {
             cout<<"0"<<"/"<<"1"<<endl;continue;
         }
         else if(n==2)
         {
             cout<<"1"<<"/"<<"1"<<endl;continue;
         }
         else{

         ll denominator=lower_bound(prefix_sum_of_totient,prefix_sum_of_totient+200003,n)-prefix_sum_of_totient;
         n=n-prefix_sum_of_totient[denominator-1];
         ll i;
         ll cont=0;
         for(i=1;;i++)
        {
          if(__gcd(i,denominator)==1)
           cont++;

           if(cont==n) break;
        }
         cout<<i<<"/"<<denominator<<endl;
         }
     }
     return 0;
 }
