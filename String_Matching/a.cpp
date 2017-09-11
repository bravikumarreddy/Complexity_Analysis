#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <exception>
using namespace std;
#define alphas 52
int alphatotrieindex(char c);
char trieindextoalpha(int i);
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
						cout<<" : "<< node->children[i]->occurences[0]<<endl;
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
