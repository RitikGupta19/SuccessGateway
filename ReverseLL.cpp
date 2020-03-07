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

node* reverse()
{
	node* p,*q,*r;
	p = NULL;
	q = start;
	r = q->next;
	while(q!=NULL)
	{
		q->next = p;
		p = q;
		q = r;
		if(r!=NULL)
			r = q->next;
	}
	return p;
}

int main()
{
	cout<<"Linked list : ";
	start = create(10);
	start->next = create(20);
	start->next->next = create(30);
	start->next->next->next = create(40);
	start->next->next->next->next = create(50);
	start->next->next->next->next->next = create(60);
	display();
	cout<<endl<<"Reversed Linked List : ";
	start = reverse();
	display();
	return 0;
}