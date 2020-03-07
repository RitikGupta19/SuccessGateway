#include<iostream>

using namespace std;

struct BTnode {
	struct BTnode *left;
	int data;
	struct BTnode *right;
};

BTnode * createNode() {
	BTnode *temp;
	int x;
	temp = (BTnode*)malloc(sizeof(BTnode));
	if (!temp) {
		cout<<"Memory not allocated."<<endl;
	}
	else {
		cout<<"Node Data: ";
		cin>>x;
		if (x == -1) {
			return NULL;
		}
		else {
			temp->data = x;
			cout<<"Left ";
			temp->left = createNode();
			cout<<"Right ";
			temp->right = createNode();
		}
	}
	return temp;
}

void PreOrder(BTnode *root) {
	if (root == NULL) {
		return ;
	}
	cout<<root->data<<" ";
	PreOrder(root->left);
	PreOrder(root->right);
}

void PostOrder(BTnode *root) {
	if (root == NULL) {
		return ;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data<<" ";
}

void InOrder(BTnode *root) {
	if (root == NULL) {
		return ;
	}
	InOrder(root->left);
	cout<<root->data<<" ";
	InOrder(root->right);
}

void ConversePreOrder(BTnode *root) {
	if (root == NULL) {
		return ;
	}
	cout<<root->data<<" ";
	ConversePreOrder(root->right);
	ConversePreOrder(root->left);
}

void ConversePostOrder(BTnode *root) {
	if (root == NULL) {
		return ;
	}
	ConversePostOrder(root->right);
	ConversePostOrder(root->left);
	cout<<root->data<<" ";
}

void ConverseInOrder(BTnode *root) {
	if (root == NULL) {
		return ;
	}
	ConverseInOrder(root->right);
	cout<<root->data<<" ";
	ConverseInOrder(root->left);
}

int main() {
	int choice;
	BTnode *start;
	start = createNode();
	while(1) {
		cout<<"Enter Choice:"<<endl<<"1. Conventional PreOrder"<<endl<<"2. Conventional PostOrder"<<endl;
		cout<<"3. Conventional InOrder"<<endl<<"4. Converse PreOrder"<<endl<<"5. Converse PostOrder"<<endl;
		cout<<"6. Converse InOrder"<<endl<<"7. Exit"<<endl;
		cin>>choice;
		switch(choice) {
			case 1 : {
				PreOrder(start);
				break;
			}
			case 2 : {
				PostOrder(start);
				break;
			}
			case 3 : {
				InOrder(start);
				break;
			}
			case 4 : {
				ConversePreOrder(start);
				break;
			}
			case 5 : {
				ConversePostOrder(start);
				break;	
			}
			case 6 : {
				ConverseInOrder(start);
				break;
			}
			case 7 : {
				exit(1);
				break;
			}
		}
	}
	cout<<endl;
}