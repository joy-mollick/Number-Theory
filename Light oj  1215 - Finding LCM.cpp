
/// Time -0.005s
/// Light oj ->  1215 - Finding LCM.
/// GCD Magic and math .

/// LCM(a,b,c)=L 
/// LCM(LCM(a,b),c)=L
/// M=LCM(a,b)
/// LCM(M,c)=L
/// (M*c)/gcd(M,c)=L
/// c= gcd(M,c)*L / M 
/// So , c is obviously divisor of L 
/// So , start from L/M ( c = L/M ) 
/// Then check repeat 


#include<bits/stdc++.h>

#define LL long long

using namespace std;

LL gcd(LL a, LL b)
{
    if(!b)return a;
    else return gcd(b, a%b);
}


int main()

{
    LL T,a,b,L;
    int cas=0;
    cin>>T;

    while(T--)
    {
        cas++;
        cin>>a>>b>>L;
        LL gc=gcd(a,b);
        LL M=(a*b)/gc;/// lcm(a,b)

        LL c=L/M;/// starting value of c

        if(L%M!=0)
        {
            printf("Case %d: impossible\n",cas);
        }

        else{
        while(true)
        {
            LL g=gcd(M,c);
           /// cout<<g<<endl;
            if(g==1) break;
            c=c*g;
            M=M/g;
        }
        printf("Case %d: %lld\n",cas,c);
        }
    }
    return 0;
}
