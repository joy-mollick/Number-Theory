
/// Codeforces : D. Alex and Julian.
/// Category : number theory +greedy.


/// bad question explanation

#include<bits/stdc++.h>


using namespace std;

const int mx=300005;

typedef long long ll;

vector<ll>vec[64];

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll x,X;
    ll n;
    cin>>n;
    for (int i = 1; i <= n; ++i)
	{
		cin>>x;
		X=x;
		int cnt = 0;
		while (x % 2ll == 0)
		{
			++cnt;
			x /= 2ll;
		}
		vec[cnt].push_back(X);
	}

	int mx = vec[0].size(), id = 0;

	for (int i = 1; i < 64; ++i)
    {
		if (vec[i].size() > mx)
		{
			mx = vec[i].size();
			id = i;
		}
    }

    /// delete all others
	cout<<(n-mx)<<endl;

	for (int i = 0; i < 64; ++i)
	{
		if (!vec[i].size() || i == id)
			continue;

		for(int j=0;j<vec[i].size();j++)
        {
            cout<<vec[i][j]<<" ";
        }
	}
	cout<<endl;

	return 0;
}
