// this code reverse the list from any middle points in between
// m: start point ; n : last point
// eg : m = 4 and n = 6
// list = 10-20-30-40-50-60-70-80-90
// o/p : 10-20-30-60-50-40-70-80-90

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

void ReverseAtLoc(int m, int n) {
	node *p, *prev, *curr, *nxt, *last;
	if(p == NULL) {
		cout<<"List is empty."<<endl;
	}
	else {
		prev = start;
		int i = 1;
		last = start;
		while (i < n) {
			last = last->next;
			i++;
		}
		i = 1;
		curr = start;
		while (i < m) {
			prev = curr;
			curr = curr->next;
			i++;
		}
		p = prev;
		while (curr!=last) {
			nxt = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nxt;
		}
		if (m==1){
			p->next->next = last->next;
			curr->next = prev;
			start = curr;
			return ;
		}
		else {
			p->next->next = last->next;
			p->next = last;
			curr->next = prev;
		}
	}
}

int main()
{
	int m,n;
	cout<<"Linked list : ";
	start = create(10);
	start->next = create(20);
	start->next->next = create(30);
	start->next->next->next = create(40);
	start->next->next->next->next = create(50);
	start->next->next->next->next->next = create(60);
	start->next->next->next->next->next->next = create(70);
	start->next->next->next->next->next->next->next = create(80);
	start->next->next->next->next->next->next->next->next = create(90);
	display();
	cout<<endl<<"Enter start: ";
	cin>>m;
	cout<<endl<<"Enter end: ";
	cin>>n;
	ReverseAtLoc(m,n);
	display();
	return 0;
}