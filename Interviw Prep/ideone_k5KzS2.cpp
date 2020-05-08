#include <iostream>
using namespace std;

struct node {
	int data;
	struct node *next;
};

class Stack {
	struct node *top;
	
public:
	void push(int data) {
		struct node *temp = new node;
		
		temp->data = data;
		temp->next = NULL;
		
		if(top != NULL)
			temp->next = top;

		top = temp;
		
	}
	
	int pop() {
		struct node *temp;
		
		if(top == NULL)
			return -1;
		
		temp = top;
		top = top->next;
		temp->next = NULL;
		int x = temp->data;
		free(temp);
		
		return x;
	}
	
	void display() {
		struct node *i = top;
		
		while(i != NULL) {
			cout<<i->data<<" ";
			i = i->next;
		}
		cout<<endl;
	}
};


class Queue {
	struct node *front = NULL, *rear = NULL;

public:
	void enqueue(int data) {
		struct node *temp = new node;
		
		temp->data = data;
		temp->next = NULL;
		
		if(front == NULL && rear == NULL)
			front = rear = temp;
		else {
			rear->next = temp;
			rear = temp;
		}
	}
	
	int dequeue() {
		struct node *temp;
		
		if(front == NULL)
			return -1;
			
		temp = front;
		front = front->next;
		int x = temp->data;
		free(temp);
		
		return x;
	}
	
	void display() {
		struct node *i = front;
		
		while(i != NULL) {
			cout<<i->data<<" ";
			i = i->next;
		}
		cout<<endl;
	}
};


struct Lnode {
	int data;
	struct Lnode *left, *right;
};

struct Lnode *newNode(int data) {
	struct Lnode *temp = (struct Lnode *)malloc(sizeof(struct Lnode));
	
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}

struct Lnode* insertNode(struct Lnode *node, int data) {
	
	if(node == NULL)
		return newNode(data);
		
	if(data < node->data)
		node->left = insertNode(node->left, data);
	else
		node->right = insertNode(node->right, data);
		
	return node;
}

struct Lnode* minValueNode(struct Lnode *root) {
	
	struct Lnode *current = root;
	
	while(current->left != NULL)
		current = current->left;
		
	return current;
}

struct Lnode* deleteNode(struct Lnode *root, int data) {
	//base case
	if(root == NULL)
		return root;
		
	//if key is smaller than root node
	if(data < root->data)
		root->left = deleteNode(root->left, data);
		
	//if key is larger than root node
	else if(data > root->data)
		root->right = deleteNode(root->right, data);
		
	//if key is equal to root node
	else {
		
		//node with 1 child or NO child
		if(root->left == NULL) {
			
			struct Lnode *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL) {
			
			struct Lnode *temp = root->left;
			free(root);
			return temp;
		}
		
		//node with 2 children, get inorder successor of the root node
		struct Lnode *temp = minValueNode(root->right);
		//copy inorder successor to root
		root->data = temp->data;
		//delete inorder successor
		root->right = deleteNode(root->right, temp->data);
		
	}
	
	return root;
}

void preorder(struct Lnode *root) {
	if(root) {
		cout<<root->data<<"	";
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct Lnode *root) {
	if(root) {
		inorder(root->left);
		cout<<root->data<<"	";
		inorder(root->right);
	}
}
void postorder(struct Lnode *root) {
	if(root) {
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<"	";
	}
}

int main() {
	
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.display();
	cout<<s.pop()<<endl<<endl;
	
	
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.display();
	cout<<q.dequeue()<<" ";
	cout<<q.dequeue()<<endl<<endl;
	
	
	struct Lnode *root = NULL;
	root = insertNode(root, 50); 
    root = insertNode(root, 30); 
    root = insertNode(root, 20); 
    root = insertNode(root, 40); 
    root = insertNode(root, 70); 
    root = insertNode(root, 60); 
    root = insertNode(root, 80); 
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl<<endl;
	
	root = deleteNode(root,20);
	inorder(root);
	cout<<endl;
	root = deleteNode(root,30);
	inorder(root);
	cout<<endl;
	root = deleteNode(root,50);
	inorder(root);
	cout<<endl;
	
	
	return 0;
}