#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <exception>
using namespace std;
vector<StoryTitles> list;
void getStoryTitles(string str)
{
	int n=str.length();
	int count=0,i=0;
	cout << str.size() << "in story \n";
	while(i<n)
	{
		if(str.at(i)=='\n' )
		{
			//cout << "1\n";
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
			temp.title=str.substr(i+1,(j-i-2));
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
}
int getStoryStartIndex(int index)
{
	return list[index-1].start;
}
int getStoryEndIndex(int index)
{
	return list[index-1].end;
}
string getStoryTitleName(int index)
{
	return list[index-1].title;
}
void allStoryName()
{
	int i;
	for(i=0;i<list.size();i++)
	{
		cout << i+1 << " " << getStoryTitleName(i+1) ;
	}
}
/*int main()
{	
	try
	{
		string line;
		string text;
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
		
		getStoryTitles(text);
		
		//cout << text;
		cout << list.size();
		
		
		
		int i;
		
		for(i=0;i<list.size();i++)
		{
			cout<<getStoryTitle(i+1)<<endl;
		}
	}
	catch(exception const &exc)
	{
		cerr<<exc.what()<<"\n";
	}
	return 0;
}*/
