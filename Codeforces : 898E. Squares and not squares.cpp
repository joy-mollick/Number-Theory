
/// Codeforces : 898E. Squares and not squares
/// Category : number theory + greedy.


#include<bits/stdc++.h>

using namespace std;

typedef  long long ll;

const ll mod=1e9+7;
const int maxn=1e5+10;

int need(int x)
{
    int sqr=sqrt(x);
    if(sqr*sqr==x) return 0;
    int ans1=abs(sqr*sqr-x);
    int ans2=abs((sqr-1)*(sqr-1)-x);
    int ans3=abs((sqr+1)*(sqr+1)-x);
    return min(min(ans1,ans2),ans3);
}

bool sqr(int x)
{
    int q=sqrt(x);
    if(q*q==x||x==1) return true;
    else return false;
}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int arr[n];
    int a[n];

    int sq=0;

    for(int i=0;i<n;i++) {cin>>arr[i],a[i]=arr[i];}

    for(int i=0;i<n;i++) {arr[i]=need(arr[i]);if(arr[i]==0) sq++;}

    sort(arr,arr+n);

     long long ans=0;
    /// adding to make square
    if(sq<=(n/2))
    {
        int i=0;
        while(sq!=(n/2))
        {
            if(arr[i]!=0)
            {
                sq++;
                ans+=(long long)arr[i];
            }
            i++;
        }
    }

    else if(sq>(n/2))
    {
        for(int i=0;i<n;i++)
        {
            int res=INT_MAX;
            int num=a[i];
            while(sqr(num)) num++;
            int num1=a[i];
            while(sqr(num1)&&num1>=0) num1--;
            if(!sqr(num1)&&num1>=0) res=abs(num1-a[i]);
            res=min(res,abs(a[i]-num));
            a[i]=res;
        }
        ///needed number of moves per a[i] to make non- square
        sort(a,a+n);
        int i=0;
        while(sq!=(n/2))
        {
            if(a[i]!=0)
            {
                sq--;
                ans+=(long long)a[i];
            }
            i++;
        }
    }

    cout<<ans<<endl;

	return 0;
}
