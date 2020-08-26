
/// Codeforces - C Vasya and Petya's Game.
/// Category - Number theory + prime.

/*
Lets say it is 10.
Hidden number can be 1, 2, 3, 4, 5, 6, 7, 8, 9, 10.
So lets say Vasya though of number 9.
So, if you say 3, the answer is yes, Vasya's number is divisible by 3.
But you can't be sure that it is 3 or 9,so you have to ask whether the number is also divisible by 9.
That is why you have to check all powers of all the primes.

A number x -> p1^a1 * p2^a2 *p3^a3.
So,we have to print all prime powers,by doing this .
Automatically all complex numbers have been asked !!
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


const int mx=1001;

vector<int>ans[mx];

/// is prime or not
bool prime[mx];

ll pow(ll a,ll b)
{
    ll ans=1ll;
    while(b--)
    {
        ans=(ans*a);
    }
    return ans;
}

/// pre-calculation
void sieve()
{
    memset(prime, true, sizeof(prime));
    for (int p=2; p<mx; p++)
    {
        ///mark all multiple's of i.
        if (prime[p]==true)
        {
            for (int i=2*p; i<mx; i += p)
            {
                prime[i] = false;
            }
        }
    }
}


int main()

{
    sieve();
    for(ll i=2;i<mx;i++)
    {
        if(prime[i])
        {
            ll p=1ll;
            while(pow(i,p)<mx)
            {
                ans[i].push_back(pow(i,p));
                p++;
            }
        }
    }

    ll n;
    cin>>n;
    int cont=0;
    vector<int>res;
    for(int k=2;k<=n;k++)
    {
        if(prime[k])
        {
            for(int i=0;i<ans[k].size()&&ans[k][i]<=n;i++)
            {
                cont++;
                res.push_back(ans[k][i]);
            }
        }
    }
    cout<<cont<<endl;
    for(int l=0;l<cont;l++) cout<<res[l]<<" ";
    cout<<endl;

    return 0;
}
