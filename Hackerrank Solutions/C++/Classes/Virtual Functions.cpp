class Person
{
protected:
    int age;
    string name;
public:
    virtual void getdata()=0;
    virtual void putdata()=0;
};

class Professor : public Person
{
    int publications,id1;
    static int cur_id1;
public:

    void getdata()
    {
        ++cur_id1;
        cin>>name>>age>>publications;
        id1=cur_id1;
    }
    void putdata()
    {
        cout<<name<<" "<<age<<" "<<publications<<" "<<id1<<endl;
    }
};
int Professor::cur_id1=0;
class Student : public Person
{
    int marks[6],id2;
    static int cur_id2;
public:

    void getdata()
    {
        ++cur_id2;
        cin>>name>>age;
        for(int i=0;i<6;i++)
            cin>>marks[i];
        id2=cur_id2;
    }
    void putdata()
    {
        int total_marks=0;
        for(int i=0;i<6;i++)
            total_marks += marks[i];
        cout<<name<<" "<<age<<" "<<total_marks<<" "<<id2<<endl;
    }
};
int Student::cur_id2=0;