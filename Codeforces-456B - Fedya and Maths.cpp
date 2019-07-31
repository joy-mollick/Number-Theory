
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;


int main()

{
   int rem=0;
   int phi_n=4;// phi(n) = 4
   string s;
   cin>>s;
   for(int i=0;i<s.size();i++)
   {
       rem=rem*10+(s[i]-'0')%phi_n;// phi(n) = 4
       rem=rem%(phi_n);
   }
   int ans=(1+((int)pow(2,rem))%5+((int)pow(3,rem))%5+((int)pow(4,rem))%5)%5; // n==5
   cout<<ans<<endl;
}
