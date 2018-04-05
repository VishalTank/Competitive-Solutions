#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector <int> v;
    int N,value;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>value;
        v.push_back(value);
    }
    int x,a,b;
    cin>>x>>a>>b;

    v.erase(v.begin()+x-1);
    v.erase(v.begin()+a-1,v.begin()+b-1);
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";

}