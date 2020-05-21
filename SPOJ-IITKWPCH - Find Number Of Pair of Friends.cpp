
/// Time -0.060s
/// it is basically bitmask and counting problem
/// which number is on in a number will be maintained by a state called mask
/// Just counting problem nothing else . you have to do it cleverly .
///The total number of digits can be 10 ,
///so there can 2^10 sets which will represent a mask
///that represents how many positions (digit) are on that mask ,take count of those mask . simple calculation.

#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll freq[1025];

/// there will be atmost 10 digits ,so the number of sets will be 2^10=1024
/// we will count the state this will give us answer
/// every state of 1024 sets will specify which digits are remaining on here ,it is our advantage .like 12 ,so our state 2^1 + 2^2 = 6 [0 0 0 0 0 1 1 0] states for 10 numbers .where 1 and 2 positions have one which in turn makes sense to us this state contains 1 and 2 digits.

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n;
    ll val;
    cin>>t;
    while(t--)
    {
        memset(freq,0,sizeof(freq));
        cin>>n;
        /// Total this part  will take maximum O(n*18) time complexity .
        for(int i=0;i<n;i++)
        {
                cin>>val;
                int mask=0ll;
                while(val)/// make mask containing the digits on .this while loop takes maximum O(18) time complexity in worst case for number 10^18 .
                {
                    int digit=val%10;
                    mask=mask|(1<<digit);/// 2^ digit1 + 2^ digit2 +............calculating
                    val=val/10ll;
                }
                freq[mask]++;/// keep frequency of every mask.
        }
        ll ans=0ll;

        /// total this part will take O(1024*1024) time complexity
        for(int i=0;i<1024;i++) /// till 2^10
        {
            ans+=(freq[i] * (freq[i] - 1)) / 2ll; /// how many pairs will be among numbers whose have same digits
            for(int j=i+1;j<1024;j++)
            {
                if(i&j)/// any digit common between i mask and j mask
                {
                    ans+=(freq[i] * freq[j]);
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
