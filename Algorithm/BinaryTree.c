#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define LEFT	100
#define RIGHT	101
#define UPDATE	102

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}typedef Node;

Node* newNode(int data) {
	Node* temp_node = NULL;

	printf("New Node[%2d]\n", data);

	temp_node = (Node*)malloc(sizeof(Node));
	
	temp_node->data		= data;
	temp_node->left		= NULL;
	temp_node->right	= NULL;

	return temp_node;
}

void deleteNode(Node* target) {
	free(target);
}

bool linkNode(Node* parent, Node* child, int option) {

	if ((option != LEFT) && (option != RIGHT))
		return false;

	if ((parent->left != NULL) && (parent->right != NULL) && option != UPDATE)
		return false;

	printf("Link : %s\tNode[%2d] -> Node[%2d]\n",
		option == LEFT ? "LEFT" : "RIGHT", parent->data, child->data);

	parent->left	= (option == LEFT)	? child : parent->left;
	parent->right	= (option == RIGHT)	? child : parent->right;

	return true;
}

void preOrder(Node* root) {

	if (root != NULL) {
		printf("Node[%2d] ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(Node* root) {

	if (root != NULL) {
		inOrder(root->left);
		printf("Node[%2d] ", root->data);
		inOrder(root->right);
	}
}

void postOrder(Node* root) {

	if (root != NULL) {
		inOrder(root->left);
		inOrder(root->right);
		printf("Node[%2d] ", root->data);
	}
}

int main() {

	Node* root;
	Node* node_A;
	Node* node_B;

	Node* node_C;
	Node* node_D;

	root = newNode(10);
	node_A = newNode(20);
	node_B = newNode(30);

	linkNode(root, node_A, LEFT);
	linkNode(root, node_B, RIGHT);

	printf("\nPREORDER : ");
	preOrder(root);
	printf("\n");

	printf("\nINORDER : ");
	inOrder(root);
	printf("\n");

	node_C = newNode(40);
	node_D = newNode(50);

	linkNode(node_B, node_C, LEFT);
	linkNode(node_B, node_D, RIGHT);

	printf("\nPOSTORDER : ");
	postOrder(root);
	printf("\n");

	deleteNode(root);
	deleteNode(node_A);
	deleteNode(node_B);

	deleteNode(node_C);
	deleteNode(node_D);

	return 0;
}
