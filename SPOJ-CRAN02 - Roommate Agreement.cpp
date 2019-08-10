#include <bits/stdc++.h>

using namespace std;

const int mx=1e6+1;

unordered_map<int,int>m;

int main()

{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int tc,n,a;
   cin>>tc;
   while(tc--){
   long long res=0;
   int pref=0;
   cin>>n;
   for(int i=0;i<n;i++){
    cin>>a;
    pref=pref+a;
    if(pref==0)
    {
        res++;
    }
     if(m.find(pref)!=m.end())
    {
        res=res+m[pref];
    }
    m[pref]++;}
    cout<<res<<'\n';
    m.clear();
   }
  return 0;
}
