    #include<bits/stdc++.h>
     
    using namespace std;
     
    typedef unsigned long long ll;
     
    ll mod=1e9+7;
     
    ll sqroot(ll x) {
    	ll l = 0, r = 1e9 + 1;
    	while (l < r - 1) {
    		ll m = (l + r) / 2;
    		if (m * m > x)
    			r = m;
    		else
    			l = m;
    	}
    	return l;
    }
    vector<ll>powers_wthout_sqrs;
     
    void pre_cal()
     
    {
        ll mx=1e18;
        vector<ll>powers;
        for(ll i=2;i<=1000000;i++)
        {
            for(ll x=i*i*i;x<=mx;x=x*i)
            {
                powers.push_back(x);
                if(x>mx/i) {break;} // avoiding overflow
            }
        }
        sort(powers.begin(),powers.end());
        powers.erase(unique(powers.begin(),powers.end()),powers.end());//removing duplicate
     
        for(int i=0;i<powers.size();i++)
        {
            ll rt=sqroot(powers[i]);
            if(rt*rt==powers[i]) continue;//It will not be pushed in the final vector
            powers_wthout_sqrs.push_back(powers[i]);
        }
        sort(powers_wthout_sqrs.begin(),powers_wthout_sqrs.end());
    }
     
     
    int main()
     
    {
      pre_cal();
      int tc;
      cin>>tc;
      while(tc--)
      {
         ll l,r;
         cin>>l>>r;
         ll ans=0ll;
         ll powers_wthout_two=upper_bound(powers_wthout_sqrs.begin(),powers_wthout_sqrs.end(),r)-lower_bound(powers_wthout_sqrs.begin(),powers_wthout_sqrs.end(),l);
         ans=ans+powers_wthout_two;
         ans=ans+(sqroot(r))-sqroot(l-1);
         cout<<ans<<'\n';
      }
    }
