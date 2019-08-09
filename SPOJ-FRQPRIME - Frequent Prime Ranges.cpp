#include<bits/stdc++.h>

using namespace std;

typedef  long long int ll;

const int mx=200026;

int prime[mx];

void sieve()
 {
    for(int i=4;i<mx;i=i+2)
    {
        prime[i]=0;
    }
    for(int i=3;i*i<mx;i=i+2)
     {
         if(prime[i]==1)
         {
             for(int j=i*i;j<mx;j=j+2*i)
             {
                 prime[j]=0;
             }
         }
     }
     prime[2]=1;
     prime[0]=0;
     prime[1]=0;
 }


int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0;i<mx;i++) prime[i]=1;
    sieve();
    int k,n,t;
   scanf("%d", &t);
    while(t --){
        scanf("%d%d", &n, &k);
        if(k == 0){
            printf("%lld\n", 1LL * n * (n - 1) / 2);
            continue;
        }
        int prms = 0, right = 1;
        long long ans = 0;
        for(int left = 2; left <= n; left ++){
            while(right < n && prms < k){
                ++right;
                prms += prime[right];
            }
            if(prms >= k){
                ans += n - right + 1;}
            prms -= prime[left];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
