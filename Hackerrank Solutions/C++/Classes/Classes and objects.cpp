class Student
{
    int scores[5];
    int total=0;
public:

    void input(){ for(int i=0;i<5;i++){
            cin>>scores[i];
            total += scores[i];
        }}
    int calculateTotalScore(){return total;}
};
