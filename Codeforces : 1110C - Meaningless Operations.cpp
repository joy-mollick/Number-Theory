/// Codeforces : 1110C - Meaningless Operations.
/// Category : number theory + greedy.


/// it is very obvious that,when a is given,b can be in the range 0<b<a
/// then  b should be chosen to make xor (a^b)=1111111111.... and and will be 0
/// So,gcd will be 11111111111..... which will be maximum
/// when given a is in the form 2^k -1 (1111....)
/// Then take the maximum one below b which is the divisor of b
/// when a is in the form of 2^k -1
/// Then for any b , (a^b)=a-b, and (a&b)=b
/// gcd((a^b),(a&b)) = gcd( a-b, b ) = gcd( a, b)
/// So ,it's optimal to take big divisor of a.

#include<bits/stdc++.h>

using namespace std;

int solve(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            return (x/i);
        }
    }
    return 1;
}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int all_one[26];
    int two=1;

    for(int i=1;i<=25;i++)
    {
        two=two*2;
        all_one[i]=two-1;
    }

    int a,tc;

    cin>>tc;

    while(tc--)
    {

    cin>>a;

    bool flag=true;

    for(int i=1;i<=25;i++)
    {
        if(all_one[i]==a)
        {
            flag=false;
            break;
        }
    }

    /// if not in the form of 111....
    if(flag)
    {
       int cont=0;
       while(a)
       {
           cont++;
           a=a>>1;
       }
       cout<<((1<<cont)-1)<<'\n';
    }

    /// in the form of 1111....
    else
    {
        cout<<solve(a)<<'\n';
    }

    }

    return 0;
}
