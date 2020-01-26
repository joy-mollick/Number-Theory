#include<bits/stdc++.h>


using namespace std;

typedef long long ll;

vector<ll>st;
map<ll,int>m;

bool found(int arr[],int n)
{
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i])
        {
            sum+=st[i];
        }
    }
    if(m[sum]>0)
    {
        return true;
    }
    else{
    m[sum]=1;
    return false;
    }
}

bool ans=false;

void solve(int arr[],int n,int index)
{
    if(index==n)
    {
        if(found(arr,n))
        {
            ans=true;
            return;
        }
        else return;
    }
    arr[index]=0;
    solve(arr,n,index+1);
    arr[index]=1;
    solve(arr,n,index+1);
}

// Here for strong induction for 2 and 3 the answer is always yes .But for others we can make them a set with numbers of powers of w less than m and just immediate greater than m .Then if two subset sum is equal then yes or no 

int main()

{
    ios::sync_with_stdio(false);
    int w,m;
    cin>>w>>m;
    if(w==2||w==3)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    int p=0;
    st.push_back(m);
    ll r=(ll)pow(w,p);
    st.push_back(r);
    while(r<m)
    {
        p++;
        r=pow(w,p);
       st.push_back(r);
    }
    int n=st.size();
    int arr[n];
    solve(arr,n,0);
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
