#include<bits/stdc++.h>


using namespace std;

const int mx=5000001;
int prime_fact[mx]={0};
long long dp[mx]={0};

void precal(){

for(int i=2;i<mx;i++)
{
    if(prime_fact[i]==0)
    {
        for(int j=i;j<mx;j=j+i)
        {
            int temp=j;
            while(temp>1&&temp%i==0)
            {
                prime_fact[j]++;
                temp=temp/i;
            }
            //prime_fact[j]+=prime_fact[j-1];
        }
    }
}

}

int main()

{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    precal();
    long long sum=0;
    for(int i=0;i<mx;i++)
    {
        sum=sum+(long long)prime_fact[i];
        //cout<<sum<<endl;
        dp[i]=sum;
    }
       int t,a,b;
       cin>>t;
       while(t--)
       {
           cin>>a>>b;
           cout<<dp[a]-dp[b]<<'\n';
       }
}
