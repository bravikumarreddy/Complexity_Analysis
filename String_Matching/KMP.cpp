#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
vector<int>  kmp(string,string);
vector<int>  compute_prefix(string);
/*int main(){

	string my_string;
	string tmp;
	string p;
	ifstream in("out");
	
	if(!in) {
		cout << "Cannot open input file.\n";
		return 1;
	}
	
	
	while(in){
	getline(in,tmp);
	my_string += tmp; 
	}
	//my_string = '@'+my_string;
	
	in.close();
	
	cout << "Enter The Patten to search \n";
	cin >> p;
	//p="@"+p;
	vector<int> res = kmp(my_string,p);
	
	for(int i=0;i<res.size();i++){
		cout << my_string[res[i]+1] << "\n";
	}
	return 0;
	
}
*/
vector<int>  kmp(string my_string,string p,vector<int>pi){
	
	my_string='@'+my_string;
	
	int n = my_string.length()-1;
	int m = p.length()-1;
	
	
	
	vector<int> res;
	for(int i=1;i< p.length();i++){
		cout << pi[i];
		
	}
	
	int q=0;
	for(int i=1;i<=n;i++){
		while(q>0 && p[q+1] != my_string[i]){
			q=pi[q];
		}
		if(p[q+1] == my_string[i])
			q=q+1;
		if(q==m){
			
			res.push_back(i-m-1);
			q=pi[q];
			
		}
			
	}
	cout<< "\n" <<res.size()<<" -res size \n";
	for(int i=0;i<res.size();i++){
		cout << my_string.substr(res[i]+2,m) << "  At -- >"<< res[i]+2 << "\n";
	}
	return res;
	
	

}

vector<int>  compute_prefix(string p){
	
	int m =p.length();
	int k=0;
	vector<int> pi; 
	
	for(int i=0;i<m+1;i++){
		pi.push_back(0);
	}
	
	for(int q=2; q <= m;q++ ){
		while(k>0 && p[k+1] != p[q])
			k = pi[k];
		if(p[k+1] == p[q])
			k=k+1;
		pi[q]=k;
			
	}
	return pi;
	
}
