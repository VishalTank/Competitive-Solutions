#include <bits/stdc++.h>

using namespace std;

struct node {
	struct node *prev;
	int data;
	struct node *next;
};

struct node *createNode(int data) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	
	newNode->prev = NULL;
	newNode->data = data;
	newNode->next = NULL;
	
	return newNode;
}

void insertFirst(struct node **head,int data) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node ));
	
	newNode->prev = NULL;
	newNode->data = data;
	newNode->next = *head;
	
	if((*head) != NULL)
		(*head)->prev = newNode;
	
	*head = newNode;
}

void insertAfter(struct node *prevNode,int data) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	
	newNode->prev = prevNode;
	newNode->data = data;
	newNode->next = prevNode->next;
	
	prevNode->next = newNode;
	
	if(newNode->next != NULL)
		newNode->next->prev = newNode;
}

void insertBefore(struct node *nextNode,int data) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	
	newNode->prev = nextNode->prev;
	newNode->data = data;
	newNode->next = nextNode;
	
	nextNode->prev = newNode;
	
	if(newNode->prev != NULL)
		newNode->prev->next = newNode;
}

void insertLast(struct node **head,int data) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	
	newNode->data = data;
	newNode->next = NULL;
	
	if(*head == NULL) {
		newNode->prev = NULL;
		*head = newNode;
		return;
	}
	
	struct node *temp = *head;
	
	while(temp->next != NULL)
		temp = temp->next;
	
	temp->next = newNode;
	newNode->prev = temp;
	return;
}

void deleteNode(struct node **head,struct node *del) {
	if(*head == NULL || del == NULL)
		return;
		
	if(*head == del)
		*head = del->next;
		
	if(del->next != NULL)
		del->next->prev = del->prev;
	
	if(del->prev != NULL)
		del->prev->next = del->next;
		
	free(del);
}

void deleteFromKey(struct node **head, int key) {
	struct node *current = *head;
 
	if(current != NULL && current->data == key) {
		*head = current->next;
		free(current);
		return;
	}
 
	struct node *prev;
 
	while(current != NULL && current->data != key) {
		prev = current;
		current = current->next;
	}
 
	if(current == NULL)
		return;
 
	prev->next = current->next;
	current->next->prev = current->prev;
	free(current);
}

void deleteFromPosition(struct node **head,int position) {
	
	if(*head == NULL ||position < 0)
		return;
		
	struct node *temp = *head;
	int count = 0;
	while(temp != NULL && count < position) {
		temp = temp->next;
		count++;
	}
	
	if(temp == NULL)
		return;
	
	deleteNode(head,temp);
}

void deleteList(struct node **head) {
	struct node *current = *head;
	struct node *nextNode;
	
	while(current != NULL) {
		nextNode = current->next;
		free(current);
		current = nextNode;
	}
	
	*head = NULL;
}

void findSumPairs(struct node **head,int sum) {
	struct node *first = *head;
	struct node *second = *head;
	int flag = 0;
	
	while(second != NULL && second->next != NULL)
		second = second->next;
	
	while(first != NULL && second != NULL && first != second && second->next != first) {	
		if((first->data + second->data) == sum) {
			flag = 1;
			cout<<"("<<first->data<<", "<<second->data<<")"<<"  ";
			first = first->next;
			second = second->prev;
		}
		else if((first->data + second->data) < sum)
			first = first->next;
		else
			second = second->prev;
	}
	if(!flag)
		cout<<"No pairs found.\n";
}

//wrong function
/*
void findSumTriplets(struct node **head,int sum) {
	struct node *first = *head;
	struct node *second = *head;
	struct node *third = first->next;
	int flag = 0;
	
	while(second != NULL && second->next != NULL)
		second = second->next;
	
	while(first != NULL && second != NULL && first != second  && second->next != first) {
		third = first->next;
		while(third != NULL && third != second && second->next != third) {
			if((first->data + second->data + third->data) == sum) {
				flag = 1;
				cout<<"("<<first->data<<", "<<second->data<<", "<<third->data<<")"<<"  ";
				third = third->next;
			}
			else if((first->data + second->data + third->data) > sum){
				second = second->prev;
				third = first->next;
			}
			else if((first->data + second->data + third->data) < sum) {
				if(third == second->prev) {
					first = first->next;
					third = first->next;
				}
				else
					third = third->next;
			}
		}
	}
	if(!flag)
		cout<<"No triplets found.\n";
}
*/

