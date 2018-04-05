#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int Q,type,marks;
    string s;

    cin>>Q;

    map<string , int> m;

    for(int i=0;i<Q;i++)
    {
        cin>>type>>s;
        if(type == 1)
        {
            cin>>marks;
            m[s] += marks;
        }
        else
        if(type == 2)
            m.erase(s);
        else
            cout<<m[s]<<endl;
    }
}
