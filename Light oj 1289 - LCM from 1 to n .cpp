
/// Time -2.340s
/// Light oj 1289 - LCM from 1 to n 
/// Number theory


/// Think about LCM (1,2,3,4,5,6,7,8,9,10) = LCM (1,2,3,2^2,5,2x3,7,2^3,3^2,5x2)= 2^3 x 3^2 x 5 x 7 =  ( 2 x 3 x 5 x 7 )           x (2^2 x 3) = 2520
///                                                                                                 Products of primes before 10
/// Here One thing is that all primes should be marked before .
/// Here max range is 10^8 .
/// So we will use bitset as a boolean set


#include<bits/stdc++.h>

#define LL long long

using namespace std;

const int maxn = 1e8+5;
const int N = 5800000;

long long int mod=1ll<<32;
int tot;
bitset<maxn> vis;					//Bitset mark
unsigned int prime[N];							//Store the prime number sifted out
unsigned int pro[N];				//Store the prefix product of prime numbers


/// euler sieve , approximately full linear time O(maxn)

void make_prime()
{
	for(int i = 2; i < maxn; i++)		//Euler Sieve
	{
		if(!vis[i])	prime[tot++] = i;
		/// marking all multiples of prime
		for(int j = 0; j < tot && i * prime[j] < maxn; j++)
		{
		    /// marked as visited
			vis[i*prime[j]] = 1;
			if(i%prime[j]==0)	break;
		}
	}

	pro[0] = 2ll;
	for(int i = 1; i < tot; i++)		///Prefix product
		pro[i] = pro[i-1] * prime[i];
}

long long int Pow(long long int a, int b)		///Quick Power
{
	long long int ans = 1ll;
	long long int base = a;
	while(b)
	{
		if(b&1ll) ans = (ans*base)%mod;
		base =(base*base)%mod;
		b=b>>1ll;
	}
	return (ans%mod);
}



int main()

{
    make_prime();
    long long int n;
    int T;
    int cas=0;
    cin>>T;

    while(T--)
    {
        cas++;

        cin>>n;

        int pos = upper_bound(prime, prime+tot, n) - prime;		/// Binary search for the first prime number greater than n
                     pos=pos-1;                   /// pos-1 find the largest prime number smaller than n

		long long int ans = pro[pos]%mod;
		/// we will run till whose square is less than or equal to n
		/// Otherwise it can't have power greater than 1.
	    for(int i = 0; i < tot && prime[i] * prime[i] <= n; i++)
		{
	        long long tmp = n;

	        int k = 0;

	        while(tmp / prime[i])		/// Find the highest power of prime p[i]
			{
	            tmp /= prime[i];
	            k++;
	        }

	        k--;					/// Because one is already included in the prefix product, the highest power here is reduced by 1

	        ans = (ans * Pow(prime[i], k))%mod;
	    }

	    printf("Case %d: %lld\n", cas, ans);

    }
    return 0;
}
