#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <exception>
using namespace std;
#include <time.h>

double time_elapsed(struct timespec, struct timespec);
#define alphas 52
int alphatotrieindex(char c);
class TrieNode
{
	public:
		TrieNode *parent;
		TrieNode *children[alphas];
		vector<int> occurences;
		bool isLeaf;
	TrieNode(){
		for(int i=0;i<alphas;i++){
				this->children[i] = NULL;
			}
		}
};
class Trie
{
	TrieNode *root;
	public:
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
					else
					{
						temp->isLeaf=false;
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

};

int main()
{	
	string text;
	string pattern;
	try
	{
		cin>>text;
		Trie t;
		t.insert(text,0);
		cin>>text;
		
		t.insert(text,0);
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
