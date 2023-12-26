#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fptr=NULL;

struct patient {	//stores the data of the patient
	int opnumber;
	char date[12];
    char name[20];
    int age;
    char contactNumber[10];
};

struct node {	//nodes for the data to be stored
    struct patient patient;
    struct node* next;
    int priority;
};

struct node* front = NULL;



void registration(FILE *fptr)  //to read the data from the file and stores it in  linked list with priorities
{
	char line[50];
	char *token;
	
	 while (fgets(line, sizeof(line), fptr) != NULL)
	{
		struct node *newnode,*temp;
		newnode=(struct node *)malloc(sizeof(struct node));
		token=strtok(line," ");           //token is a pointer to allocate a substring to break the string
		if(token!=NULL)
		{
			newnode->patient.opnumber=atoi(token);
			token=strtok(NULL," ");		//strtok breaks the string into substring till the space
		}
		if(token!=NULL)
		{
			strcpy(newnode->patient.date,token);
			token=strtok(NULL," ");
		}
		if(token!=NULL)
		{
			strcpy(newnode->patient.name,token);
			token=strtok(NULL," ");
		}
		if(token!=NULL)
		{
			newnode->patient.age=atoi(token);
			token=strtok(NULL," ");
		}
		if(token!=NULL)
		{
			strcpy(newnode->patient.contactNumber,token);
			token=strtok(NULL," ");
		}
		if(token!=NULL)
		{
			newnode->priority=atoi(token);
		}
		//newnode with the file data
		temp = front;
    	if (front == NULL || front->priority > newnode->priority) 
		{
        	newnode->next = front;
        	front = newnode;
    	} 
		else
		{
        	while (temp->next != NULL && temp->next->priority <= newnode->priority)
			{
           	 	temp = temp->next;
        	}
        	newnode->next = temp->next;
        	temp->next = newnode;
    	}
	}
}

void printOP(struct node *ptr)  //to print the op card after registration
{
	printf("\n\t\t**************************************************************\n");
    printf("\t\t\t\tOP Card\n");
    printf("\t\t**************************************************************\n");
    printf("\n\t\tOP NUMBER        :%d",ptr->patient.opnumber);
    printf("\n\t\tDATE             :%s",ptr->patient.date);
    printf("\n\t\tNAME             :%s",ptr->patient.name);
    printf("\n\t\tAGE              :%d",ptr->patient.age);
    printf("\n\t\tCONTACT NUMBER   :%s",ptr->patient.contactNumber);
    printf("\n");
    printf("\n\t\t\t\tPrescriptions:\n\n\n\n\n\n");
    printf("\n\t\t************************************************************\n\n\n\n\n\n");
}

void patient_registration() {	//new patient registration
    static int i = 9; // static variable to maintain its value between function calls

    char name[50],date[12],nothing[2],phone[10];
    struct node* temp;
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    
    gets(nothing);
    
    printf("\nEnter date:");
    gets(date);
    strcpy(newnode->patient.date,date);

    printf("\nENTER YOUR NAME: ");
    gets(name);
    strcpy(newnode->patient.name,name);

    printf("\nENTER YOUR AGE: ");
    scanf("%d", &newnode->patient.age);
    
    gets(nothing);

    printf("\nENTER YOUR CONTACT NUMBER: ");
    gets(phone);
    strcpy(newnode->patient.contactNumber,phone);

    printf("\n/*PRIORITIES*/\n");
    printf("1. EMERGENCY\n");
    printf("2. OLD PATIENT Consultation\n");
    printf("3. OLD AGE PATIENT\n");
    printf("4. FEE PAYMENT\n");
    printf("5. NORMAL PATIENT\n");

    printf("ENTER YOUR PRIORITY: ");
    scanf("%d", &newnode->priority);

    newnode->patient.opnumber = i;		//assigning a unique number to identify patient uniquely
    printf("\n\t**Your OP Number is %d**",i);	
    i += 1;
    printf("\n\n");
	printOP(newnode);
    temp = front;
    if (front == NULL || front->priority > newnode->priority) {
        newnode->next = front;
        front = newnode;
    } 
	else 
	{
        while (temp->next != NULL && temp->next->priority <= newnode->priority) 
		{
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    fprintf(fptr,"%d\t %s\t %s\t %d\t %s\t %d\n",newnode->patient.opnumber,date,name,
	newnode->patient.age,phone,newnode->priority);
}

void display() {
	if(front==NULL)
	{
		printf("\n NO patient is there:");
		return;
	}
    else
    {
    	struct node* temp = front;
    	while (temp != NULL) 
		{
        	printf("op number %d, name %s\n", temp->patient.opnumber, temp->patient.name);
        	temp = temp->next;
    	}
	}
}

void printOPCard(struct node *ptr) {
    printf("\n\t\t**************************************************************\n");
    printf("\t\t\t\tOP Card\n");
    printf("\t\t**************************************************************\n");
    printf("\n\t\tOP NUMBER        :%d",ptr->patient.opnumber);
    printf("\n\t\tDATE             :%s",ptr->patient.date);
    printf("\n\t\tNAME             :%s",ptr->patient.name);
    printf("\n\t\tAGE              :%d",ptr->patient.age);
    printf("\n\t\tCONTACT NUMBER   :%s",ptr->patient.contactNumber);
    printf("\n");
    printf("\n\t\t\t\tPrescriptions:\n");
    printf("\t\t1. Tablet A - Take twice daily after meals\n");
    printf("\t\t2. Tablet B - Take once daily before bedtime\n");
    printf("\t\t3. Tablet C - Take three times daily before meals\n");
    printf("\n\t\t************************************************************\n\n\n\n\n\n");
}

void nextPatient(){
	if(front==NULL)
	{
		printf("\n NO PATIENT IS THERE");
		return;
	}
	else
	{
		struct node *ptr;
		ptr=front;
		int t;
		printf("\n1.Enter if time is between 8AM-4PM");
		printf("\n2.Enter if time is between 4PM-12AM");
		printf("\n3.Enter if time is between 12AM-8AM");
		printf("\nEnter time:");
		scanf("%d",&t);
		switch(t)
		{
			case 1:
				printf("\nMEET DOCTOR 1\n");
				break;
			case 2:
				printf("\nMEET DOCTOR 2\n");
				break;
			case 3:
				printf("\nMEET DOCTOR 3\n");
				break;
		}
		printf("\nPatient Details:");
		printf("\nOP NUMBER:%d",ptr->patient.opnumber);
		printf("\nNAME:%s\n",ptr->patient.name);
		sleep(2);
		printOPCard(ptr);
		front=front->next;
		free(ptr);
	}
}


int main() {
    printf("\n\n//**********PATIENT MANAGEMENT SYSTEM**********//");
	
	fptr=fopen("patientDetails.txt","r");
	if(fptr!=NULL)
	{
		registration(fptr);
	}
	fclose(fptr);
	
    fptr=fopen("patientDetails.txt","a");
    int choice;
    do{
    	printf("\n\n\t****MAIN MENU****\n");
    	printf("\n1.Patient Registration");
    	printf("\n2.Display All the Patients");
    	printf("\n3.Display Next Patient to be consulted");
    	printf("\n4.Exit");
    	printf("\nEnter your choice:");
    	scanf("%d",&choice);
    	switch(choice)
    	{
    		case 1:
    			patient_registration();
    			break;
    		case 2:
    			display();
    			break;
    		case 3:
    			nextPatient();
    			break;
		}
	}
	while(choice!=4);
	
	fclose(fptr);
}
