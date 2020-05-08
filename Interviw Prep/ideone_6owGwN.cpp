#include <bits/stdc++.h>

using namespace std;

struct node {
	int data;
	struct node *next;
};

struct node *createNode(int data) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
 
	newNode->data = data;
	newNode->next = NULL;
 
	return newNode;
};

void insertFirst(struct node **head,int data) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

void insertAfter(struct node *prev,int data) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	
	if(prev == NULL)
		return;
		
	newNode->data = data;
	newNode->next = prev->next;
	prev->next = newNode;
}

void insertLast(struct node **head,int data) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	
	newNode->data = data;
	newNode->next = NULL;
	
	if(*head == NULL) {
		*head = newNode;
		return;
	}
	
	struct node *lastNode = *head;
	
	while(lastNode->next != NULL)
		lastNode = lastNode->next;
	lastNode->next = newNode;
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
	free(current);
}

void deleteFromPosition(struct node **head,int position) {
	if(*head == NULL)
		return;
		
	struct node *temp = *head;
	
	if(position == 0) {
		*head = temp->next;
		free(temp);
		return;
	}
	
	for(int i=0;temp != NULL && i<position-1;i++)
		temp = temp->next;
		
	if(temp == NULL || temp->next == NULL)
		return;
		
	struct node *nextNode = temp->next->next;
	free(temp->next);
	temp->next = nextNode;
}

void findFromLast(struct node *head,int n) {
	
	int length = 0;
	struct node *temp = head;
	while(temp != NULL) {
		temp = temp->next;
		length++;
	}
	
	if(length < n)
		return;
		
	temp = head;
	
	for(int i=0;i<length-n;i++)
		temp = temp->next;
		
	cout<<temp->data<<endl;
}

void findFromLast2(struct node *head,int n) {
	struct node *first = head;
	struct node *second = head;
	
	int count = 0;
	while(count < n) {
		second = second->next;
		count++;
	}
	
	while(second != NULL) {
		first = first->next;
		second = second->next;
	}
	
	cout<<first->data<<endl;
}

struct node *findMiddle(struct node *head) {
	struct node *slow = head;
	struct node *fast = head;
	
	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	
	//cout<<"Middle node is "<<slow->data<<endl;
	return slow;
}

void findSumPairs(struct node **head,int sum) {
	struct node *second = (*head)->next;
	int flag = 0;
	
	for(struct node *first = *head; first != NULL && first->next != NULL;first = first->next) {
		second = first->next;
		while(second != NULL) {
			if(first->data + second->data == sum) {
				flag = 1;
				cout<<"("<<first->data<<", "<<second->data<<")"<<"  ";
			}
			second = second->next;
		}
	}
	if(!flag)
		cout<<"No pairs found.\n";
}

void detectLoop(struct node *head) {
	struct node *slow = head;
	struct node *fast = head;
	
	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		
		if(slow == fast) {
			cout<<"Loop exists"<<endl;
			return;
		}
	}
	cout<<"No loop"<<endl;
	return;
}

void swapNodes(struct node **head,int x,int y) {
	if(x == y)
		return;
		
		
	struct node *prevX = NULL, *currX = *head;
	while(currX != NULL && currX->data != x) {
		prevX = currX;
		currX = currX->next;
	}
	
	struct node *prevY = NULL, *currY = *head;
	while(currY != NULL && currY->data != y) {
		prevY = currY;
		currY = currY->next;
	}
	
	
	if(currX == NULL || currY == NULL)
		return;
	
		
	if(prevX != NULL)
		prevX->next = currY;
	else
		*head = currY;
		
	if(prevY != NULL)
		prevY->next = currX;
	else
		*head = currX;
		
	
	struct node *temp = currX->next;
	currX->next = currY->next;
	currY->next = temp;
}

void removeDuplicates(struct node *head) {
	struct node *currentNode = head;
	struct node *nextNode;
	
	while(currentNode->next != NULL) {
		if(currentNode->data == currentNode->next->data) {
			nextNode = currentNode->next->next;
			free(currentNode->next);
			currentNode->next = nextNode;
		}
		else
			currentNode = currentNode->next;
	}
}

void moveNode(struct node **target, struct node **source) {
	struct node *newNode = *source;
	
	assert(newNode != NULL);
	
	*source = newNode->next;
	newNode->next = *target;
	*target = newNode;
}

struct node* mergeLists(struct node *a, struct node *b) {
	struct node dummy;
	struct node *tail = &dummy;
	dummy.next = NULL;
	
	while(1) {
		if(a == NULL) {
			tail->next = b;
			break;
		}
		else if(b == NULL) {
			tail->next = a;
			break;
		}
		
		if(a->data <= b->data)
			moveNode(&(tail->next), &a);
		else
			moveNode(&(tail->next), &b);
			
		tail = tail->next;
	}
	
