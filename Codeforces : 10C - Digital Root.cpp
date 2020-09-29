
/// Codeforces : 10C - Digital Root.
/// Category : number theory + observation .

/// every time finding such triplets where a*b==c 
/// so every time find number of multiples of a within n 
/// as you can make triplets with those multiples as a*b=multiple 
/// You can calculate it within (n) ,so just subtract this from real calculation where d(d(a)*d(b))=d(c) 

#include<bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;
typedef long long ll;

int cnt[10];

int d(int x)
{
    if(x%9) return x%9;
    return 9;
}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    ll res=0;
    for(int i=1;i<=n;i++) cnt[d(i)]++;
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            for(int k=1;k<=9;k++)
            {
                /// counting d(a*b) = d(c) 
                if(d(i*j)==d(k)) res+=(ll)cnt[i]*(ll)cnt[j]*(ll)cnt[k];
            }
        }
    }
    
    /// removing the amount of triplets where 
    /// a*b=c 
    
    for(int i=1;i<=n;i++) res-=n/i;
    cout<<res<<endl;

	return 0;
}
