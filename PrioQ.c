#include <stdio.h>

int size, rear, front;

struct pq
{
    int item, priority;
} A[20];

void enqueue(int ITEM, int PRIORITY)
{
    int i, loc;
    if (front == 0 && rear == size - 1)
        printf("Queue is full");
    else if (front == -1)
    {
        front = 0;
        rear = 0;
        A[rear].item = ITEM;
        A[rear].priority = PRIORITY;
    }
    else
    {
        if (rear == size - 1)
        {
            for (i = front; i <= rear; i++)
            {
                A[i - front] = A[i];
            }
            front = 0;
            rear = rear - front;
        }
        for (i = rear; i >= front; i--)
        {
            if (A[i].priority < PRIORITY)
            {
                break;
            }
            A[i + 1] = A[i];
        }
        loc = i + 1;
        A[loc].item = ITEM;
        A[loc].priority = PRIORITY;
        rear++;
    }
}

void dequeue()
{
    if (front == -1)
        printf("Queue is empty");
    else if (front == rear)
    {
        printf("Deleted item is %d", A[front].item);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("The deleted item is %d", A[front].item);
        front++;
    }
}

void display()
{
    int i;
    if (front == -1)
        printf("Queue is empty");
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d\t", A[i].item);
    }
}

int main()
{
    int item, opt, prio;
    front = -1;
    rear = -1;
    printf("Enter the size of the Queue: ");
    scanf("%d", &size);
    do
    {
        printf("\nEnter the option:\n");
        printf("1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            printf("Enter the priority: ");
            scanf("%d", &prio);
            enqueue(item, prio);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Invalid option!");
        }
    } while (opt != 4);

    return 0;
}