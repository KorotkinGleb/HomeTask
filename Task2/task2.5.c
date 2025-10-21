#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  struct Node *link; /*  pointer to list node */
typedef  char* elemtype; /*  list element type */
typedef struct Node {                    /* list node type */
                         elemtype elem;  /* element type */
                         link next;      /* pointer to the next node */
                    } node;

typedef link list; /* list type (pointer to the first node) */

void Print(list p)
{
	if(p == NULL) return;
	while(p) {
		printf(p->next ? "%s " : "%s\n", p->elem);
		p = p->next;
	}
}

void PrintReverseList(list List)
{
	char *Words[100];
	int WordNumber = 0;
	while(List) {
		Words[WordNumber ++] = List->elem;
		List = List->next;
	}
	WordNumber -= 1;
	for(; WordNumber >= 0; WordNumber --)
		printf(WordNumber ? "%s " : "%s\n", Words[WordNumber]);
}

list CreateList(int ListElementsSize, elemtype *ListElements)
{
	if(ListElementsSize == 0) return NULL;
	link CurrentNode;
	list List;
	List = CurrentNode = (link) malloc(sizeof(node));
	CurrentNode->elem = *ListElements ++;
	ListElementsSize -= 1;
	while(ListElementsSize)
	{
		CurrentNode = CurrentNode->next=(list)malloc(sizeof(node));
		CurrentNode->elem=*ListElements++;
		ListElementsSize --;
	}
	CurrentNode->next = NULL;
	return List;
}

void GetLastWord(list List, char *LastWord)
{	
	if(List == NULL) return;
	while(List->next) List = List->next;
	strcpy(LastWord, List->elem);	
}

void DeleteElements(list *List, elemtype Element)
{
	if(List == NULL) return;
	list Previous = NULL, Current = *List, Temporary;
	while(Current->next)
	{
		if(!strcmp(Current->elem, Element))
		{
			if(Previous) Previous->next = Current->next;
			else *List = Current->next;
			Temporary = Current;	
			Current = Current->next;
			free(Temporary);
		} else
		{
			Temporary = Current;
			Current = Current->next;
			Previous = Temporary;
		}
	}
}

int main(int argc, char **argv)
{
	char LastWord[100];
	list InputList = CreateList(argc - 1, argv + 1);
	GetLastWord(InputList, LastWord);
	DeleteElements(&InputList, LastWord);
	Print(InputList);
	PrintReverseList(InputList);
	free(InputList);
	return 0;
}
