#include <stdio.h>
#include <cstdlib>
int main()
{
    int i, j, n, disk, sum = 0;
    int disk_queue[20], st[20];
    printf("Enter number of locations : ");
    scanf("%d", &n);
    printf("Enter position of head : ");
    scanf("%d", &disk); 
    printf("Enter elements of disk queue : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&disk_queue[i]);
        st[i] = abs(disk - disk_queue[i]);
        disk = disk_queue[i];
        sum = sum + st[i];
    }
    printf("\nTotal Seek Time = %d \n", sum);
    return 0;
}