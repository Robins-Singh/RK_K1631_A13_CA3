#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
 
#define MAX 5
#define N 10

typedef struct

{

int process_id, arrival_time, burst_time, priority;

int q, ready;

}process_structure;

int Queue(int t1)

{

if (t1 == 0 || t1 == 1 || t1 == 2 || t1 == 3)

{

return 1;

}

else

{

return 2;

}

}

int main()

{

int limit, count, temp_process, time, j, y;

process_structure temp;

printf("Enter Total Number of Processes:\t");

scanf("%d", &limit);

process_structure process[limit];

for(count = 0; count < limit; count++)

{

printf("\nProcess ID:\t");

scanf("%d", &process[count].process_id);

printf("Arrival Time:\t");





scanf("%d", &process[count].arrival_time);

printf("Burst Time:\t");

scanf("%d", &process[count].burst_time);

printf("Process Priority:\t");

scanf("%d", &process[count].priority);

temp_process = process[count].priority;

process[count].q = Queue(temp_process);

process[count].ready = 0;

}

time = process[0].burst_time;

for(y = 0; y < limit; y++)

{

for(count = y; count < limit; count++)

{

if(process[count].arrival_time < time)

{

process[count].ready = 1;

}

}

for(count = y; count < limit - 1; count++)

{

for(j = count + 1; j < limit; j++)

{

if(process[count].ready == 1 && process[j].ready == 1)

{

if(process[count].q == 2 && process[j].q == 1)

{

temp = process[count];

process[count] = process[j];

process[j] = temp;






}

}

}

}

for(count = y; count < limit - 1; count++)

{

for(j = count + 1; j < limit; j++)

{

if(process[count].ready == 1 && process[j].ready == 1)

{

if(process[count].q == 1 && process[j].q == 1)

{

if(process[count].burst_time > process[j].burst_time)

{

temp = process[count];

process[count] = process[j];

process[j] = temp;

}

else

{

break;

}

}

}

}

}

printf("\nProcess[%d]:\tTime:\t%d To %d\n", process[y].process_id, time, time + process[y].burst_time);

time = time + process[y].burst_time;

for(count = y; count < limit; count++)

{

if(process[count].ready == 1)

{

process[count].ready = 0;

}

}

}

return 0;
}


//FCFS_implementation

