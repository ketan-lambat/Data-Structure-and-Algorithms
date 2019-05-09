#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define HEAP_SIZE 21

struct student
{
	char name[25];
	int RollNo;
	float CGPA;
	int hackerRank;
	struct student *next_student;
};

typedef struct student Student;

Student *head;

struct heap
{
	int *arr;
	int size;
	int capacity;	
};
typedef struct heap Heap;

Heap *heapMain;



Heap* buildHeap(int capacity);
void percolateUp(Heap *heapMain, int index);
void percolateDown(Heap *heapMain, int parentNode);
int delete(int deleteRoll, Student *head);
Student* findStudentByRoll(int queryRoll, Student *head);
Student* findStudentByRank(int queryRank, Student *head);
void print(Student *prntStudt);
void print_from(Student *prntStudt);
void print_all(Student *head);
int deleteMin(Heap *heapMain);
void printHeap(Heap *heapMain);
void printHeapRank(int queryRank, Student *head, Heap *heapMain);
void insertHeap(Heap *heapMain, int hRankKey);
void getTopRankingStudent(Heap *heapMain, Student* head);
Student *getDetails();
void add(Student *studtEntry, Student *head, Heap *heapMain);
void create(Student *head, Heap *heapMain);
void update(Student *updateStudt);
void prettyPrintBHeap(Heap *heapMain);


#endif