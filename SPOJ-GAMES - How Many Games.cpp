#include <bits/stdc++.h>

using namespace std;


int main()

{
    int n;
    string s;
    cin>>n;
    while(n--)
    {
        cin>>s;
        int decimal_indx=0;
        int sz=(int)(s.size());
        bool is=false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='.')
            {
                decimal_indx=i;
                is=true;
                break;
            }
        }
        if(!is)
            cout<<"1"<<endl;
        else{
            int to=(sz-1)-decimal_indx;
            int one;
            if(to==1) one=10;
            else if(to==2) one=100;
            else if(to==3) one=1000;
            else if(to==4) one =10000;

            //cout<<one<<endl;
            int sum=0;
            for(int i=0;i<sz;i++)
            {
                if(s[i]!='.')
                sum=sum*10+(s[i]-'0');
            }
            int ans=__gcd(sum,one);
            cout<<(one/ans)<<endl;
        }
    }
}
