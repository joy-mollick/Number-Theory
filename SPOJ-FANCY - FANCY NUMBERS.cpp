#include <bits/stdc++.h>

using namespace std;

const int mx=1e6+1;

typedef long long int ll;

vector<ll>v;

int main()

{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int tc;
   string s;
   cin>>tc;
   while(tc--)
   {
       cin>>s;
       ll ans=1;
       ll po;
       v.clear();
       ll conti=0;
       for(int i=0;i<s.size()-1;i++)
       {
           if(s[i]==s[i+1])
           {
               conti++;
           }
           else{
            v.push_back(conti);
            conti=0;
           }
       }
       if(conti)
        v.push_back(conti);

       for(int i=0;i<v.size();i++){
        po=v[i];
        ans=ans*pow(2,po);
       }
       cout<<ans<<'\n';
   }
}
