
/// Codeforces : 992D - Nastya and a Game.
/// Category : number theory + constructive .


/// Just jump over the piles of ones 

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


ll mx=2e62;

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N,K;

    cin>>N>>K;
    ll A[N];
    ll next[N];
	for(int i=0;i<N;i++) cin>>A[i];
	/// keeping first non one position after i
	int x=N;
	for(int i=N-1;i>=0;i--)
    {
		next[i]=x;
		if(A[i]!=1) x=i;
	}

	ll res=0ll;

	for(int i=0;i<N;i++)
    {
        int R=i;
		ll pro=1;
		ll sum=0;
		while(R<N)
        {
            /// if overflow ,no need to iterate
            /// because we have ensured that good subsequent product is less than 2^63
			if(mx/A[R]<pro) break;

			pro*=A[R];
			sum+=A[R];
           ///number of contiguous one ,we have to jump over it
			int ones=next[R]-R-1;

            /// now here is a tricky part
            /// when, sum*k<=pro implies we need some ones which can
            /// fill up sum ,so that K*sum==pro
            /// so, if pro/K -sum <=ones ,then we will take some ones from this ones bundle
            /// and fill up sum ,so ans is increased by one

            /// when there is no ones on that state
            /// then ones=0 , sum*K<=pro and pro<=sum*K hold the condition and ans will be increased.

			if(pro%K==0)
            {
				if(sum*K<=pro && pro<=(sum+ones)*K) res++;
			}
			sum+=ones;
			/// R will iterate after box of ones
			R=next[R];
		}

    }

    cout<<res<<endl;

	return 0;
}
