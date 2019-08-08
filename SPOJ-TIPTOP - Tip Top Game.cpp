#include <bits/stdc++.h>
using namespace std;

int main()
{
int t ;
scanf("%d", &t);
int cs = 1;
while(t--)
{
long long int num;
scanf("%lld", &num);
long long int srt = sqrt(num) ;
if( srt*srt == num )
printf("Case %d: Yes\n", cs);
else
printf("Case %d: No\n", cs);
cs++;
}
}


