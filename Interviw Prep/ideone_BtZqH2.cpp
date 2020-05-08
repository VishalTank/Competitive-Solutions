#include <bits/stdc++.h>
#define n 4

using namespace std;

void swap(int &a,int &b) {
	a = a+b;
	b = a-b;
	a = a-b;
}

void transpose(int a[n][n]) {
	for(int i=0;i<n;i++) {
		for(int j=i;j<n;j++)
			swap(a[i][j],a[j][i]);
	}
}

void reverseColumns(int a[n][n]) {
	for(int i=0;i<n;i++) {
		
		int k = n-1;
		for(int j=0;j<k;j++) {
			swap(a[j][i],a[k][i]);
			k--;
		}
	}
}

void reverseRows(int a[n][n]) {
	for(int i=0;i<n;i++) {
		
		int j = 0;
		int k = n-1;
		while(j <= k) {
			swap(a[i][j],a[i][k]);
			j++;
			k--;
		}
	}
}

void rotate90Anti(int a[][n]) {
	for(int i=0;i<n/2;i++) {
		
		for(int j=i;j<n-i-1;j++) {
			
			//current to temp
			int temp = a[i][j];
			
			//right to top
			a[i][j] = a[j][n-i-1];
			
			//bottom to right
			a[j][n-i-1] = a[n-i-1][n-j-1];
			
			//left to bottom
			a[n-i-1][n-j-1] = a[n-j-1][i];
			
			//temp to left
			a[n-j-1][i] = temp;
		}
	}
}

void rotate90Anti1(int a[][n]) {
	transpose(a);
	reverseColumns(a);
}

void rotate90(int a[][n]) {
	transpose(a);
	reverseRows(a);
}



void createMatrix(int a[n][n]) {
	int k=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++)
			a[i][j] = k++;
	}
}

void printMatrix(int a[][n]) {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<"	";
		cout<<endl;
	}
	cout<<endl;
}

int main() {
	// your code goes here
	int a[n][n] = {{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}};
	printMatrix(a);
	rotate90Anti(a);
	printMatrix(a);
	cout<<endl;
	
	createMatrix(a);
	printMatrix(a);
	reverseRows(a);
	printMatrix(a);
	reverseColumns(a);
	printMatrix(a);
	cout<<endl;
	
	createMatrix(a);
	printMatrix(a);
	rotate90(a);
	printMatrix(a);
	cout<<endl;
	
	createMatrix(a);
	printMatrix(a);
	rotate90(a);
	printMatrix(a);
	cout<<endl;
	return 0;
}