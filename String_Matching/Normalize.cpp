#include<string>
#include<iostream>
#include<vector>
#include "declarations.h"
using namespace std;
string Normalize(string book){
	string new_book;
	int strlen = book.length();
	for(int i=0;i<strlen;i++){
		if(book[i] == ' '){
			while(i+1 < strlen && book[i+1] == ' ')
				i++;
			new_book += book[i];
		 }
		 else{
		 	new_book += book[i];
		 }
	}
	return new_book;
	
}
int length_of_book(string){
	
}
vector<string> Infected_Urls(string a){
	vector<string> vs;
	
}
vector<string> Story_titles(string a){
	vector<string> vs;
	
}


