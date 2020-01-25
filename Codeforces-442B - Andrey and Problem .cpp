#include<bits/stdc++.h>

using namespace std;

// Basic probability and mathmatical term

int main()

{
    int n;
    vector<double>proba;
    cin>>n;
    double p;
    while(n--)
    {
        cin>>p;
        proba.push_back(p);
    }
    sort(proba.rbegin(),proba.rend());
    double prev=1.0,present=0.0;
    double ans=0.0;
    for(int i=0;i<proba.size();i++)
    {
        p=proba[i];
        present*=(1-p);
        present=present+(prev*p);
        prev=prev*(1-p);
        ans=max(present,ans);
    }
    printf("%0.09lf\n",ans);
    return 0;
}
