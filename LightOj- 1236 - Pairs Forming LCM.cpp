/// Time- 0.439s
/// LightOj- 1236 - Pairs Forming LCM
/// Number theory


/// A nice question 
/// You want p1^a * p2^b 
/// keep one side all time p1^a 
/// then like 2^2 . Then 
/// 2^2 , 2^0 : 2^2 ,2^1 : 2^2 , 2^2  , same pair will be reversed 
/// Then total will be (2*e + 2 ) -1 . e is the number of that factor. 


#include<bits/stdc++.h>

using namespace std;

const int mx=10000001;
int prime[1000001];
bool vis[mx];
int m;

void Prime()
{
        long long i,j;
    memset(vis,0,sizeof(vis));
    memset(prime,0,sizeof(prime));

         for(i=2;i<mx;i++) //MAXN here is the number of all numbers
    {
        if(vis[i]==0)
        {
            prime[m++]=i;
            for(j=2*i;j<mx;j+=i)
            {
                vis[j]=1;
            }
        }
    }

}

long long factor_cnt(long long n)
{
    long long sum=1;
    int i=0;
    int cont=0;

    while((long long)prime[i]*prime[i]<=n && i<m)
    {
        cont=0;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                n=n/prime[i];
                cont++;
            }
        }

        if(cont!=0) sum=sum*(2ll*cont+1ll);
        i++;
    }

    if(n>1) {sum=sum*(3ll);}

    /// twice count will be divided by two
    /// and another one which is equal in both side
    return (sum/2ll+1ll);
}

int main()

{
    Prime();
    int T;
    scanf("%d",&T);
    for(int caso=1;caso<=T;caso++)
    {
       long long n;
       int cont=0;
       scanf("%lld",&n);
       printf("Case %d: %lld\n",caso,factor_cnt(n));
    }
    return 0;
}
