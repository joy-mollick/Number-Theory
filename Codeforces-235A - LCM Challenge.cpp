        #include<bits/stdc++.h>

        using namespace std;

        typedef unsigned long long ll;

        int main()

        {
            ll n;
            cin>>n;
            if(n<3)
            {
                cout<<n<<endl;
                return 0;
            }
            if(n&1)
            {
                cout<<n*(n-1)*(n-2)<<endl;
            }
            else
            {
                if(n%3==0)
                {
                    cout<<(n-1)*(n-2)*(n-3)<<endl;
                }
                else
                {
                    cout<<(n*(n-1)*(n-3))<<endl;
                }
            }

            return 0;
        }
