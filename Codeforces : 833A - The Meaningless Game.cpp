/// Codeforces : 833A - The Meaningless Game.
/// Category : number theory + greedy.

/// it is very obvious that when two numbers then if it is possible.
/// Then (a*b) makes form of (pi1*pi2*pi3...)^3 .

#include<bits/stdc++.h>

using namespace std;

typedef  long long ll;

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin>>tc;

    while(tc--)
    {
    ll a,b;
    cin>>a>>b;
    ll pro=(a*b);
    ll c=cbrt((long double)(pro));

    if( c*c*c!=pro) cout<<"No"<<'\n';
    /// c*c*c==pro
    /// it can be not sure that we get answer
    /// think about 27 and 1 , 27*1=3^3 ,but this format is not right for game.
    else if(a%c==0 && b%c==0) cout<<"Yes"<<'\n';
    else cout<<"No"<<'\n';
    }

    return 0;
}
