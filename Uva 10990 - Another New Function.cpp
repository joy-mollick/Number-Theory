
/// Time-0.140s

#include<bits/stdc++.h>

 using namespace std;

 const int mx=2000001;/// max-range

 typedef long long ll;

 ll ans[mx];

 ll phi[mx];

 ll res[mx];

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
 void cal()
 {
    ans[2]=1ll;
    for(int i=3;i<mx;i++)
    {

        ll x=phi[i];
        ll cnt=1ll;
        while(x>1&&ans[x]==0)
        {
            x=phi[x];
            cnt++;
        }
        ans[i]=cnt+ans[x];
    }
 }

 void full()
 {
     ll sum=0ll;
     for(int i=0;i<mx;i++)
     {
         sum+=ans[i];
         res[i]=sum;
     }
 }

 int main()

 {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     totient_sieve();
     cal();
     full();
     ll n,m,tc;
     cin>>tc;
     while(tc--)
     {
         cin>>m>>n;
         cout<<(res[n]-res[m-1])<<endl;
     }
     return 0;
 }
