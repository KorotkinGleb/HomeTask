#ifndef WORDLIST_H
#define WORDLIST_H

#define SIZE 16
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct wordlist
{
        char ** lst;
        int sizelist;
        int curlist;
} wordlist;

typedef struct wordbuf
{
        char *buf;
        int sizebuf;
        int curbuf;
} wordbuf;

void clearlist(wordlist *wordset);
void null_list(wordlist *wordset);
void addsym(wordbuf *word, int sym);
void addword(wordlist *wordset, wordbuf *word);
void printlist(wordlist *wordset);
void null_list(wordlist *wordset);
void termlist(wordlist *wordset);
void wordsort(wordlist *wordset);
void nullbuf(wordbuf *word);
wordlist* createlist();
wordbuf* createword();
int symset(int c);

#endif
