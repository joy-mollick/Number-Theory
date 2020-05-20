
/// Time - 0.000s
/// It is basically a derangement problem (counting problem of combinatorics )
/// You can go through a good article about it on shafayet vai website
/// I used recursive code , as it can implemented easily .

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const int mx=21;

ll mod=1000000007;

ll fac[mx];
ll nCr[mx][mx];
ll derangement[mx];/// how many numbers are not in their original positions

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
                nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]);
        }
    }
}

/// calculating factorials
void pre(){
    fac[0] = 1ll;
    for(int i = 1; i <mx; i++) {fac[i] = (fac[i-1]*i);}
}

ll derange(ll n)
{
    /// three base cases
    if(n==0) return 1ll;
    else if(n==1) return 0ll;
    else if(n==2) return 1ll;
    if(derangement[n]!=-1) return derangement[n];
    ll res=(n-1)*(derange(n-1)+derange(n-2));
    derangement[n]=res;
    return derangement[n];
}

int main()
{
    pre();
    cal();
    memset(derangement,-1,sizeof(derangement));
    int ts,caso;
    ll n,m;
    while (scanf("%llu %llu",&n , &m )!=EOF)
  {
         ll ans=0ll;
         for(int i=0;i<=m;i++)
         {
             ans+=(nCr[n][i]*derange(n-i));
         }
         printf("%llu\n",ans);
  }

    return 0;
}
