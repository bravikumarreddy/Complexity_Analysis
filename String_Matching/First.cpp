#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include "declarations.h"
#include <sstream>   
using namespace std;


void Find_Length_of_text();
void Find_Pattern();
void Build_Cross_Index();
void Find_Maximal_Palindromes();
void Print_Stats();
void PrintTitles();
stringstream res2;
#include <exception>
using namespace std;
#define alphas 52
int alphatotrieindex(char c);
char trieindextoalpha(int i);

class StoryTitles
{
	public:
		string title;
		int start;
		int end;
	
};
bool st=false;
vector<StoryTitles> list;
vector<string> stats;
double time_elapsed(struct timespec start, struct timespec end){
	double t;
	t = (end.tv_sec - start.tv_sec) * 1000;
	t += (end.tv_nsec - start.tv_nsec) * 0.000001; 
	return t;
}
struct timespec start,end;
void getStoryTitles(string str)
{
	if(st==false)
	{
		int n=str.length();
		int count=0,i=0;
		while(i<n)
		{
			if(str.at(i)=='\n')
			{
				count++;
			}
			else if(str.at(i)==' '||str.at(i)=='\r')
			{
				count = count;
			}
			else
			{
				count=0;
			}
			if(count>=3&&(str.at(i+1)!='\n'))
			{	
				StoryTitles temp;
				int j=i+1;
				while(str.at(j)!='\n')
				{
					j++;
				}
				temp.title=str.substr(i+1,(j-i-1));
				temp.start=i+1;
				temp.end=j;
				list.push_back(temp);
				i=j+1;
				count=1;
			}
			else
			{
				i++;
			}
		}
		st=true;	
	}
}
string getStoryTitle(int index)
{
	return list[index-1].title;
}
class InfectedUrls
{
	public:
		string url;
		int start;
		int end;
};
vector<InfectedUrls> iu;
class urlmatcher
{
	private:
		int state;
		string evaluate;
	public:
		urlmatcher()
		{
			state=0;
		}
		bool isvalid(string ev)
		{
			state=0;
			evaluate=ev;
			return isvalidstate(0,0);
		}
		bool isvalidstate(int index,int state)
		{	
			if(index>=evaluate.length())
			{
				return false;
			}
			if(state==0)
			{
				if(evaluate.at(index)=='h')
				{
					isvalidstate(index+1,1);
				}
				else if(evaluate.at(index)=='f')
				{
					isvalidstate(index+1,8);
				}
				else
				{
					return false;
				}
			}
			else if(state==1)
			{
				if(evaluate.at(index)=='t')
				{
					isvalidstate(index+1,2);
				}
				else
				{
					return false;
				}
			}
			else if(state==2)
			{
				if(evaluate.at(index)=='t')
				{
					isvalidstate(index+1,3);
				}
				else
				{
					return false;
				}
			}
			else if(state==3)
			{
				if(evaluate.at(index)=='p')
				{
					isvalidstate(index+1,4);
				}
				else
				{
					return false;
				}
			}
			else if(state==4)
			{
				if(evaluate.at(index)==':')
				{
					isvalidstate(index+1,5);
				}
				else if(evaluate.at(index)=='s')
				{
					isvalidstate(index+1,7);
				}
				else
				{
					return false;
				}
			}
			else if(state==5)
			{
				if(evaluate.at(index)=='/')
				{
					isvalidstate(index+1,6);
				}
				else
				{
					return false;
				}
			}
			else if(state==6)
			{
				if(evaluate.at(index)=='/')
				{
					isvalidstate(index+1,11);
				}
				else
				{
					return false;
				}
			}
			else if(state==7)
			{
				if(evaluate.at(index)==':')
				{
					isvalidstate(index+1,5);
				}
				else if(evaluate.at(index)=='s')
				{
					isvalidstate(index+1,7);
				}
				else
				{
					return false;
				}
			}
			else if(state==8)
			{
				if(evaluate.at(index)=='t')
				{
					isvalidstate(index+1,9);
				}
				else
				{
					return false;
				}
			}
			else if(state==9)
			{
				if(evaluate.at(index)=='p')
				{
					isvalidstate(index+1,10);
				}
				else
				{
					return false;
				}
			}
			else if(state==10)
			{
				if(evaluate.at(index)==':')
				{
					isvalidstate(index+1,5);
				}
				else if(evaluate.at(index)=='s')
				{
					isvalidstate(index+1,7);
				}
				else
				{
					return false;
				}
			}
			else if(state==11)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};
class TrieNode
{
	public:
		TrieNode *parent;
		TrieNode *children[alphas];
		vector<int> occurences;
		bool isLeaf;
	TrieNode()
		{
			isLeaf=false;
			for(int i=0;i<alphas;i++)
			{
				this->children[i] = NULL;
			}
		}
};
class Trie
{
	
