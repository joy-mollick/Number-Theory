    #include<bits/stdc++.h>
    #include <iostream>
    #include <set>


        using namespace std;
        int nmbrtheory(int n,int m)
        {
            int ans=0;
            while( n>0 && m>0 )
            {
                if(n>m)
                {
                    n=n-2;
                    m=m-1;
                    if(n<0||m<0)
                    {
                        break;
                    }
                }
                else{
                    n=n-1;
                    m=m-2;
                    if(n<0||m<0)
                    {
                        break;
                    }
                }
                ans++;
            }
            return ans;
        }

        int main()
        {
            int n,m;
            cin>>n>>m;
            cout<<nmbrtheory(n,m)<<endl;

        }
