#include<stdio.h>
void first()
{
    int process,blocks,proc[40],flag_bl[30]={0},flag_pr[30]={0},i,j,block[40];
    printf("\nFIRST FIT ALLOCATION\n");
    for(i=0;i<process;i++)
    {
        for(j=0;j<blocks;j++)
        {
            if(block[j]>=proc[i]&&flag_bl[j]==0)
            {
                printf("\nProcess P%d has been allocated to block B%d of size->%d",i+1,j+1,block[j]);
                flag_bl[j]=1;
                flag_pr[i]=1;
            }
            if(flag_pr[i]==0)
            {
                printf("\nProcess P%d cannot be allocated...",i+1);
            }
        }
    }
}
void best()
{
    int process,blocks,proc[40],bl[40],flag_bl[20]={0},flag_pr[20]={0},i,j,k,pr[40],block[40],temp;
    printf("\nBEST FIT ALLOCATION\n");
    for(i=1;i<blocks;i++)
    {
        for(j=0;j<blocks-i;j++)
        {
            if(block[j]>block[j+1])
            {
                temp=block[j];
                block[j]=block[j+1];
                block[j+1]=temp;
            }
        }
    }
    for(i=0;i<process;i++)
    {
        for(j=0;j<blocks;j++)
        {
            if(block[j]>=proc[i]&&flag_bl[j]==0)
            {
                for(k=0;k<blocks;k++)
                {
                    if(bl[k]==block[j])
                    {
                        break;
                    }
                }
                printf("\nProcess P%d has been allocated to block B%d of size->%d",i+1,j+1,block[j]);
                flag_bl[j]=1;
                flag_pr[i]=1;
            }
            if(flag_pr[i]==0)
            {
                printf("Process P%d cannot be allocated...",i+1);
            }
        }
    }
}
void worst()
{
    int process,blocks,proc[40],bl[40],flag_bl[30]={0},flag_pr[40]={0},i,j,k,pr[40],block[40],temp;
    printf("\nWORST FIT ALLOCATION\n");
    for(i=1;i<blocks;i++)
    {
        for(j=0;j<blocks-i;j++)
        {
            if(block[j]<block[j+1])
            {
                temp=block[j];
                block[j]=block[j+1];
                block[j+1]=temp;
            }
        }
    }
    for(i=0;i<process;i++)
    {
        for(j=0;j<blocks;j++)
        {
            if(block[j]>=proc[i]&&flag_bl[j]==0)
            {
                for(k=0;k<blocks;k++)
                {
                    if(bl[k]==block[j])
                    {
                        break;
                    }
                }
                printf("\nProcess P%d has been allocated to block B%d of size->%d",i+1,j+1,block[j]);
                flag_bl[j]=1;
                flag_pr[i]=1;
            }
            if(flag_pr[i]==0)
            {
                printf("Process P%d cannot be allocated...",i+1);
            }
        }
    }
}
void main()
{
    int process,blocks,proc[40],bl[40],i,pr[40],block[40];
    printf("Enter the number of blocks available: ");
    scanf("%d",&blocks);
    printf("Enter each block size:\n");
    for(i=0;i<blocks;i++)
    {
        printf("Block B%d-> ",i+1);
        scanf("%d",&bl[i]);
        block[i]=bl[i];
    }
    printf("Enter the number of requesting processes: ");
    scanf("%d",&process);
    printf("Enter each process size:\n");
    for(i=0;i<process;i++)
    {
        printf("Process P%d-> ",i+1);
        scanf("%d",&pr[i]);
        proc[i]=pr[i];
    }
    first();
    best();
    worst();   
}