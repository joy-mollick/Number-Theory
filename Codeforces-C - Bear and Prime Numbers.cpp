#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const int mx = 1e7+1;
bool prime[mx]={false};
int cunt[mx]={0};
int dp[mx]={0};

void sieve()
{
    for(int i=2;i<=sqrt(mx);i++)
    {
        if(!prime[i])
        {
            for(int j=2*i;j<=mx;j=j+i)
            {
                prime[j]=true;
            }
        }
    }
    prime[1]=true;
    prime[2]=false;
}

void pre_compute()

{
    for(int i=1;i<=mx;i++)
    {
        if(!prime[i])
        {
            for(int j=i;j<=mx;j=j+i)
            {
                dp[i]+=cunt[j];
            }
        }
    }
    for(int i=1;i<=mx;i++)
    {
        dp[i]+=dp[i-1];
    }
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    int n,a,l,r,mm;
    cin>>n;
    while(n--)
    {
        cin>>a;
        cunt[a]++;
    }
    pre_compute();
    cin>>mm;
    while(mm--)
    {
        cin>>l>>r;
        int ans;
        if (r>mx)
				r= mx;
			if (l > mx)
				cout<<"0"<<'\n';
			else
				cout<<(dp[r] - dp[l - 1])<<'\n';
    }
}

