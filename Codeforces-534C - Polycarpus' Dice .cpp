#include<bits/stdc++.h>


using namespace std;

typedef long long ll;

// It can be solved with using inequalities classically
// All summation of d1 , d2 ...dn = S.
//Every dice has atleast die-face number 1 .So the value of A will be within the range n<=A<=S
// When we choose a dice di , suppose it's face value is d ( 1<=d<=di ) rest of value stated by p . So , p+d=A -> d = A-p ;
// So , for any value of dice di , if we choose d ,then other value p will be within range (n-1)<= p <=S-di
// from d=A-p , we can get p = A -d ; (n-1)<= A-d <=S-di . (n-1)-A<= -d <=S-di-A ;A-(n-1)>= d >=A-(S-di)
// So , for the values for di will be impossible which is  not in the range upper_limit=min(di ,A-(n-1) ) and lower_limit=max(1,A-(S-di))

int main()

{
    ios::sync_with_stdio(false);
    ll n,A,x;
    vector<ll>d;
    cin>>n>>A;
    ll S=0ll;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        d.push_back(x);
        S+=x;
    }
    ll ans=0ll;
    for(int i=0;i<n;i++)
    {
        ll upper_limit=min(d[i],A-(n-1));
        ll lower_limit=max(1ll,A-(S-d[i]));
        ll possible_values=(upper_limit-lower_limit)+1;
        ll impossible_values=d[i]-possible_values;
        cout<<impossible_values<<" ";
    }
    return 0;
}
