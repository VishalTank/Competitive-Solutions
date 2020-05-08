#include <bits/stdc++.h>
using namespace std;

void memsetEx() {

	char s[] = "Vishal";
	char m = 'm';
	memset(s,m,sizeof(s));
	cout<<s<<endl;
}

void printPrime(int a, int b) {

	if(a > b)
		swap(a, b);
		
	while(a < b) {
		int flag = 0;
		
		for(int i=2; i*i <= a; i++) {
			if(a%i == 0) {
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			cout<<a<<" ";
			
		a++;
	}
}

void checkArmstrong(int n,int len) {
	
	int sum = 0,temp = n;
	while(temp != 0) {
		sum += pow(temp%10, len);
		temp /= 10;
	}
	if(sum == n)
		cout<<"\n"<<sum<<" Armstrong.\n";
	else
		cout<<"\n"<<sum<<" Not Armstrong.\n";
}

int intLength(int n) {

	int count = 0;
	
	while(n != 0) {
		count++;
		n /= 10;
	}
	return count;
}

int countBits(int a, int b) {
	
	int n = a^b, count = 0;
	
	while(n) {
		count += n & 1;
		n >>= 1;
	}
	
	return count;
}

void maxHeapify(int a[], int n, int i) {
	
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	
	if(left < n && a[left] > a[largest])
		largest = left;
		
	if(right < n && a[right] > a[largest])
		largest = right;
		
	if(largest != i) {
		swap(a[largest], a[i]);
		maxHeapify(a, n, largest);
	}
}

void heapSort(int a[], int n) {
	
	for(int i=(n/2)-1;i>=0;i--)
		maxHeapify(a, n, i);
		
	for(int i=n-1;i>=0;i--) {
		swap(a[0], a[i]);
		maxHeapify(a, i, 0);
	}
}

void printArray(int a[], int n) {
	
	cout<<endl;
	
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
		
	cout<<endl;
}


struct Node {
	int data;
	struct Node* next;
};

struct Queue {
	struct Node *front, *rear;
};

struct Node* createNode(int data) {
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	
	temp->data = data;
	temp->next = NULL;
	
	return temp;
}

struct Queue* createQueue() {
	struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	
	return q;
}

void enQueue(struct Queue *q, int data) {
	
	struct Node *temp = createNode(data);
	
	if(q->rear == NULL) {
		q->rear = q->front = temp;
		return;
	}
	
	q->rear->next = temp;
	q->rear = temp;
}

struct Node* deQueue(struct Queue *q) {
	
	if(q->front == NULL)
		return NULL;
		
	struct Node *temp = q->front;
	q->front = q->front->next;
	
	if(q->front == NULL)
		q->rear == NULL;
	
	return temp;
}

void printQueue(struct Queue *q) {
	
	struct Node *temp = q->front;
	while(temp != NULL) {
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

unsigned char swapNibbles(unsigned char x) {
	unsigned char temp1 = x & 0x0F, temp2 = x & 0xF0;

	temp1 <<= 4;
	temp2 >>= 4;
	
	unsigned char temp = temp1 | temp2;
	return temp;
}

struct node {
	int data;
	struct node *next;
};

void printMiddle(struct node *head) {
	
	struct node *fast = head;
	struct node *slow = head;
	
	while(fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
		
	cout<<slow->data<<endl;
}

bool powerOf2(int x) {
	
	return !(x&(x-1));
}

int patternFinder(string s) {
	
	int count = 0, last = s[0];
	
	for(int i=1;i<s.length();i++) {
		
		if(s[i] == '0' && last == '1') {
			while(s[i] == '0')
				i++;
				
			if(s[i] == '1')
				count++;
			
			last = s[i];
		}
	}
	
	return count;
}

void swap(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

void NGN(char a[], int n) {
	
	int i,j;
	
	for(i=n-1;i>0;i--)
		if(a[i] > a[i- 1])
			break;
			
	if(i == 0)
		cout<<"\nNot Possible.";
		
	int d = a[i-1],smallest = i;
	cout<<"d"<<d<<"d "<<i<<"i";
	
	for(j = i+1;j<n;j++)
		if(a[j] > d && a[j] < a[smallest])
			smallest = j;
			
	swap(&a[smallest], &a[i-1]);
	sort(a+i, a+n);
	
	cout<<a<<endl;
}

int main() {

	memsetEx();
	printPrime(1,20);
	checkArmstrong(371,intLength(371));
	cout<<countBits(10,20);
	
	int a[] = {12,11,13,6,8,224,634,1,12,57,8,52};
	heapSort(a, sizeof(a)/sizeof(a[0]));
	printArray(a, sizeof(a)/sizeof(a[0]));
	
	struct Queue *q = createQueue();
	enQueue(q,10);
	enQueue(q,20);
	enQueue(q,30);
	enQueue(q,40);
	enQueue(q,50);
	printQueue(q);
	struct Node *temp = deQueue(q);
	cout<<temp->data<<endl;
	printQueue(q);
	
	cout<<(int)swapNibbles(100)<<endl;
	
	cout<<powerOf2(10)<<endl;
	
	cout<<patternFinder("1001ab010abc01001")<<endl;
	
	char digit[] = "534976";
	NGN(digit,strlen(digit));
	
	
	return 0;
}