void sortedInsert(struct node **head,struct node *newNode) {
	
	//empty list
	if(*head == NULL)
		*head = newNode;

	//insertion before head
	else if((*head)->data >= newNode->data) {
		newNode->next = *head;
		newNode->next->prev = newNode;
		*head = newNode;
	}
	else {
		struct node *temp = *head;

		//go to the node after which new node has to be inserted		
		while(temp->next != NULL && temp->next->data < newNode->data)
			temp = temp->next;
			
		newNode->next = temp->next;
		newNode->prev = temp;
		
		//node is not last one
		if(temp->next != NULL)
			newNode->next->prev = newNode;
			
		temp->next = newNode;
	}
	
	
}

void swapNodes(struct node **head,int x,int y) {
	if(x == y)
		return;
		
	struct node *prevX = NULL, *nextX = NULL, *currX = *head;
	while(currX != NULL && currX->data != x)
		currX = currX->next;
	prevX = currX->prev;
	nextX = currX->next;
	
	struct node *prevY = NULL, *nextY = NULL, *currY = *head;
	while(currY != NULL && currY->data != y)
		currY = currY->next;
	prevY = currY->prev;
	nextY = currY->next;
	
	if(currX == NULL || currY == NULL)
		return;
		
	if(prevX != NULL && nextX != NULL) {
		prevX->next = currY;
		nextX->prev = currY;
	}
	else
		*head = currY;
		
	if(prevY != NULL && nextY != NULL) {
		prevY->next = currX;
		nextY->prev = currX;
	}
	else
		*head = currX;
	
	struct node *temp = currX->next;
	currX->next = currY->next;
	currY->next = temp;
	
	temp = currX->prev;
	currX->prev = currY->prev;
	currY->prev = temp;
}

void reverseList(struct node **head) {
	struct node *currentNode = *head;
	struct node *temp = NULL;
	
	while(currentNode != NULL) {
		temp = currentNode->prev;
		currentNode->prev = currentNode->next;
		currentNode->next = temp;
		
		currentNode = currentNode->prev;
	}
	
	if(temp != NULL )
		*head = temp->prev;
}

void removeDuplicatesUnsorted(struct node **head) {
	if(*head == NULL)
		return;
		
	unordered_set<int> set;
	
	struct node *temp = *head, *next;
	
	while(temp != NULL) {
		if(set.find(temp->data) != set.end()) {
			next = temp->next;
			deleteNode(head,temp);
			temp = next;
		}
		else {
			set.insert(temp->data);
			temp = temp->next;
		}
	}
}

void removeDuplicatesSorted(struct node *head) {
	struct node *currentNode = head;
	struct node *nextNode;
 
	while(currentNode->next != NULL) {
		if(currentNode->data == currentNode->next->data) {
			nextNode = currentNode->next->next;
			free(currentNode->next);
			currentNode->next = nextNode;
			nextNode->prev = currentNode;
		}
		else
			currentNode = currentNode->next;
	}
}

int lengthOfList(struct node **head) {
	struct node *temp = *head;
	int count = 0;
	
	while(temp != NULL) {
		temp = temp->next;
		count++;
	}
	return count;
}

void leftRotateList(struct node **head,int N) {
	
	if (N == 0)
		return;
	
	struct node* temp = *head;
	int count = 1;
	while (count < N && temp != NULL) {
		temp = temp->next;
		count++;
	}
	
	if (temp == NULL)
		return;
	
	struct node* NthNode = temp;
	while (temp->next != NULL)
		temp = temp->next;
		
	temp->next = *head;
	(*head)->prev = temp;
	
	*head = NthNode->next;
	(*head)->prev = NULL;

	NthNode->next = NULL;
}

