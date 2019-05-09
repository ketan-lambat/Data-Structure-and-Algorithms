#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

/*
struct student
{
	char Student_Name[50];
	int RollNo;
	float CGPA;
	struct student* next_student;
};

typedef struct student Student;

Student *head;
*/
int main()
{
	Student *head = NULL;

	int choice, flag=1;
	int DeleteRoll;
	int findRoll;
	int printRoll;

	while(flag==1)
	{
		printf("\nPlease enter the solution to run: \n");

	    	printf("\t1: Add a new student \n");
	   		printf("\t2: Print RollNo\n"); 
	    	printf("\t3: Print All\n");
			printf("\t4: Delete RollNo\n");
			
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
					printf("Add New student : \t");
						head = create(head);
					break;
				}
				
			case 2:
			{
				printf("Enter the roll no to print \t");
					scanf("%d", &printRoll);
					Student* query = find_student(findRoll);
						print(query);
				break;
			}
		
			case 3:
				printf("Printing all Rollnos \t");
					print_all(head);
				break;
			case 4:
			{	printf("Delete Rollno: \t");
				scanf("%d", &DeleteRoll);
				delete(&head, DeleteRoll);
				break;	
			}
	    }
	}

	return 0;
}