#include<bits/stdc++.h>

using namespace std;

const int mx=1e8+1;

 typedef long long ll;
 vector<int>v;

 bool prime_fact(int n)
 {
     int fact=0;
     if(n%2==0)
     {
         fact++;
         while(n%2==0)
         {
             n=n>>1;
         }
     }
     for(int i=3;i<=n;i=i+2)
     {
         if(n%i==0)
         {
             fact++;
             while(n%i==0)
             {
                 n=n/i;
             }
         }
         if(fact>=3)
         {
            return true;
         }
     }
     if(n>2) fact++;

     if(fact<3)
        return false;
     else return true;
 }

void pre_cal()
{
    for(int i=30;;i++)
    {
        if(prime_fact(i))
        {
            v.push_back(i);
        }
        if(v.size()==1000)
        {
            break;
        }
    }
}
int main()

{
    pre_cal();
    int test,n;
    cin>>test;
    while(test--)
    {
        cin>>n;
        cout<<v[n-1]<<endl;
    }
}
