#include <stdio.h>

void Display(int arr[], int n){
	for(int i = 0; i<n; i++)
		printf(" %d ",arr[i]);
	printf("\n");
}

void InsertionSort(int arr[], int n){
	int i = 1 ,j ,temp;
	for(i=1; i<n; i++){
		temp = arr[i];
		j = i-1;
		while(j >= 0 && temp <= arr[j]){
			arr[j + 1]= arr[j];
			j--;
		}
		arr[j +1] = temp;
		Display(arr,n);
	}
	printf("final display : ");
	Display(arr,n);
}

void SelectionSort(int arr[], int n){
	int i, min, j, temp;
	for(i=0; i < n; i++){
		min = i;
	for(j = i+1 ; j < n; j++){
		if(arr[j] < arr[min])
			min = j;
	}
	Display(arr,n);
	temp = arr[i];
	arr[i] = arr[min];
	arr[min] = temp;
	}
	printf("fianl display : ");
	Display(arr,n);
}

int main(){
	int n,ch;
	
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	int arr[50];
	for(int i=0; i<n; i++){
		printf("Enter element %d :",i+1);
		scanf("%d",&arr[i]);
	}

	while(1){
		printf("Menu\n1.InsertionSort\n2.SelectionSort\n3.DisplayArray\n4.Exit\nEnter Your Choice : ");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				InsertionSort(arr, n);
				break;
			case 2:
				SelectionSort(arr, n);
				break;
			case 3:
				Display(arr,n);
				break;
			case 4:
				printf("Exiting !");
				return 0;
			default :
				printf("Enter a Valid Choice ! \n");
				break;

		}

	}
}
