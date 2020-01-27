#include<bits/stdc++.h>


using namespace std;

// After some observation it can be said that if (i1,j1) is top left corner co-ordinate and right bottom co-ordinate is (i2,j2)
// Then sum of elements is within this rectangle is sum(i1,j1)*sum(i2,j2) ->where  sum(i,j)=si+....+sj .
// We have to found out the sum of total possible segment of given string S.
// Then the given sum A is obviously in form of sum(i1,j1)*sum(i2,j2)=X*Y. So , obviously X and Y is a factor of A
// We have to find out the frequency of factors of A in sum of all segments of S.
// For A=0.Then X*Y=0. So , think about non_zero and zero sum segments.it will be 2*#include<bits/stdc++.h>


using namespace std;

// After some observation it can be said that if (i1,j1) is top left corner co-ordinate and right bottom co-ordinate is (i2,j2)
// Then sum of elements is within this rectangle is sum(i1,j1)*sum(i2,j2) ->where  sum(i,j)=si+....+sj .
// We have to found out the sum of total possible segment of given string S.
// Then the given sum A is obviously in form of sum(i1,j1)*sum(i2,j2)=X*Y. So , obviously X and Y is a factor of A
// We have to find out the frequency of factors of A in sum of all segments of S.
// For A=0.Then X*Y=0. So , think about zero_segments and total_segments .

typedef unsigned long long ll;


int main()

{
    ios::sync_with_stdio(false);
    ll A;
    cin>>A;
    string s;
    cin>>s;
    ll n=(ll)s.size();
    map<ll,ll>freq;
    ll zero_segments=0ll;
    ll tot_segments=n*(n+1)/2ll;
    for(int i=0;i<s.size();i++)
    {
        ll sum=0ll;
        for(int j=i;j<s.size();j++)
        {
            sum+=(ll)s[j]-'0';
            if(sum==0ll) zero_segments++;
            freq[sum]++;
        }
    }
    ll res=0ll;
    if(A==0ll)
    {
        res=2ll*(zero_segments*tot_segments) -(zero_segments*zero_segments);
    }
    else
    {
        for(ll i=1;i*i<=A;i++)
        {
            if(A%i==0)
            {
                if(i*i==A)
                {
                    res+=(1ll*freq[i]*freq[i]);
                }
                else res+=(2ll*freq[i]*freq[A/i]);
            }
        }
    }
    cout<<res<<endl;
}
