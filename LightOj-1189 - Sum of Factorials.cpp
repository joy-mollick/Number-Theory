
/// Time-0.010s
/// normal math and fibonacchi number 

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll fact[21];

void cal()
{
    fact[0]=1;
    for(int i=1;i<21;i++)
    {
        fact[i]=fact[i-1]*i;
    }
}

int main()

{
    ios::sync_with_stdio(false);
    cal();
    int t;
    ll n;
    cin>>t;
    int caseno=0;
    while(t--)
    {
        caseno++;
        cin>>n;
        priority_queue < int , vector< int >, greater< int > > pq;/// it will keep the values sorted

        /// fact(n) > fact(n-1)+....+fact(0)
        /// we can use greedy approach to take factorial from the greatest  one

        for(int i=20;i>=0;i--)
        {
            if(n>=fact[i])
            {
                n=n-fact[i];
                pq.push(i);
            }
        }
        if(n!=0){
        printf("Case %d: impossible\n",caseno);
        }
        else
        {
            printf("Case %d: ", caseno);
			while(pq.size() != 1) {
				printf("%d!+", pq.top());
				pq.pop();

			}

			printf("%d!\n", pq.top());
			pq.pop();
        }
    }
    return 0;
}
