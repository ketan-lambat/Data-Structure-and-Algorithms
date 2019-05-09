#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "functions.h"
#define HEAP_SIZE 21

Heap* buildHeap(int capacity)
{	
	Heap *hStart = (Heap*)malloc(sizeof(Heap));
	hStart -> size = 1;
	hStart -> capacity = capacity;
	hStart -> arr = (int *)malloc(capacity*sizeof(int));

	return hStart; 
}

void percolateUp(Heap *heapMain, int index)
{
	int temp;
	int parentNode = index/2;

	if ((heapMain->arr[parentNode]) > (heapMain->arr[index]))
	{
		temp = heapMain->arr[parentNode];
		heapMain->arr[parentNode] = heapMain->arr[index];
		heapMain->arr[index] = temp;

		percolateUp(heapMain, parentNode);
	}
}

void percolateDown(Heap *heapMain, int parentNode)
{
	int left = parentNode*2;
	int right = parentNode*2 + 1;

	int min;
	int temp;

		/*Check If Left & right Node exists */
	if(left >= heapMain-> size || left<0)
		left = -1;
	if(right >= heapMain->size || right<0)
		right = -1;

	if((left != -1) && (heapMain->arr[left]) < (heapMain->arr[parentNode]))
		min = left;
	else if(right != -1 && (heapMain->arr[right]) < (heapMain->arr[parentNode]))
		min = right;
	else 
		min = parentNode;

		/*Condition to percolateDown*/
	if (min != parentNode)
	{
		temp = heapMain->arr[min];
		heapMain->arr[min] = heapMain->arr[parentNode];
		heapMain->arr[parentNode] = temp;

		percolateDown(heapMain, min);
	}

}

int delete(int deleteRoll, Student *head)
{
	Student *temp = head;
	Student *deleteStudt;

	while(temp != NULL)
	{
		if (temp -> next_student -> RollNo == deleteRoll)
		{
			deleteStudt = temp -> next_student;
			temp -> next_student = deleteStudt -> next_student;

			free(deleteStudt);
			printf("\n Record Deleted !!\n");
			return 0;
		}
		else
			temp = temp -> next_student;
	}
	return 1;
}

Student* findStudentByRoll(int queryRoll, Student *head)
{
	Student *temp = head;

	while(temp != NULL)
	{
		if (temp -> RollNo == queryRoll)
		{
			return temp;
		}
		else
			temp = temp -> next_student;
	}

	return NULL;
}

Student* findStudentByRank(int queryRank, Student *head)
{
	Student *temp = head;

	while(temp != NULL)
	{
		if (temp -> hackerRank == queryRank)
		{
			return temp;
		}
		else
			temp = temp -> next_student;
	}

	return NULL;
}



void print(Student *prntStudt)
{
	if(prntStudt == NULL)
		return;
	else
		{
				printf("\n");
			printf("Name : %s \n",prntStudt -> name);
			printf("Roll No. : %d\n", prntStudt -> RollNo);
			printf("CGPA : %.2f\n", prntStudt -> CGPA);	
			printf("hackerRank : %d\n", prntStudt -> hackerRank);
		}
}

void print_from(Student *prntStudt)
{
	if(prntStudt == NULL)
		return;
	else
	{
		print(prntStudt);
		print_from(prntStudt -> next_student);
	}
}

void print_all(Student *head)
{
	if(head -> next_student == NULL)
		printf("\nList is empty !!\n");
	else
		print_from(head -> next_student);
}



int deleteMin(Heap *heapMain)
{
	int deleteRank;
	if(heapMain->size == 0)
	{
		printf("Empty Heap\n");
		return -1;
	}
	deleteRank = heapMain->arr[1];
	heapMain->arr[1] = heapMain->arr[heapMain->size-1];
	heapMain->size--;
	percolateDown(heapMain, 1);

	return deleteRank;
}


void printHeap(Heap *heapMain)
{
	int i;
	for(i=1; i<=(heapMain->size)-1; i++)
		printf(" %d ", heapMain->arr[i]);
}

void printHeapRank(int queryRank, Student *head, Heap *heapMain)
{
	Student* query = findStudentByRank(heapMain->arr[1], head);
		print(query);

}

void insertHeap(Heap *heapMain, int hRankKey)
{
	if ((heapMain -> size) < (heapMain -> capacity))
	{
		heapMain -> arr[heapMain -> size] = hRankKey;
		percolateUp(heapMain, heapMain->size);
		heapMain -> size++;
		printf("HeapSize = %d\n", heapMain->size);
	}
}


void getTopRankingStudent(Heap *heapMain, Student* head)
{
	printHeapRank(heapMain->arr[1], head, heapMain);

	int queryRank = deleteMin(heapMain);
    Student* query = findStudentByRank(queryRank, head);
    	int	queryRoll = query-> RollNo;

    int statusCode = delete(queryRoll, head);
    	if(statusCode == 1)
    		printf("\nError in deleting\n");

}

Student *getDetails()
{
	Student *newStudt = (Student *)malloc(sizeof(Student));

	printf("Enter name: \t");
		scanf("%s", newStudt -> name);
	printf("Enter Roll NO.:\t");
		scanf("%d", &(newStudt -> RollNo));
	printf("Enter CGPA.:\t");
		scanf("%f", &(newStudt-> CGPA));
	printf("Enter hackerRank.:\t");
		scanf("%d", &(newStudt -> hackerRank));
	newStudt-> next_student = NULL;

	return newStudt;
}

void add(Student *studtEntry, Student *head, Heap *heapMain)
{
	Student *temp = head;
	while(temp -> next_student != NULL)
		{
			temp = temp -> next_student;			
		}
	temp -> next_student = studtEntry;

	insertHeap(heapMain, studtEntry -> hackerRank);
}


void create(Student *head, Heap *heapMain)
{
	Student *newStudt = getDetails();
	add(newStudt, head, heapMain);
}



void update(Student *updateStudt)
{
	printf("\nEnter the New details : \n");

	printf("Enter New Name:\n");
		scanf("%s", updateStudt -> name);
	printf("Enter New CGPA: \n");
		scanf("%f", &(updateStudt -> CGPA));
	/*printf("Enter New hackerRank\n");
		scanf("%d", &(updateStudt -> hackerRank));*/

}


void prettyPrintBHeap(Heap *heapMain)
{
	int hSize = (heapMain->size)-1;
	int i=hSize;
	int space;
	int level=1;
	int step=1;
	int temp;

	while(i>1)
	{
		i/=2;
		/*level++; */
		level*=2;
	}
		i=1;
	while(i<=(hSize))
	{
		/*space=(hSize)-level;*/
		space=level;
		if(i < 2*step)
		{
			temp = space;
			while(temp--)
				printf(" ");

					printf("%d",heapMain->arr[i++]);

			temp = space;
			while(temp--)
				printf(" ");
		}
		else if(i==2*step)
		{		
			printf("\n");
			step=step*2;
			/*level--;*/
			level/=2;
		}
		
	}
}