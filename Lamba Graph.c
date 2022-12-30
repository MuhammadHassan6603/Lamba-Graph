#include<stdio.h>
#include<stdlib.h>
#define MAX 5
#define VISITED 1
#define UNVISITED 0
struct graphNode
{
    int data;
    struct graphNode *next;
};
struct graphNode *arr[MAX];
int vertex_list[MAX] = {1,2,3,4,5};
int visited_list[MAX];
int q[MAX];
int front=-1;
int rear=-1;
void addq(int data)
{
	if(rear >= MAX-1)
	{
		printf("\nQueue is full. \n");
		return;
	}
	rear++;
	q[rear]=data;
	if(front==-1)
	{
		front++;	//front=0
	}
}
void delq()
{
	if(front == -1)
	{
		printf("\nQueue is Empty");
		return;
	}
	q[front]=0;
	if(front==rear)
	{
		front =rear= -1;
	}
	else
	{
		front++;
	}
}
struct graphNode *createList(int vertex)
{
    struct graphNode *r;
    int data;
    printf("vertex %d connected to:",vertex);
    scanf("%d",&data);
    if(data==-1)
    {
        return NULL;
    }
    r = (struct graphNode *)malloc(sizeof(struct graphNode));
    r-> data =data;
    r-> next = createList(vertex);
    return r;
}
int find_index(int cwv)
{
	int i;
	for(i=0;i<MAX;i++)
	{
		if(cwv==vertex_list[i])
		{
			return i;
		}
	}
}
void bfs(int cwv)	//cwv current working vertex
{
	//Rule #1
	
	int vli=0;		//vli visited list index
	visited_list[vli]=cwv;
	printf("\n%d",cwv);
	addq(cwv);
	struct graphNode *adjacent=arr[find_index(cwv)];
	
	//Rule #2
	
	int i;
	int flag;
	while(front!=-1)
	{
		while(adjacent != NULL)
		{
			flag = UNVISITED;
			for(i=0;i<MAX;i++)
			{
				if(adjacent->data == visited_list[i])
				{
					flag = VISITED;
					break;
				}
			}
			if(flag == UNVISITED)
			{
				vli++;
				visited_list[vli]=adjacent->data;
				printf("\t%d",adjacent->data);
				addq(adjacent->data);
				adjacent=adjacent->next;
			}
			else
			{
				adjacent=adjacent->next;	
			}
		}
		delq();
		cwv=q[front];
		adjacent=arr[find_index(cwv)];
	}
}
int main()
{
	int i;
	for(i=0; i<MAX; i++)
	{
		arr[i] = createList(vertex_list[i]);
	}
	for(i=0; i<MAX; i++)
	{
		printf("\nAdjacent of %d: \n" , vertex_list[i]);
		struct graphNode *temp = arr[i];
		
		while(temp != NULL)
		{
		printf("\t%d", temp->data);
		temp = temp->next;
		}
	}
	bfs(1);
 	return 0;
}

