#include "wordlist.h"
#include "Lgraph.h"

int main()
{
	int c = 0;
	wordlist *wordset = createlist();
	wordbuf *curword = createword();
	vertex V = start;
	c = getsym();
	null_list(wordset);
	while(1){
		V = V(wordset, curword, &c);
	}
	return 0;
}
