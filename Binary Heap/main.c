#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main()
{
	Student *head;
	Student list;
	list.next_student =  NULL;
	head = &list;
	

	int choice, flag=1;
	int queryRoll, queryRank;
	int statusCode;

	Heap* heapMain = buildHeap(HEAP_SIZE);

	while(flag==1)
	{
		printf("\n\nPlease enter the solution to run: \n");

			printf("\t1: Add a new student \n");
	    	printf("\t2: Update student by RollNo \n");
	    	printf("\t3: Delete student by RollNo \n");
	   		printf("\t4: Print RollNo\n"); 
	    	printf("\t5: Print All\n");
	    	printf("\t6: Delete minRank \n");
	    	printf("\t7: getTopRankingStudent \n");
	    	printf("\t8: prettyPrintBHeap \n");
					
	    	printf("\t0: To exit \n");

	    scanf("%d", &choice);

	    switch(choice)
	    {
	    	case 0:
	    		{
	    			flag = 0;
	    			break;
	    			return 0;
	    		}

	    	case 1:
		    	{
		    		printf("\nEnter the details of the new student to add : \n");
		    		create(head, heapMain);
		    		
		    		break;
		    	}

		    case 2:
		    	{
		    		printf("\nEnter the Roll No to Update\n");
		    			scanf("%d", &queryRoll);
		    		Student* query = findStudentByRoll(queryRoll, head);
		    		if(query == NULL)
		    			printf("\nRollNo Does Not Exist\n");
		    		else
		    			update(query);
		    		break;
		    	}

		    case 3:
		    	{
		    		printf("\nEnter the RollNo to Delete : \n");
		    			scanf("%d", &queryRoll);
		    		
		    		statusCode = delete(queryRoll, head);
		    			if(statusCode == 1)
		    				printf("Error in deleting\n");

		    		break;
		    	}

		    case 4:
		    	{
		    		printf("\nEnter the Roll No to print: \n");
		    			scanf("%d", &queryRoll);

		    		Student* query = findStudentByRoll(queryRoll, head);
		    		if(query == NULL)
		    			printf("\nRollNo Does Not Exist\n");
		    		else
		    			print(query);

		    		break;
		    	}

		   case 5:
		    	{
		    		printf("\nPrinting Entire List: \n");
		    			print_all(head);
		    		printf("\nPrinting Heap Array: ");
		    			printHeap(heapMain);
		    		printf("\nPretty Printing Min Binary Heap\n");
		    		prettyPrintBHeap(heapMain);


		    		break;
		    	}
		    case 6:
		    	{
		    		printf("\nDeleting Min Rank : \n");
		    		queryRank = deleteMin(heapMain);
		    			Student* query = findStudentByRank(queryRank, head);
		    		queryRoll = query-> RollNo;

		    		statusCode = delete(queryRoll, head);
		    			if(statusCode == 1)
		    				printf("\nError in deleting\n");
		    		break;
		    	}
		    case 7:
		    	{
		    		printf("\n getTopRankingStudent : \n");
		    		getTopRankingStudent(heapMain, head);

		    		break;
		    	}
		    default:
		    	{
		    		flag = 0;
	    			break;
	    			return 0;
		   	 	}
		    
	    }
	}


	
	return 0;
}