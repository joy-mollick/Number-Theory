#include<bits/stdc++.h>

using namespace std;

const int mx=1e6+1;

 typedef long long ll;

 ll phi[mx];
 ll lcm_sum[mx];

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

 void sum()
 {
     for(int i=1;i<mx;i++)
     {
        for(int j=i;j<mx;j=j+i)
        {
            lcm_sum[j]+=(i*phi[i]);
        }
     }
 }
int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    totient_sieve();
    phi[1]=1;
    sum();
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll res=lcm_sum[n]+1;
        res=(res*n);
        res=res>>1;
        cout<<res<<'\n';
    }
    return 0;
}
