#include <bits/stdc++.h>

using namespace std;

const int mx=1e6+1;

bool prime[mx];
int prm_fct[mx];
vector<int>v[mx];

void sieve()
{
    for(int i=2;i<mx;i++)
    {
        if(prime[i])
        {
            prm_fct[i]=1;
            for(int j=2*i;j<mx;j=j+i)
            {
                prm_fct[j]++;
                prime[j]=false;
            }
        }
    }
}


int main()

{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   for(int i=0;i<mx;i++)
   {
       prime[i]=true;
       prm_fct[i]=0;
   }
   sieve();
   for(int i=0;i<mx;i++)
   {
       v[prm_fct[i]].push_back(i);
   }
   int tc,a,b,n;
   cin>>tc;
   while(tc--)
   {
       cin>>a>>b>>n;
       vector<int>ad=v[n];
       int pos2=upper_bound(ad.begin(),ad.end(),b)-ad.begin();
       int pos1=lower_bound(ad.begin(),ad.end(),a)-ad.begin();
       cout<<(pos2-pos1)<<endl;
   }
}
