#ifndef FUNCTIONS_H
#define FUNCTIONS_H



struct student
{
	char Student_Name[50];
	int RollNo;
	float CGPA;
	struct student* next_student;
};

typedef struct student Student;

Student *head;

Student* add(Student *student, Student *head);
Student* create(Student *head);

Student* find_student(int findRoll);
void print(Student *student);
void print_from(Student *student);
void print_all(Student *head);
void delete(Student **head, int deleteRoll);


#endif