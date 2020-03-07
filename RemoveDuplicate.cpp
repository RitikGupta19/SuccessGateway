// program removes the duplicate element
// not working completely

#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};


node* start = NULL;

node* create(int x)
{
	node* temp;
	temp = (node*)malloc(sizeof(node));
	temp->data = x;
	temp->next = NULL;
	return temp;
}

void display()
{
	node* ptr;
	ptr = start;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"-->";
		ptr = ptr->next;
	}
	cout<<"NULL";
}

void RemoveDup() {
	node *p, *q;
	p = start;
	while (p!=NULL && p->next!=NULL) {
		q = p->next;
		while (p->data == q->data) {
			q = q->next;
		}
		p->next = q;
		p = p->next;
	}
}

int main()
{
	cout<<"Linked list : ";
	start = create(10);
	start->next = create(20);
	start->next->next = create(20);
	start->next->next->next = create(30);
	start->next->next->next->next = create(30);
	start->next->next->next->next->next = create(30);
	start->next->next->next->next->next->next = create(40);
	start->next->next->next->next->next->next->next = create(50);
	start->next->next->next->next->next->next->next->next = create(50);
	display();
	RemoveDup();
	cout<<endl<<"After removing duplicate elements : ";
	display();
	return 0;
}