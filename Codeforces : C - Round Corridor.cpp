/// Codeforces : C - Round Corridor.
/// Category : number theory + gcd.


#include<bits/stdc++.h>

using namespace std;

typedef  long long ll;

ll __gcd(ll a, ll b)
{
    if (b == 0)
        return a;

    return __gcd(b, a % b);

}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,m,q;
    cin>>n>>m>>q;

    ll sx,sy,ex,ey,s;
    ll gcd=__gcd(n,m);
    /// how much number are in every sector
    ll nn=n/gcd;
    ll mm=m/gcd;
    while(q--)
    {
        cin>>sx>>sy>>ex>>ey;
        if(sx==1)
        {
           s=(sy-1)/nn;
        }
        else
        {
            s=(sy-1)/mm;
        }

        if(ex==1)
        {
            if((ey-1)/nn==s)
			cout<<"YES"<<endl;
			else
			cout<<"NO"<<endl;
        }
        else
		{
			if((ey-1)/mm==s)
			cout<<"YES"<<endl;
			else
			cout<<"NO"<<endl;
		}
    }

    return 0;
}
