#include<bits/stdc++.h>

using namespace std;

const int mx=1e8+1;

 typedef long long ll;

 bool prime[mx]={true};
 unsigned int prime_numbers[mx];

 void sieve()

 {
     for(int j=4;j<mx;j=j+2)
     {
         prime[j]=false;
     }
     for(int i=3;i*i<mx;i=i+2)
     {
         if(prime[i])
         {
             for(int j=i*i;j<mx;j=j+2*i)
             {
                 prime[j]=false;
             }
         }
     }
     prime[1]=false;
     ll sum=0;
     for(int i=2;i<mx;i+=1)
     {
         if(prime[i])
         {
             sum++;
         }
         prime_numbers[i]=sum;
     }
 }

int main()

{
    memset(prime,true,sizeof(prime));
    sieve();
    int t,x;
    while(scanf("%d",&x)&&x!=0){
    ll pi_x=prime_numbers[x];
    //cout<<pi_x<<endl;

    double pi=(double) pi_x;
    double lnx=(double)x/log((double)x);
    //cout<<lnx<<endl;
    double oo=fabs(pi-lnx);
    //cout<<oo<<endl;
    double ans=(oo/pi)*100;
    printf("%0.1lf\n",ans);
    }
    return 0;
}
