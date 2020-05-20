
/// Time - 0.040s
/// Inclusion-Exclusion principle

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

vector<bool>isPrime(1000001,1);
vector<int> primes(1000001,0);

void genPrimes(){
	for(int i=2;i*i<=1000000;i++){
		if(isPrime[i]){
			for(int j=i*i;j<=1000000;j+=i){
				isPrime[j]=0;
			}
		}
	}
	int cont=0;
	for(int i=2;i<=1000000;i+=1){
		if(isPrime[i]){
			cont++;
		}
		primes[i]=cont; /// how many primes till i
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    genPrimes();
    ll n,m;
    int tc;
    cin>>tc;
    int caso=0;
    while(tc--)
    {
        cin>>n>>m;
        caso++;
        ll arr[m];
         ll numbers_greater_than_n=0;
        for(int i=0;i<m;i++) {cin>>arr[i];if(arr[i]>n) numbers_greater_than_n++;}
        if(n <=3){ /// till 3 there is no composite numbers 
			cout <<"Case "<<caso<<": "<< "0" <<endl;
			continue;
		}
        /// now find how many numbers are divisible by anyone of from array of m
        int set_sz=(1<<m);/// 2^m is the number of sets
        ll multiples_of_anyone_of_array=0;
        for(int mask=1;mask<set_sz;mask++)
        {
            ll mult=1ll;
            int bits=0;
            bool check=true;
            for(int i=0;i<m;i++)
            {
                if(((1<<i)&mask)) /// ith element is here
                {
                    bits++;/// how many elements we choose
                    mult*=arr[i];///multiple of all prime elements of this set
                    if(mult>n) {check=false;break;}
                }
            }
            if(!check) continue;
            ll num_till_n=n/mult;/// how many multiples of multiple within n ?
            if(bits&1)/// inclusion, number of elements are odd
                multiples_of_anyone_of_array+=num_till_n;
            else /// exclusion ,number of elements are even
                multiples_of_anyone_of_array-=num_till_n;
        }
        ll ans=n-multiples_of_anyone_of_array;
        ll prm_till_n =primes[n];
        ans=ans-prm_till_n+m;/// when all multiples till n has been removed m primes also removed ,so here again after prm_till_n it is subtracted twice so add m again .
        ans=ans-1;/// 1 itself not composite number,so subtract this
        ans=ans-numbers_greater_than_n;/// if anyone of m prime numbers are greater than n ,then subtract that because we added m to ans previously 
        cout<<"Case "<<caso<<": ";
        cout<<ans<<endl;
    }
}
