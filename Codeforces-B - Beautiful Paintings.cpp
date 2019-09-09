    #include<bits/stdc++.h>

    using namespace std;

    typedef long long ll;


    int main(){
       ll n,k,sum;
       cin>>n;
       map<int,int>m;
       int ans=0;
       for(int i=0;i<n;i++)
       {
           cin>>k;
           m[k]++;
           ans=max(ans,m[k]);
       }
       cout<<n-ans<<endl;
       }
