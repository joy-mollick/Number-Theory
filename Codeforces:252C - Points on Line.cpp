/// Codeforces:252C - Points on Line.
/// Category: binary search + combinatorics.(medium)

/// But I didn't use binary search.

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()

{
    ll n,d,p;

    cin>>n>>d;

    vector<ll>point(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>point[i];
    }

    ll res=0ll;
    int right=1;
    ll nums;
    /// fixed right point with whom we ca make triplets by using all numbers before rght.
    for(int i=1;i<=n;i++)
    {
       while(right<n && point[right+1]-point[i]<=d) right++;
       nums=(right-i);
       res+=(nums*(nums-1ll))/2ll;
    }

    cout<<res<<endl;

   return 0;
}
