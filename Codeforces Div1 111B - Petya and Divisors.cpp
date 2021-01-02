

/// Codeforces Div1 111B - Petya and Divisors 
/// Nice one !


/// number theory 


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mx=100001;
int used[mx];

int main()

{
    int tc;
    cin>>tc;
    int x,y;
    memset(used,-1,sizeof(used));
    int indx=0;
    while(tc--)
    {
        indx++;
        cin>>x>>y;
        int cont=0;
        for(int div=1;div*div<=x;div++)
        {
            if(x%div==0)
            {
            if(y==0 || used[div]==-1 || used[div]<indx-y) cont++;
            /// this is the last indx which number is divisible by div 
            used[div]=indx;
            if(div*div==x) continue;
            if(y==0 || used[x/div]==-1 || used[x/div]<indx-y) cont++;
            used[x/div]=indx;
            }
        }
        cout<<cont<<endl;
    }

    return 0;
}
