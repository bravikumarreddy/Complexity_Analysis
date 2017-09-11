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
		a[i]= new double[po];
	}

	for(int i=0;i<po;i++)
		for(int j=0;j<po;j++)
			a[i][j]=arr1[i][j] + arr2[i][j];
	return a; 
		
}

double ** sub(double **arr1 ,double **arr2,int po){

	double **a= new double*[po];
	for(int i=0;i<po;i++){
		a[i] = new double[po];
	}

	for(int i=0;i<po;i++)
		for(int j=0;j<po;j++)
			a[i][j]=arr1[i][j] - arr2[i][j];
	return a; 
		
}


double ** multiply(double **arr1 ,double **arr2,int po){

	int two=po/2;
	
	double **arr3= new double*[po];
	for(int i=0;i<po;i++){
		arr3[i] = new double[po];
	}
	
	if(po==1){
		arr3[0][0] =arr1[0][0]*arr2[0][0];
		return arr3;
	}
	
	double **A1= new double*[two];
	for(int i=0;i<two;i++){
		A1[i] = new double[two];
	}
	
	double **A2= new double*[two];
	for(int i=0;i<two;i++){
		A2[i] = new double[two];
	}
	
	double **A3= new double*[two];
	for(int i=0;i<two;i++){
		A3[i] = new double[two];
	}
	
	double **A4= new double*[two];
	for(int i=0;i<two;i++){
		A4[i] = new double[two];
	}
	
	copy(arr1,0,0,A1,two);
	copy(arr1,0,two,A2,two);
	copy(arr1,two,0,A3,two);
	copy(arr1,two,two,A4,two);
	
	double **B1= new double*[two];
	for(int i=0;i<two;i++){
		B1[i] = new double[two];
	}
	
	double **B2= new double*[two];
	for(int i=0;i<two;i++){
		B2[i] = new double[two];
	}
	
	double **B3= new double*[two];
	for(int i=0;i<two;i++){
		B3[i] = new double[two];
	}
	
	double **B4= new double*[two];
	for(int i=0;i<two;i++){
		B4[i] = new double[two];
	}
	
	copy(arr2,0,0,B1,two);
	copy(arr2,0,two,B2,two);
	copy(arr2,two,0,B3,two);
	copy(arr2,two,two,B4,two);
	
	double **fmh = sub(B2,B4,two);
	
	double **cpd = add(A3,A4,two);
	double **apd = add(A1,A4,two);
	double **eph = add(B1,B4,two);
	double **amc = sub(A1,A3,two);
	double **epf = add(B1,B2,two);
	double **apb = add(A1,A2,two);
	double **gme = sub(B3,B1,two);
	double **bmd = sub(A2,A4,two);
	double **gph = add(B3,B4,two);
	
	
	
	double **p1 = multiply(A1,fmh,two);
	double **p3 = multiply(cpd,B1,two);
	double **p5 = multiply(apd,eph,two);
	double **p7 = multiply(amc,epf,two);
	
	double **p2 = multiply(apb,B4,two);
	double **p4 = multiply(A4,gme,two);
	double **p6 = multiply(bmd,gph,two);
	
	
	
	
	
	for(int i=0;i<two;i++){
		delete [] fmh[i];
		delete [] cpd[i];
		delete [] apd[i];
		delete [] eph[i];
		delete [] amc[i];
		delete [] epf[i];
		delete [] apb[i];
		delete [] gme[i];
		delete [] bmd[i];
		delete [] gph[i];
		
		
	}
		delete [] fmh;
		delete [] cpd;
		delete [] apd;
		delete [] eph;
		delete [] amc;
		delete [] epf;
		delete [] apb;
		delete [] gme;
		delete [] bmd;
		delete [] gph;
	
	
	double **a1 = add(p5,p4,two);
	double **a2 = sub(a1,p2,two);
	double **f1 = add(a2,p6,two);
	double **f2 = add(p1,p2,two);
	double **f3 = add(p3,p4,two);
	double **a3 = add(p1,p5,two);
	double **a4 = sub(a3,p3,two);
	double **f4 = sub(a4,p7,two);
	

	
	copy2(arr3,0,0,f1,two);
	copy2(arr3,0,two,f2,two);
	copy2(arr3,two,0,f3,two);
	copy2(arr3,two,two,f4,two);
	
	
	for(int i=0;i<two;i++){
		delete [] A1[i];
		delete [] A2[i];
		delete [] A3[i];
		delete [] A4[i];
		delete [] B1[i];
		delete [] B2[i];
		delete [] B3[i];
		delete [] B4[i];
		delete [] a1[i];
		delete [] a2[i];
		delete [] a3[i];
		delete [] a4[i];
		delete [] f1[i];
		delete [] f2[i];
		delete [] f3[i];
		delete [] f4[i];
		delete [] p1[i];
		delete [] p2[i];
		delete [] p3[i];
		delete [] p4[i];
		delete [] p5[i];
		delete [] p6[i];
		delete [] p7[i];
		
		
	}
		delete [] A1;
		delete [] A2;
		delete [] A3;
		delete [] A4;
		delete [] B1;
		delete [] B2;
		delete [] B3;
		delete [] B4;
		delete [] f1;
		delete [] f2;
		delete [] f3;
		delete [] f4;
		delete [] a1;
		delete [] a2;
		delete [] a3;
		delete [] a4;
		
		delete [] p1;
		delete [] p2;
		delete [] p3;
		delete [] p4;
		delete [] p5;
		delete [] p6;
		delete [] p7;
	
		
		
	return arr3;
	
	
	
			
	
} 
	
int main(){
	struct timespec start,end;
	time_t t;
	int po ;
	cout << "Enter The input in the powers of 2 \n";
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
		
	double **x = multiply(arr1,arr2,po);
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
