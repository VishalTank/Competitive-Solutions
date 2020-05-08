#include <bits/stdc++.h>

using namespace std;

void pattern1(int n) {
	cout<<"\npattern 1 : \n";

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++)
			cout<<i<<","<<j<<" ";
		cout<<endl;
	}
}

void pattern2(int n) {
	cout<<"\npattern 2 : \n";
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<=i;j++)
			cout<<"*";
		cout<<endl;
	}
}

void pattern3(int n) {
	cout<<"\npattern 3 : \n";
	
	for(int i=0;i<n;i++) {
		for(int j=i;j<n;j++)
			cout<<"*";
		cout<<endl;
	}
}

void pattern4(int n) {
	cout<<"\npattern 4 : \n";
	
	int k = n-1;
	
	for(int i=0;i<n;i++) {
		
		for(int j=0;j<k;j++)
			cout<<" ";
		
		k--;;
		
		for(int j=0;j<=i;j++)
			cout<<"*";
		
		cout<<endl;
	}
}

void pattern5(int n) {
	cout<<"\npattern 5 : \n";
	
	for(int i=0;i<n;i++) {
		
		for(int j=0;j<i;j++)
			cout<<" ";
			
		for(int j=0;j<n-i;j++)
			cout<<"*";
		
		cout<<endl;
	}
}

void pattern6(int n) {
	cout<<"\npattern 6 : \n";
	
	int k = 0;
	for(int i=n-1;i>=0;i--) {
		
		for(int j=0;j<i;j++)
			cout<<" ";
		
		for(int j=0;j<=k;j++)
			cout<<"* ";
			
		k++;
		cout<<endl;
	}
}

void pattern7(int n) {
	cout<<"\npattern 7 : \n";
	
	for(int i=n-1;i>=0;i--) {
		
		for(int j=n-1;j>=i;j--)
			cout<<" ";
			
		for(int j=0;j<=i;j++)
			cout<<"* ";
			
		cout<<endl;
	}
}

void pattern8(int n) {
	cout<<"\npattern 8 : \n";
	
	for(int i=0;i<n;i++) {
		for(int j=i;j<n;j++)
			cout<<" ";
			
		for(int k=0;k<i*2-1;k++)
			cout<<"*";
		
		cout<<endl;
	}
	
	for(int i=n-1;i>=0;i--) {
		for(int j=n;j>i;j--)
			cout<<" ";
			
		for(int k=0;k<i*2-1;k++)
			cout<<"*";
		
		cout<<endl;
	}
}

void pattern9(int n) {
	cout<<"\npattern 9 : \n";
	
	int k = n-1;
	for(int i=0;i<n;i++) {
		
		for(int j=0;j<k;j++)
			cout<<" ";
		
		k--;
		
		for(int j=0;j<2*i-1;j++)
			cout<<"*";
			
		cout<<endl;
	}
	
	k = 0;
 
	for (int i=0; i<n-1;i++) {
	
		for (int j=0;j<k;j++)
			cout<<" ";
	
		k++;
	
		for(int j=0;j<2*(n-i-1)-1;j++)
			cout<<"*";
	
		cout<<endl;
	}
}

void pattern10(int n) {
	cout<<"\npattern 10 : \n";
	
	int k = 1;
	for(int i=0;i<n;i+=2) {
		for(int j=n-1;j>=0;j--) {
			if(j > i)
				cout<<" ";
			else
				cout<<k++;
		}
		cout<<endl;
	}
}

void pattern11(string s) {
	cout<<"\npattern 11 : \n";
	
	for(int i=0;i<s.length();i++) {
		for(int j=0;j<=i;j++)
			cout<<s[j];
		cout<<endl;
	}
}

void pattern12(int n) {
	cout<<"\npattern 12 : \n";
	
	//upper
	for(int i=0;i<n;i++) {
		for(int j=0;j<2*n;j++) {
			
			//left
			if(i > (n-j))
				cout<<" ";
			else
				cout<<"*";
			//right	
			if(i > (j-n))
				cout<<" ";
			else
				cout<<"*";
		}
		cout<<endl;
	}
	
	//bottom
	for(int i=0;i<n;i++) {
		for(int j=0;j<2*n;j++) {
			
			//right
			if(i < j)
				cout<<" ";
			else
				cout<<"*";
			//left	
			if(i < (2*n)-j-1)
				cout<<" ";
			else
				cout<<"*";
		}
		cout<<endl;
	}
}

void pattern13(int n) {
	cout<<"\npattern 13 : \n";
	
	for(int i=0;i<n;i++) {
		
		for(int j=0;j<2*n;j++) {
			if(i < j)
				cout<<" ";
			else
				cout<<"*";
				
			if(i < (2*n)-j-1)
				cout<<" ";
			else
				cout<<"*";
		}
		cout<<endl;
	}
	
	for(int i=0;i<n;i++) {
		
		for(int j=0;j<2*n;j++) {
			if(i >= (n-j))
				cout<<" ";
			else
				cout<<"*";
			
			if(i > (j-n))
				cout<<" ";
			else
				cout<<"*";
		}
		cout<<endl;
	}
}

