template <class T>
class AddElements
{
public:
    T element;
    AddElements(T x) : element(x) {}
    T add(T x)
    {
        return (element+x);
    }
};
template <>
class AddElements <string>
{
public:
    string element;
    AddElements(string s) : element(s) {}
    string concatenate(string s1)
    {
        return (element+s1);
    }
};
