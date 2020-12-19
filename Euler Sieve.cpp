
/// maxn is max range 
/// Time complexity is approximately O(maxn) .Linear Time.

void euler_sieve()
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
}
