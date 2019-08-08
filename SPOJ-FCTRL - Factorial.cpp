#include <bits/stdc++.h>
using namespace std;

int findTrailingZeros(int n)
{
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5)
        count += (n / i);

    return count;
}

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<findTrailingZeros(n)<<endl;
    }
}
