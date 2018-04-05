/* Define the exception here */
class BadLengthException: public exception {
    int N;
public:
    BadLengthException(int N){this->N = N;}
    int what(){return N;}
};