#include<math.h>
#include<stdio.h>
int main()
{
    int i,n,req[50],mov=0,cp;
    printf("enter the current position\n");
    scanf("%d",&cp);
    printf("enter the number of requests\n");
    scanf("%d",&n);
    printf("enter the request order\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    mov=mov+abs(cp-req[0]); // abs is used to calculate the absolute value
    printf("%d -> %d",cp,req[0]);
    for(i=1;i<n;i++)
    {
        mov=mov+abs(req[i]-req[i-1]);
        printf(" -> %d",req[i]);
    }
    printf("\n");
    printf("total head movement = %d\n",mov);
}



//multilevel queue schedualing

main()
{
int p[20],bt[20], su[20], wt[20],tat[20],i, k, n, temp;
float wtavg, tatavg;
clrscr();
printf("Enter the number of processes --- ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
p[i] = i;
printf("Enter the Burst Time of Process %d --- ", i);
scanf("%d",&bt[i]);
printf("System/User Process (0/1) ? --- ");
scanf("%d", &su[i]);
}
for(i=0;i<n;i++)
for(k=i+1;k<n;k++)
if(su[i] > su[k])
{
temp=p[i];
p[i]=p[k];
p[k]=temp;
temp=bt[i];
bt[i]=bt[k];
bt[k]=temp;
temp=su[i];
su[i]=su[k];
su[k]=temp;
}
wtavg = wt[0] = 0;
tatavg = tat[0] = bt[0];
for(i=1;i<n;i++)
{
wt[i] = wt[i-1] + bt[i-1];
tat[i] = tat[i-1] + bt[i];
wtavg = wtavg + wt[i];
tatavg = tatavg + tat[i];
}
printf("\nPROCESS\t\t SYSTEM/USER PROCESS \tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
for(i=0;i<n;i++)
printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d ",p[i],su[i],bt[i],wt[i],tat[i]);
printf("\nAverage Waiting Time is --- %f",wtavg/n);
printf("\nAverage Turnaround Time is --- %f",tatavg/n);
getch();
}




//round robin

#include<stdio.h> 
 
int main() 
{ 
 
  int count,j,n,time,remain,flag=0,time_quantum; 
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10]; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  remain=n; 
  for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
    scanf("%d",&at[count]); 
    scanf("%d",&bt[count]); 
    rt[count]=bt[count]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      wait_time+=time-at[count]-bt[count]; 
      turnaround_time+=time-at[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
  
  return 0; 
}




 
void insert_by_priority(int);
void delete_by_priority(int);
void create();
void check(int);
void display_pqueue();
 
int pri_que[MAX];
int front, rear;
 
void main()
{
    int n, ch;
 
    printf("\n1 - Insert an element into queue");
    printf("\n2 - Delete an element from queue");
    printf("\n3 - Display queue elements");
    printf("\n4 - Exit");
 
    create();
 
    while (1)
    {
        printf("\nEnter your choice : ");    
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1: 
            printf("\nEnter value to be inserted : ");
            scanf("%d",&n);
            insert_by_priority(n);
            break;
        case 2:
            printf("\nEnter value to delete : ");
            scanf("%d",&n);
            delete_by_priority(n);
            break;
        case 3: 
            display_pqueue();
            break;
        case 4: 
            exit(0);
        default: 
            printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
}
 
/* Function to create an empty priority queue */
void create()
{
    front = rear = -1;
}
 
/* Function to insert value into priority queue */
void insert_by_priority(int data)
{
    if (rear >= MAX - 1)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        pri_que[rear] = data;
        return;
    }    
    else
        check(data);
    rear++;
}
 
/* Function to check priority and place element */
void check(int data)
{
    int i,j;
 
    for (i = 0; i <= rear; i++)
    {
        if (data >= pri_que[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                pri_que[j] = pri_que[j - 1];
            }
            pri_que[i] = data;
            return;
        }
    }
    pri_que[i] = data;
}
 
/* Function to delete an element from queue */
void delete_by_priority(int data)
{
    int i;
 
    if ((front==-1) && (rear==-1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }
 
    for (i = 0; i <= rear; i++)
    {
        if (data == pri_que[i])
        {
            for (; i < rear; i++)
            {
                pri_que[i] = pri_que[i + 1];
            }
 
        pri_que[i] = -99;
        rear--;
 
        if (rear == -1) 
            front = -1;
        return;
        }
    }
    printf("\n%d not found in queue to delete", data);
}
 
/* Function to display queue elements */
void display_pqueue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }
 
    for (; front <= rear; front++)
    {
        printf(" %d ", pri_que[front]);
    }
 
    front = 0;
}



int main()
{
	int n;
	printf("enter the number of process\n");
	scanf("%d",&n);
	int q[n],q1[n],q2[n],b[n],b1[n],b2[n],k,a=0,a1=0,a2=0,p[n],p1[n],p2[n],at[n],rt[n];
	printf("\nEnter priority between:\n0 to 10 for high priority\n11 to 20 for medium priority\n21 to 30 for lowest priority for every process\n");
	for(int i=0;i<n;i++)
	{
		printf("\nEnter priority of process %d:",(i+1));
		scanf("%d",&k);
		if(k>0&&k<=10){
		p[a]=k;
		printf("\nEnter burst time of process %d:",(i+1));
		scanf("%d",&b[a]);rt[a]=b[a];
		printf("\nEnter arival time of process %d:",(i+1));
		scanf("%d",&at[a]);
		q[a++]=(i+1);}
		else if(k>10&&k<=20){
		p1[a1]=k;
		printf("\nEnter burst time of process %d:",(i+1));
		scanf("%d",&b[a1]);
		q1[a1++]=(i+1);}
		else if(k>20&&k<=30){
		p2[a2]=k;
		printf("\nEnter burst time of process %d:",(i+1));
		scanf("%d",&b[a2]);
		q2[a2++]=(i+1);}
	}
	printf("\nHighest priority queue:");
	printf("\nProcess ID\tArrival Time\tPriority\tBurst Time\n");
	for(int i=0;i<a;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\n",q[i],at[i],p[i],b[i]);
	}
	//-------------------------ROUND-ROBIN-------------------------------------------------------
	  int count,time,remain=a,flag=0,time_quantum=4; 
   int wait_time=0,turnaround_time=0;
	printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-b[count]); 
      wait_time+=time-at[count]-b[count]; 
      turnaround_time+=time-at[count]; 
      flag=0; 
    } 
    if(count==a-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/a); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/a); 
  //---------------------PRIORITY-----------------------------------------------------
	printf("\nmedium priority queue:");
	printf("\nProcess ID\tPriority\tBurst Time\n");
	for(int i=0;i<a1;i++)
	{
		printf("%d\t\t%d\t\t%d\n",q1[i],p1[i],b1[i]);
	}
	

