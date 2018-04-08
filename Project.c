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
