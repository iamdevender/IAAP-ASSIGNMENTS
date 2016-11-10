#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key , height ;
	struct node *left , *right;
};

struct node *rightrotate(struct node *);
struct node *leftrotate(struct node *);

int height(struct node *node)
{
	if(node == NULL)
	return 0;
	return node->height;
}

int max(int a, int b)
{
	if(a > b)  return a ;
	else  return b;
}

struct node *newnode(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = key;
	temp->height = 1;
	temp->left = temp->right = NULL;
	return temp;
}

int getbalance(struct node *n)
{
	if(n == NULL) return 0;
	return height(n->left) - height(n->right) ;
}

struct node *create(struct node *node, int key)
{
	if(node == NULL) return newnode(key);

	if( key < node->key)
		node->left = create(node->left, key);

	if( key > node->key )
		node->right = create(node->right , key);
	
	node->height = max(height(node->left),height(node->right)) + 1;
	
	int balance = getbalance(node);

	if( balance > 1 && key < node->left->key)
		return rightrotate(node);

	if(balance > 1 && key > node->left->key)
	{
		node->left = leftrotate(node->left);
		return rightrotate(node);
	} 
	if( balance < -1 && key > node->right->key )
	 return leftrotate(node);

	if( balance < -1 && key < node->right->key )
	{
		node->right = rightrotate(node->right);
		return leftrotate(node);
	}
return node;
}

struct node *rightrotate(struct node *root)
{
	struct node *newroot = root->left;
	struct node *lr = newroot->right;

	newroot->right = root;
	root->left = lr;

	newroot->height = max(height(newroot->left), height(newroot->right)) + 1;
	root->height = max(height(root->left) , height(root->right)) + 1;	
	return newroot;
}

struct node *leftrotate(struct node *root)
{
	struct node *newroot = root->right;
	struct node *lr = newroot->left;

	newroot->left = root;
	root->right = lr;

	newroot->height = max(height(newroot->left), height(newroot->right)) + 1;
	root->height = max(height(root->left) , height(root->right)) + 1;	
return newroot;
}

void inorder(struct node *root)
{
	struct node *curr = root;
	if(curr != NULL)
	{
		inorder(curr->left);
		printf("%d ",curr->key);
		inorder(curr->right);
	}
}

void preorder(struct node *root)
{
	struct node *curr = root;
	if(curr != NULL)
	{
		printf("%d ",curr->key);
		preorder(curr->left);
		preorder(curr->right);
	}
}

int main()
{
	struct node *root  = NULL;
	int n;
	scanf("%d",&n);
	while(n)
	{
		int value;
		scanf("%d",&value);
		root = create(root, value);
		n--;
	}



preorder(root);
return 0;
}
