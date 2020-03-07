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


int main()
{
	cout<<"Linked list : "<<endl;
	start = create(10);
	start->next = create(20);
	start->next->next = create(30);
	start->next->next->next = create(40);
	start->next->next->next->next = create(50);
	start->next->next->next->next->next = create(60);
	display();
	return 0;
}