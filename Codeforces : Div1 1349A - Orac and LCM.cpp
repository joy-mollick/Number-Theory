
/// Codeforces : Div1 1349A - Orac and LCM
/// Category : number theory + observation .


/// Here , we use a formula that
/// Think about a,b,c three numbers
/// We have to find gcd{lcm(a,b),lcm(a,c),lcm(b,c)}
/// Now ,if we separate the pairs with a ->lcm(a,b) lcm(a,c)
/// then gcd( lcm(a,b),lcm(a,c)) = ?
/// gcd ( a*b / gcd(a,b) , a*c / gcd(a,c) )
/// a * gcd( b / gcd(a,b) , c / gcd(a,c) )
/// a * gcd(b,c) / gcd(a,b,c)
/// ai * suff_gcd[i+1] / __gcd( suff_gcd[i+1] ,ai )
/// so separately find gcd of each number of the array.

#include<bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;
typedef long long ll;
ll a[maxn],suf[maxn];


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    suf[n]=a[n];
    for(int i=n-1;i>=1;i--){
        suf[i]=__gcd(suf[i+1],a[i]);
    }
    ll ans=a[1]*suf[2]/__gcd(a[1],suf[2]);
    for(int i=2;i<=n-1;i++)ans=__gcd(ans,a[i]*suf[i+1]/__gcd(a[i],suf[i+1]));
    cout<<ans<<"\n";

	return 0;
}
