#include<string>
#include<vector>
using namespace std;
string Normalize(string);
int length_of_book(string);
vector<string> Infected_Urls(string);
vector<int>  compute_prefix(string p);
vector<int>  kmp(string my_string,string p,vector<int>pi);
int Min(int a ,int b);
int Max(int a ,int b);
int cmp(struct suffix a, struct suffix b);
void printArr(vector<int> arr, int n);
void printArr(vector<int> arr, int n,string txt);
void printArr(int arr[], int n);
vector<int> LCP(string txt,vector<int> suffixArr);
int *buildSuffixArray(string txt, int n);
void buildSuffixArrayp(string txt, int n,int si);
void search(string pat,string txt,vector<int> suffArr,vector<int> lcp,int n);
vector<int> search_rb(string,string,int);
int bigmod(int,int,int);
double ret();
/*void getStoryTitles(string str);
int getStoryStartIndex(int index);
int getStoryEndIndex(int index);
string getStoryTitleName(int index);
void allStoryName();*/
