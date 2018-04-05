class Matrix
{
public:
    vector<vector<int> > a;

    Matrix operator+(Matrix y)
    {
        for (int m=0; m<y.a.size(); m++)
        {
            for (int n=0; n<y.a[0].size();n++)
                a[m][n] = a[m][n] + y.a[m][n];
        }
        return *this;
    }
};