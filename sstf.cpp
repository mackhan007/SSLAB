#include <stdio.h>
#include <cstdlib>
struct di
{
    int num;
    int flag;
};

int main()
{
    int i,j,sum=0,n,min,loc,x,y;
    struct di d[20];
    int disk;
    int ar[20],a[20];
    printf("Enter number of locations:\t");
    scanf("%d",&n);
    printf("Enter position of head:\t");
    scanf("%d",&disk);
    printf("Enter elements of disk queue:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&d[i].num);
        d[i].flag=0;
    }
    for(i=0;i<n;i++)
    {
        x=0,min=0;loc=0;
        for(j=0;j<n;j++)
        {
            if(d[j].flag==0)
            {
                if(x==0)
                {
                    ar[j]=abs(disk-d[j].num);
                    min=ar[j]; loc=j;x++;
                }
                else
                {
                    ar[j]=abs(disk-d[j].num);
                }
                if(min>ar[j])
                {
                    min=ar[j];loc=j;
                }
            }
        }
        d[loc].flag=1;
        a[i]=abs(d[loc].num-disk);
        sum += a[i];
        disk=d[loc].num;
    }
    printf("\nTotal head movements:%d",sum);
}