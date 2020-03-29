#include<stdio.h>
#include<stdlib.h>
int main()
{     
      printf("***************************************************************************");
      printf("\n");
	  printf("OPERATING--------------------------SYSTEM------------------------ASSIGNMENT");
	  printf("\n");
	  int i=0;
	  int j;
	  int a;
	  int priority[20];
	  for(i=0;i<3;i++)
	  {
	  	printf("enter priority for all the three queue between(1-12):");//taking user input for priority of queue yo decide
	  	scanf("%d",&priority[i]);//which algorithm should be used for respective queue
	  }
	  for(i=0;i<3;i++)//higher the number higher the priority
	  {
	  	if(priority[i]>=1&&priority[i]<=4)
	  	{
	  		printf("we should apply here fcfs algorithm as priority range is low for queue%d:- ",i+1);
	  		printf("\n");//if priority is lowest then applying fcfs algorithm on that
	  		void firstcomeserve();
	  		firstcomeserve();
		}
		else if(priority[i]>=5 && priority[i]<=8)
		{
			
			printf("we should apply here priority scheduling algorithm as priority range is medium for queue%d:- ",i+1);
			printf("\n");//if priority is middle level then applying priority scheduling algorithm on that
			void priorityscheduling();
			priorityscheduling();
		}
		else
		{
			printf("we should apply here round pobin algorithm as priority range is high here for queue%d:- ",i+1);
			printf("\n");//if priority is highest then applying roundrobin algorithm on that
			void roundrobin();
			roundrobin();
		}
	  }
}
void roundrobin()
{
int arrival_time[20],burst_time[20],no_of_process;
int arrival_timeq1[20],burst_timeq1[20],waiting_timeq1[20],turnaround_timeq1[20];
float avgwaiting_timeq1,avgturnaround_timeq1;
int Total=0,t1=0,t2=0,t3=0;
int total,x,temp[30],count=0;
int pos,temp1,sum=0;
int l=0;
int i,p,q,k=0,j=0;

 printf("Enter the no. of process you want to enter\n");//taking time quantum 4s
	scanf("%d",&no_of_process);
	for(i=0;i<no_of_process;i++)
	    {
	    printf("Enter details of process[%d]\n",i+1);
	    printf("**********************************");
	    printf("\n");
		printf("Arrival Time:");
	    scanf("%d",&arrival_time[i]);
		printf("Burst Time:");
		scanf("%d",&burst_time[i]);
		Total=Total+burst_time[i];
		}
		for(i=0;i<no_of_process;i++)
	    { 
			arrival_timeq1[j]=arrival_time[i];
			burst_timeq1[j]=burst_time[i];
			j++;
			t1=t1+burst_time[i];
		}
		
 printf("Time Quantum for Queue1 is 4\n");
 for(i=0;i<j;i++)
    {
	temp[i]=burst_timeq1[i];
	} 
    printf("\nProcess ID\tBurst Time\t Turnaround Time\t Waiting Time\n");
    printf("************************************************************");
	x=j;
	for(i=0,total=0;x!=0;) 
	{ 
    if(temp[i]<=4&&temp[i]>0) 
	{
	
	total=total+temp[i]; 
            temp[i]=0; 
			count=1; 
			} 
	else if(temp[i]>0) 
	{
	
	temp[i]=temp[i]-4;
	total=total+4; 
	} 
	if(temp[i]==0&&count==1) 
	{ x--; 
	printf("\nProcess[%d]\t%d\t%d\t%d",i+1,burst_timeq1[i],total-arrival_timeq1[i],total-arrival_timeq1[i]-burst_timeq1[i]);
	avgwaiting_timeq1=avgwaiting_timeq1+total-arrival_timeq1[i]-burst_timeq1[i]; 
	avgturnaround_timeq1=avgturnaround_timeq1+total-arrival_timeq1[i]; 
	count = 0; 
	} 
	if(i==j-1) 
	{
	i=0; 
	}
    else if(arrival_timeq1[i+1]<=total) 
	{
	i++;
	}
	else 
	{
	i=0;
	}
	} 
	avgwaiting_timeq1=avgwaiting_timeq1/j;
	avgturnaround_timeq1=avgturnaround_timeq1/j;
	printf("\nAverage Waiting Time:%f",avgwaiting_timeq1); 
	printf("\nAverage Turnaround Time:%f\n",avgturnaround_timeq1); 
	
	printf("Time Quantum between the three queues is 10\n");//since time quantum between the queues is 10s hence after 10s
	for(i=1;i<Total;i=i+10)//context switching occurs between the queues
	{
	    if(t1>10)
		{
		    printf("Q1 is running for 10 units\n");
			t1=t1-10;
		}
		else if(t1<=10&&t1!=0)
		{
		    printf("Q1 is running for %d units\n",t1);
			t1=0;
		}
	}
}

