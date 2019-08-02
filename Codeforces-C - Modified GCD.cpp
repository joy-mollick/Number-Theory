#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;


int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   int a,b,q,low,high;
   cin>>a>>b;
   vector<int>v;
   int l=min(a,b);
   for(int i=1;i<=sqrt(l);i++)
   {
       if(a%i==0 && b%i==0)
       {
           v.push_back(i);
       }
       if(i*i!=l){
       if(a%(l/i)==0 && (b%(l/i))==0)
       {
           v.push_back((l/i));
       }
       }
   }
   sort(v.begin(),v.end());
   cin>>q;
   while(q--)
   {
       cin>>low>>high;
       int ans=0;
       int sz=v.size()-1;
       for(sz;sz>=0;sz--)
       {
           if( v[sz]>=low && v[sz]<=high )
           {
               ans=v[sz];
               break;
           }
       }
       if(ans==0)
       {
           cout<<"-1"<<'\n';
       }
       else{
        cout<<ans<<'\n';
       }
   }
}

