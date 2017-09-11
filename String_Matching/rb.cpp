#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <exception>

using namespace std;
#define ASCII 256
vector<int> search_rb(string,string,int);
int bigmod(int,int,int);
double time_elapse(struct timespec start, struct timespec end){
	double t;
	t = (end.tv_sec - start.tv_sec) * 1000;
	t += (end.tv_nsec - start.tv_nsec) * 0.000001; 
	return t;
}
struct timespec star,en;
double ret(){
	return (time_elapse(star, en));
}
/*int main()
{	
	
		
		
	
	string text;
	string pattern;
	try
	{
		string line;
		
		ifstream myfile ("A");
		if (myfile.is_open())
		{	
			while ( getline (myfile,line) )
			{
				text.append(line);
				text.append("\n");
			}
			myfile.close();
		}
		else cout << "Unable to open file";
		
		
		
		
		
		cout << "Enter the Pattern\n";
		cin>>pattern;
		vector<int> occ=search_rb(text,pattern,101);
		int i;
		cout << occ.size()<<endl;
	}
	catch(exception const &exc)
	{
		cerr<<exc.what()<<"\n";
	}
	//for(i=0;i<occ.size();i++)
	//	cout << occ[i] << ' ';
	return 0;
}*/
vector<int> search_rb(string text,string pattern,int q)
{
	int n=text.length();
	int m=pattern.length();
	
	int hp=0;
	int ht=0;
	int i=0,j=0;
	vector<int> occurences;
	clock_gettime(CLOCK_REALTIME,&star);
	int h=bigmod(ASCII,m-1,q);//modular exponentitaion
	for(i=0;i<m;i++)
	{
		hp=(ASCII*hp+pattern.at(i))%q;
		ht=(ASCII*ht+text.at(i))%q;
		//cout<<hp<<":"<<ht<<endl;
	}
	clock_gettime(CLOCK_REALTIME,&en);
	for(i=0;i<=n-m;i++)
	{
		if(hp==ht)
		{
			bool temp=true;
			for(j=0;j<m&&temp;j++)
			{
				//cout<<pattern.at(j)<<":"<<pattern.at(i+j)<<endl;
				if(pattern.at(j)!=text.at(i+j))
				{
					temp=false;
				}
			}
			if(temp==true)
			{
				cout<<"Pattern occured at position:"<<i<<endl;
				occurences.push_back(i);
			}
		}
		if(i<n-m)
		{
			//cout<<"Hi"<<endl;
			ht=(ASCII*(ht-text.at(i)*h)+text.at(i+m))%q;
			if(ht<0)
				ht+=q;
				
		}
	}
	return occurences;
	
}
int bigmod(int base,int exp,int mod)
{
	int res=1;
	base%=mod;
	while(exp>0)
	{
		if(exp%2==1)
			res=(res*base)%mod;
		exp/=2;
		base=(base*base)%mod;
	}
	return res;
}
