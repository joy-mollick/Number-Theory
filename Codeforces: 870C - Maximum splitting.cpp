
/// Codeforces: 870C - Maximum splitting .
/// Category: greedy + number theory (medium).


/// it is greedy to make maximum fours(4) to make n.
/// if remainder is 1 like say 21 ,then it can be like 9+(12/4) = 9+4+4+4.
/// if remainder is 2 like say 22 ,then it can be like 6+(16/4) =6+4+4+4+4.
/// if remainder is 3 like say 23 ,then it can be like 15+(8/4) =6+9+4+4.

#include<bits/stdc++.h>

using namespace std;

int fun(int n)
{
    if (n < 4)
        return -1;

    int rem = n % 4;

    if (rem == 0)
        return n / 4;

    // Case1:   if the remainder is 1
    if (rem == 1)
    {
        if (n < 9)
            return -1;

        return (n - 9) / 4 + 1;
    }

    // Case 2: When remainder is 2
    if (rem == 2)
        return (n - 6) / 4 + 1;

    // Case 3:When rem is 3

    if (rem == 3)
    {
        if (n < 15)
            return -1;

        return (n - 15) / 4 + 2;
    }
}



int main()

{
    int tc,n;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        cout<<fun(n)<<"\n";
    }
    return 0;
}
