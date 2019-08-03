#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int counta[6]={0};
int countb[6]={0};

int a,b;

void prime_fact()
{
  while(a%2==0)
  {
        counta[2]++;
        a=a>>1;
  }
  while(a%3==0)
  {
      counta[3]++;
     a=a/3;
  }
  while(a%5==0)
  {
    counta[5]++;
     a=a/5;
  }

  while(b%2==0)
  {
        countb[2]++;
        b=b>>1;
  }
  while(b%3==0)
  {
      countb[3]++;
     b=b/3;
  }
  while(b%5==0)
  {
    countb[5]++;
     b=b/5;
  }

}
int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>a>>b;
    prime_fact();
    if(a!=b)
    {
        cout<<"-1"<<endl;
        //cout<<a<<" "<<b<<endl;
    }
    else{
        int sum=abs(counta[2]-countb[2])+abs(counta[3]-countb[3])+abs(counta[5]-countb[5]);
        cout<<sum<<endl;
    }
}

