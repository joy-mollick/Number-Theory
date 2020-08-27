
/// Codeforces: Div1 A. 24 Game
/// Category : math+greedy+observation.


#include<bits/stdc++.h>

using namespace std;


int main()

{
   int n;

   vector<string>v4;
   vector<string>v5;
   //4 , 1*2*3*4=24
   v4.push_back("1 * 2 = 2");
   v4.push_back("3 * 4 = 12");
   v4.push_back("12 * 2 = 24");
   //5 , (5-3)*4*(2+1)
   v5.push_back("5 - 3 = 2");
   v5.push_back("2 + 1 = 3");
   v5.push_back("2 * 4 = 8");
   v5.push_back("8 * 3 = 24");

   cin>>n;
    vector<string>ans;
   if(n<4) cout<<"NO"<<endl;

   else
   {
       cout<<"YES"<<endl;

       int dist;
       if(n%2==1)
         dist=n-5;
       else
        dist=n-4;

       dist/=2;
       if(n%2==1)
       {
           for(int i=0;i<4;i++) cout<<v5[i]<<endl;
       }
       else
       {
           for(int i=0;i<3;i++) cout<<v4[i]<<endl;
       }

       for(int j=0;j<dist;j++)
       {
           cout<<n<<" - "<<n-1<<" = 1"<<endl;
           n-=2;
       }

       while(dist--)
       {
           cout<<"24 * 1 = 24"<<endl;
       }

   }

   return 0;
}
