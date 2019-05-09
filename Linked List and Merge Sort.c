#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	char Student_Name[50];
	int RollNo;
	struct student* next_student;
};


typedef struct student Student;

Student *HeadA;
Student *HeadB;
Student *Master;


Student* EnterStudtData()
{
	char name[50];
	int rollno;

	printf("Enter name: \t");
		scanf("%s", name);
	printf("Enter Roll NO.:\t");
		scanf("%d", &rollno);

	Student *tempStudt = (Student*)malloc(sizeof(Student));

		strcpy(tempStudt -> Student_Name, name);
		tempStudt -> RollNo = rollno;
		tempStudt -> next_student = NULL;

	return tempStudt;
}

Student* add(Student *student, Student *head)
{
	Student *temp = head;

	if (head == NULL)
	{
			Student *studt = (Student*)malloc(sizeof(Student));
			studt = student;
			head = studt;
	}
	else
	{
		while(temp -> next_student !=NULL)
		{
			temp = temp -> next_student;
		}

			temp -> next_student = student;
	}

	return head;
}

Student* create(Student *head)
{
	char name[50];
	int rollno;

	printf("Enter name: \t");
		scanf("%s", name);
	printf("Enter Roll NO.:\t");
		scanf("%d", &rollno);

	Student *tempStudt = (Student*)malloc(sizeof(Student));

		strcpy(tempStudt -> Student_Name, name);
		tempStudt -> RollNo = rollno;
		tempStudt -> next_student = NULL;

		head = add(tempStudt, head);

	return head;
}


void print(Student *student)
{
	if(student == NULL)
		return;
	else
	{
			printf("\n");
		printf("Name : %s \n",student -> Student_Name);
		printf("Roll No. : %d\n", student -> RollNo);		
	}
}

void print_from(Student *student)
{
	if(student == NULL)
		return;
	
	print(student);
	print_from(student -> next_student);

}

void print_all(Student *head)
{
	print_from(head);
}

void update(int i, Student *nstudent, Student *head)
{

	Student *temp = head;

	for (int pos = 0; pos < i-1; pos++)
	{
		temp = temp -> next_student;
	}
		Student *tempnext = temp -> next_student ->next_student;
		temp = nstudent;
		nstudent -> next_student = tempnext;
}

void insert(int i, Student *student, Student *head)
{

	Student *temp = head;

	for (int pos = 0; pos < i-1; pos++)
	{
		temp = temp -> next_student;
	}
		Student *tempnext = temp ->next_student;
		temp -> next_student = student;
		student -> next_student = tempnext;
}

void delete(int i, Student *head)
{
	Student *temp = head;

	for (int pos = 0; pos < i-1; pos++)
	{
		temp = temp -> next_student;
	}
		temp -> next_student = temp -> next_student -> next_student;
}

Student *merge(Student *HeadA, Student *HeadB, Student* Master)
{
	
	Master = HeadA;
	Student *temp = Master;

	while(temp -> next_student !=NULL)
		{
			temp = temp -> next_student;
		}

		temp -> next_student = HeadB;
		return Master;
}


void FrontBackSplit(Student *source, Student **frontref, Student **backref)
{
	Student *fast;
	Student *slow;

	slow = source;
	fast = source -> next_student;

//Advance fast by two node, slow by one node
	while(fast!=NULL)
	{
		fast = fast -> next_student;
			if(fast != NULL)
			{
				slow = slow -> next_student;
				fast = fast -> next_student;
			}
	}

	*frontref = source;
	*backref = slow -> next_student;
	slow -> next_student =NULL;
}

Student *SortedMerge(Student *a, Student *b)
{
	Student *result = NULL;

	if(a==NULL)
		return (b);
	else if(b==NULL)
		return (a);

	if (a->RollNo <= b->RollNo)
	{
		result = a;
		result->next_student = SortedMerge(a->next_student ,b);
	}
	else
	{
		result = b;
		result->next_student = SortedMerge(a, b->next_student);
	}

	return (result);
}

void mergesort(Student **headRef)
{
	Student *head = *headRef;
	Student *a;
	Student *b;

	if((head==NULL) || (head->next_student == NULL))
		return;

	FrontBackSplit(head, &a, &b);

	mergesort(&a);
	mergesort(&b);

	*headRef = SortedMerge(a, b);
}


int main()
{
	Student *HeadA = NULL;
	Student *HeadB = NULL;
	Student *Master = NULL;

	int choice, flag=1;
	int SecChoice;
	int InsertPos, DeletePos;

	while(flag==1)
	{
		printf("\nPlease enter the solution to run: \n");
		printf("Sec A : 1 \t Sec B : 2 \t MasterList : 3\n");
	    printf("\t1: Create a new student (Sec A/Sec B)\n");
	    printf("\t2: Insert a student (Sec A/Sec B)\n");
			printf("\t3: Delete a student (Sec A/Sec B)\n");
			printf("\t4: Create a master list\n");
	    printf("\t5: mergesort a list (Sec A/Sec B/Masterlist)\n");
			printf("\t6: Print all students (Sec A/Sec B/Masterlist)\n");
	    printf("\t0: To exit \n");

	    scanf("%d", &choice);

	    switch(choice)
	    {
	    	case 0:
				flag=0;
				break;
				return 0;

			case 1:
				{
					printf("New Student for Sec (A/B) : \t");
					scanf("%d", &SecChoice);
					if (SecChoice==1)
					{
						HeadA = create(HeadA);
					}
					else if (SecChoice == 2)
					{
						HeadB = create(HeadB);
					}
					else
						printf("Please enter a valid choice\n");

					break;
				}
				
			case 2:
				printf("Insert a student in (SecA/SecB): \t");
					scanf("%d", &SecChoice);
				printf("At postion : \n");
					scanf("%d", &InsertPos);

				Student *student = EnterStudtData();

				if (InsertPos ==0)
				{
					if (SecChoice ==1)
					{
						HeadA = student;
					}
					else if (SecChoice ==2)
					{
						HeadB = student;
					}
				}

				if (SecChoice==1)
				{
					insert(InsertPos, student, HeadA);
				}
				else if (SecChoice == 2)
				{
					insert(InsertPos, student, HeadB);
				}
				else
					printf("Please enter a valid choice\n");

				break;
			case 3:
				printf("Delete a student in (SecA/SecB): \t");
					scanf("%d", &SecChoice);
				printf("At postion : \n");
					scanf("%d", &DeletePos);

				if (SecChoice==1)
				{
					delete(DeletePos, HeadA);
				}
				else if (SecChoice == 2)
				{
					delete(DeletePos, HeadB);
				}
				else
					printf("Please enter a valid choice\n");

				break;

			case 4:
				Master = merge(HeadA, HeadB, Master);
				break;

			case 5:
				printf("MergeSort list (A/B/MasterList) : \t");
					scanf("%d", &SecChoice);
					if (SecChoice==1)
					{
						mergesort(&HeadA);
					}
					else if (SecChoice == 2)
					{
						mergesort(&HeadB);
					}
					else if (SecChoice == 3)
					{
						mergesort(&Master);
					}
					else
						printf("Please enter a valid choice\n");
				break;

			case 6:
				printf("Print data for (A/B/MasterList) : \t");
					scanf("%d", &SecChoice);
					if (SecChoice==1)
					{
						print_all(HeadA);
					}
					else if (SecChoice == 2)
					{
						print_all(HeadB);
					}
					else if (SecChoice == 3)
					{
						print_all(Master);
					}
					else
						printf("Please enter a valid choice\n");
				break;		
	    }
	}

	return 0;
}
