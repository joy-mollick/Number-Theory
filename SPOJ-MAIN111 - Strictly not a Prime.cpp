#include<bits/stdc++.h>

using namespace std;

const int mx=1e5+1;

bool prime[mx];
bool strctly_prm[mx];
vector<int>arr;

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
     prime[0]=false;
     prime[1]=false;
 }

 int digit(int m)
 {
     int ans=0;
     while(m)
     {
         ans++;
         arr.push_back(m%10);
         m=m/10;
     }
     return ans;
 }

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(prime,true,sizeof(prime));
    memset(strctly_prm,false,sizeof(strctly_prm));
    sieve();
    // subsequence checking till mx which is strctly prme or not
    for(int i=1;i<mx;i++)
    {
        arr.clear();
        int m=digit(i);
        unsigned int sz=pow(2,m);
        bool ok=true;
        reverse(arr.begin(),arr.end());
        for(int counter=1;counter<sz;counter++)
        {
            int nmber=0;
            for(int j=0;j<m;j++)
            {
                if(counter&(1<<j))
                    nmber=nmber*10+arr[j];
            }
            if(prime[nmber]){ ok=false;
                break;}
        }
        if(ok)
        {
            strctly_prm[i]=true;
        }
    }
    int ans[mx];
    ans[0]=0;
    int sum=0;
    for(int y=1;y<mx;y++)
    {
        if(strctly_prm[y])
            sum++;

        ans[y]=sum;
    }
    int t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<ans[max(a,b)]-ans[min(a,b)-1]<<endl;
    }
    return 0;
}
