#include<bits/stdc++.h>


using namespace std;

vector< pair<int,int> >v;

// Cramer's Eule finding the area of triangle 

int non_zero_area(int x1,int y1,int x2,int y2,int x3,int y3)
{
    return x1*(y2-y3)+y1*(x3-x2)+(x2*y3-y2*x3);
}


int main()

{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int x,y;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    if(n<3)
    {
        cout<<"0"<<endl;
        return 0;
    }
    int result=0;
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            for(int k=j+1;k<v.size();k++)
            {
                if(non_zero_area(v[i].first,v[i].second,v[j].first,v[j].second,v[k].first,v[k].second)) {result++;}
            }
        }
    }
    cout<<result<<endl;
}
