#include<bits/stdc++.h>

using namespace std;

const int mx=1e7;
typedef unsigned long long ll;

int min_prim[mx];
bool prime[mx];
ll nw_fibo[mx];

 void sieve()
 {
     for(int i=2;i<mx;i++)
     {
         if(prime[i]==true)
         {
             for(int j=i;j<mx;j=j+i)
             {
                 if(min_prim[j]==0)
                 {
                     min_prim[j]=i;
                     prime[j]=false;
                 }
             }
         }
     }
     min_prim[0]=0;
     min_prim[1]=0;
 }
 void pre_cal()
 {
     sieve();
     ll sum=0;
     for(int i=0;i<mx;i++)
     {
         sum=sum+min_prim[i];
         nw_fibo[i]=sum;
     }
 }
int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(prime,true,sizeof(prime));
    pre_cal();
    int t,a;
    cin>>t;
    while(t--)
    {
        cin>>a;
        cout<<nw_fibo[a]<<endl;
    }
}
