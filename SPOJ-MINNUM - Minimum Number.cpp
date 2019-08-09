#include <bits/stdc++.h>

using namespace std;


string longDivision(string number, int divisor)
{
    string ans;
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
       temp = temp * 10 + (number[++idx] - '0');

    while (number.size() > idx)
    {
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + (number[++idx] - '0');
    }
    if (ans.length() == 0)
        return "0";

    return ans;
}

bool remainder(string str)
{
    int n = str.size();
    int digitSum = 0;
    for (int i=0; i<n; i++){
        digitSum += (str[i]-'0');}

    if(digitSum%9==0)
        return false;

    else
        return true;
}

string increase_1(string s)
{
    string ans="";
    int carry=0;
    int sz=s.size();
    int digit=s[sz-1]-'0';
    if(digit==9) {carry=1;}
    digit=digit+1;
    digit=digit%10;ans+=digit+'0';
    for(int i=sz-2;i>=0;i--)
    {
       digit=s[i]-'0';
       if(carry){
       digit=digit+1;
       }
       carry=digit/10;
       digit=digit%10;
       ans+=digit + '0';
    }
    if(carry)
    {
        ans=ans+'1';
    }
    return ans;
}

int main()
{
    string s,ans;
    while(cin>>s&&(s!="-1"))
    {
        string t=longDivision(s,9);
        //cout<<t<<endl;
        if(!remainder(s))
        {
            cout<<t<<endl;
        }
        else{
            ans=increase_1(t);
            for(int j=ans.size()-1;j>=0;j--)
            {
                cout<<ans[j];
            }
            cout<<endl;
        }
    }
}
