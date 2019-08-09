#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mx=1e6+1;
int phi[mx];

void totient_sieve()
{
    for(int i=1;i<mx;i++)
        phi[i]=i;

    for(int p=2;p<mx;p++)
    {
        if(phi[p]==p)
        {
            phi[p]=p-1;
            for(int i=2*p;i<mx;i=i+p)
            {
                phi[i]=(phi[i]/p)*(p-1);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    totient_sieve();
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<phi[n]<<'\n';
    }
}
