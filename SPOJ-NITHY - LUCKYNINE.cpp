#include <bits/stdc++.h>

using namespace std;


int main()

{
    int dp[10001];
    memset(dp,0,sizeof(dp));
    dp[9]=1;
    for(int i=9;i<10001;i=i+10)
        {dp[i]=1;}

        for(int j=10;j<10001;j++)
        {
            if(dp[j-9]&&(j%10)!=9)
            {
                dp[j]=dp[j-9]+1;
            }
        }

    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(dp[n])
        cout<<dp[n]<<endl;
        else
         cout<<"Impossible"<<endl;
    }
    return 0;
}
