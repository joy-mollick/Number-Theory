
/// Time -0.000s
/// it is basically inclusion and exclusion problem
/// using the technique of bitmask

/*

 Considering this problem as chessboard ,in how many ways we can arrange the chessboard containing k pieces ,and the four pieces are must on
 the four sides on chessboard . Now the question is little bit easy from former one.

 Now first calculate the number of ways we can arrange k pieces on n*m chessboard . this is (n*m)C(k)
 now we have to subtract the cases where the the four sides does not contain exact 4 pieces on their sides.Here we need inclusion-Exclusion

set A: no piece not in the first line;  1st row
Set B: no piece not in the last line;   nth row
Set C: no piece in the first column;    1st column
Set D: no piece not in the last column; mth column

So , (A U B U C U D) = the set contains counting where there are no 4 pieces must on four sides ( possibly may be one side or two sides or three sides or four sides are being missed with pieces )
So our final answer is  (n*m)C(k) - (A U B U C U D) .
Now how will you calculate (A U B U C U D) ? Its totally up to you to exercise.
*/

#include<bits/stdc++.h>

using namespace std;

const int mod=1000007;

int nCr[501][501];

void cal()
{
    /// base case nC0=nCn=1
    /// nCr = (n-1)c(r) + (n-1)c(r-1) ,our formula
     int i, j;
    for (i = 0; i <=500; i++)
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

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cal();
    int m,n,k,tc;
    cin>>tc;
    int cas=1;
    while(tc--)
    {
        cin>>m>>n>>k;
        int total_ways=nCr[m*n][k]%mod;
        int sets=0;/// this will calculate (A U B U C U D) .
        for(int mask=1;mask<(1<<4);mask++) /// total distinct four cases for a,b,c,d sets so ,2^4
        {
            int bits=0;
            int newm=m;/// number of rows
            int newn=n;/// number of columns
            if(mask&(1<<0))/// assuming this as set of a
            {
                bits++;
                newm--;/// number of rows will be decreased by one , as we will not any piece on first row ,so count without first row
            }
            if(mask&(1<<1)) /// assuming this as set of b
            {
                bits++;
                newm--;/// number of rows will be decreased by one , as we will not any piece on last row ,so count without last row
            }
            if(mask&(1<<2)) /// assuming this as set of c
            {
                bits++;
                newn--;/// number of columns will be decreased by one , as we will not any piece on first column ,so count without first column
            }
            if(mask&(1<<3)) /// assuming this as set of d
            {
                bits++;
                newn--;/// number of columns will be decreased by one , as we will not any piece on last column ,so count without last column
            }

            if(bits&1) sets=(sets+nCr[newn*newm][k])%mod;
            else sets=(((sets-nCr[newn*newm][k])%mod)+mod)%mod;/// take care of during subtraction
        }
        total_ways=((total_ways-sets)%mod+mod)%mod;/// take care of during subtraction
        cout<<"Case "<<cas++<<": "<<total_ways<<'\n';
    }
    return 0;
}
