#include<stdio.h>

int check(int arr[],int n,int key) {
    for(int i=0;i<n;i++) {
        if(arr[i] == key)
            return 1;
    }
    return 0;
}

void print(int arr[],int n) {
    for(int i=0;i<n;i++) {
        if(arr[i] !=0)
            printf("%d ",arr[i]);
    }
}

void fifo(int arr[],int m,int pframe[],int n) {
    int fin = 0,pfault = 0;
    for(int i=0;i<m;i++) {
        if(check(pframe,n,arr[i])) {
            printf("%d NPF ",arr[i]);
            print(pframe,n);
            printf("\n");
            continue;
        }
        pframe[fin] = arr[i];
        pfault++;
        fin = (fin+1)%n;
        printf("%d PF  ",arr[i]);
        print(pframe,n);
        printf("\n");
    }
    printf("Page faults: %d\n",pfault);
}

int main() {
    int n;
    printf("Enter number of page frames: ");
    scanf("%d",&n);
    
    int pframe[n];
    for(int i=0;i<n;i++) {
        pframe[i] = 0;
    }
    
    int m;
    printf("Enter number of pages: ");
    scanf("%d",&m);
    int arr[m];
    printf("Enter pages: ");
    for(int i=0;i<m;i++) {
        scanf("%d",&arr[i]);
    }
    
    fifo(arr,m,pframe,n);
    return 0;
}
