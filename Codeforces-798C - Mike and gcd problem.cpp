#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;


int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    bool even[n];
    memset(even,false,sizeof(even));
    for(int j=0;j<n;j++)
    {
        cin>>arr[j];
        if(arr[j]%2==0)
        {
            even[j]=true;
        }
    }
    int ans=arr[0];
    for(int i=1;i<n;i++)
    {
        ans=__gcd(ans,arr[i]);
    }
    if(ans>1)
    {
        cout<<"YES\n0"<<'\n';
        return 0;
    }
    int sum=0;
    for(int i=0;i<n-1;i++)
    {
        if(!even[i])
        {
            if(!even[i+1])
                sum++;// if odd and odd then 1 times to make even
            else if(even[i+1])
                sum=sum+2; // if odd even then 2 times to make even

            even[i]=true;
            even[i+1]=true;
        }
    }
    if(!even[n-1])
        sum=sum+2;

    cout<<"YES"<<endl<<sum<<endl;
}

