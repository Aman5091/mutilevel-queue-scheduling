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

