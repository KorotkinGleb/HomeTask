#include <stdio.h>
#include <stdlib.h>

/* binary tree */

typedef struct tNode *tree;
typedef int elemtype;  

typedef struct tNode
{
	     elemtype elem;
	          tree left;
		       tree right;
} tnode;

tree InitTree(elemtype Element)
{
	tree Root = malloc(sizeof(tnode));
	Root->left = NULL;
	Root->right = NULL;
	Root->elem = Element;
	return Root;	
}

void UptateRoot(tree *Root, elemtype Element)
{
	if((*Root)->elem >= Element) return;
	tree NewRoot = malloc(sizeof(tnode));
	NewRoot->left = (*Root);
	NewRoot->elem = Element;
	NewRoot->right = NULL;
	(*Root) = NewRoot;
}

void InsertNode(tree *Root, elemtype Element)
{
	if(*Root == NULL)
	{
		*Root = InitTree(Element);
		return;
	}
	if((*Root)->elem < Element) InsertNode(&((*Root)->right), Element);
	if((*Root)->elem > Element) InsertNode(&((*Root)->left), Element);
}

tree MinTree(tree Tree)
{
	while(Tree && Tree->left) Tree = Tree->left;
	return Tree;
}

tree DeleteNode(tree Root, elemtype Element)
{
	if(Root == NULL) return Root;
	else if(Root->elem < Element) Root->right = DeleteNode(Root->right, Element);
	else if(Root->elem > Element) Root->left = DeleteNode(Root->left, Element);
	else{
		if(Root->left == NULL) {
			tree RootRight = Root->right;
			free(Root);
			return RootRight;
		}
		if(Root->right == NULL) {
			tree RootLeft = Root->left;
			free(Root);
			return RootLeft;
		}
		tree MinRoot = MinTree(Root->right);
		Root->elem = MinRoot->elem;
		Root->right = DeleteNode(Root->right, MinRoot->elem);
	}
	return Root;
}

void TreeSearch(tree Root, elemtype Element)
{
	if(Root == NULL)
	{
		printf("%d %s\n", Element, "no");
		return;
	}
	if(Root->elem == Element)
	{
		printf("%d %s\n", Element, "yes");
		return;
	}
	if(Root->elem < Element) TreeSearch(Root->right, Element);
	if(Root->elem > Element) TreeSearch(Root->left, Element);
}

int main()
{
	tree Tree = NULL;
	char Data[10];
	char Sign;
	int Value;
	while(scanf("%s", Data) != EOF)
	{
		Sign = Data[0];
		Value = atoi(Data + 1);
		if(Sign == '+') InsertNode(&Tree, Value);
		if(Sign == '?') TreeSearch(Tree, Value);
		if(Sign == '-') Tree = DeleteNode(Tree, Value);
	}
	return 0;
}
