#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll sum_of_divisors[500001];

void sieve()

{
    for(ll i=2;i<500001;i++)
    {
        for(ll j=2;j*j<=i;j++)
        {
            if(i%j==0&&(j*j)!=i)
            {

                sum_of_divisors[i]+=j;
                sum_of_divisors[i]+=(i/j);
            }
            else if(i%j==0 && (j*j)==i){
                sum_of_divisors[i]+=j;
            }
        }
    }
}

int main()


{

    memset(sum_of_divisors,0,sizeof(sum_of_divisors));
    sieve();
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<"0"<<'\n';
            continue;
        }
        cout<<sum_of_divisors[n]+1<<'\n';
    }

    return 0;
}
