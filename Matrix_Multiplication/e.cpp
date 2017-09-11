#include<iostream>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<pthread.h>
using namespace std;
double ** multipl(double **arr1 ,double **arr2,int po);
void *multiply(void *tdata);
void cop2(double **arr1 ,int istart,int jstart,double **arr2,int two);
void prin(double **arr,int po);
struct thread_data{
	double **arr1;
	double **arr2;
	int start;
	int stop;
	int start2;
	int stop2;
	int po;
	
	};
	
void prin(double **arr,int po){
	for(int i=0;i<po;i++){
		for(int j=0;j<po;j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
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

void cop(double **arr1 ,int istart,int jstart,double **arr2,int two){
	
	for(int i=0;i<two;i++)
		for(int j=0;j<two;j++)
			arr2[i][j] = arr1[istart+i][jstart+j];


}

void cop2(double **arr1 ,int istart,int jstart,double **arr2,int two){
	
	for(int i=0;i<two;i++)
		for(int j=0;j<two;j++)
			arr1[istart+i][jstart+j] = arr2[i][j];


}
using namespace std;
double time_elapsed(struct timespec, struct timespec);

void *multiply(void *tdata){

	struct thread_data *data;
	
	data = (struct thread_data *)tdata;
	
	double **arr1 = data->arr1;
	double **arr2 = data->arr2;
	int po = data->po;
	
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
	
	cop(arr1,0,0,A1,two);
	cop(arr1,0,two,A2,two);
	cop(arr1,two,0,A3,two);
	cop(arr1,two,two,A4,two);
	
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
	
	cop(arr2,0,0,B1,two);
	cop(arr2,0,two,B2,two);
	cop(arr2,two,0,B3,two);
	cop(arr2,two,two,B4,two);
	
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
	
	
	
	double **p1 = multipl(A1,fmh,two);
	double **p3 = multipl(cpd,B1,two);
	double **p5 = multipl(apd,eph,two);
	double **p7 = multipl(amc,epf,two);
	
	double **p2 = multipl(apb,B4,two);
	double **p4 = multipl(A4,gme,two);
	double **p6 = multipl(bmd,gph,two);
	
	
	
	
	
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
	

	
	cop2(arr3,0,0,f1,two);
	cop2(arr3,0,two,f2,two);
	cop2(arr3,two,0,f3,two);
	cop2(arr3,two,two,f4,two);
	
	
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
double ** multipl(double **arr1 ,double **arr2,int po){

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
	
	cop(arr1,0,0,A1,two);
	cop(arr1,0,two,A2,two);
	cop(arr1,two,0,A3,two);
	cop(arr1,two,two,A4,two);
	
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
	
	cop(arr2,0,0,B1,two);
	cop(arr2,0,two,B2,two);
	cop(arr2,two,0,B3,two);
	cop(arr2,two,two,B4,two);
	
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
	

	double **p1 = multipl(A1,fmh,two);
	double **p3 = multipl(cpd,B1,two);
	double **p5 = multipl(apd,eph,two);
	double **p7 = multipl(amc,epf,two);
	
	double **p2 = multipl(apb,B4,two);
	double **p4 = multipl(A4,gme,two);
	double **p6 = multipl(bmd,gph,two);
	
	
	
	
	
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
	

	
	cop2(arr3,0,0,f1,two);
	cop2(arr3,0,two,f2,two);
	cop2(arr3,two,0,f3,two);
	cop2(arr3,two,two,f4,two);
	
	
	
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
	
	
		
	
	//prin(arr3,po);	

int main(){
	struct timespec star,end;
	time_t t;
	int num;
	
	int po=0 ;
	cin >> po;
	int two = po/2;
	int start=0;
	int stop=0;
	int start2=0;
	int stop2=0;
	srand((unsigned) time(&t));
	
	double **arr1 = new double*[po];
	for(int i=0;i<po;i++){
		arr1[i] = new double[po];
	}
	
	double **arr3=new double*[po];
	double **arr2= new double*[po];
	for(int i=0;i<po;i++){
		arr2[i] = new double[po];
		arr3[i] = new double[po];
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
	
	double **x;
	
	if(num<0){
	clock_gettime(CLOCK_REALTIME,&star);
		
	x = multipl(arr1,arr2,po);
	clock_gettime(CLOCK_REALTIME,&end);
	printf("Execution time: %.6lf miliseconds.\n", time_elapsed(star, end));
	
	
	for(int i=0;i<po;i++){
		
		delete [] x[i];
		
		
	}
	
	delete [] x;
	
	}
	else{
	
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
	
	cop(arr1,0,0,A1,two);
	cop(arr1,0,two,A2,two);
	cop(arr1,two,0,A3,two);
	cop(arr1,two,two,A4,two);
	
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
	
	
	cop(arr2,0,0,B1,two);
	cop(arr2,0,two,B2,two);
	cop(arr2,two,0,B3,two);
	cop(arr2,two,two,B4,two);
	
	
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
	double **p1 ;
	double **p3;
	double **p5 ;
	double **p7 ;
	double **p2 ;
	double **p4;
	double **p6;
	
	
	clock_gettime(CLOCK_REALTIME,&star);
	pthread_t th1;
	struct thread_data d1;
	void *exitstatus1;
	d1.arr1=A1;
	d1.arr2=fmh;
	
	d1.start=start;
	d1.stop=stop;
	
	d1.start2=0;
	d1.stop2=0;
	
	d1.po=two;
	pthread_create(&th1,NULL , multiply,(void *)&d1);
	
	
	pthread_t th2;
	struct thread_data d2;
	void *exitstatus2;
	d2.arr1=cpd;
	d2.arr2=B1;
	d2.po=two;
	
	d2.start=0;
	d2.stop=0;
	
	d2.start2=start2;
	d2.stop2=stop2;
	
	pthread_create(&th2,NULL , multiply,(void *)&d2);
	
	pthread_t th3;
	struct thread_data d3;
	void *exitstatus3;
	d3.arr1=apd;
	d3.arr2=eph;
	d3.po=two;
	
	d3.start=0;
	d3.stop=0;
	
	d3.start2=0;
	d3.stop2=0;
	pthread_create(&th3,NULL , multiply,(void *)&d3);
	
	pthread_t th4;
	struct thread_data d4;
	void *exitstatus4;
	d4.arr1=amc;
	d4.arr2=epf;
	d4.po=two;
	
	d4.start=0;
	d4.stop=0;
	
	d4.start2=0;
	d4.stop2=0;
	
	pthread_create(&th4,NULL , multiply,(void *)&d4);
	
	pthread_t th5;
	struct thread_data d5;
	void *exitstatus5;
	
	d5.arr1=apb;//A3;
	d5.arr2=B4;//B1;
	d5.po=two;
	d5.start=0;
	d5.stop=0;
	
	d5.start2=start2+two;
	d5.stop2=stop2+two;
	pthread_create(&th5,NULL , multiply,(void *)&d5);
	
	
	pthread_t th6;
	struct thread_data d6;
	void *exitstatus6;
	d6.arr1=A4;//A4;
	d6.arr2=gme;//B3;
	d6.start=start+two;
	d6.stop=stop+two;
	
	d6.start2=0;
	d6.stop2=0;
	d6.po=two;
	pthread_create(&th6,NULL , multiply,(void *)&d6);
	
	pthread_t th7;
	struct thread_data d7;
	void *exitstatus7;
	d7.arr1=bmd;
	d7.arr2=gph;
	d7.po=two;
	d7.start=0;
	d7.stop=0;
	
	d7.start2=0;
	d7.stop2=0;
	pthread_create(&th7,NULL , multiply,(void *)&d7);

	pthread_join(th1, &exitstatus1);
	p1 = (double **)exitstatus1;
	pthread_join(th2, &exitstatus2);
	p3 = (double **)exitstatus2;
	pthread_join(th3, &exitstatus3);
	p5 = (double **)exitstatus3;
	pthread_join(th4, &exitstatus4);
	p7 = (double **)exitstatus4;
	pthread_join(th5, &exitstatus5);
	
	p2 = (double **)exitstatus5;
	pthread_join(th6, &exitstatus6);
	p4 = (double **)exitstatus6;
	
	pthread_join(th7, &exitstatus7);
	p6 = (double **)exitstatus7;
	

	
	for(int i=0;i<two;i++){
		delete [] A1[i];
		delete [] A2[i];
		delete [] A3[i];
		delete [] A4[i];
		delete [] B1[i];
		delete [] B2[i];
		delete [] B3[i];
		delete [] B4[i];
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
		delete [] A1;
		delete [] A2;
		delete [] A3;
		delete [] A4;
		delete [] B1;
		delete [] B2;
		delete [] B3;
		delete [] B4;
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
	
	
	cop2(arr3,0,0,f1,two);
	cop2(arr3,0,two,f2,two);
	cop2(arr3,two,0,f3,two);
	cop2(arr3,two,two,f4,two);
	
	clock_gettime(CLOCK_REALTIME,&end);
	for(int i=0;i<two;i++){
		
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
	printf("Execution time: %.6lf miliseconds.\n", time_elapsed(star, end));
	
	}
	
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
