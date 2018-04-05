#include <iostream>
#include <string>
using namespace std;

int main() {
    string a,b,c,a1,b1;
    cin>>a;
    cin>>b;
    cout<<a.size()<<" "<<b.size()<<endl;
    cout<<(a+b)<<endl;
    a1=a;
    b1=b;
    a1[0] = b[0];
    b1[0] = a[0];

    cout<<a1<<" "<<b1;
    return 0;
}
