#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


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
	float cgpa;

	printf("Enter name: \t");
		scanf("%s", name);
	printf("Enter Roll NO.:\t");
		scanf("%d", &rollno);
	printf("Enter CGPA.:\t");
		scanf("%f", &cgpa);

	Student *tempStudt = (Student*)malloc(sizeof(Student));

		strcpy(tempStudt -> Student_Name, name);
		tempStudt -> RollNo = rollno;
		tempStudt -> CGPA = cgpa;
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
		printf("CGPA : %.2f\n", student -> CGPA);		
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

Student* find_student(int findRoll)
{
	Student* temp = head;

	while(temp -> next_student != NULL)
	{
		if(temp -> RollNo == findRoll)
			return temp;
		else
			temp = temp-> next_student;
	}
	return NULL;
}


void delete(Student **head, int deleteRoll)
{
	Student *temp = *head;
	Student *prev;
	if (temp ->RollNo == deleteRoll)
	{
		temp = temp->next_student;
		return;

	}
	else{
		while(temp!=NULL)
		{
			if (temp->RollNo==deleteRoll)
			{
				break;
			}
			prev = temp;
			temp = temp->next_student;
			prev ->next_student = temp->next_student;
		}

	}


}


