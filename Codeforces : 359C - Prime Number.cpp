
/// Codeforces : 359C - Prime Number
/// Category : number theory + bit manipulation.


/// (1/x^a1) + (1/x^a2) + (1/x^a3)+....+(1/x^an)
/// sum=a1+a2+a3+...+an.
/// After summing up , summation = (x^(sum-a1) + x^(sum-a2) +... +x^(sum-an) ) / x^sum.
/// Then if all sum-ai are distinct ,then it is very easy ,only take minimum one which will be common to all.
/// If they are not distinct elements.
/// Then you have to take care the number of counts of (sum-ai).
/// like , 3^2 + 3^2 +3^2 ,so here it will make 3^2 * 3 = 3^3 = 27.
/// So, extra count can make another power increase to x ,take care of them.


#include<bits/stdc++.h>

using namespace std;

typedef  long long ll;

const ll mod=1e9+7;
const int maxn=1e5+10;

ll numer_pow[maxn];

ll quick_po(ll a,ll b)
{
    ll ans=1ll;
    while(b)
    {
        if(b&1ll) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b=b>>1ll;
    }
    return (ans%mod);
}


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,x,a;
    cin>>n>>x;

    ll arr[n];
    ll sum=0ll;
    ll min_po;

    for(int i=0;i<n;i++) {cin>>arr[i];sum+=arr[i];}

    for(int i=0;i<n;i++) arr[i]=(sum-arr[i]);

    sort(arr,arr+n);

    arr[n]=-1;

    ll cnt=1ll;

    for(int i=1;i<=n;i++)
    {
        if(arr[i]==arr[i-1]) cnt++;
        else
        {
            if(cnt%x!=0ll)
            {
                min_po=arr[i-1];
                break;
            }
            /// that means by summing x^number_pow[i-1]
            /// we can increase its power
            else
            {
                arr[i-1]++;
                /// x times x^number_pow(i-1) increase one time.
                cnt/=x;
                /// again iterate from here.
                i--;
            }
        }
    }

    ll ans=min(min_po,sum);
    cout<<quick_po(x,ans)<<endl;

	return 0;
}
