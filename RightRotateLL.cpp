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

int length()
{
	node* ptr;
	int i = 1;
	ptr = start;
	while(ptr->next!=NULL)
	{
		ptr = ptr->next;
		i++;
	}
	return i;
}

node* RightRotate(int x)
{
	node* ptr,*qtr;
	ptr = start;
	int i=1,l;
	l = length();
	while(i<l-x)
	{
		ptr = ptr->next;
		i++;
	}
	qtr = ptr->next;
	while(qtr->next!=NULL)
		qtr = qtr->next;
	qtr->next = start;
	start = ptr->next;
	ptr->next = NULL;
	return start;
}

int main()
{
	int num;
	cout<<"Enter num : ";
	cin>>num;
	cout<<"Linked list : "<<endl;
	start = create(10);
	start->next = create(20);
	start->next->next = create(30);
	start->next->next->next = create(40);
	start->next->next->next->next = create(50);
	start->next->next->next->next->next = create(60);
	display();
	start = RightRotate(num);
	cout<<endl<<"Right Rotated Linked List :";
	display();
	return 0;
}