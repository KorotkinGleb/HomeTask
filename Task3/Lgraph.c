#include "Lgraph.h"

int getsym()
{
	static int *symbstr = NULL;
	static int cursym = 0;
	if(symbstr == NULL) {
		symbstr = malloc(sizeof(int) * N);
		for(int i = 0; i < N; i ++)
			if(fscanf(stdin, "%lc", symbstr + i) == EOF){
				symbstr[i] = EOF;
				break;
			}
	} else if(cursym == N)
	{
		cursym = 0;
		for(int i = 0; i < N; i ++)
                        if(fscanf(stdin, "%lc", symbstr + i) == EOF) {
				symbstr[i] = EOF;
				break;
			}
	}
	return symbstr[cursym ++];
}

void* start(wordlist *wordset, wordbuf *curword, int *c) {
	if(*c==' '||*c=='\t') { *c=getsym(); return start;}
	else if (*c==EOF) {
		termlist(wordset);
		printlist(wordset);
		wordsort(wordset);
		printlist(wordset);
		clearlist(wordset);
		return stop;
	}
	else if (*c=='\n') {
		termlist(wordset);
		printlist(wordset);
		wordsort(wordset);
		printlist(wordset);
		*c=getsym();
		return newline;
	}
	else { char cprev=*c;
		nullbuf(curword);
		addsym(curword, *c);
		*c=getsym();
		return (isspecial(cprev))? specialword: word;
	}
}

int isspecial(char c)
{
	if(c == '|' || c == '&' || c == '>' || c == '<' || c == ')' || c == '(' || c == ';') return 1;
	return 0;
}

int isspecial2(char c)
{
	if(c == '|' || c == '&' || c == '>') return 1;
	return 0;
}

void* word(wordlist *wordset, wordbuf *curword, int *c){
	if(symset(*c)) {
		addsym(curword, *c);
		*c=getsym();
		return word;
	}
	else {
		addword(wordset, curword);
		return start;
	}
}

void* specialword(wordlist *wordset, wordbuf *curword, int *c) {
	if(isspecial2(*c) && curword->buf[curword->curbuf - 1] == *c) {
		addsym(curword, *c);
		*c=getsym();
		return specialword2;
	}
	else {
		addword(wordset, curword);
		return start;
	}
}
void* specialword2(wordlist *wordset, wordbuf *curword, int *c) {
	addword(wordset, curword);
	return start;
}

void* newline(wordlist *wordset, wordbuf *curword, int *c){
	clearlist(wordset);
	return start;
}
void* stop(wordlist *wordset, wordbuf *curword, int *c){exit(0);}
