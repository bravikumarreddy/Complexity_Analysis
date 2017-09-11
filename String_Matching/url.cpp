#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <exception>
using namespace std;
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
int main()
{	
	/*try
	{
		string url;
		cin>>url;	
		urlmatcher u;
		cout<<u.isvalid(url)<<endl;
	}
	catch(exception const &exc)
	{
		cerr<<exc.what()<<"\n";
	}
	return 0;*/
	try
	{
		urlmatcher u;
		string line;
		string text;
		ifstream myfile ("AESOP TALES (with random URLs).txt");
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
		int i=0;
		int n=text.length();
		while(i<n)
		{
			int length=0;
			while(i+length<n&&text.at(i+length)!=' '&&text.at(i+length)!='\n'&&text.at(i+length)!='\r')
			{
				length++;
			}
			if(length!=0)
			{
				if(u.isvalid(text.substr(i,length)))
				{
					InfectedUrls temp;
					temp.url=text.substr(i,length);
					temp.start=i;
					temp.end=i+length;
					iu.push_back(temp);
				}
			}
			i+=length+1;
		}
		cout<<iu.size()<<endl;
		for(i=0;i<iu.size();i++)
		{
			cout<<iu[i].url<<endl;
		}
	}
	catch(exception const &exc)
	{
		cerr<<exc.what()<<"\n";
	}
	return 0;
}
