#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(a,b)  {int t; t = a; a=b; b=t;}

void menu()
{
	printf("\n=================================================\n");
	printf("\n\t1. original sort\n");
	printf("\t2. optimized version\n");
	printf("\t3. comparison\n");
	printf("\t4. exit\n");
	printf("\n=================================================\n");

	printf("\n\t [-] please enter your number >> ");
}

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_arr(int *arr, int n){
    for (int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion(int *base, int n){
    	int i, j;
	
	//print_arr(base, 10);

    	for (i = 1; i<n; i++){
        	for (j = i; j>0; j--){
            		if (base[j - 1]>base[j])
                		swap(&base[j - 1], &base[j]);
            		else
                		break;
        	}	
    	}

	//print_arr(base,30);
}

void optimized_insert(int *base, int n){
	int i,j;

	//print_arr(base, 10);

	for(i = 1; i < n; i++){
		for( j = i; j > 0; j--){
			if(base[j - 1] > base[j])
				SWAP(base[j-1], base[j])
			else
				break;
		}
	}

	//print_arr(base,30);
}


int main(int argc, char* argv[])
{
    	int *arr1, *arr2;
	int size = atoi(argv[1]);
	clock_t start, finish;
	double origin, optimized;
	int option;

	srand(time(NULL));

	arr1 = (int*)malloc(sizeof(int)*size);
	arr2 = (int*)malloc(sizeof(int)*size);

	for(int i=0;i<size;i++){
		arr1[i] = rand()%1000;
		arr2[i] = arr1[i];
	}

	while(1){
		menu();
		scanf("%d",&option);

		switch(option){
			case 1:
				printf("\n\t[+] Original version Insertion sort\n");
				sleep(1);
				printf("\t\t[-] Start sorting\n");
				sleep(1);
				start = clock();
				insertion(arr1,size);
				finish = clock();
				printf("\t\t[-] sorting completed\n");
				sleep(1);
				printf("\t\t[-] lapsed time : %.3lf second(s). \n",(finish-start)/(double)CLOCKS_PER_SEC);
				sleep(1);
				break;
			case 2:
				printf("\n\t[+] Optimized version Insertion sort\n");
				sleep(1);
				printf("\t\t[-] Start sorting\n");
				sleep(1);
				start = clock();
				optimized_insert(arr1,size);
				finish = clock();
				printf("\t\t[-] sorting completed\n");
				sleep(1);
				printf("\t\t[-] lapsed time : %.3lf second(s). \n",(finish-start)/(double)CLOCKS_PER_SEC);
				sleep(1);
				break;
			case 3:
				printf("\n\t[+] comparison two algorithms Insertion sort\n");
				sleep(1);
				start = clock();
				insertion(arr1,size);
				finish = clock();
				origin = (finish-start)/(double)CLOCKS_PER_SEC;
				printf("\t\t[-] original version : %.3lf second(s). \n",origin);
				sleep(1);
				start = clock();
				optimized_insert(arr2,size);
				finish = clock();
				optimized = (finish-start)/(double)CLOCKS_PER_SEC;
				printf("\t\t[-] optimized version : %.3lf second(s). \n",optimized);
				sleep(1);
				printf("\t\t[-] %.3lf second(s) faster ( %lf %% )\n",origin-optimized,(optimized/origin)*100);
				sleep(1);
				break;
			case 4:
				printf("\n[-] exit program\n");
				return 0;

			default:
				continue;
		}
	}

	return 0;
}
