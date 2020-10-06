/// Codeforces : 1342C - Yet Another Counting Problem.
/// Category : number theory + greedy.


/// assuming a is small than b i.e. a<b
/// for any x less than b, (x%a)%b=(x%a)
/// for any x less than b, (x%b)%a=(x%a)
/// Now think about lcm(a,b)=c.
/// X = c*k + x ,where x is in the 0 to b-1.
/// (X%a)%b=  (c*k + x)%a%b = (x%a)%b=(x%a)
/// (X%b)%a=  (c*k + x)%b%a = (x%b)%a=(x%a)
/// we have to avoid such X , which is made of lcm(a,b) + i , where i is in 0 to (b-1)
/// Other X will be answers.

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

/// this will return number of such numbers from 1 to r.
ll finds(ll r,ll a,ll b)
{
   ll lcm=(a*b)/__gcd(a,b);
   ll times=r/lcm;
   ll remainder=r%lcm+1;
   ll tot=times*b+min(remainder,b);
   return (r-tot);
}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a,b,q,tc,l,r;
    cin>>tc;

    while(tc--)
    {
        cin>>a>>b>>q;
        if(a>b) swap(a,b);
        while(q--)
        {
            cin>>l>>r;
            cout<<finds(r,a,b)-finds(l-1,a,b)<<" ";
        }
        cout<<endl;
    }

    return 0;
}
