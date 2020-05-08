#include <bits/stdc++.h>

using namespace std;

int precedence(char);


//reverse stack using recursion
struct stackNode {
	int data;
	struct stackNode *next;
};

bool isEmpty(stackNode *top) {
	return (top == NULL) ? 1 : 0;
}

void push(stackNode **top,int data) {
	struct stackNode *newNode = (struct stackNode *)malloc(sizeof(struct stackNode));
	
	if (newNode == NULL) {
		printf("Stack overflow \n");
		exit(0);
	}
    
	newNode->data = data;
	newNode->next = (*top);
	(*top) = newNode;
}

int pop(stackNode **top) {
	char ans;
	stackNode *temp;
	
	if (*top == NULL) {
		printf("Stack overflow \n");
		exit(0);
	}else {
		temp = *top;
		ans = temp->data;
		*top = temp->next;
		
		free(temp);
		
		return ans;
	}
}

void insertAtBottom(stackNode **top,int data) {
	if(isEmpty(*top))
		push(top,data);
	else {
		int temp = pop(top);
		insertAtBottom(top,data);
		
		push(top,temp);
	}
}

void reverseStack(stackNode **top) {
	
	if(!isEmpty(*top)) {
		int temp = pop(top);
		reverseStack(top);
		
		insertAtBottom(top,temp);
	}
}


void printStack(stackNode *top) {
	while(top != NULL) {
		cout<<top->data<<"->";
		top = top->next;
	}
}

//reverse stack using temporary stack
void reverseStack(stack<int> s) {
	stack<int> tempStack;
	
	while(!s.empty()) {
		int temp = s.top();
		s.pop();
		
		while(!tempStack.empty() && tempStack.top() > temp) {
			s.push(tempStack.top());
			tempStack.pop();
		}
		tempStack.push(temp);
	}
	
	while(!tempStack.empty()) {
		cout<<tempStack.top()<<" ";
		tempStack.pop();
	}
}

