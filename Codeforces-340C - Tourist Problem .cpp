#include<bits/stdc++.h>


using namespace std;

typedef unsigned long long ll;

// Here the sum S (ai+aj+...+an) will be appear (n-1)! times and (ai-aj) when aj<ai appears (n-1)! times 
// So , every pair difference summation will be needed but it will take O(n^2) .
// It can be done in O(n) . But it will appear left and right both side .
// so average will be (S +2*diff_sum) /n 


int main()

{
    ios::sync_with_stdio(false);
    ll n,a;
    cin>>n;
    ll S=0ll;
    ll arr[n];
    ll prefix_sum[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        S=S+arr[i];
    }
    sort(arr,arr+n);
    ll sum=0ll;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        prefix_sum[i]=sum;
    }
    ll diff_sum=0ll;
    ll summation_before=0ll;
    for(ll i=1;i<n;i++)
    {
        summation_before=prefix_sum[i-1];
        diff_sum=diff_sum+(( (i)*arr[i])- summation_before);
    }
    ll total_diff_sum=2ll*diff_sum;
    ll up=S+total_diff_sum;
    ll down=n;
    cout<<up/(__gcd(up,down))<<" "<<down/(__gcd(up,down))<<endl;
}
