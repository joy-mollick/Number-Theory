
/// Time -   0.156 s
/// Light oj 1090 - Trailing Zeroes (II) 
/// Number theory + counting.

/// we will keep counting on how many 5 and 2 can be up to a particular number ?


#include<bits/stdc++.h>

using namespace std;

const int maxn=1000001;

int dp[maxn][2];

void counting()
{
    memset(dp,0,sizeof(dp));
   for(int i=2;i<maxn;i++)
   {
       int x_2=i;

       dp[i][0]=dp[i-1][0];
       while(x_2%2==0)
       {
           dp[i][0]++;
           x_2=x_2>>1;
       }

       int x_5=i;

       dp[i][1]=dp[i-1][1];
       while(x_5%5==0)
       {
           dp[i][1]++;
           x_5=x_5/5;
       }

   }
}

int main()

{
    counting();
    int T,n,r,p,q;
    cin>>T;
    for(int caso=1;caso<=T;caso++)
    {
        cin>>n>>r>>p>>q;

        int num_2=dp[n][0]-dp[r][0]-dp[n-r][0]+(dp[p][0]-dp[p-1][0])*q;
        int num_5=dp[n][1]-dp[r][1]-dp[n-r][1]+(dp[p][1]-dp[p-1][1])*q;

        printf("Case %d: %d\n", caso,min(num_2,num_5));
    }
    return 0;
}