	return dummy.next;
}

void nodeCounter(struct node *start) {
	struct node *temp = start;
	
	int count = 0;
	while(temp->next != start) {
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

bool compareLists(struct node *head1,struct node *head2) {
	struct node *temp1 = head1;
	struct node *temp2 = head2;
	
	while(temp1 != NULL && temp2 != NULL) {
		if(temp1->data == temp2->data) {
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else
			return false;
	}
	
	if(temp1 == NULL && temp2 == NULL)
		return true;
}

void reverseList(struct node **head) {
	struct node *currentNode = *head;
	struct node *prevNode = NULL;
	struct node *nextNode;
	
	while(currentNode != NULL) {
		nextNode = currentNode->next;
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
		
	}
	*head = prevNode;
}

void isPalindrome(struct node *head) {
	struct node *temp = head;
	
	struct node *midNode = findMiddle(head);
	reverseList(&midNode);
	bool isSame = compareLists(head,midNode);
	
	if(isSame)
		cout<<"List is palindrome"<<endl;
	else
		cout<<"List is NOT palindrome"<<endl;
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

void printList(struct node *head) {
	struct node *temp = head;
	
	while(temp != NULL) {
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<endl;
}

int main() {
	struct node *head = NULL;
	
	printList(head);


	insertFirst(&head,10);
	insertFirst(&head,20);
	insertFirst(&head,30);
	insertFirst(&head,40);
	insertFirst(&head,50);
	insertFirst(&head,60);
	insertAfter(head->next->next,70);
	insertLast(&head,80);
	insertLast(&head,90);
	insertAfter(head->next->next->next->next,100);
	printList(head);
	
	deleteFromKey(&head,20);
	cout<<"After deletion from key : ";
	printList(head);
	
	deleteFromPosition(&head,1);
	cout<<"After deletion from position : ";
	printList(head);
	
	
	cout<<"2nd node form last 1 : ";
	findFromLast(head,2);
	cout<<"2nd node form last 2 : ";
	findFromLast2(head,2);


	struct node *midNode = findMiddle(head);
	cout<<"Middle node is "<<midNode->data<<endl<<endl;
	
	
	deleteList(&head);
	insertFirst(&head,100);
	insertFirst(&head,200);
	insertFirst(&head,300);
	insertFirst(&head,400);
	printList(head);
	
	//creating loop
	head->next->next->next->next = head;
	detectLoop(head);
	
	countNodesInLoop(head);
	
	//deleting loop
	head->next->next->next->next = NULL;
	detectLoop(head);
	
	reverseList(&head);
	cout<<"Reversed List : ";
	printList(head);
	cout<<endl;
	
	
	deleteList(&head);
	insertFirst(&head,'a');
	insertFirst(&head,'b');
	insertFirst(&head,'c');
	insertFirst(&head,'b');
	insertFirst(&head,'a');
	printList(head);

	isPalindrome(head);
	
	
	deleteList(&head);
	insertFirst(&head,100);
	insertFirst(&head,200);
	insertFirst(&head,300);
	insertFirst(&head,400);
	cout<<"\nList 1 : ";
	printList(head);
	
	struct node *head2 = NULL;
	
	insertFirst(&head2,100);
	insertFirst(&head2,300);
	insertFirst(&head2,300);
	insertFirst(&head2,400);
	cout<<"List 2 : ";
	printList(head2);
	
	if(compareLists(head,head2))
		cout<<"Lists are same"<<endl;
	else
		cout<<"Lists are NOT same"<<endl;
	cout<<endl;
	
	
	deleteList(&head);
	deleteList(&head2);
	insertFirst(&head,400);
	insertFirst(&head,300);
	insertFirst(&head,300);
	insertFirst(&head,200);
	printList(head);
	
	removeDuplicates(head);
	cout<<"Removed Duplicates : ";
	printList(head);
	
	
	deleteList(&head);
	insertFirst(&head,7);
	insertFirst(&head,6);
	insertFirst(&head,5);
	insertFirst(&head,4);
	insertFirst(&head,3);
	insertFirst(&head,2);
	insertFirst(&head,1);
	cout<<endl;
	printList(head);
	cout<<"Pairs for given sum : ";
	findSumPairs(&head,7);
	cout<<"\nBefore Swapping : ";
	printList(head);
	
	swapNodes(&head,6,3);
	cout<<"After swapping 6 and 3 : ";
	printList(head);
	
	
	
	deleteList(&head);
	deleteList(&head2);
	
	insertFirst(&head,1);
	insertFirst(&head,3);
	insertFirst(&head,5);
	
	insertFirst(&head2,2);
	insertFirst(&head2,4);
	
	struct node *ans = mergeLists(head, head2);
	printList(ans);
	return 0;
}