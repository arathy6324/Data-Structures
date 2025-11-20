#include <stdio.h>
int A[20], size, front, rear;

void push(int item)
{
    int i;
    if (front == 0 && rear == size - 1 )
    {
        printf("Deque is FULL. Insertion not possible.");
    }
    else if (rear == -1)
    {
        front = 0;
        rear = 0;
        A[front] = item;
    }
    else if (front > 0)
    {
        front--;
        A[front] = item;
    }
    else
    {
        for (i = rear; i >= front; i--)
        {
            A[i + 1] = A[i];
        }
        A[front] = item;
        rear++;
    }
}

void inject(int item)
{
    int i;
    if (front == 0 && rear == size - 1)
    {
        printf("Deque is FULL. Insertion not possible.");
    }
    else if (rear == -1)
    {
        front = 0;
        rear = 0;
        A[front] = item;
    }
    else if (rear < size - 1)
    {
        rear++;
        A[rear] = item;
    }
    else
    {
        for (i = rear; i >= front; i--)
        {
            A[i + 1] = A[i];
        }
        A[front] = item;
        front--;
    }
}

void pop()
{
    if (front == -1)
    {
        printf("Deque is EMPTY");
    }
    else if (front == rear)
    {
        printf("Deleted item is %d", A[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("Deleted item is %d", A[front]);
        front++;
    }
}

void eject()
{
    if (front == -1)
    {
        printf("Deque is EMPTY");
    }
    else if (front == rear)
    {
        printf("Deleted item is %d", A[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("Deleted item is %d", A[rear]);
        rear--;
    }
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("Deque is EMPTY");
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d\t", A[i]);
        }
    }
}

int main()
{
    int item, opt;
    front = -1;
    rear = -1;

    printf("Enter the size of the Queue: ");
    scanf("%d", &size);

    do
    {
        printf("\nEnter the option:\n");
        printf("1.PUSH\n2.INJECT\n3.POP\n4.EJECT\n5.DISPLAY\n6.EXIT\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            inject(item);
            break;
        case 3:
            pop();
            break;
        case 4:
            eject();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exit");
            break;
        default:
            printf("Invalid option....");
        }
    } while (opt != 6);

    return 0;
}