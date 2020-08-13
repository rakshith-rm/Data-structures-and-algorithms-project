/*most visited place using sorting*/

#include<stdio.h>
#define INFINITY 9999
#define MAX 5

void dijkstra(int G[MAX][MAX],int startnode,int destnode);

int main()
{
	int i,j,n,u,d;
	int ch;
    int u1,d1,c=0;

	//char[20]=password;
    int G[5][5]={ {0,50,60,0, 0},
                  {50, 0,40,45,0},
                  {60,40,0,40,50},
                  {0,45,40, 0, 0},
                  {0,0,50, 60, 0} };
       /* printf("enter password to proceed\n");
        scanf("%s",password);
        for(i=o;i<5;i++){
        if()
        }
        */
        //string matching
        while(1){
    printf("The Hubli-Dharwad city:\n");
    printf("0:Railway Station\t 1:Gokul Road\t 2:Hosur\t 3:Dharwad\t 4:BVB");

	printf("\nEnter the source:");
	scanf("%d",&u);
	printf("\nenter the destination:");
	scanf("%d",&d);
	printf("\nMode of travelling: 1. Private  2.sharing:\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:dijkstra(G,u,d);
               break;

	case 2:printf("enter the details of customer 2\n");
           printf("\nEnter the source:");
	       scanf("%d",&u1);
           printf("\nenter the destination:");
	       scanf("%d",&d1);

	    c=dijkstra1(G,u,d,u1,d1);
        if(c==0){
            printf("\nOops! Sharing service not available. Try again later.\n");
            break; }
        else{
            printf("The details of customer 1:\n");
            dijkstra2(G,u,d);
            printf("The details of customer 2:\n");
            dijkstra2(G,u1,d1);
        }
    }
    printf("\nThank You! Come again\n\n");
        }

	return 0;
}

int dijkstra1(int G[MAX][MAX],int startnode,int destnode,int u1,int d1)
{
    int fare,c=0;
	int w[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j;


	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)
			if(G[i][j]==0)
				w[i][j]=INFINITY;
			else
				w[i][j]=G[i][j];


	for(i=0;i<MAX;i++)
	{
		distance[i]=w[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}

	distance[startnode]=0;
	visited[startnode]=1;
	count=1;

	while(count<MAX-1)
	{
		mindistance=INFINITY;


		for(i=0;i<MAX;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}


			visited[nextnode]=1;
			for(i=0;i<MAX;i++)
				if(!visited[i])
					if(mindistance+w[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+w[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}


	i=destnode;
		if(i!=startnode )
		{
			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
                if(j==u1 || j==d1)
                c++;
			}while(j!=startnode);

	}return c;
}

void dijkstra(int G[MAX][MAX],int startnode,int destnode)
{
    int fare;
	int w[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j;


	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)
			if(G[i][j]==0)
				w[i][j]=INFINITY;
			else
				w[i][j]=G[i][j];


	for(i=0;i<MAX;i++)
	{
		distance[i]=w[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}

	distance[startnode]=0;
	visited[startnode]=1;
	count=1;

	while(count<MAX-1)
	{
		mindistance=INFINITY;


		for(i=0;i<MAX;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}


			visited[nextnode]=1;
			for(i=0;i<MAX;i++)
				if(!visited[i])
					if(mindistance+w[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+w[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}


	i=destnode;
		if(i!=startnode )
		{
			printf("\nDistance of node%d=%d",i,distance[i]);

			printf("\nPath=%d",i);


			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=startnode);

        if(distance[i]<=50)
        printf("\ntotal fare is %d",distance[i]*15);

       else if(distance[i]>50 && distance[i]<=70)
            printf("\ntotal fare is %d",distance[i]*13);

        else
            printf("\ntotal fare is %d",distance[i]*11);
	}
}
void dijkstra2(int G[MAX][MAX],int startnode,int destnode)
{
    int fare;
	int w[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j;


	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)
			if(G[i][j]==0)
				w[i][j]=INFINITY;
			else
				w[i][j]=G[i][j];


	for(i=0;i<MAX;i++)
	{
		distance[i]=w[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}

	distance[startnode]=0;
	visited[startnode]=1;
	count=1;

	while(count<MAX-1)
	{
		mindistance=INFINITY;


		for(i=0;i<MAX;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}


			visited[nextnode]=1;
			for(i=0;i<MAX;i++)
				if(!visited[i])
					if(mindistance+w[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+w[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}


	i=destnode;
		if(i!=startnode )
		{
			printf("\nDistance of node%d=%d",i,distance[i]);

			printf("\nPath=%d",i);


			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=startnode);

        if(distance[i]<=50)
        printf("\ntotal fare is %d",distance[i]*11);

       else if(distance[i]>50 && distance[i]<=70)
            printf("\ntotal fare is %d",distance[i]*9);

        else
            printf("\ntotal fare is %d",distance[i]*7);
	}
}
