#include<bits/stdc++.h>

using namespace std;

const int mx=5000000;
typedef  long long ll;

bool prime[mx];
vector<int>v;
vector<int>pp;

bool palindrome(int n)
{
    int original=n;
    int nw=0;
    while(n)
    {
        nw=nw*10+(n%10);
        n=n/10;
    }
    if(nw==original)
        return true;
    else
        return false;
}
int fnd_m(int n)
{
    int m=1;
    while(n!=0)
    {
        if(n%10!=0){
        m=m*(n%10);}
        n=n/10;
    }
    return m;
}
 void sieve()
 {
    for(int i=4;i<mx;i=i+2)
    {
        prime[i]=false;
    }
    for(int i=3;i*i<mx;i=i+2)
     {
         if(prime[i])
         {
             for(int j=i*i;j<mx;j=j+2*i)
             {
                 prime[j]=false;
             }
         }
     }
     prime[2]=true;
 }

 void pre_cal()
 {
     sieve();
     for(int j=2;j<mx&&pp.size()<114;j++)
     {
         if(palindrome(j)&&prime[j])
         {
             pp.push_back(j);
         }
     }
     v.push_back(2);
     for(int i=3;i<mx;i=i+2)
     {
         if(prime[i]) v.push_back(i);
     }
 }
int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(prime, true,sizeof(prime));
    pre_cal();
    //cout<<pp.size()<<endl;
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<pp[n-1]<<" ";
        cout<<v[fnd_m(pp[n-1])-1]<<endl;
    }
}