void priorityscheduling()  // priority we are taking lower the number higher the priority...
{
	          
        printf("\nPriority Scheduling algorithm for middle level priority:-\n");
		int i,j,n,pos,temp,avgwaiting_time,avgturnaround_time;
		
		int total=0,burst_time[20],p[20],waiting_time[20],turnaround_time[20],prioritys[20];
		printf("Enter Total Number of Process:");
		scanf("%d",&n);
		printf("\nEnter Burst Time and Priority\n");
		for(i=0;i<n;i++)
		{  
		    printf("\nP[%d]\n",i+1);
			printf("Burst Time:");
			scanf("%d",&burst_time[i]);
			printf("Priority:");
			scanf("%d",&prioritys[i]);
			p[i]=i+1;
			       
		}
	   for(i=0;i<n;i++)
	   { pos=i;
	    
	     for(j=i+1;j<n;j++)
		    {
			    if(prioritys[j]<prioritys[pos])
				pos=j;
			}
			temp=prioritys[i];
			prioritys[i]=prioritys[pos];
			prioritys[pos]=temp;
			temp=burst_time[i];
			burst_time[i]=burst_time[pos];
			burst_time[pos]=temp;
			temp=p[i];
			p[i]=p[pos];
			p[pos]=temp;
		}
		waiting_time[0]=0;	
		for(i=1;i<n;i++)
		{
		    waiting_time[i]=0;
		    for(j=0;j<i;j++)
		    
			    waiting_time[i]+=burst_time[j];
				
			
			total+=waiting_time[i];
	   }
		avgwaiting_time=total/n;     
		total=0;
		printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
		for(i=0;i<n;i++)
		{
	        turnaround_time[i]=burst_time[i]+waiting_time[i];    
			total+=turnaround_time[i];
			printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],burst_time[i],waiting_time[i],turnaround_time[i]);
		}
		avgturnaround_time=total/n;     
		printf("\n\nAverage Waiting Time=%d",avgwaiting_time);
		printf("\nAverage Turnaround Time=%d\n",avgturnaround_time);
	}
    
void firstcomeserve()
	{
	    printf("\nFirst come First Serve\n");
		int n,burst_time[20],waiting_time[20],turnaround_time[20],avgwaiting_time=0,avgturnaround_time=0,i,j;
		printf("Enter total number of processes(maximum 20):");
		scanf("%d",&n);
		printf("\nEnter Process Burst Time\n");
		for(i=0;i<n;i++)
		{   
		    printf("P[%d]:",i+1);
			scanf("%d",&burst_time[i]);
		}
		waiting_time[0]=0;    
		for(i=1;i<n;i++)
		{
		    waiting_time[i]=0;
			for(j=0;j<i;j++)
			  waiting_time[i]+=burst_time[j];
		}
		printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
		for(i=0;i<n;i++)
		{
		    turnaround_time[i]=burst_time[i]+waiting_time[i];
			avgwaiting_time+=waiting_time[i];
			avgturnaround_time+=turnaround_time[i];
			printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,burst_time[i],waiting_time[i],turnaround_time[i]);
		}
		avgwaiting_time/=i;
		printf("\n\nAverage Waiting Time:%d",avgwaiting_time);
		avgturnaround_time/=i;
		printf("\nAverage Turnaround Time:%d",avgturnaround_time);
		}
    
    