
/// Time - 0.491s
/// Light oj 1007 - Mathematically Hard 
/// Number theory


#include<bits/stdc++.h>

using namespace std;

const int maxn = 5000001;

unsigned long long phi[maxn];

void Phi()
{
	 for (int i=1; i<maxn; i++)
        phi[i] = i;

         // Compute other Phi values
    for (int p=2; p<maxn; p++)
    {
        // If phi[p] is not computed already,
        // then number p is prime
        if (phi[p] == p)
        {
            // Phi of a prime number p is
            // always equal to p-1.
            phi[p] = p-1;

            // Update phi values of all
            // multiples of p
            for (int i = 2*p; i<maxn; i += p)
            {
            phi[i] = (phi[i]/p) * (p-1);
            }
        }
    }

    for(int i=0;i<maxn;i++) {phi[i]=phi[i]*phi[i];phi[i]+=phi[i-1];}
    ///for(int i=1;i<maxn;i++) phi[i]+=phi[i-1];
}


int main()

{
    Phi();
    int a,b;
    int T;
    int cas=0;
    scanf("%d",&T);

    while(T--)
    {
        cas++;
        scanf("%d%d",&a,&b);
        unsigned long long ans;
        ans=phi[b]-phi[a-1];
	    printf("Case %d: %llu\n", cas, ans);

    }
    return 0;
}
