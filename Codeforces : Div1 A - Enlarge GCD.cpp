
/// Codeforces : Div1 A - Enlarge GCD.
/// Category : number theory + sieve .


#include<bits/stdc++.h>

using namespace std;

const int maxn=(1.5*1e7)+10;

int mul[maxn];
int counts[maxn];

inline int gcd(int a,int b)
{
	return b == 0 ? a:gcd(b,a%b);
}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int g=0;

    int n,x;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>x;
        counts[x]++;
        g=gcd(g,x);
    }

    int mx=0;

    for(int i=g+1;i<=maxn;i++)
    {
        if(!mul[i])
        {
            int cont=0;
            for(int j=i;j<=maxn;j=j+i)
            {
                mul[j]=1;
                cont+=counts[j];
            }
            /// check whose multiples occur here most time
            /// so, obviously new gcd will be multiple of that i .
            /// whose multiples occur most
            mx=max(mx,cont);
        }
    }

    if(mx==0) cout<<"-1"<<endl;
    else cout<<(n-mx)<<endl;

	return 0;
}
