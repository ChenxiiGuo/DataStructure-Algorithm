#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <stack>
#include <Queue>
using namespace std;

typedef struct Node{
	char data;
	struct Node *lchild;
	struct Node *rchild;
	} *Tree 

int index=0;
void treeNodeConstructor(Tree &root, char data[])
{
	char e=data[index++];
	if(e=='#') 
		root=NULL;
	else
	{
		root=(Node *)malloc(sizeof(Node));
		root->data=e;
		treeNodeConstructor(root->lchild,data);
		treeNodeConstructor(root->rchild,data);
	}
}

void depthFirstSearch(Tree root)//DFS
{
	stack<Node *> nodeStack;
	nodeStack.push(root);
	Node *node;
	while(!nodeStack.empty())
	{
		node=nodeStack.top();
		cout<<node->data;
		nodeStack.pop();
		if(node->rchild)
			nodeStack.push(node->rchild);
		if(node->lchild)
			nodeStack.push(node->lchild);
	}
} 

void breadthFirstSearch(Tree root)//BFS, level by level
{
	queue<Node *>nodeQueue;
	nodeQueue.push(root);
	Node *node;
	while(!nodeQueue.empty())
	{
		node=nodeQueue.front();
		cout<<node->data;
		nodeQueue.pop();
		if(node->rchild)
			nodeQueue.push(node->rchild);
		if(node->lchild)
			nodeQueue.push(node->lchild);
	}
}

int main()
{
	char data[15]={'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F','#', '#', 'G', '#', '#' };
	Tree tree;
	treeNodeConstructor(tree,data);
	cout<<"the result of DFS is : "<<depthFirstSearch(tree)<<endl;
	cout<<"the result of BFS is :"<<breadthFirstSearch(tree)<<endl;
	return 0;
	
}