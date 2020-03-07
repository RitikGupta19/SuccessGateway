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

int Height(BTnode *root) {
	if (root == NULL) 
        return -1;
    else {
        int l = Height(root->left);
        int r = Height(root->right);
        if(l>r) 
            return l+1; 
        else
            return r+1;
    }
}

int LeafNode(BTnode *root) {
	if (root == NULL)
        return 0;
    if (root->left==NULL && root->right==NULL)
        return 1;
    else
        return (LeafNode(root->left) + LeafNode(root->right));
}

int InternalNode(BTnode *root) {
	    if (root != NULL)
    {
        if (root->left==NULL && root->right==NULL)
            return 0;
        else
            return (1 + InternalNode(root->left) + InternalNode(root->right));
    }
    return 0;
}

int Nodes(BTnode *root) {
	if (root != NULL)
    {
        if (root->left==NULL && root->right==NULL)
            return 1;
        else
            return (1 + Nodes(root->left) + Nodes(root->right));
    }
    return 0;
}

int LeftMostElement(BTnode *root) {
	if(root!=NULL)
	{
		while(root->left!=NULL)
			root = root->left;
		return root->data;
	}
	return 0;
}

int StrictBinaryTree(BTnode *root) {
	if (root) {
		if (root->left != NULL && root->right != NULL)
			return (StrictBinaryTree(root->left)* StrictBinaryTree(root->right));
		if (root->left == NULL && root->right == NULL)
			return 1;
		else
			return 0;
	}
	return 0;
}

int main() {
	int choice;
	BTnode *start;
	start = createNode();
	while(1) {
		cout<<"Enter Choice:"<<endl<<"1. Height of Tree"<<endl<<"2. Number of leaf nodes"<<endl;
		cout<<"3. Number of internal nodes"<<endl<<"4. Number of nodes"<<endl<<"5. Left most node"<<endl;
		cout<<"6. Strict Binary Tree or Not"<<endl<<"7. Exit"<<endl;
		cin>>choice;
		switch(choice) {
			case 1 : {
				int h = Height(start);
				cout<<"Height: "<<h<<endl;
				break;
			}
			case 2 : {
				int leafNode = LeafNode(start);
				cout<<"Leaf Node: "<<leafNode<<endl;
				break;
			}
			case 3 : {
				int internalNode = InternalNode(start);
				cout<<"Internal Node: "<<internalNode<<endl;
				break;
			}
			case 4 : {
				int totalNode = Nodes(start);
				cout<<"Total Node: "<<totalNode<<endl;
				break;
			}
			case 5 : {
				int leftMost = LeftMostElement(start);
				cout<<"Left Most Element: "<<leftMost<<endl;
				break;	
			}
			case 6 : {
				int Sbt = StrictBinaryTree(start);
				if (Sbt)
					cout<<"Strict Binary Tree"<<endl;
				else
					cout<<"Not a Strict Binary Tree"<<endl;
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