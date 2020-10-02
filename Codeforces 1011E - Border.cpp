/// Codeforces : 1011E - Border
/// Category : number theory + observation .
 
 
/*
 
    At first think about for two kinds bank notes.
    a*x+b*y=gcd(a,b). this is true all time right ?
    So, we have to actually find for how many different value i.e. (mod by 8)  we can get by putting non-negative x and y
    So , (a*x+b*y)%k=gcd(a,b)%k
    => (a%k)*x + (b%k)*y = gcd(a,b)%k
    => ( (a1)*x + (b1) * y)%k= (gcd(a1,b1) )%k
    if x is negative for some reason for mod k , we can assume any multiple  value of k can be added to co-efficient.
        By reduction ,we can prove that it is true for three values
*/
 
 
#include<bits/stdc++.h>
 
using namespace std;
 
const int maxn=1e5+10;
 
typedef long long ll;
 
const ll mod=1e9+7;
 
 
int main()
 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n,k,a;
    cin>>n>>k;
 
    int gcd=k;
 
    while(n--)
    {
        cin>>a;
        gcd=__gcd(gcd,a%k);
    }
 
    /// we can get all multiples of gcd below base k
    cout<<(k/gcd)<<endl;
    for(int i=0;i<k;i+=gcd) cout<<i<<" ";
    cout<<endl;
 
	return 0;
}
