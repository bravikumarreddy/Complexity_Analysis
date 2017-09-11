#include<iostream>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
using namespace std;
double time_elapsed(struct timespec, struct timespec);

void prin(long double **arr,int po){
	for(int i=0;i<po;i++){
		for(int j=0;j<po;j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

void multiply(long double **arr1 ,long double **arr2, long double **arr3,int po){

	for(int i=0;i<po;i++){
		for(int j=0;j<po;j++){
			int tot=0;
			for(int k=0;k<po;k++){
				
				tot += arr1[i][k]*arr2[k][j];
			
			}
			arr3[i][j] =tot;
		}
	}
		
}
int main(){
	struct timespec start,end;
	time_t t;
	int num;
	int po=0;
	cin >> po;
	
	long double **arr1 = new long double*[po];
	for(int i=0;i<po;i++){
		arr1[i] = new long double[po];
	}
	
	
	long double **arr2= new long double*[po];
	for(int i=0;i<po;i++){
		arr2[i] = new long double[po];
	}
	
	long double **arr3= new long double*[po];
	for(int i=0;i<po;i++){
		arr3[i] = new long double[po];
	}
	
	
	for(int i =0;i<po;i++){
		for(int j=0;j<po;j++){
			cin >> arr1[i][j];
			
		}
	}
	
	for(int i =0;i<po;i++){
		for(int j=0;j<po;j++){
			
			cin >> arr2[i][j];
		}
	}
	
	

	clock_gettime(CLOCK_REALTIME,&start);
		
	multiply(arr1,arr2,arr3,po);
	clock_gettime(CLOCK_REALTIME,&end);
	printf("Execution time: %.6lf miliseconds.\n", time_elapsed(start, end));
	
	for(int i=0;i<po;i++){
		delete [] arr1[i];
		delete [] arr2[i];
		delete [] arr3[i];
	}
	delete [] arr1;
	delete [] arr2;
	delete [] arr3;
	
	
}

double time_elapsed(struct timespec start, struct timespec end){
	double t;
	t = (end.tv_sec - start.tv_sec) * 1000;
	t += (end.tv_nsec - start.tv_nsec) * 0.000001; 
	return t;
}
