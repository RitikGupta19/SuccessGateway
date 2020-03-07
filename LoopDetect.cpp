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

void Loop(node *fptr)
{
	node *sptr = start;
	while(sptr!=fptr)
	{
		sptr = sptr->next;
		fptr = fptr->next;
	}
	cout<<"Starting point : "<<sptr->data<<endl;
}

void LoopDetect()
{
	node *ptr, *qtr;
	int flag = 0;
	ptr = start;
	qtr = start;
	while(ptr->next!=NULL && qtr->next!=NULL)
	{
		if(ptr == qtr && ptr!=start && qtr!=start)
		{
			flag = 1;
			break;
		}
		ptr = ptr->next;
		qtr = qtr->next->next;
	}
	if(flag==1)
	{
		cout<<"Loop present."<<endl;
		Loop(qtr);
	}
	else
	{
		cout<<"Loop not present."<<endl;
	}
}

int main()
{
	start = create(10);
	start->next = create(20);
	start->next->next = create(30);
	start->next->next->next = create(40);
	start->next->next->next->next = create(50);
	start->next->next->next->next->next = create(60);
	start->next->next->next->next->next->next = create(70);
	start->next->next->next->next->next->next->next = create(80);
	start->next->next->next->next->next->next->next->next = create(90);
	start->next->next->next->next->next->next->next->next->next = start->next->next->next->next->next;
	LoopDetect();
	return 0;
}