
/// Time - 0.040s
/// It is basically a derangement problem (counting problem of combinatorics ) 
/// You can go through a good article about it on shafayet vai website 
/// You can use that formula here cleverly for two state dp .


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

ll solve(int x,int y)
{
    if(x<0 || y<0) return 0ll;
    if(x==0) return fac[y];
    if(derrangement[x][y]!=-1) return derrangement[x][y];
    
    /// we can choose a position called (A) from x positions. 
    /// Now think a position B whose value is put on position A . and B comes from within other (x-1) places.
    /// Now think about two cases when B position holds the value of position A . ( solve(x-2,y) )
    /// another case is when B doesn't hold position of A so , now total two cases (solve(x-1,y)+solve(x-2,y))
    /// a position A has total available (x-1) without position of itself as that is correct position 
    
    ll think_about_left=(x-1ll)*(solve(x-2,y)+solve(x-1,y));

/// Now think a position B whose value is put on position A . and B comes from within other (y) places.
/// Now think about two cases when B position holds the value of position A . B and A positions are deranged now recur for( solve(x-1,y-1) ).
/// another case is when B doesn't hold position of A ,so we have to derange (y-1) and number of places are remaining x for deranging (y-)  

    ll think_about_right=(y)*(solve(x-1,y-1)+solve(x,y-1));
    ll res=(think_about_left+think_about_right)%mod;
    derrangement[x][y]=res;
    return derrangement[x][y];
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
         /// how many ways we can choose k from first m positions ?
         /// then derrangement technique for every ways of mCk
         ll ans = ( nCr[m][k] * solve(m-k ,n-m) ) %mod;
         printf("Case %d: %lld\n",caso,ans);
  }

    return 0;
}
