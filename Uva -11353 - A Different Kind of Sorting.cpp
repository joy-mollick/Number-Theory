
///  Sieve implementation
/// Time-0.270s

#include<bits/stdc++.h>

 using namespace std;

 struct factor{
    int nmber_of_factors;
    int serial;
 };

 const int mx=2000000+1;

 bool status[mx];///
 factor dp[mx];

 void sieve()
 {
     int i, j;
     dp[1].nmber_of_factors=0;
     dp[1].serial=1;
     for( i = 2; i <mx; i += 1 ) /// we will not iterate through only sqrt ,because many prime numbers will not be cover by dp,as they will not be iterated 
     {
		 if( status[i]==0)
		 {
		     dp[i].serial=i;
		     dp[i].nmber_of_factors=1;/// prime number has only one factor
	 		 for( j = 2*i; j <mx; j += (i) )
			 {
				 status[j]=1;
				 dp[j].nmber_of_factors=dp[j/i].nmber_of_factors+1;/// it will count repeated prime factors also like 8 has 3 prime factors 
				 dp[j].serial=j;
	 		 }
		 }
	 }
 }

 bool comp( factor a, factor b)
 {
    if(a.nmber_of_factors==b.nmber_of_factors) return (a.serial<b.serial);
    else return (a.nmber_of_factors<b.nmber_of_factors);
 }

 int main()
 {
      sieve();
      sort(dp,dp+mx,comp);
      int n;
      int cas=1;
      while(scanf("%d",&n)&&n!=0)
      {
          printf("Case %d: %d\n",cas,dp[n].serial);
          cas++;
      }
      return 0;
 }
