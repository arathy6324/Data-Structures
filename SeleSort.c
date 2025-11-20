#include<stdio.h>

void main() 
{ 
    int a[20], n, min, i, j, temp;  

    printf("\nEnter the size of the array:"); 
    scanf("%d", &n);     
    printf("\nEnter the array elements:");

    for(i = 0; i < n; i++) 
    { 
        scanf("%d", &a[i]); 
    } 

    for(i = 0; i < n - 1; i++) 
    { 
        min = i;

        for(j = i + 1; j < n; j++) 
        { 
            if(a[j] < a[min]) 
            {     
                min = j; 
            }     
        } 

        if(min != i) 
        { 
            temp = a[min]; 
            a[min] = a[i];    
            a[i] = temp; 
        } 
    } 

    printf("\nSorted array:");   

    for(i = 0; i < n; i++) 
    { 
        printf("\t%d", a[i]); 
    } 
}