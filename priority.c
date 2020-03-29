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
