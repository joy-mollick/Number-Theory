#include<bits/stdc++.h>

using namespace std;

bool div(int n)
{
    int count=0;
    while(n%2==0)
    {
        count++;
        n=n>>1;
    }
    if(count>2) return false;

    for(int j=3;j<=sqrt(n);j=j+2)
    {
        count=0;
       while(n%j==0)
       {
           count++;
           n=n/j;
       }
       if(count>2) return false;
    }

    return true;
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int b=2;
    vector<int>pre;
    pre.push_back(1);
    for(int i=2;i<=1000005;i++)
    {
        if(div(i))
        {
            pre.push_back(i);
        }
    }
    int tc,l;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        cout<<"Case "<<i<<": ";
        cin>>l;
        vector<int>::iterator it;
        it=lower_bound(pre.begin(),pre.end(),l);
        if((*it)==l)
        {
            int ans=it-pre.begin();
            cout<<ans+1<<endl;
        }
        else{
            cout<<"Not Cube Free"<<endl;
        }
    }
    return 0;
}
