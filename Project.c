#include<stdio.h>

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


