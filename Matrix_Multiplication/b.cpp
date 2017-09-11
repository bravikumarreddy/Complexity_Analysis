#include<iostream>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
using namespace std;
double time_elapsed(struct timespec, struct timespec);

void prin(double **arr,int po){
	for(int i=0;i<po;i++){
		for(int j=0;j<po;j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

void copy(double **arr1 ,int istart,int jstart,double **arr2,int two){
	
	for(int i=0;i<two;i++)
		for(int j=0;j<two;j++)
			arr2[i][j] = arr1[istart+i][jstart+j];


}

void copy2(double **arr1 ,int istart,int jstart,double **arr2,int two){
	
	for(int i=0;i<two;i++)
		for(int j=0;j<two;j++)
			arr1[istart+i][jstart+j] = arr2[i][j];


}

double ** add(double **arr1 ,double **arr2,int po){

	double **a= new double*[po];
	for(int i=0;i<po;i++){
		a[i] = new double[po];
	}

	for(int i=0;i<po;i++)
		for(int j=0;j<po;j++)
			a[i][j]=arr1[i][j] + arr2[i][j];
	return a; 
		
}


double ** multiply(double **arr1,int start,int stop,int start2,int stop2,double **arr2,int po){

	int two=po/2;
	
	double **arr3= new double*[po];
	for(int i=0;i<po;i++){
		arr3[i] = new double[po];
	}
	
	if(po==1){
		arr3[0][0] =arr1[start][stop]*arr2[start2][stop2];
		return arr3;
	}
	
	double **t1 ;
	double **t2 ;
	double **t3 ;
	double **t4 ;
	double **t5 ;
	double **t6 ;
	double **t7 ;
	double **t8 ;
	
	
	
	
	
	t1 = multiply(arr1,start,stop,start2,stop2,arr2,two);
	t2 = multiply(arr1,start,stop+two,start2+two,stop2,arr2,two);
	t3 = multiply(arr1,start,stop,start2,stop2+two,arr2,two);
	t4 = multiply(arr1,start,stop+two,start2+two,stop2+two,arr2,two);
	t5 = multiply(arr1,start+two,stop,start2,stop2,arr2,two);
	t6 = multiply(arr1,start+two,stop+two,start2+two,stop2,arr2,two);
	t7 = multiply(arr1,start+two,stop,start2,stop2+two,arr2,two);
	t8 = multiply(arr1,start+two,stop+two,start2+two,stop2+two,arr2,two);
	
	double **a1 = add(t1,t2,two);
	double **a2 = add(t3,t4,two);
	double **a3 = add(t5,t6,two);
	double **a4 = add(t7,t8,two);
	
	copy2(arr3,0,0,a1,two);
	copy2(arr3,0,two,a2,two);
	copy2(arr3,two,0,a3,two);
	
	copy2(arr3,two,two,a4,two);
	
	
	
	
	for(int i=0;i<two;i++){
	
		delete [] t1[i];
		delete [] t2[i];
		delete [] t3[i];
		delete [] t4[i];
		delete [] t5[i];
		delete [] t6[i];
		delete [] t7[i];
		delete [] t8[i];
		delete [] a1[i];
		delete [] a2[i];
		delete [] a3[i];
		delete [] a4[i];
		
	}
		
		delete [] t1;
		delete [] t2;
		delete [] t3;
		delete [] t4;
		delete [] t5;
		delete [] t6;
		delete [] t7;
		delete [] t8;
		delete [] a1;
		delete [] a2;
		delete [] a3;
		delete [] a4;
	return arr3;
	
	
	
			
	
} 
	
int main(){
	struct timespec start,end;
	time_t t;
	int po ;
	cin >> po;
	srand((unsigned) time(&t));

	
	double	 **arr1 = new double*[po];
	for(int i=0;i<po;i++){
		arr1[i] = new double[po];
	}
	
	
	double **arr2= new double*[po];
	for(int i=0;i<po;i++){
		arr2[i] = new double[po];
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
		
	double **x = multiply(arr1,0,0,0,0,arr2,po);
	clock_gettime(CLOCK_REALTIME,&end);
	printf("Execution time: %.6lf miliseconds.\n", time_elapsed(start, end));
	
	
	for(int i=0;i<po;i++){
		delete [] arr1[i];
		delete [] arr2[i];
		delete [] x[i];
		
	}
	delete [] arr1;
	delete [] arr2;
	delete [] x;
}

double time_elapsed(struct timespec start, struct timespec end){
	double t;
	t = (end.tv_sec - start.tv_sec) * 1000;
	t += (end.tv_nsec - start.tv_nsec) * 0.000001; 
	return t;
}
