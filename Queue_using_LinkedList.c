// Queue using liked list
#include <stdio.h>
#include <stdlib.h>

// structure for node , two variable data and next 
struct node
{
    int data;
    struct node *next;
};

// structure for queue 
struct queue
{
    struct node *front;
    struct node *rear;
};
struct queue *q;
void enqueue();
void dequeue();
void creat_queue(struct queue *);
void showqueue();
int isEmpty();
int main()
{
    int ch;

    // memory allocation for q pointer 
    q = (struct queue *)malloc(sizeof(struct queue));
    creat_queue(q);
    do
    {
        printf("\n ======  MEAN MANU ==== \n 1. insert in the queue \n 2. delete in the queue \n 3. Element show \n 4. exit \n Enter your chooise :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            showqueue();
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("\n Invailed Input ");
            break;
        }
    } while (1);
}

//  creat null for front and rear pointer 
void creat_queue(struct queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

// check queue is empty or not 
int isEmpty()
{
    if (q->front == NULL)
    {
        return 1;
    }
    return 0;
}


// input the element in the queue 
void enqueue()
{
    // creat a space
    struct node *ptr;
    int value = 0;

    // creat memory for ptr pointer 
    ptr = (struct node *)malloc(sizeof(struct node));
    // check the space crate or not
    if (ptr == NULL)
    {
        printf("Queue is Full ");
        return;
    }
    printf("\n Enter the element :");
    scanf("%d", &value);
    ptr->data = value;
    ptr->next = NULL;
    // when our queue is uninitialize
    if (q->rear == NULL)
    {
        q->front = q->rear = ptr;
    }
    else // when our queue is initialize
    {
        q->rear->next = ptr;
        q->rear = ptr;
    }
}

// Delete the element from the queue 
void dequeue()
{
    if (isEmpty())
    {
        printf("\n Queue is Empty ");
        return;
    }
    struct node *ptr = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    
    printf("\n Deleted item :%d", ptr->data);
    free(ptr);
}

// display all element of queue 
void showqueue()
{
    if (isEmpty())
    {
        printf("\n Queue is Empty ");
        return;
    }
    struct node *ptr  = q->front;
    printf(" \n Element :");
    while (ptr != NULL)
    {

        printf(" %d", ptr->data);
        ptr = ptr->next;
    }
}