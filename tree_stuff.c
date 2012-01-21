#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
}Tree;


Tree* create_tree(int data);
int height(Tree* t);
int binary_smallest_node(Tree* t);
int left_most_node(Tree* t);
int right_most_node(Tree* t);
void in_order(Tree* t);
void post_order(Tree* t);
void pre_order(Tree* t);
Tree* insert_binary_tree(Tree* t, int d);
Tree* mirror(Tree* t);
Tree* copy_tree(Tree* t1);
void add_ten_to_left_of_leaves(Tree* t);


int main()
{
	Tree* t = NULL;
	Tree* t2 = NULL;
	Tree* t3 = NULL;
	
	t = insert_binary_tree(t, 50);
	t = insert_binary_tree(t, 40);
	t = insert_binary_tree(t, 70);
	t = insert_binary_tree(t, 20);
	t = insert_binary_tree(t, 45);
	t = insert_binary_tree(t, 42);
	t = insert_binary_tree(t, 60);
	t = insert_binary_tree(t, 90);
	t = insert_binary_tree(t, 65);
					
	printf("In-Order:\n");
	printf("Expected: 20 40 42 45 50 60 65 70 90\n");
	printf("Actual  : ");
	in_order(t);
	printf("\n\n");
	
	printf("Pre-Order:\n");
	printf("Expected: 50 40 20 45 42 70 60 65 90\n");
	printf("Actual  : ");
	pre_order(t);
	printf("\n\n");
	
	printf("Post-Order:\n");
	printf("Expected: 20 42 45 40 65 60 90 70 50\n");
	printf("Actual  : ");
	post_order(t);
	printf("\n\n");
			
	printf("Height:\n");
	printf("Expected: 4\n");	
	printf("Actual  : %d\n\n", height(t));		
	
	printf("Binary Tree Smallest node:\n");
	printf("Expected: 20\n");
	printf("Actual  : %d\n\n", binary_smallest_node(t));
	
	printf("Left most node:\n");
	printf("Expected: 20\n");
	printf("Actual  : %d\n\n", left_most_node(t));
	
	printf("Right most node:\n");
	printf("Expected: 90\n");
	printf("Actual  : %d\n\n", right_most_node(t));

	t2 = mirror(t);
	printf("Mirror In-Order:\n");
	printf("Expected: 90 70 65 60 50 45 42 40 20\n");
	printf("Actual  : ");
	in_order(t2);
	printf("\n\n");
	
	t3 = copy_tree(t);
	printf("Copy In-Order:\n");
	printf("Expected: 20 40 42 45 50 60 65 70 90\n");
	printf("Actual  : ");
	in_order(t3);
	printf("\n\n");
	
	add_ten_to_left_of_leaves(t3);
	printf("Copy after adding left node with 10 to leaves In-Order:\n");
	printf("Expected: 10 20 40 10 42 45 50 60 10 65 70 10 90\n");
	printf("Actual  : ");
	in_order(t3);
	printf("\n\n");
	
	t3 = mirror(t3);
	printf("Mirrored Copy after adding left node with 10 to leaves In-Order:\n");
	printf("Expected: 90 10 70 65 10 60 50 45 42 10 40 20 10\n");
	printf("Actual  : ");
	in_order(t3);
	printf("\n\n");
	
	printf("Original In-Order:\n");
	printf("Expected: 20 40 42 45 50 60 65 70 90\n");
	printf("Actual  : ");
	in_order(t);
	printf("\n\n");
	
	return 0;
}

int binary_smallest_node(Tree* t)
{
	return left_most_node(t);
}

void add_ten_to_left_of_leaves(Tree* t)
{
	if(t == NULL)
		return;
	
	if(t->left == NULL && t->right == NULL)
	{
		t->left = create_tree(10);
		return;
	}
	
	add_ten_to_left_of_leaves(t->left);
	add_ten_to_left_of_leaves(t->right);
	
	return;
}


Tree* copy_tree(Tree* t1)
{
	if(t1 == NULL)
		return t1;
	
	Tree* t2 = NULL;
	
	t2 = create_tree(t1->data);
	t2->left = copy_tree(t1->left);
	t2->right = copy_tree(t1->right);
	
	return t2;
}


int height(Tree* t)
{
	int left_height, right_height;
	
	if(t == NULL)
		return 0;
	
	left_height = height(t->left);
	right_height = height(t->right);
	
	return left_height > right_height ? left_height + 1 : right_height + 1;
}

Tree* mirror(Tree* t)
{
	if(t == NULL)
		return t;
	
	Tree* temp = NULL;
	
	temp = create_tree(t->data);
	temp->left = mirror(t->right);
	temp->right = mirror(t->left);
	
	return temp; 	
}

Tree* create_tree(int data)
{
	Tree* t = (Tree *)malloc(sizeof(Tree));
	t->data = data;
	t->left = NULL;
	t->right = NULL;
}

Tree* insert_binary_tree(Tree* t, int d)
{
	if(t == NULL)
	{
		t = create_tree(d);
	}
	else if(d < t->data)
	{
		t->left = insert_binary_tree(t->left, d);
	}
	else
	{
		t->right = insert_binary_tree(t->right, d);
	}
	
	return t;
}

int left_most_node(Tree* t)
{
	if(t->left == NULL)
		return t->data;
	
	return left_most_node(t->left);
}

int right_most_node(Tree* t)
{
	if(t->right == NULL)
		return t->data;
	
	return right_most_node(t->right);
}

void in_order(Tree* t)
{
	if(t == NULL)
		return;
	in_order(t->left);
	printf("%d ", t->data);
	in_order(t->right);
}

void pre_order(Tree* t)
{
	if(t == NULL)
		return;
	printf("%d ", t->data);
	pre_order(t->left);
	pre_order(t->right);
}

void post_order(Tree* t)
{
	if(t == NULL)
		return;
	post_order(t->left);
	post_order(t->right);
	printf("%d ", t->data);
}
