#include<bits/stdc++.h>

using namespace std;


// Basic probability and series reduction problem

typedef unsigned long long ll;

ll mod=1000000007 ;

/*

// try to find the probability of being prime of one number in range 
// not_prob=(not prime numbers in range /total number in range )
// for two numbers adjacent i,i+1 . Being pair multiplication be divisible by p .1-(not_prob_i*not_prob_i+1)
// Now multiply the amount of dollars 2000 ( for each 1000) for all i,i+1.That's all .

ll po(ll a,ll b)
{
   ll ans=1ll;
   while(b)
   {
       if(b&1)
        ans=(ans*a)%mod;
       b=b>>1;
       a=(a*a)%mod;
   }
   return (ans%mod);
}
*/
int num_of_multiples_range(int l,int r,int p)
{
    int s=r/p;
    int t=(l-1)/p;
    return s-t;
}

int main()

{
    ios_base::sync_with_stdio(false);
    int n,p,l,r;
    cin>>n>>p;
    vector<double>v;
    for(int i=1;i<=n;i++)
    {
        cin>>l>>r;
        double num=(double)num_of_multiples_range(l,r,p);
        double nt_mul=(double)(r-l+1)-num;
        double tot=(double)(r-l+1);
        double not_prob=nt_mul/tot;
        v.push_back(not_prob);
    }
    double dollar=2000.0;
    double ans=0.0;
    for(int i=0;i<n-1;i++)
    {
        double a_not=v[i];
        double b_not=v[i+1];
        double get_dollar_prob=1.00-(a_not*b_not);
        ans=ans+(get_dollar_prob*dollar);
    }
    double a_not=v[0];
    double b_not=v[n-1];
    double get_dollar_prob=1.00-(a_not*b_not);
    ans=ans+(get_dollar_prob*dollar);
    printf("%0.06lf\n",ans);
    return 0;
}
