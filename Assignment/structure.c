/*
Title-:WAP for the bitwise operations.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a  no and choice from user and the no of bits to shift
             Output-: 


 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Structure 
struct Student
{   
    //structure variable
    char name[30];
    struct Subject *sub;
    int total;
    int average;
    int totalSub;
};

struct Subject
{
    char subName[30];
    int marks;
};

//Structure create subject data
struct Subject create_Subject_data(struct Subject su)
{
    
    struct Subject *SubjectPtr = &su;

    //Ask user for subject name    
    printf("Enter the Sub name :");
    scanf("%s", SubjectPtr->subName);
    
    //Ask user for sub marks
    printf("Enter the Sub marks :");
    scanf("%d", &(*SubjectPtr).marks);
 
    return su;
}

//Structure create student data
struct Student create_Student_data(struct Student s)
{
    int i;
    int sum;
    int totalSub;
    
    //Pointer to the structure  pointing to struct Student s
    struct Student *studentptr = &s; 
    int c;
    
    printf("Enter the student name: ");
    scanf("%s", studentptr->name);
    
    printf("Enter the number of subjects: ");
    scanf("\n%d", &totalSub);
    
    s.sub = (struct Subject *)malloc(totalSub * sizeof(struct Subject));
    
    if(s.sub == NULL)
    {
        printf("ERROR: malloc fail\n");
        exit(1);
    }
    
    sum = 0;
    for (i =0; i < totalSub; i++)
    {
        (*((s.sub)+i)) = create_Subject_data((*((s.sub)+i)));
        //Calculate Average of those three sub 
        sum+=((*((s.sub)+i))).marks;
    }
    
    //update the totalSub value 
    studentptr->totalSub = totalSub;
    
    //update the sum value 
    studentptr->total = sum;
    
    //update the average value 
    studentptr->average = (sum/totalSub);
    
    printf("average: %d \n ", studentptr->average);
    return s;
}

//Function to display student data
void displayStudentdata(struct Student s)
{
    struct Student *studentptr = &s;
    int i;
    
    printf("Student name : %s \n", studentptr->name);
    printf("Total Subjects : %d \n", studentptr->totalSub);
    
    //Loop to print 
    for (i = 0; i < studentptr->totalSub; i++)
    {
        printf("Subject name %s: ----> marks =  %d \n", ((s.sub)+i)->subName, ((*((s.sub)+i))).marks);
    }
    
    printf("Total of marks : %d \n", s.total);
    printf("Average of marks : %d \n", s.average);

}

int main()
{
    int choice, i;
    static int TotalStudents = 0;
    static struct Student totalStu[10];
    char name[10];
    char option;
    
    do
    {
	//Prompt to choice
        printf("Enter the choice: \n");
        printf("1. Create Student\n2.Display Student Info \n");
        printf("Choice : ");
        scanf("%d", &choice);
        
	//Case
        switch (choice)
        {
            case 1 :
                printf("No of students Database to be created: \n");
                scanf("\n%d", &TotalStudents);
              
	        //Loop to create student data	
                for(i = 0; i < TotalStudents; i++)
                {
                    totalStu[i] = create_Student_data(totalStu[i]);
                }
                break;
            case 2 :
                printf("\nPrint Student name whose info has to be displayed: ");
                scanf("%s", name);
                
		//Loop to display student data
                for(i = 0; i < TotalStudents; i++)
                {
                    if ((strcmp(totalStu[i].name, name) ) == 0 )
                    {
                        displayStudentdata(totalStu[i]);
                        break;
                    }
                }	
                break;		
            default:
                printf("Invalid option\n");
                break;
        }	
        
        //Ask the user whether to continue or not 
        printf("Continue(y/n): ");
        scanf("\n%s",&option);
        
        if (option == 'y')
        {
            continue;
        }
        else
        {
            break;
        }
        
    } while (1);
    
    return 0;
}
