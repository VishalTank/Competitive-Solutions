#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,q,k,x;
    cin >> n >> q;
    vector< vector<int> > v1;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        vector<int> v2;
        for(int j=0;j<k;j++)
        {
            cin>>x;
            v2.push_back(x);
        }
        v1.push_back(v2);
    }
    int a,b;
    for(int i=0;i<q;i++)
    {
        cin>>a>>b;
        cout<<v1[a][b]<<endl;
    }
    return 0;
}
