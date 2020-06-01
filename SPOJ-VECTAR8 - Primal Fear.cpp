
///  Sieve implementation and some other logic 
/// Time-0.18s

#include<bits/stdc++.h>

 using namespace std;

 const int mx=1000001;

 int status[mx];
 int dp[mx];

 void sieve()
 {
     int i, j;
     int sqrtn=sqrt(mx)+1;
     for(i = 2; i <=sqrtn; i += 1) /// we will not iterate through only sqrt ,because many prime numbers will not be cover by dp,as they will not be iterated
     {
		 if(status[i]==0)
		 {
	 		 for( j = 2*i; j <mx; j += (i) )
			 {
				 status[j]=1;
	 		 }
		 }
	 }
	 status[0]=status[1]=1;
 }

 bool ok(int n)
 {
     int ten=10;
     bool chck=true;
     while(n%ten!=n)
     {
         int x=n%ten;
         if(status[x]==1)
         {
             chck=false;
             break;
         }
         ten*=10;
     }
     return chck;
 }

 bool zero(int n)
 {
     bool okk=false;
     while(n)
     {
         if(n%10==0)
         {
             okk=true;
             break;
         }
         n=n/10;
     }
     return okk;
 }

 int main()
 {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     sieve();
     for(int i=2;i<mx;i++)
     {
         if(status[i]==0)/// prime
         {
             if(!ok(i))
             {
                 status[i]=1;
             }
             if(zero(i))
             {
                 status[i]=1;
             }
         }
     }
     int cont=0;
     for(int i=0;i<mx;i++)
     {
         if(status[i]==0) cont++;
         dp[i]=cont;
     }
     int tc,n;
     cin>>tc;
     while(tc--)
     {
         cin>>n;
         cout<<dp[n]<<endl;
     }
     return 0;
 }
