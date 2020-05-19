
/// Time - 0.025s
/// It is basically a derangement problem (counting problem of combinatorics )
/// You can go through a good article about it on shafayet vai website
/// It is more faster than recursive code 


#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const int mx=1005;

ll mod=1000000007;

ll fac[mx];
ll nCr[mx][mx];
ll derrangement[mx][mx];/// how many numbers are not in their original positions

void cal()
{
    /// base case nC0=nCn=1
    /// nCr = (n-1)c(r) + (n-1)c(r-1) ,our formula
     int i, j;
    for (i = 0; i < mx; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                nCr[i][j] = 1ll; /// nC0= nCn = 1

            else /// nCr = (n-1)c(r) + (n-1)c(r-1)
                nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j])%mod;
        }
    }
}

/// calculating factorials
void pre(){
    fac[0] = 1ll;
    for(int i = 1; i <mx; i++) {fac[i] = (fac[i-1]*i)%mod;}
}

int main()
{
    pre();
    cal();
    memset(derrangement,-1,sizeof(derrangement));
    int ts,m,k,n,caso;
    scanf("%d", &ts);
    for ( caso = 1 ; caso <= ts ; caso++ )
  {
         scanf("%d %d %d",&n , &m , & k );
         int our_fixed_points=m-k;/// k are initial positions but m-k are not so we have find out those derangements
         int our_permutable_positions =n-k;/// k are on their positions fixed , so we can permutate other positions
         /// here we will find answer considering only m-k points
         int derangements_for_fixed_points=fac[our_permutable_positions];
         for(int i=1;i<=our_fixed_points;i++)
         {
             if(i%2==1)
             {
                 derangements_for_fixed_points-=(nCr[our_fixed_points][i]*fac[our_permutable_positions-i])%mod;
             }
             else
             derangements_for_fixed_points+=(nCr[our_fixed_points][i]*fac[our_permutable_positions-i])%mod;

             derangements_for_fixed_points=(derangements_for_fixed_points+mod)%mod;
         }
         ll tot_ways_of_choosing_k_positions=nCr[m][k];
         derangements_for_fixed_points=(derangements_for_fixed_points*tot_ways_of_choosing_k_positions)%mod;
         printf("Case %d: %llu\n",caso,derangements_for_fixed_points);
  }

    return 0;
}
