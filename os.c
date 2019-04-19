#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct process
{
    int bt,at,tat,wt,comt,pid,remt;
}process;

void calculate(struct process p[],int n);
void display(struct process p[],int n);
void sjf(struct process p[],int n);
void print_table(process p[], int n);

float atat=0,awt=0;
int n=0,i=0,n1=0,n2=0,n3=0;
int t=0,done=0,small,flag=0,smallest=100;

void main()
{
printf("\nEnter the number of process : ");
scanf("%d",&n);
fflush(stdin);
struct process p[n];

	//Allocatig Memory
	for(i=0;i<n;i++){
		fflush(stdin);
			p[i].pid= i+1;
		printf("\nEnter Burst time and Arrival time for P%d : ",i+1);
		scanf("%d%d",&p[i].bt,&p[i].at);
		
	}

system("cls");
sjf(p,n);
calculate(p,n);
printf("\n\n");
display(p,n);


getch();

}


void sjf(struct process p[],int n)
{

int i=0,t=3;
int done=0,small=0,flag=0,smallest=1000;

	
	printf("\n\n\t\t**************SHORTEST EXECUTION TIME FIRST**************\n\n");
	printf("This is order execution of the processes\n");
	for(i=0;i<n;i++)
	{
	p[i].remt=p[i].bt;

	p[i].comt=0;
	}

	while(done!=n)
{
	for(i=0;i<n;i++){
		if(p[i].at<=t && p[i].remt<smallest && p[i].remt>0)
		{
			small=i;
			smallest=p[i].remt;
			flag=1;
		}
	}
		if(flag==0)
		{
			t++;
			continue;
		}
		if(p[small].remt>=10)
		{
			p[small].remt-=10;
			t+=10;
		}
		else
		{
			t+=p[small].remt;
			p[small].remt=0;
		}
		
		smallest=p[small].remt;
		if (smallest==0)
		{
			smallest=1000;
		}
		if(p[small].remt==0)
		{
			p[small].comt=t;
			done++;
			flag=0;
			printf("P[%d]->",p[small].pid);
		}

		
	}
}

void calculate(struct process p[],int n)
{

   for(i=0;i<n;i++)
   {
   	p[i].tat=p[i].comt - p[i].at;
    p[i].wt=p[i].tat - p[i].bt;
   }


}


void display(struct process p[],int n)
{
	atat=0;
	awt=0;
print_table(p,n);
for(i=0;i<n;i++)
{

	atat+=p[i].tat;
	awt+=p[i].wt;
}
atat/=n;
awt/=n;

printf("\n\nAvarage turn around time is %f\n",atat);
printf("\n\nAvarage Waiting time is %f",awt);
}

void print_table(process p[], int n)
{
    int i;

    puts("+-----+--------------+------------+-----------------+-----------------+---------------+");
    puts("| PID | Arrival Time | Burst Time | Completion Time | Turnaround Time |  Waiting Time |");
    puts("+-----+--------------+------------+-----------------+-----------------+---------------+");

    for(i=0; i<n; i++) {
        printf("| %2d  |      %2d      |     %2d     |       %2d        |       %2d        |      %2d       | \n"
               , p[i].pid,p[i].at, p[i].bt, p[i].wt, p[i].tat,p[i].comt );
        puts("+-----+--------------+------------+-----------------+-----------------+---------------+");
    }

}
