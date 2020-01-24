#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

/*

ll mod=1000000007 ;

ll po(ll a,ll b)
{
   ll ans=1ll;
   while(b)
   {
       if(b&1ll){
        ans=(ans*a)%mod;}
       b=b>>1ll;
       a=(a*a)%mod;
   }
   return (ans%mod);
}
*/


int main()

{
    ios_base::sync_with_stdio(false);
    multiset<int>s;
    int n,a;
    cin>>n;
    int k=n*n;
    while(k--)
    {
        cin>>a;
        s.insert(a);
    }
    vector<int>::iterator it;
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        int mx=*--s.end();
        s.erase(s.lower_bound(mx));
        for(it=ans.begin();it!=ans.end();it++)
        {
            int g=__gcd(mx,(*it));
            s.erase(s.lower_bound(g));
            s.erase(s.lower_bound(g));
        }
        ans.push_back(mx);
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}
