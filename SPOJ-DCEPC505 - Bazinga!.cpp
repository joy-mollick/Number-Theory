
///  Sieve implementation
/// Time-0.99s

#include<bits/stdc++.h>

 using namespace std;

 const int mx=5300001;

 int status[mx];
 vector<int>primes;
 vector<long long>ans;

 void sieve()
 {
     int i, j;
     int sqrtn=sqrt(mx);
     for(i = 2; i <sqrtn; i += 1) /// we will not iterate through only sqrt ,because many prime numbers will not be cover by dp,as they will not be iterated
     {
		 if(status[i]==0)
		 {
	 		 for( j = 2*i; j <mx; j += (i) )
			 {
				 status[j]=1;
	 		 }
		 }
	 }
	 primes.push_back(2);
	 for(int i=3;i<mx;i+=2)
     {
         if(status[i]==0) primes.push_back(i);
     }
 }

 int main()
 {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
      sieve();
      int sz=primes.size();
      for(int i=0;i<sz;i++)
      {
          for(int j=i+1;j<sz;j++)
          {
              if(10527449<((long long)primes[i]*(long long)primes[j])) break;/// 2000000th number is 10527449 
              ans.push_back((long long)primes[i]*(long long)primes[j]);
          }
      }
      sort(ans.begin(),ans.end());
      int tc,n;
      cin>>tc;
      while(tc--)
      {
          cin>>n;
          n--;
          cout<<ans[n]<<endl;
      }
      return 0;
 }
