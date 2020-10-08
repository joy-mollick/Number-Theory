
/// How many unordered pairs (a,b) till N , so that  a xor b = gcd(a,b)
/// Category : number theory.


/*
   We have to count such a and b so that gcd(a,b)=a xor b = g.
   a xor b=g . -> a xor g =b
   gcd(a,b) = gcd(a-b , b) = g
   So, g<= (a-b)
   It is obvious that a xor b >= (a-b) , g>= (a-b)

   So , g<= (a-b) and g>= (a-b) imply that g = (a-b). i.e. b= a-g.

    b = a xor g = a - g.

    So , it is mandatory to check ->  a xor g = a - g.

    where a is obviously multiple of g. It is our trick.

    Take any number g and check from its double i.e. 2*g till up N.
*/


#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n;
	cin>>n;
	int ans=0;

	for(int g=1;g<=n/2;g++)
    {
	  for(int a=g*2;a<=n;a+=g)
      {
	    if((a^g)==(a-g)) ans++;
	  }
	}

	cout<<ans<<endl;
}
