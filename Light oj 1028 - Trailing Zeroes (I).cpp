
/// Time -  0.330s
/// Light oj 1028 - Trailing Zeroes (I) 
/// Number theory + prime factorization


#include<bits/stdc++.h>

using namespace std;

const int maxn=1000001;

bool vis[maxn];
long long prime[maxn];
int p=0;

void Prime()
{
    for(int i=0;i<maxn;i++) vis[i]=false;
    for(long long i=2;i<maxn;i++)
    {
        /// prime
        if(!vis[i])
        {
            for(long long j=i*i;j<maxn;j=j+i)
            {
                vis[j]=true;
            }
            prime[p++]=i;/// storing prime numbers
        }
    }
}

long long count_of_div(long long N)
{
    long long ans=1ll;
    for(int i=0;i<p && prime[i]*prime[i]<=N;i++)
    {
        long long cnt=0ll;
        while(N%prime[i]==0)
        {
            cnt++;
            N=N/prime[i];
        }
        ans=(ans*(cnt+1ll));
    }
    if(N>1ll) ans=ans*2ll;

        return ans;
}

int main()

{
    Prime();
    int T;
    long long n;
    cin>>T;
    for(int caso=1;caso<=T;caso++)
    {
        scanf("%lld",&n);
        long long res=count_of_div(n)-1ll;
        printf("Case %d: %lld\n", caso,res);
    }
    return 0;
}
