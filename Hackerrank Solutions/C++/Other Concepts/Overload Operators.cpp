Complex operator+(Complex c1,Complex c2)
{
    Complex temp;
    temp.a= c1.a + c2.a;
    temp.b = c1.b + c2.b;
    return temp;
}
ostream & operator<<(ostream &out, Complex &c)
{
    if(c.b<0) out<<c.a<<"-i"<<c.b;
    out<<c.a<<"+i"<<c.b;
    return out;
}
