#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALPHABETS 26

struct TrieNode
{
	struct TrieNode *child[ALPHABETS];
	int isEndOfWord; /*1 If TRUE*/
};

typedef struct TrieNode trieNode;

trieNode *getNewNode()
{
	trieNode *node = (trieNode*)malloc(sizeof(trieNode));
	node->isEndOfWord = 0;

			/*Allocate all the alphabets to null*/
	for(int i=0 ; i<ALPHABETS; i++)
		node->child[i] = NULL;

	return node;
}

void addWord(trieNode *head, char *word)
{
	trieNode *curnt = head;
	char *temp = word;
	while(*temp)
	{
	//	printf("%c -> %p\n", *temp, curnt->child[*temp - 'a']);

		if(curnt->child[*temp - 'a'] == NULL)
			{
			//	printf("\n\t %c => New node Required\n", (*temp));
				curnt->child[*temp - 'a'] = getNewNode();
				printf("\n\t %c => New node created\n", (*temp));
			}

		curnt = curnt->child[*temp - 'a'];

			temp++;
	}

	curnt->isEndOfWord = 1;
	printf("\n '%s' Added Successfully !!", word);
}

int findWord(trieNode *head, char *word)
{
	trieNode *curnt = head;
	char *temp = word;

	if(curnt == NULL)
		return 0;

	while(*temp)
	{
		curnt = curnt->child[*temp-'a'];

		if(curnt == NULL)
			return 0;

		temp++;
	}

	return curnt->isEndOfWord;
}

int hasChild(trieNode *head)
{
	for(int i=0; i<ALPHABETS; i++)
		if(head->child[i])
			return 1; /*hasChild == TRUE */

	return 0;
}

int deleteWord(trieNode **head, char *word)
{

	trieNode **curnt = head;
	char *temp = word;

//	printf("\n\t %p\n", *curnt);

			/*Trie is empty*/
	if(*curnt == NULL)
		{
		//	printf("\n\t curnt == NULL\n");
			return 0;
		}

			/*Until end of the string is reached*/
if(*temp) 
{
	if( (*curnt!=NULL) 
			&& ((*curnt)->child[*temp-'a'] != NULL) 
			&& (deleteWord( &((*curnt)->child[*temp-'a']), (temp+1))) 
			&& ((*curnt)->isEndOfWord == 0) 
			)
	{
		if(!hasChild(*curnt))
		{
			//	printf("\n\t '%c' !Leaf node, !hasChild\n", (*temp));
			(*curnt) = NULL;
			free(*curnt);
			//	printf("\n\t '%c' !Leaf node, !hasChild : DELETED\n", (*temp));
			return 1;
		}
		else
			return 0;
	}
}
			/*End of the strig is reached*/
	if(*temp == '\0' && ((*curnt)->isEndOfWord))
	{
		if(!hasChild(*curnt))
		{
			//	printf("\n\t '%c' Leaf node, !hasChild\n", (*temp));
			(*curnt) = NULL;
			free(*curnt);
			//	printf("\n\t '%c' Leaf node, !hasChild: DELETED\n", (*temp));
			return 1;
		}
		else
		{
			//	printf("\n\t '%c' Leaf node, hasChild\n", (*temp));
			(*curnt)->isEndOfWord = 0;
			//	printf("\n\t '%c' Leaf node, hasChild: isEndOfWord, not DELETED\n", (*temp));
			return 0;
		}
	}
	return 0;
}


void printTrie(trieNode *node, char *word, int level)
{
	if (node==NULL)
	{
		return;
	}

	if(node->isEndOfWord)
	{
		*(word+level) = '\0';
		printf("\n\t\t\t %s", word);
	}

	int i;
	for(i=0; i<ALPHABETS; i++)
	{
		if(node->child[i])
		{
			*(word+level) = i +'a';
			printTrie(node->child[i], word, level+1);
		}
	}
}

int main()
{
	
	int choice;
	int flag=1;
	char insertWord[25];
	char queryWord[25];
	char tpWord[25];

	trieNode *root = getNewNode();

	while(flag == 1)
	{

		if(root == NULL)
					{
						printf("\n\t\tTrie Empty\n");
					}

		printf("\n\nEnter the Step to Run : \n");

			printf("\t1: addWord in trie\n");
			printf("\t2: deleteWord in trie\n");
			printf("\t3: findWord in trie\n");
			printf("\t4: printTrie\n");
	
			printf("\t0: EXIT\n");

				scanf("%d", &choice);

		switch(choice)
		{
			case 0:
				{
					flag=0;
					printf("\n\t\tExiting, Thank You !!\n");
					break;
					return 0;
				}

			case 1:
				{
					printf("\n\tEnter the Word to insert: ");
						scanf("%s", insertWord);
					if(root == NULL)
					{
						root = getNewNode();
					}
					


					if(findWord(root, insertWord))
						printf("\t '%s' Word Already exists\n", insertWord);
					else if (!findWord(root, insertWord))
						addWord(root, insertWord);

						printf("\n\n\tPrinting Trie: ");
						printTrie(root, tpWord , 0);
						printf("\n");

					break;
				}

			case 2:
				{
					printf("\n\tEnter the Word to delete: ");
						scanf("%s", queryWord);

						if(!findWord(root, queryWord))
							printf("\t '%s' Word Not Found\n", queryWord);
						else if (findWord(root, queryWord))
							{
								printf("\t'%s' Word Found !!\n", queryWord);
								deleteWord(&root, queryWord);
								printf("\t'%s' Word DELETED !!\n", queryWord);
							}

							printf("\n\n\tPrinting Trie: ");
						printTrie(root, tpWord , 0);
						printf("\n");
					break;
				}

			case 3:
				{
					printf("\n\tEnter the Word to find: ");
						scanf("%s", queryWord);

					if(!findWord(root, queryWord))
						printf("\t '%s' Word Not Found\n", queryWord);
					else if (findWord(root, queryWord))
						printf("\t'%s' Word Found !!\n", queryWord);
					break;
				}

			case 4:
				{
					printf("\n\n\tPrinting Trie: ");
						printTrie(root, tpWord , 0);
						printf("\n");
					break;
				}

			default:
				{
					flag=0;
					printf("\n\t\tExiting, Thank You !!\n");
					break;
					return 0;
				}
			}
		}



	return 0;
}