#include "wordlist.h"

void clearlist(wordlist *wordset)
{
	wordset->sizelist = 0;
	wordset->curlist = 0;
	if(wordset->lst == NULL) return;
	for(int i = 0; wordset->lst[i] != NULL; i ++)
		free(wordset->lst[i]);
	free(wordset->lst);
	wordset->lst = NULL;
}

wordlist* createlist()
{
	return (wordlist *) malloc(sizeof(wordlist));
}

wordbuf* createword()
{
	return (wordbuf *) malloc(sizeof(wordbuf));
}

void null_list(wordlist *wordset)
{
	wordset->sizelist = 0;
	wordset->curlist = 0;
	wordset->lst = NULL;
}

void addsym(wordbuf *word, int sym)
{
	if(word->curbuf>word->sizebuf-1)
		word->buf = realloc(word->buf, word->sizebuf+=SIZE);
	word->buf[word->curbuf++] = sym;
}

void termlist(wordlist *wordset){
	if (wordset->lst == NULL) return;
	if (wordset -> curlist> wordset->sizelist - 1)
		wordset->lst=realloc(wordset->lst,(wordset->sizelist+1)*sizeof(*(wordset->lst)));
	wordset->lst[wordset->curlist]=NULL;
	wordset->lst=realloc(wordset->lst,(wordset->sizelist=wordset->curlist+1)*sizeof(*(wordset->lst)));
}

void nullbuf(wordbuf *word){
	word->buf=NULL;
	word->sizebuf=0;
	word->curbuf=0;
}

void addword(wordlist *wordset, wordbuf *word)
{
	if(word->curbuf > word->sizebuf - 1)
		word->buf = realloc(word->buf, word->sizebuf += 1);
	word->buf[word->curbuf++] = '\0';
	word->buf = realloc(word->buf, word->sizebuf=word->curbuf);
	if(wordset->curlist > wordset->sizelist - 1)
		wordset->lst = realloc(wordset->lst, (wordset->sizelist += SIZE) * sizeof(*(wordset->lst)));
	wordset->lst[wordset->curlist ++] = word->buf;
}

void printlist(wordlist *wordset){
	int i;
	if (wordset->lst==NULL) return;
	printf("%d\n", wordset->sizelist - 1);
	for (i=0; i<wordset->sizelist-1; i++)
		fprintf(stdout, "%s\n", wordset->lst[i]);
}

int symset(int c){
	return c!='\n' &&
		c!=' ' &&
		c!='\t' &&
		c!='>' &&
		c!='|' &&
		c!='&' &&
		c!=';' &&
		c!='(' &&
		c!=')' &&
		c!='<' &&
		c!= EOF ;
}

void wordsort(wordlist *wordset)
{
        int curword = 0, sortedword = 0;
        while(curword < wordset->curlist)
        {
                sortedword = curword;
                while(sortedword){
                        if(strcmp(wordset->lst[sortedword - 1], wordset->lst[sortedword]) > 0)
                        {
                                char *tmp = wordset->lst[sortedword];
                                wordset->lst[sortedword] = wordset->lst[sortedword - 1];
                                wordset->lst[sortedword - 1] = tmp;
                        } else
                                break;
                        sortedword --;
                }
                curword ++;
        }
}
