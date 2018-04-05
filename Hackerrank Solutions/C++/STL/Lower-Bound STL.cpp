#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector <int> v;
    int N,value;
    cin>>N;
    while(N--)
    {
        cin>>value;
        v.push_back(value);
    }
    int Q,Y;
    cin>>Q;
    for(int i=0;i<Q;i++)
    {
        cin>>Y;
        if(v[lower_bound(v.begin(), v.end(), Y) - v.begin()] == Y)
            cout<<"Yes "<<(lower_bound(v.begin(), v.end(), Y) - v.begin() + 1)<<endl;
        else
            cout<<"No "<<(lower_bound(v.begin(), v.end(), Y) - v.begin() + 1)<<endl;
    }
}