void pattern14(int n) {
	cout<<"\npattern 14 : \n";
	
	int k = n-1;
	
	for(int i=0;i<n;i++) {
		
		for(int j=0;j<k;j++)
			cout<<"1";
		
		k--;;
		
		for(int j=0;j<=i;j++)
			cout<<i+1;
		
		cout<<endl;
	}
}

void pattern15(int n) {
	cout<<"\npattern 15 : \n";
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<=i;j++)
			cout<<j+1<<" ";
		cout<<endl;
	}
	
	for(int i=n-1;i>=0;i--) {
		for(int j=0;j<i;j++)
			cout<<j+1<<" ";
		cout<<endl;	
	}
}

void pattern16(int n) {
	cout<<"\npattern 16 : \n";
	
	for(int i=0;i<n;i++) {
		
		for(int j=0;j<i;j++)
			cout<<" ";
			
		for(int j=0;j<n-i;j++)
			cout<<j+1<<" ";
		
		cout<<endl;
	}
}

void pattern17(int n) {
	cout<<"\npattern 17 : \n";

	for (int i=0;i<n;i++) {
	            for (int j=0;j<i;j++)
	            	cout<<" ";
	             
	            for (int j=i;j<=n;j++)
	            	cout<<j+1<<" ";
	             
	            cout<<endl; 
	} 
	     
	for (int i=n-1;i>=0;i--) { 
	            for (int j=0;j<i;j++)
	                cout<<" ";
	             
	            for (int j=i;j<=n;j++)
	            	cout<<j+1<<" ";
	             
	            cout<<endl;
	}
}

void pattern18(int n) {
	cout<<"\npattern 18 : \n";
	
	int k = 0;
	for(int i=n-1;i>=0;i--) {
		//print i spaces in the begninning of each row
		for(int j=0;j<=i;j++)
			cout<<" ";
			
		//print k's value k times at the end of each row
		for(int j=0;j<=k;j++)
			cout<<k+1<<" ";
		
		k++;	
		cout<<endl;
	}
}

void pattern19(int n) {
	cout<<"\npattern 19 : \n";
	
	int k = 0;
	for(int i=n-1;i>=0;i--) {
		//print i spaces in the begninning of each row
		for(int j=0;j<=i;j++)
			cout<<" ";
			
		//print k's value k times at the end of each row
		for(int j=0;j<=k;j++)
			cout<<j+1<<" ";
		
		k++;	
		cout<<endl;
	}
}

void pattern20(int n) {
	cout<<"\npattern 20 : \n";
	
	int k = 1;
	for(int i=n;i>0;i--) {
		
		for(int j=1;j<=2*i;j++)
			cout<<" ";
			
		for(int j=1;j<=k;j++)
			cout<<j<<" ";
			
		for(int j=k-1;j>=1;j--)
			cout<<j<<" ";
			
		cout<<endl;
		k++;
	}
}

void pattern21(int n) {
	cout<<"\npattern 21 : \n";
	
	int k = n;
	for(int i=0;i<n;i++) {
		
		for(int j=1;j<=2*i;j++)
			cout<<" ";
			
		for(int j=1;j<=k;j++)
			cout<<j<<" ";
			
		for(int j=k-1;j>=1;j--)
			cout<<j<<" ";
			
		cout<<endl;
		k--;
	}
}

void pattern22(int n) {
	cout<<"\npattern 22 : \n";
	
	for(int i=n;i>=1;i--) {
		
		for(int j=1;j<=2*i;j++)
			cout<<" ";
			
		for(int j=i;j<=n;j++)
			cout<<j+1<<" ";
			
			
		for(int j=n-1;j>=i;j--)
			cout<<j+1<<" ";
			
		cout<<endl;
	}
}

void pattern23(int n) {
	cout<<"\npattern 23 : \n";
	
	int k = n-1;
	
	for(int i=0;i<n;i++) {
		
		for(int j=0;j<k;j++)
			cout<<" ";
		
		k--;;
		
		for(int j=0;j<=i;j++)
			cout<<"*";
		
		cout<<endl;
	}
	
	for(int i=1;i<n;i++) {
		
		for(int j=0;j<i;j++)
			cout<<" ";
			
		for(int j=0;j<n-i;j++)
			cout<<"*";
		
		cout<<endl;
	}
}

void pattern24(int n) {
	cout<<"\npattern 24 : \n";
	
	n++;
	int k = 0;
	for(int i=n;i>=1;i--) {
		
		for(int j=1;j<=2*i;j++)
			cout<<" ";
			
		for(int j=i;j<=n;j++) {
			cout<<k<<" ";
			k--;
		}
			
		k = 1;
		for(int j=n-1;j>=i;j--) {
			cout<<k<<" ";
			k++;
		}
			
		cout<<endl;
	}
}

int main() {
	pattern24(5);
	pattern23(5);
	pattern22(5);
	pattern21(5);
	pattern20(5);
	pattern19(5);
	pattern18(5);
	pattern17(5);
	pattern16(5);
	pattern15(5);
	pattern14(5);
	pattern13(5);
	pattern12(5);
	pattern11("Vishal");
	pattern10(5);
	pattern9(5);
	pattern8(5);
	pattern7(5);
	pattern6(5);
	pattern5(5);
	pattern4(5);
	pattern3(5);
	pattern2(5);
	pattern1(5);
	
	return 0;
}