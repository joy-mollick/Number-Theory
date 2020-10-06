/// Codeforces : 1059C - Sequence Transformation.
/// Category : number theory + greedy.


/// Given 1,2,3.....n integers
/// First half ,we will write (x=) 1 ,then all time remove odd numbers
/// Now all are even numbers,now write x=2*x .remove all multiples of 2 not 4
/// Then x will be equal to x=2*2*x.

#include<bits/stdc++.h>

using namespace std;

typedef  long long ll;

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,N;
    cin>>n;
    int x=1;

    while(n)
    {
        for(int i=1;i<=(n-(n/2));i++)
        {
            cout<<x<<" ";
        }
        /// critical case
        if(n==3)
        {
            cout<<(3*x)<<" ";
            break;
        }
        n=n>>1;
        x=2*x;
    }

    return 0;
}
