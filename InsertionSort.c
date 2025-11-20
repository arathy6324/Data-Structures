#include<stdio.h>

void main() 
{ 
    int a[20], n, i, j, temp; 

    printf("\nEnter the size of the array:");  
    scanf("%d", &n);   
    printf("\nEnter the array elements:"); 

    for(i = 0; i < n; i++) 
    { 
        scanf("%d", &a[i]); 
    } 

    for(i = 1; i < n; i++) 
    { 
        temp = a[i]; 
        j = i - 1; 

        while(j >= 0 && a[j] > temp) 
        {  
            a[j + 1] = a[j]; 
            j--; 
        } 

        a[j + 1] = temp; 
    } 

    printf("\nSorted array:"); 

    for(i = 0; i < n; i++) 
    { 
        printf("\t%d", a[i]); 
    } 
}