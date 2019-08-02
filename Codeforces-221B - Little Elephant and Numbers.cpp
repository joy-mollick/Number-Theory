#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

bool mil(int n,int m)
{
    set<int>s;
    while(n!=0)
    {
        s.insert(n%10);
        n=n/10;
    }
    while(m!=0)
    {
        if(s.count(m%10))
            return true;
        m=m/10;
    }
    return false;
}


int main()

{
   int n;
   cin>>n;
   int ans=0;
   for(int i=1;i<=sqrt(n);i++)
   {
       if(n%i==0&&i*i!=n)
       {
           if(mil(i,n))
           {
               ans++;
           }
           if(mil((n/i),n))
           {
               ans++;
           }
       }
       else if(n%i==0)
       {
           if(mil(i,n))
           {
               ans++;
           }
       }
   }
   cout<<ans<<endl;
}