void rightRotateList(struct node **head,int N) {
	if(N == 0)
		return;
		
	struct node* temp = *head;
	int count = 1;
	while (count < lengthOfList(head)-N && temp != NULL) {
		temp = temp->next;
		count++;
	}
	
	if (temp == NULL)
		return;
	
	struct node* NthNode = temp;
	while (temp->next != NULL)
		temp = temp->next;
		
	temp->next = *head;
	(*head)->prev = temp;
	
	*head = NthNode->next;
	(*head)->prev = NULL;
	
	NthNode->next = NULL;
}

void nodeCounter(struct node *head) {
	struct node *temp = head;
	
	int count = 0;
	while(temp->next != head) {
		count++;
		temp = temp->next;
	}
	cout<<"Length of loop : "<<count<<endl;
}

void countNodesInLoop(struct node *head) {
	struct node *slow = head;
	struct node *fast = head;
 
	while(fast != NULL && slow != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
 
		if(fast == slow) {
			nodeCounter(slow);
			return;
		}
	}
	return;
}

void printListForward(struct node *head) {
	struct node *temp = head;
	
	while(temp != NULL) {
		cout<<temp->data<<"<->";
		temp = temp->next;
	}
	cout<<endl;
}

void printListBackward(struct node *head) {
	struct node *temp = head;
	
	while(temp != NULL && temp->next != NULL)
		temp = temp->next;
		
	while(temp != NULL) {
		cout<<temp->data<<"<->";
		temp = temp->prev;
	}
	cout<<endl;
}

int main() {
	
	struct node *head = NULL;
	
	insertLast(&head,100);
	insertFirst(&head,10);
	insertFirst(&head,20);
	insertFirst(&head,30);
	insertFirst(&head,40);
	insertFirst(&head,50);
	insertAfter(head->next->next,60);
	insertBefore(head->next->next->next->next,70);
	insertLast(&head,80);
	insertLast(&head,90);
	cout<<"after insertion : ";
	printListForward(head);
	
	reverseList(&head);
	cout<<"after reversal : ";
	printListForward(head);
	
	deleteNode(&head,head->next);
	cout<<"after deletion : ";
	printListForward(head);
	
	deleteList(&head);
	printListForward(head);
	
	insertLast(&head,50);
	insertFirst(&head,40);
	insertFirst(&head,30);
	insertFirst(&head,20);
	insertFirst(&head,10);
	sortedInsert(&head,createNode(-10));
	sortedInsert(&head,createNode(-10+20));
	sortedInsert(&head,createNode(44));
	sortedInsert(&head,createNode(454));
	printListForward(head);
	deleteFromPosition(&head,8);
	printListForward(head);
	
	findSumPairs(&head,200);
	cout<<endl;
	deleteList(&head);
	
	insertLast(&head,'g');
	insertFirst(&head,'f');
	insertFirst(&head,'e');
	insertFirst(&head,'d');
	insertFirst(&head,'d');
	insertFirst(&head,'c');
	insertFirst(&head,'b');
	insertFirst(&head,'a');
	//findSumTriplets(&head,17);
	printListForward(head);
	swapNodes(&head,'e','b');
	cout<<"after swapping : ";
	printListForward(head);
	
	cout<<"after removing duplicates : ";
	removeDuplicatesSorted(head);
	printListForward(head);
	cout<<endl;
	
	insertFirst(&head,'e');
	insertFirst(&head,'d');
	insertFirst(&head,'d');
	insertFirst(&head,'c');
	printListForward(head);
	cout<<"after removing duplicates : ";
	removeDuplicatesUnsorted(&head);
	printListForward(head);
	leftRotateList(&head,3);
	cout<<"left rotation : ";
	printListForward(head);
	cout<<"right rotation : ";
	rightRotateList(&head,5);
	printListForward(head);
	cout<<endl;
	
	
	return 0;
}