	public:
		TrieNode *root;
		Trie()
		{
			root=new TrieNode;
			
		}
		void insert(string str,int index)
		{
			TrieNode *temp=root;
			int i;
			int n=str.length();
			for(i=0;i<n;i++)
			{
				int j=alphatotrieindex(str.at(i));	
				if((temp->children[j]==NULL))
				{
					temp->children[j]=new TrieNode;
					temp->children[j]->parent=temp;
				}
				temp=temp->children[j];
			}	 
			temp->occurences.push_back(index);
			temp->isLeaf=true;
		}
		void delet()
		{
			
			delet(root);
			
			
		}
		void delet(TrieNode *t)
		{
			for(int i=0;i<alphas;i++){
				if(t->children[i] != NULL){
					delet(t->children[i]);
					}
			}
			delete t;
		}
		void Lexo(TrieNode *node,int depth,bool print)
		{
			int i;
			static char str[100]="";
			for(i=0;i<52;i++)
			{
				if(node->children[i]!=NULL)
				{
					if(print==false)
					{
						cout<<endl<<trieindextoalpha(i)<<endl<<endl;
					}
					str[depth]=trieindextoalpha(i);
					if(node->children[i]->isLeaf)
					{
						int j;
						for(j=0;j<=depth;j++)
						{
							cout<<str[j];
						}
						cout<<" : "<< node->children[i]->occurences[0]<<" Occurences : "<< node->children[i]->occurences.size()<<"\n";
					}
					Lexo(node->children[i],depth+1,true);
				}
			}
		}
};

int Build_cross(string text)
{	
	Trie t;
	
	try
	{
		
		int i=0;
		//text="aaa bb asdasdasdasdsdsadasdasdsadsd \n WDDASDA";
		int n=text.length();
		while(i<n)
		{
			int length=0;
			while(i+length<n && ((text.at(i+length) >= 97 && text.at(i+length) <= 122 ) || (text.at(i+length) >=  65 && text.at(i+length) <= 90 ) ) )
			{
				length++;
			}
			if(length!=0)
			{
				t.insert(text.substr(i,length),i);
			}
			i+=length+1;
		}
		t.Lexo(t.root,0,false);
		t.delet();
		
	}
	catch(exception const &exc)
	{
		cerr<<exc.what()<<"\n";
	}
	return 0;
}
int alphatotrieindex(char c)
{
	if(c>='A'&&c<='Z')
	{
		return (int)(c-'A');
	}
	else
	{
		return 26+(int)(c-'a');
	}
}
char trieindextoalpha(int i)
{
	if(i<26)
	{
		return (char)(i+'A');
	}
	else
	{
		return (char)(i-26+'a');
	}
}
string book="";
string path="";
bool normalize = false;
int main(){
	int p;
	char option;
	do{
	cout << "\n\n\n----------- Enter Your Option---------" << endl << endl<< "******q to Quit******" << endl;
	cout << "\n1.Find_length_of_Text" << endl;
	cout << "\n2.Find_pattern"<<endl;
	cout << "\n3.Build_Cross_Index" << endl;
	cout << "\n4.Find_Maximal_Palindromes"<<endl;
	cout << "\n5.Print_Stats"<< endl << endl;
	
	cin >> option;
	
	switch(option){
		
		case '1':
			Find_Length_of_text();
			break;
		case '2':
			Find_Pattern();
			break;
		case '3':
			Build_cross(book);
			break;
		case '4':
			cout<<"\nEnter the Minimum length of Palindrome : ";
			
			cin >> p;
			buildSuffixArrayp(book,book.size(),p);
			break;
		case '5':
			Print_Stats();
			break;
		default:
			break;
			
			
	}
	
	}
	while(option != 'q');
	
	return 0;
}
void getInfectedUrls(string book)
{
	urlmatcher u;
	int i=0;
	int n=book.length();
	while(i<n)
	{
		int length=0;
		while(i+length<n&&book.at(i+length)!=' '&&book.at(i+length)!='\n'&&book.at(i+length)!='\r')
		{
			length++;
		}
		if(length!=0)
		{
			if(u.isvalid(book.substr(i,length)))
			{
				InfectedUrls temp;
				temp.url=book.substr(i,length);
				temp.start=i;
				temp.end=i+length;
				iu.push_back(temp);
			}
		}
		i+=length+1;
	}
		//cout<<iu.size()<<endl;
		for(i=0;i<iu.size();i++)
		{
			cout<<iu[i].url<<endl;
		}
}
void Find_Length_of_text(){

	char option;
	
	
	if(book==""){
		cout << "\nEnter the Path of file (Relative or Absolute) : \n";
		cin >> path;
		ifstream in;
		in.open(path.c_str());
		if(!in){
			cout << "Cannot open input file. \n";
			return;
		}
		
		while(in){
			string tmp;
			getline(in,tmp);
			book += tmp + '\n';
		}
		
		in.close();
		
	}
	
	do{
	cout << "\n\n\n Enter Your Option" << endl << "q to Quit" << endl;
	cout << "\n1.Normalize_text" << endl;
	cout << "\n2.Find_Infected_Urls"<<endl;
	cout << "\n3.Print_Length_of_text" << endl;
	
	cin >> option;
	
	switch(option){
		
		case '1':
			book=Normalize(book);
			getStoryTitles(book);
			break;
		case '2':
			getInfectedUrls(book);
			break;
		case '3':
			cout << book.size();
			break;
		
		default:
			break;
			
			
		}
	
	}
	while(option != 'q');

}
void Find_Pattern(){
	if(book == ""){
		cout << "Please Normalize the text\n";
		return;
	}
	int a;int b;
	char option;
	int algo;
	string pat;
	vector<int> v;
	string s;
	vector<int> pi;
	int * array;
	string res ;
	cout << "\n\n\n Enter Algorithm" << endl << "q to Quit" << endl;
	cout << "\n1.KMP" << endl;
	cout << "\n2.Rabin Karb"<<endl;
	cout << "\n3.Suffix tree" << endl;
	
	cin >> algo;
	
	
do{
	cout << "\n\n\n Enter Your Option" << endl << "q to Quit" << endl;
	cout << "\n1.Pattern in range" << endl;
	cout << "\n2.Between two Story Titles"<<endl;
	cout << "\n3.Entire txt" << endl;
	/*clock_gettime(CLOCK_REALTIME,&start);
		
	multiply(arr1,arr2,arr3,po);
	clock_gettime(CLOCK_REALTIME,&end);*/
	cin >> option;
	
	cout << "\nEnter the Pattern  : ";
	
	getline(cin, pat);
	getline(cin, pat);	
	
	
		
		if(option=='1'){
			
			cout << "\nEnter the Left index  : ";
			//cin >> a;
			a=0;
			cout << "\nEnter the Right index  : ";
			//cin >> b;
			b=book.size();
			s = book.substr(a,b-a);
			
			
			//if(algo==1){
			clock_gettime(CLOCK_REALTIME,&start);
			
			pi= compute_prefix('@'+pat);
			clock_gettime(CLOCK_REALTIME,&end);
			
			res2 << "Time Taken for preComputing in Kmp  " <<" is " << (time_elapsed(start, end)) << "\n" ;
			res2 << "Pattern Searched is " << pat << "\n" ;
			
			clock_gettime(CLOCK_REALTIME,&start);
			v=kmp(s,'@'+pat,pi);
			clock_gettime(CLOCK_REALTIME,&end);
			res2 << "Time Taken for searching in Kmp for Text length " << s.size() <<" is " << (time_elapsed(start, end)) << "\n\n\n" ;
			
			
			//break;
		//	}	
			//else if(algo==2){
			
			clock_gettime(CLOCK_REALTIME,&start);
			search_rb(s,pat,101);
			clock_gettime(CLOCK_REALTIME,&end);
			res2 << "Time Taken for preComputing in Rabin Karp  " <<" is " << ret() << "\n" ;
			res2 << "Time Taken for Searching using Rabin Karp of Text length " << s.size() <<" is " << (time_elapsed(start, end)) << "\n" ;
			res2 << "Pattern Searched is " << pat << "\n" ;
			
			
			
			//break;
			//}
			//else if(algo==3){
			clock_gettime(CLOCK_REALTIME,&start);
			array=buildSuffixArray(s,s.size());
			vector<int> v(array,array+s.size());
			vector<int> lcp = LCP(s,v);
			clock_gettime(CLOCK_REALTIME,&end);
			res2 << "Time Taken for Building Suffix Tree  " <<" is " << (time_elapsed(start, end)) << "\n" ;
			res2 << "Pattern Searched is " << pat << "\n" ;
			
			clock_gettime(CLOCK_REALTIME,&start);
			search(pat,s,v,lcp,s.size());
			clock_gettime(CLOCK_REALTIME,&end);
			res2 << "Time Taken for searching in Suffix tree for Text length " << s.size() <<" is " << (time_elapsed(start, end)) << "\n\n\n" ;
			delete [] array;
			//break;
			//}
		
		}
		else if(option=='2'){
			if(st==false)
			{
				getStoryTitles(book);
			}
			PrintTitles();
			cout << "\nEnter the Title range  : ";
			int x=1;
			int y=315;
			//cin >> x;
			//cout << "\n";
			//cin >> y;
			x=list[x-1].start;
			y=list[y-1].end;
			s = book.substr(x,y-x);
			//if(algo==1){
			clock_gettime(CLOCK_REALTIME,&start);
			
			pi= compute_prefix('@'+pat);
			clock_gettime(CLOCK_REALTIME,&end);
			
			res2 << "Time Taken for preComputing in Kmp  " <<" is " << (time_elapsed(start, end)) << "\n" ;
			res2 << "Pattern Searched is " << pat << "\n" ;
			
			clock_gettime(CLOCK_REALTIME,&start);
			v=kmp(s,'@'+pat,pi);
			clock_gettime(CLOCK_REALTIME,&end);
			res2 << "Time Taken for searching in Kmp for Text length " << s.size() <<" is " << (time_elapsed(start, end)) << "\n\n\n" ;
			//break;
			//}	
			//else if(algo==2){
			clock_gettime(CLOCK_REALTIME,&start);
			search_rb(s,pat,101);
			clock_gettime(CLOCK_REALTIME,&end);
			res2 << "Time Taken for preComputing in Rabin Karp  " <<" is " << ret() << "\n" ;
			res2 << "Time Taken for Searching using Rabin Karb of Text length " << s.size() <<" is " << (time_elapsed(start, end)) << "\n" ;
			res2 << "Pattern Searched is " << pat << "\n" ;
			
			//}
			//else{
			
			clock_gettime(CLOCK_REALTIME,&start);
			array=buildSuffixArray(s,s.size());
			vector<int> v(array,array+s.size());
			vector<int> lcp = LCP(s,v);
			clock_gettime(CLOCK_REALTIME,&end);
			res2 << "Time Taken for Building Suffix Tree  " <<" is " << (time_elapsed(start, end)) << "\n" ;
			res2 << "Pattern Searched is " << pat << "\n" ;
			
			clock_gettime(CLOCK_REALTIME,&start);
			search(pat,s,v,lcp,s.size());
			clock_gettime(CLOCK_REALTIME,&end);
			res2 << "Time Taken for searching in Suffix tree for Text length " << s.size() <<" is " << (time_elapsed(start, end)) << "\n\n\n" ;
			delete [] array;
			break;
			
			//}
		}
		else if(option=='3'){
			/*allStoryName();
			*/
			
			if(algo==1){
			clock_gettime(CLOCK_REALTIME,&start);
			
			pi= compute_prefix('@'+pat);
			clock_gettime(CLOCK_REALTIME,&end);
			
			res2 << "Time Taken for preComputing in Kmp  " <<" is " << (time_elapsed(start, end)) << "\n" ;
			res2 << "Pattern Searched is " << pat << "\n" ;
			
			clock_gettime(CLOCK_REALTIME,&start);
			v=kmp(book,'@'+pat,pi);
			clock_gettime(CLOCK_REALTIME,&end);
			res2 << "Time Taken for searching in Kmp for Text length " << book.size() <<" is " << (time_elapsed(start, end)) << "\n\n\n" ;
			break;
			}
			else if(algo==2){
			s=book;
			clock_gettime(CLOCK_REALTIME,&start);
			search_rb(s,pat,101);
			clock_gettime(CLOCK_REALTIME,&end);
			res2 << "Time Taken for preComputing in Rabin Karp  " <<" is " << ret() << "\n" ;
			res2 << "Time Taken for Searching using Rabin Karb of Text length " << s.size() <<" is " << (time_elapsed(start, end)) << "\n" ;
			res2 << "Pattern Searched is " << pat << "\n" ;
			
			break;
			}
			else if(algo==3){
			
			s=book;
			clock_gettime(CLOCK_REALTIME,&start);
			array=buildSuffixArray(s,s.size());
			vector<int> v(array,array+s.size());
			vector<int> lcp = LCP(s,v);
			clock_gettime(CLOCK_REALTIME,&end);
			res2 << "Time Taken for Building Suffix Tree  " <<" is " << (time_elapsed(start, end)) << "\n" ;
			res2 << "Pattern Searched is " << pat << "\n" ;
			
			clock_gettime(CLOCK_REALTIME,&start);
			search(pat,s,v,lcp,s.size());
			clock_gettime(CLOCK_REALTIME,&end);
			res2 << "Time Taken for searching in Suffix tree for Text length " << book.size() <<" is " << (time_elapsed(start, end)) << "\n\n\n" ;
			
			delete [] array;
			break;
			}
			
		}
		
			
		
		

	}while(option != 'q');
	
}
void Build_Cross_Index(){
	 
	 

}
void Find_Maximal_Palindromes(){
 
	
}
void Print_Stats(){
	/*clock_gettime(CLOCK_REALTIME,&start);
		
	multiply(arr1,arr2,arr3,po);
	clock_gettime(CLOCK_REALTIME,&end);*/
	stats.push_back(res2.str());
	cout << "\n\n\n*************************-----------STATS--------------******************** \n\n";
	res2.str("");
	for(int i=0;i<stats.size();i++){
		cout << stats[i];
	}
	cout << "\n\n\n*************************************************************************** \n\n";

}
void PrintTitles(){
	int n=list.size();
	int i;
	
	for(i=0;i<n;i++)
	{
		cout<<(i+1)<<". "<<getStoryTitle(i+1)<<endl;
	}
}
