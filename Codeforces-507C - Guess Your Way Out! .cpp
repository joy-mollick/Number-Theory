#include<bits/stdc++.h>


using namespace std;

typedef unsigned long long ll;

ll mod=1e9+7;

ll po(ll a,ll b)
{
    ll ans=1ll;
    while(b)
    {
        if(b&1ll) ans=(ans*a);

        a=(a*a);
        b=b>>1ll;
    }
    return (ans);
}

int main()

{
    ios::sync_with_stdio(false);
    ll h,n;
    cin>>h>>n;
    int binary[51];
    n--;
    for(int i=0;i<h;i++)
    {
        binary[h-i-1]=n%2;
        n=n>>1ll;
    }
    // LRLRLRLRLR given pattern
    // 0101010101 in binary instruction
    ll visited=0ll;
    if(binary[0]==1) visited+=po(2ll,h);
    else visited+=1ll;
    for(int j=1;j<h;j++)
    {
        //pattern doesn't match
        if(binary[j]==binary[j-1])
        {
            visited+=po(2ll,h-j);
        }
        else visited=visited+1ll;

    }
    cout<<visited<<endl;
}
