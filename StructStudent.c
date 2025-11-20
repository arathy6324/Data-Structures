//STRUCTURE OF STUDENT
#include<stdio.h>
struct student
{
  char name[50];
  int sub1,sub2,sub3;
  int total;
  int rank;
}st[20];
int main()
{
  int n,i,j,k=1;
  struct student temp;
  printf("Enter the number of Students:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Enter the Name and Marks of 3 Subjects,of %dth student:",i+1);
    scanf("%s%d%d%d",st[i].name,&st[i].sub1,&st[i].sub2,&st[i].sub3);
    st[i].total=st[i].sub1+st[i].sub2+st[i].sub3;
  }
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-1-i;j++)
    {
      if(st[j].total<st[j+1].total)
      {
        temp=st[j];
        st[j]=st[j+1];
        st[j+1]=temp;
      }
    }
  }
  printf("\nName  Sub1  Sub2  Sub3  Total  Rank\n");
  for(i=0;i<n;i++)
  {
    st[i].rank=k;
    printf("\n%s  %d    %d   %d   %d    %d\n",st[i].name,st[i].sub1,st[i].sub2,st[i].sub3,st[i].total,st[i].rank);
    k++;
  }
  return 0;
}