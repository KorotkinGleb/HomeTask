#ifndef LGRAPH_H
#define LGRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include "wordlist.h"

#define N 1

typedef void * (*vertex)(wordlist *, wordbuf *, int *);
void * start(wordlist *wordset, wordbuf *curword, int *c);
void * word(wordlist *wordset, wordbuf *curword, int *c);
void * specialword(wordlist *wordset, wordbuf *curword, int *c);
void * specialword2(wordlist *wordset, wordbuf *curword, int *c);
void * newline(wordlist *wordset, wordbuf *curword, int *c);
void * stop(wordlist *wordset, wordbuf *curword, int *c);
int getsym();
int isspecial(char c);
int isspecial2(char c);

#endif
