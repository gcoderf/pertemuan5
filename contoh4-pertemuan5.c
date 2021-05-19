#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
	struct node *next;
	int data;
	struct node *prev;
};

struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display( struct node *);
struct node *insert_beg( struct node *);
struct node *insert_end( struct node *);
struct node *delete_beg( struct node *);
struct node *delete_end( struct node *);
struct node *delete_node( struct node *);
struct node *delete_list ( struct node *);
int main()
{
	int option;
	puts("Nama	: GEVANO RANDHI PILKO");
	puts("NIM	: 20343011");
	puts("Prodi	: Informatika (NK)\n");
	puts("--- Pertemuan Ke-5 Algostruk (Linked List) ---");
	puts("---        Proggramming Examples 4         ---");
	printf("\n\n");
	do
	{
	printf( "\n\n *****MAIN MENU*****");
	printf( "\n 1: Create a list");
	printf( "\n 2: Display the list");
	printf( "\n 3: Add a node at the beginning");
	printf( "\n 4: Add a node at the end");
	printf( "\n 5: Delete a node from the beginning" );
	printf( "\n 6: Delete a node from the end" );
	printf( "\n 7: Delete a given node");
	printf( "\n 8: Delete the entire list");
	printf( "\n 9: EXIT");
	printf( "\n\n Enter your option : ");
	scanf("%d", &option);
	switch(option)
	{
		case 1: start = create_ll(start);
		printf("\n CIRCULAR DOUBLY LINKED LIST CREATED");
		break;
		case 2: start = display(start);
		break;
		case 3: start = insert_beg(start);
		break;
		case 4: start = insert_end(start);
		break;
		case 5: start = delete_beg(start);
		break;
		case 6: start = delete_end(start);
		break;
		case 7: start = delete_node(start);
		break;
		case 8: start = delete_list(start);
		printf("\n CIRCULAR DOUBLY LINKED LIST DELETED");
		break;
	}
	}while(option != 9);
	getch(); 
	return 0;
}

struct node *create_ll(struct node *start)
{
	struct node *new_node, *ptr;
	int num;
	printf("\n Enter -1 to end ");
	printf("\n Enter the data : ");
	scanf("%d", &num);
	while(num != -1)
	{
		if(start == NULL) 
		{
			new_node = (struct node*)malloc(sizeof(struct node));
			new_node -> prev = NULL;
			new_node -> data = num;
			new_node -> next = NULL;
			start = new_node;
		}
		else
		{
			ptr=start;
			new_node = (struct node*)malloc(sizeof(struct node));
			new_node -> data = num;
			while(ptr-> next!= NULL)
			ptr = ptr-> next;
			ptr -> next = new_node;
			new_node-> prev = ptr;
			new_node-> next = NULL;
		}
			printf("\n Enter the data : ");
			scanf("%d", &num) ;
	}
	return start;
}

struct node *display(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while(ptr != NULL)
	{
		printf("\t %d " , ptr->data);
		ptr = ptr->next;
	}
	return start;
}

struct node *insert_beg( struct node *start )
{
	struct node *new_node;
	int num;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	new_node -> next = start;
	start = new_node;
	return start;
}

struct node *insert_end( struct node *start )
{
	struct node *ptr, *new_node;
	int num;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node-> data = num;
	ptr=start;
	while(ptr-> next != NULL)
		ptr = ptr-> next;
	ptr-> next = new_node;
	new_node-> prev = ptr;
	new_node-> next = NULL;
	return start;
	
}

struct node *delete_beg(struct node *start) {
	struct node *ptr;
	ptr = start;
	start = start -> next;
	free(ptr);
	return start;
}

struct node *delete_end(struct node *start) {
	struct node *ptr;
	ptr = start;
	while(ptr -> next != NULL)
	ptr = ptr -> next;
	ptr-> prev -> next = NULL;
	free(ptr);
	return start; 
}

struct node *delete_node(struct node *start)
{
	struct node *ptr;
	int val;
	printf("\n Enter the value of the node which has to be deleted : ");
	scanf("%d", &val);
	ptr = start;
	if(ptr -> data == val)
	{
	 	start = delete_beg(start);
		return start;
	}
	else
	{
		while(ptr -> data != val)
		ptr = ptr -> next;
		ptr -> prev -> next = ptr -> next;
		ptr -> next -> prev = ptr -> prev;
 		free(ptr);
		return start;
	}
}

struct node *delete_list(struct node *start)
{
	while(start != NULL)
		start = delete_beg(start);
	return start;
	
}
