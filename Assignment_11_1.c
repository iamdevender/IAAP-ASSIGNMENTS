#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key ;
	struct node *left , *right;
};

struct node *newnode(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

struct node *create(struct node *node, int key)
{
	if(node == NULL) return newnode(key);

	if( key < node->key)
		node->left = create(node->left, key);

	if( key > node->key )
		node->right = create(node->right , key);

return node;
}

struct node *rightrotate(struct node *root)
{
	struct node *newroot = root->left;
	struct node *lr = newroot->right;

	newroot->right = root;
	root->left = lr;
	
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
inorder(root);
printf("\n");
root = rightrotate(root);
preorder(root);
return 0;
}
