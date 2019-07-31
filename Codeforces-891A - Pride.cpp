    #include<bits/stdc++.h>
    #include <iostream>
    #include <set>


    using namespace std;

    int main()

    {
        int n;
        cin>>n;
        int arr[n];
        int one=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]==1)
            {
                one++;
            }
        }
        if(one) // if one is already available in array then it's easy task
        {
            cout<<(n-one);
            return 0;
        }
        int mn_length=INT_MAX;
        // finding subarray whose numbers gcd is 1 O(n*n) , to make this subarray one 1, we need (mn_length-1) operations
        for(int i=0;i<n;i++)
        {
            int g=arr[i];
            for(int j=i+1;j<n;j++)
            {
                g=__gcd(g,arr[j]);
                if(g==1)
                {
                    mn_length=min(mn_length,j-i+1);
                }
            }
        }
        if(mn_length==INT_MAX)
        {
            cout<<"-1"<<endl;
        }
        else{
            cout<<(mn_length-1)+(n-1)<<endl;
        }
        return 0;
    }
