
/// Codeforces : C - Ehab and a Special Coloring Problem
/// Category : sieve + greedy  .


#include<bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;

int arr[maxn];

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,num=0;
    cin>>n;

    /// it is better to fill up array same numbers of non co-prime pairs
    for(int i=2;i<=n;i++)
    {
        if(!arr[i])
        {
            arr[i]=++num;
            for(int j=i;j<=n;j+=i) arr[j]=arr[i];
        }
        cout<<arr[i]<<" ";
    }

    cout<<endl;

	return 0;
}
