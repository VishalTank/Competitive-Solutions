class D : public A,public B,public C
{

public:
    int val;
    //Initially val is 1
    D()
    {
        val = 1;
    }


    //Implement this function
    void update_val(int new_val)
    {
        while (!(new_val%2))
        {
            new_val /= 2;
            A::func(val);
        }
        while (!(new_val%3))
        {
            new_val /= 3;
            B::func(val);
        }
        while (!(new_val%5))
        {
            new_val /= 5;
            C::func(val);
        }

    }
    //For Checking Purpose
    void check(int); //Do not delete this line.
};
