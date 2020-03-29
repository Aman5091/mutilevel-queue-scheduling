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
