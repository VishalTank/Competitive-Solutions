try
{
Server s;
long long int result = s.compute(A,B);
cout<<result<<endl;
}
catch(bad_alloc ba){cout<<"Not enough memory"<<endl;}
catch(exception &e){cout<<"Exception: "<< e.what() <<endl;}
catch(...){cout<<"Other Exception"<<endl;}