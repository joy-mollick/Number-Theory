
/// Codeforces : D. Power Products.
/// Category : number theory.

/// nice one just prime factorization and stl 

#include<bits/stdc++.h>


using namespace std;

const int mx=100005;

typedef vector< pair<int,int> > pi;
pi v;
map<pi,int>cont;
int k;

void calcul(int x)
{
    /// for prime factor 2 only
    int cnt=0;
    while(x%2==0)
    {
        x=x>>1;
        cnt++;
    }
    cnt=cnt%k;
    if(cnt)
    v.push_back(make_pair(2,cnt));

    for(int i=3;i<=sqrt(x);i+=2)
    {
        if(x%i==0)
        {
            cnt=0;
            while(x%i==0)
            {
                cnt++;
                x=x/i;
            }
            ///we need to make products as power of k
            ///so all time count cnt%k
            cnt=cnt%k;
            if(cnt)
                v.push_back(make_pair(i,cnt));
        }
    }
    /// that means one prime factor
    if(x>1)
    {
        v.push_back(make_pair(x,1));
    }

}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,x;
    cin>>n>>k;

    long long ans=0;
    while(n--)
    {
        cin>>x;
        v.clear();
        calcul(x);
        int len=(int)v.size();
        /// adding the composite container of current container v 
        ans+=(long long)cont[v];
        /// this loop is making composite container of x
        /// which can make X^k ,where X is arbitrary with this value x.
        for(int i=0;i<len;i++)
        {
            v[i].second=k-v[i].second;
        }
        cont[v]++;
    }

    cout<<ans<<endl;

	return 0;
}
