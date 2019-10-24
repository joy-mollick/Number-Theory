#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll arr[101];

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


ll findlcm( int n)
{
    ll ans = arr[0];
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
                (gcd(arr[i], ans)));

    return ans;
}

// Driver Code
int main()
{
    int tc,n;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
        }
        printf("%lld\n", findlcm( n));
    }
    return 0;
}
