#include<stdio.h>

struct process
{
      char process_name; //declaration for the name of process
      int arrival_time, burst_time, ct, waiting_time, turnaround_time, priority;
      int status; //declaration of status of process
}process_queue[10]; //declare the queue for processes

int limit; //declaration for the total number of process
// creating a function which is called by another
void Arrival_Time_Sorting() 
{
      struct process temp;
      int i, j;
      for(i = 0; i < limit - 1; i++) // for loop for i
      {
            for(j = i + 1; j < limit; j++) //for loop for j
            {
                  if(process_queue[i].arrival_time > process_queue[j].arrival_time)
                  {
                        temp = process_queue[i];
                        process_queue[i] = process_queue[j];
                        process_queue[j] = temp;
                  }
            }
      }
}

void main()
{
      int i, time = 0, burst_time = 0, largest; //decalre and initialize the variables
      char c; //declared a variable for give the name to the process 
      float wait_time = 0, turnaround_time = 0, average_waiting_time, average_turnaround_time;
      printf("\nEnter Total Number of Processes:\t"); //print total number of processes
      scanf("%d", &limit); //taking input from user for total number of processes
      for(i = 0, c = 'A'; i < limit; i++, c++)//for loop
      {
            process_queue[i].process_name = c;  
            printf("\nEnter Details For Process[%C]:\n", process_queue[i].process_name); //print the details of processes
            printf("Enter Arrival Time:\t"); //print arrival time of one process
            scanf("%d", &process_queue[i].arrival_time ); //taking input of arrival time from user
            printf("Enter Burst Time:\t"); //print burst time
            scanf("%d", &process_queue[i].burst_time); //taking input of burst time from user
            printf("Enter Priority:\t"); // print priority
            scanf("%d", &process_queue[i].priority); //taking priority of process from user
            process_queue[i].status = 0; // initialize status of process=0
            burst_time = burst_time + process_queue[i].burst_time; //initialize the burst time to variable
      }
      Arrival_Time_Sorting();
      process_queue[9].priority = -9999;
      printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time");//printing attributes for table
      for(time = process_queue[0].arrival_time; time < burst_time;)
      {
            largest = 9;
            for(i = 0; i < limit; i++)
            {
                  if(process_queue[i].arrival_time <= time && process_queue[i].status != 1 && process_queue[i].priority > process_queue[largest].priority)
                  {
                        largest = i;
                  }
            }
            time = time + process_queue[largest].burst_time; //initialize time
            process_queue[largest].ct = time;
            process_queue[largest].waiting_time = process_queue[largest].ct - process_queue[largest].arrival_time - process_queue[largest].burst_time; //calculate waiting time for each process
            process_queue[largest].turnaround_time = process_queue[largest].ct - process_queue[largest].arrival_time;
            process_queue[largest].status = 1; // initialize status=1
            wait_time = wait_time + process_queue[largest].waiting_time; // calculate waiting time
            turnaround_time = turnaround_time + process_queue[largest].turnaround_time; //calculate turnaround time
            printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d", process_queue[largest].process_name, process_queue[largest].arrival_time, process_queue[largest].burst_time, process_queue[largest].priority, process_queue[largest].waiting_time);
      }
      average_waiting_time = wait_time / limit; // calculate average waiting time
      average_turnaround_time = turnaround_time / limit; // calculate average turnaround time
      printf("\n\nAverage waiting time:\t%f\n", average_waiting_time); //print average waiting time
      printf("Average Turnaround Time:\t%f\n", average_turnaround_time); // print average turnaround time
}