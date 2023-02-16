#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue(int);
int dequeue();
void traverse();

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    traverse();     

    dequeue();    
    traverse();     
    enqueue(60);    
    traverse();     

    dequeue();      
    traverse();     

    return 0;
}

void enqueue(int data)
{
    if ((front == 0 && rear == MAX - 1) || (rear + 1 == front))
    {
        printf("\nQueue is full. Overflow!");
        exit(1);
    }

    if (rear == MAX - 1)
        rear = 0;
    else
        ++rear;

    queue[rear] = data;

    if (front == -1)
        front = 0;
}

int dequeue()
{
    if (front == -1)
    {
        printf("\nQueue is empty. Underflow!");
        exit(1);
    }

    int data = queue[front];
    queue[front] = 0;

    if (front == rear)
        front = -1, rear = -1;
    else if (front == MAX - 1)
        front = 0;
    else
        ++front;

    return data;
}

void traverse()
{
    if (front == -1)
    {
        printf("\nQueue is empty. Underflow!");
        exit(1);
    }

    printf("\nQueue: ");

  
    if (front <= rear)
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);

   
    else
    {
        for (int i = front; i < MAX; i++)
            printf("%d ", queue[i]);

        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}