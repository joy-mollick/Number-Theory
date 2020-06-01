
///  Sieve implementation and dp 
/// Time-0.34s

#include<bits/stdc++.h>

 using namespace std;

 const int mx=1000001;

 bool status[mx];///
 int factor[mx];
 int ans[mx][11];
 int maxi=0;

 void sieve()
 {
     int i, j;
     factor[1]=0;
     for( i = 2; i <mx; i += 1 ) /// we will not iterate through only sqrt ,because many prime numbers will not be cover by dp,as they will not be iterated
     {
		 if( status[i]==0)
		 {
		     factor[i]=1;
	 		 for( j = 2*i; j <mx; j += (i) )
			 {
				 status[j]=1;
				 factor[j]++;
	 		 }
		 }
	 }
 }

 int main()
 {
      sieve();
      /// it will take O(mx*10)
      for(int i=1;i<mx;i++)
      {
          for(int k=0;k<=10;k++)
          {
              ans[i][k]=ans[i-1][k];
          }
          int factors=factor[i];/// taking factors
          ans[i][factors]+=1;
      }
      int tc,a,b,n;
      cin>>tc;
      while(tc--)
      {
          cin>>a>>b>>n;
          cout<<ans[b][n]-ans[a-1][n]<<endl;
      }
      return 0;
 }