//evaluate expressions
int applyOp(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

void evaluate(string s) {
	stack<int> operands;
	stack<int> operators;
	
	for(int i=0;i<s.length();i++) {
		
		if(isdigit(s[i]))
			operands.push(s[i]);
			
		else {
			while(!operators.empty() && precedence(operators.top()) >= precedence(s[i])) {
				int a = operands.top();
				operands.pop();
				
				int b = operands.top();
				operands.pop();
				
				char op = operators.top();
				operators.pop();
				
				operands.push(applyOp(a,b,op));
			}
			operators.push(s[i]);
		}
	}
	
	cout<<operands.top()<<endl;
}

// next greater element
void NGE(int a[],int n) {
	stack<int> s;
	
	s.push(a[0]);
	
	for(int i=1;i<n;i++) {
		while(!s.empty() && s.top() < a[i]) {
			cout<<s.top()<<"	"<<a[i]<<endl;
			s.pop();
		}
		
		s.push(a[i]);
	}
	
	while(!s.empty()) {
		cout<<s.top()<<"	-1"<<endl;
		s.pop();
	}
}

//infix to postfix
int precedence(char c) {
	if(c == '^')
		return 3;
	else if(c == '/' || c == '*')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else
		return -1;
}

void infixToPostfix(string str) {
	stack<int> s;
	s.push('N');
	
	string final_str;
	
	for(int i=0;i<str.length();i++) {
		
		if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			final_str += str[i];
			
		else if(str[i] == '(')
			s.push('(');
			
		else if(str[i] == ')') {
			while(s.top() != 'N' && s.top() != '(') {
				char c = s.top();
				s.pop();
				
				final_str += c;
			}
			
			if(str[i] == '(') {
				char c = s.top();
				s.pop();
			}
		}
		
		else {
			while(s.top() != 'N' && precedence(str[i]) <= precedence(s.top())) {
				char c = s.top();
				s.pop();
				
				final_str += c;
			}
			s.push(str[i]);
		}
	}
	
	while(s.top() != 'N') {
		char c = s.top();
		s.pop();
			
		final_str += c;
	}
	
	cout<<final_str<<endl;
}


/* stack using only one queue 
	algo :
	-push(int x) :
		-let size of q be s
		-enqueue x in q
		-dequeue s items from queue and re-enqueue them
		
	pop() :
		dequeue from queue
*/

class stackUsingOneQueue {
	queue<int> q;
	
public:
	void push(int x) {
		int s = q.size();
		cout<<"s1 "<<s;
		q.push(x);
		cout<<" s2 "<<s;
		for(int i=0;i<s;i++) {
			int temp = q.front();
			q.push(temp);
			q.pop();
		}
	}
	
	void pop() {
		cout<<q.front()<<" ";
		q.pop();
	}
};

/* stack using queues
	algo : 
	-push(int x) : 
		-push into q1
	
	-pop() : 
		-dequeue everything from q1 but the last element and enqueue them into q2
		-dequeue remaining last element which is the result
		-swap names of q1 and q2 so that we don't have to swap all the elements again
*/

class myStack {
	queue<int> q1;
	queue<int> q2;
	
public:
	void pushOnStack(int n) {
		q1.push(n);
	}
	
	void popFromStack() {
		while(q1.size() != 1) {
			int temp = q1.front();
			q2.push(temp);
			q1.pop();
		}
		int temp = q1.front();
		cout<<temp<<" ";
		q1.pop();
		
		queue<int> tempQueue = q1;
		q1 = q2;
		q2 = tempQueue;
	}
};

/* queue using stacks
	enqueue(int n) :
		-push to s1
		
	dequeue() :
		-if both stacks s1 & s2 are empty , show error
		-if s2 is empty , pop from s1 and push it to s2 while s1 is not empty
		-pop from s2
*/

class myQueue {
	stack<int> s1;
	stack<int> s2;
	
public:
	void enQueue(int n) {
		s1.push(n);
	}
	
	void deQueue() {
		
		if(s2.empty()) {
			while(!s1.empty()) {
				int temp = s1.top();
				s2.push(temp);
				s1.pop();
			}
		}
		cout<<s2.top()<<" ";
		s2.pop();
	}
};

int main() {
	
	myQueue obj;
	
	obj.enQueue(10);
	obj.enQueue(20);
	obj.enQueue(30);
	
	obj.deQueue();
	obj.deQueue();
	obj.deQueue();
	cout<<endl;
	
	
	myStack obj1;
	
	obj1.pushOnStack(100);
	obj1.pushOnStack(200);
	obj1.popFromStack();
	
	obj1.pushOnStack(300);
	obj1.pushOnStack(400);
	obj1.pushOnStack(500);
	
	obj1.popFromStack();
	obj1.popFromStack();
	cout<<endl;
	
	stackUsingOneQueue obj2;
	
	obj2.push(1000);
	obj2.push(2000);
	obj2.pop();
	obj2.push(3000);
	obj2.push(4000);
	obj2.pop();
	obj2.pop();
	cout<<endl;
	
	string str = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(str);
	
	
	int a[] = {11,13,21,3,5,71,5,44,1,66,100};
	int n = sizeof(a)/sizeof(a[0]);
	NGE(a,n);
	
	
	string str1 = "2+3+4";
	evaluate(str1);
	
	
	stack<int> stck;
	stck.push(10);
	stck.push(20);
	stck.push(30);
	stck.push(40);
	stck.push(50);
	reverseStack(stck);
	
	
	stackNode *s = NULL;
	push(&s,10);
	push(&s,20);
	push(&s,30);
	push(&s,40);
	push(&s,50);
	
	cout<<endl;
	printStack(s);
	cout<<endl;
	
	reverseStack(&s);
	
	printStack(s);
	cout<<endl;
	return 0;
}