#include<bits/stdc++.h>

using namespace std;

const int mx=1e6+1;
typedef  long long ll;

ll phi[mx];
ll gcd_sum[mx];
ll ans[mx];

 void totient_sieve()
 {
    for (int i=1;i<mx;i++)
        phi[i]=i;

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

 void gcd_sum_sieve()

 {
     totient_sieve();
     for(ll i=1;i<mx;i++)
     {
         for(ll j=i;j<mx;j=j+i)
         {
             gcd_sum[j]+=1ll*i*phi[j/i];
         }
     }
 }

 void final_cal()
 {
     gcd_sum_sieve();

    for(int i=1;i<mx;i++){
        gcd_sum[i]=gcd_sum[i]-i;}

    ll sum=0;
    ans[0]=0;
    for(int j=1;j<mx;j++)
    {
        sum=sum+gcd_sum[j];
        ans[j]=sum;
    }
 }

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    final_cal();
    ll n;
    while(cin>>n && n!=0)
    {
        cout<<ans[n]<<'\n';
    }
}
