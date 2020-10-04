
/// Codeforces : 635C - XOR Equation.
/// Category : number theory + bit manipulation.


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll xr;
    ll sum;
    cin>>sum>>xr;

    /// (a+b) = (a^b) + (a&b)*2 , ^ denotes for xor
    /// (a&b)*2 = (a+b)-(a^b)
    /// (a&b) = (sum-xor)/2;
    ///  how many a and b are available
    ///  if ((xor>>i)&1 == 1) then obviously a and b should hold in that bit 1 and or 0 and 1
    /// but if in that bit position ((a&b)>>i)&1==0 ,then it is not possible , there is no solution.

    ll diff=(sum-xr);
    ll a_and_b= (diff>>1ll);

    if(diff<0 || (diff%2ll==1ll)) {cout<<"0"<<endl;return 0;}

    else

    {
        ll ans=1ll;
	for(int i=0;i<=60;i++)
	{
		if((xr>>i)&1ll)
		{
			if((a_and_b>>i)&1ll)
			{
			  /// when both is 1 then it is impossible
				cout<<"0"<<endl;
				return 0;
			}
			else ans=(ans*2ll);
		}
	}
    /// if xr then of course (0,xr) and (xr,0) are not valid pair 
	if(xr==sum) ans-=2ll;
	cout<<ans<<endl;
    }

	return 0;
}
