/// Codeforces : A - Sasha and a Bit of Relax.
/// Category : number theory + dp.


/// It is nothing but to count number of intervals with xor equal to zero
/// But here is a problem as if xor[r]=xor[l-1] ,then the segment from l to r will make interval with xor equal to zero.
/// Now one thing is left , (r-l+1) should be even so , r and l parity should be different ,right ?
/// That makes sense that r and l-1 parity should be same ,right ?


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mx=300005;

int prefix_xor[mx];

typedef pair<int,int> pi;


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    for(int i=1;i<=n;i++) cin>>prefix_xor[i];

    map<pi,int>mp;
    mp[(make_pair(0,0))]++;

    long long ans=0;

    for(int i=1;i<=n;i++)
    {
        prefix_xor[i]^=prefix_xor[i-1];
        pi p=make_pair(prefix_xor[i],(i%2));
        /// it will add all same parity like (l-1 and r parity should be same)
        ans+=(long long)mp[p];
        mp[p]++;
    }

    cout<<ans<<endl;

    return 0;
}
