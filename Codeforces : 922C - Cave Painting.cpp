/// Codeforces : 922C - Cave Painting.
/// Category : number theory .

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,k;
    cin>>n>>k;

    bool flag=false;

    /// when Yes ,then k is so small
    /// So, iteration will not cross Time Limit
    for( ll i=1;i<=k;i++)
    {
        if(n%i!=i-1)
        {
            flag=true;
            break;
        }
    }

    if(flag) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;

    return 0;
}
