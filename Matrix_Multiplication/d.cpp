#include<iostream>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<semaphore.h>
#include<pthread.h>
using namespace std;
int count=0;
void prin(double **arr,int po){
	for(int i=0;i<po;i++){
		for(int j=0;j<po;j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}
struct thread_data{
	double **arr1;
	double **arr2;
	int start;
	int stop;
	int start2;
	int stop2;
	int po;
	
	};

double time_elapsed(struct timespec start, struct timespec end){
	double t;
	t = (end.tv_sec - start.tv_sec) * 1000;
	t += (end.tv_nsec - start.tv_nsec) * 0.000001; 
	return t;
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

double ** multipl(double **arr1,int start,int stop,int start2,int stop2,double **arr2,int po){

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
	
	
	
	
	
	t1 = multipl(arr1,start,stop,start2,stop2,arr2,two);
	t2 = multipl(arr1,start,stop+two,start2+two,stop2,arr2,two);
	t3 = multipl(arr1,start,stop,start2,stop2+two,arr2,two);
	t4 = multipl(arr1,start,stop+two,start2+two,stop2+two,arr2,two);
	t5 = multipl(arr1,start+two,stop,start2,stop2,arr2,two);
	t6 = multipl(arr1,start+two,stop+two,start2+two,stop2,arr2,two);
	t7 = multipl(arr1,start+two,stop,start2,stop2+two,arr2,two);
	t8 = multipl(arr1,start+two,stop+two,start2+two,stop2+two,arr2,two);
	
	
	
	
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

void *multiply(void *tdata){
	
	struct thread_data *data;
	
	data = (struct thread_data *)tdata;
	
	double **arr1 = data->arr1;
	double **arr2 = data->arr2;
	int po = data->po;
	int start = data->start;
	int stop = data->stop;
	
	int start2 = data->start2;
	int stop2 = data->stop2;
	

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
	
	
	
	
	
	t1 = multipl(arr1,start,stop,start2,stop2,arr2,two);
	t2 = multipl(arr1,start,stop+two,start2+two,stop2,arr2,two);
	t3 = multipl(arr1,start,stop,start2,stop2+two,arr2,two);
	t4 = multipl(arr1,start,stop+two,start2+two,stop2+two,arr2,two);
	t5 = multipl(arr1,start+two,stop,start2,stop2,arr2,two);
	t6 = multipl(arr1,start+two,stop+two,start2+two,stop2,arr2,two);
	t7 = multipl(arr1,start+two,stop,start2,stop2+two,arr2,two);
	t8 = multipl(arr1,start+two,stop+two,start2+two,stop2+two,arr2,two);
	
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
			
	
int num=0;
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
	if(po<16){
	
	clock_gettime(CLOCK_REALTIME,&star);
	x = multipl(arr1,0,0,0,0,arr2,po);
	clock_gettime(CLOCK_REALTIME,&end);
	
	printf("Execution time: %.6lf miliseconds.\n", time_elapsed(star, end));
	}
	else{
	
	double **t1 ;
	double **t2 ;
	double **t3 ;
	double **t4 ;
	double **t5 ;
	double **t6 ;
	double **t7 ;
	double **t8 ;
	clock_gettime(CLOCK_REALTIME,&star);
	pthread_t th1;
	struct thread_data d1;
	void *exitstatus1;
	d1.arr1=arr1;
	d1.arr2=arr2;
	
	d1.start=start;
	d1.stop=stop;
	
	d1.start2=start2;
	d1.stop2=stop2;
	
	d1.po=two;
	pthread_create(&th1,NULL , multiply,(void *)&d1);
	
	count++;
	pthread_t th2;
	
	
	struct thread_data d2;
	void *exitstatus2;
	d2.arr1=arr1;
	d2.arr2=arr2;
	d2.po=two;
	
	d2.start=start;
	d2.stop=stop+two;
	
	d2.start2=start2+two;
	d2.stop2=stop2;
	
	pthread_create(&th2,NULL , multiply,(void *)&d2);
	
	count++;
	pthread_t th3;
	struct thread_data d3;
	void *exitstatus3;
	d3.arr1=arr1;//A1;
	d3.arr2=arr2;//B2;
	d3.po=two;
	
	d3.start=start;
	d3.stop=stop;
	
	d3.start2=start2;
	d3.stop2=stop2+two;
	pthread_create(&th3,NULL , multiply,(void *)&d3);
	
	count++;
	pthread_t th4;
	struct thread_data d4;
	void *exitstatus4;
	d4.arr1=arr1;//A2;
	d4.arr2=arr2;//B4;
	d4.po=two;
	
	d4.start=start;
	d4.stop=stop+two;
	
	d4.start2=start2+two;
	d4.stop2=stop2+two;
	pthread_create(&th4,NULL , multiply,(void *)&d4);

	count++;
	pthread_t th5;
	struct thread_data d5;
	void *exitstatus5;
	
	d5.arr1=arr1;//A3;
	d5.arr2=arr2;//B1;
	d5.po=two;
	d5.start=start +two;
	d5.stop=stop;
	
	d5.start2=start2;
	d5.stop2=stop2;
	
	pthread_create(&th5,NULL , multiply,(void *)&d5);
	count++;
	pthread_t th6;
	struct thread_data d6;
	void *exitstatus6;
	d6.arr1=arr1;//A4;
	d6.arr2=arr2;//B3;
	d6.start=start+two;
	d6.stop=stop+two;
	
	d6.start2=start2+two;
	d6.stop2=stop2;
	d6.po=two;
	pthread_create(&th6,NULL , multiply,(void *)&d6);
	
	count++;
	pthread_t th7;
	struct thread_data d7;
	void *exitstatus7;
	d7.arr1=arr1;
	d7.arr2=arr2;
	d7.po=two;
	d7.start=start+two;
	d7.stop=stop;
	
	d7.start2=start2;
	d7.stop2=stop2+two;
	pthread_create(&th7,NULL , multiply,(void *)&d7);
	
	count++;
	pthread_t th8;
	
	struct thread_data d8;
	void *exitstatus8;
	d8.arr1=arr1;
	d8.arr2=arr2;
	d8.po=two;
	d8.start=start+two;
	d8.stop=stop+two;
	
	d8.start2=start2+two;
	d8.stop2=stop2+two;
	
	pthread_create(&th8,NULL , multiply,(void *)&d8);
	
	count++;
	
	pthread_join(th1, &exitstatus1);
	t1 = (double **)exitstatus1;
	pthread_join(th2, &exitstatus2);
	t2 = (double **)exitstatus2;
	pthread_join(th3, &exitstatus3);
	t3 = (double **)exitstatus3;
	pthread_join(th4, &exitstatus4);
	t4 = (double **)exitstatus4;
	pthread_join(th5, &exitstatus5);
	
	t5 = (double **)exitstatus5;
	pthread_join(th6, &exitstatus6);
	t6 = (double **)exitstatus6;
	pthread_join(th7, &exitstatus7);
	t7 = (double **)exitstatus7;
	pthread_join(th8, &exitstatus8);
	t8 = (double **)exitstatus8;
	
	clock_gettime(CLOCK_REALTIME,&end);
	printf("Execution time: %.6lf miliseconds.\n", time_elapsed(star, end));
	
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
}
	
	
	
			
	//prin(arr3,po);

	
	for(int i=0;i<po;i++){
		delete [] arr1[i];
		delete [] arr2[i];
		delete [] arr3[i];
		
	}
	delete [] arr1;
	delete [] arr2;
	delete [] arr3;
	
	
	
}
