#include<iostream>

using namespace std;

class Box
{
    long long int l,b,h;
public:
    Box()
    {
        l=b=h=0;
    }
    Box(int length,int breadth,int height)
    {
        l=length;
        b=breadth;
        h=height;
    }
    Box(Box &B)
    {
        l=B.l;
        b=B.b;
        h=B.h;
    }
    int getLength(){return l;}
    int getBreadth(){return b;}
    int getHeight(){return h;}
    long long int CalculateVolume(){return (l*b*h);}

    bool operator<(Box B)
    {
        if(l<B.l) return true;
        if(l>B.l)return false;
        if(b<B.b)return true;
        if(b>B.b)return false;
        return h<B.h;
    }
    friend ostream &operator<<(ostream &obj,Box B)
    {
        return obj<<B.l<<" "<<B.b<<" "<<B.h;
    }
};

