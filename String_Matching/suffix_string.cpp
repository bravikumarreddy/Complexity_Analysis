#include <iostream>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;
 

struct suffix
{
    int index; 
    int rindex;
    int rank[2]; 
};

 
int Min(int a ,int b){
	if(a<b)
		return a;
	return b;
}
int Max(int a ,int b){
	if(a>b)
		return a;
	return b;
}
int cmp(struct suffix a, struct suffix b)
{
    return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0):
               (a.rank[0] < b.rank[0] ?1: 0);
}
void printArr(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void printArr(vector<int> arr, int n,string txt)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " "<< txt.substr(arr[i],n-1) << "  "<< i << endl;
    cout << endl;
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

vector<int> LCP(string txt,vector<int> suffixArr)
{
	int n = suffixArr.size();
	
	vector<int> lcp(n,0);
	
	vector<int> invSuff(n,0);
	for(int i=0;i<n;i++){
		invSuff[suffixArr[i]] = i;
	}
	
	int k =0;
	
	for(int l=0;l<n;l++,k?k--:0){
	    
	    
		if(invSuff[l]==n-1){
			k=0;
			continue;
		}
		
		
		int j= suffixArr[invSuff[l]+1];
		
		while(l+k<n && j+k<n && txt[l+k]==txt[j+k])
			k++;
			
		
		lcp[invSuff[l]]=k;
		
		
}


return lcp;
}


int *buildSuffixArray(string txt, int n)
{
   
    struct suffix *suffixes = new struct suffix[n];
    
 
    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        
        suffixes[i].rank[0] = txt[i];
        suffixes[i].rank[1] = ((i+1) < n)? (txt[i + 1] ): -1;
    }
 
   
    sort(suffixes, suffixes+n, cmp);
 
   
    int ind[n];  
    for (int k = 4; k < 2*n; k = k*2)
    {
        
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;
 
        
        for (int i = 1; i < n; i++)
        {
            
            if (suffixes[i].rank[0] == prev_rank &&
                    suffixes[i].rank[1] == suffixes[i-1].rank[1])
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            }
            else 
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }
 
        
        for (int i = 0; i < n; i++)
        {
            int nextindex = suffixes[i].index + k/2;
            suffixes[i].rank[1] = (nextindex < n)?
                                  suffixes[ind[nextindex]].rank[0]: -1;
        }
 
        
        sort(suffixes, suffixes+n, cmp);
    }
 
    int *suffixArr = new int[n];
    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;
 
   	delete []suffixes;
    return  suffixArr;
}



void buildSuffixArrayp(string txt, int n,int si)
{
   
    string txtr = txt;
    string txt2=txt;
    txtr += '~';
     reverse(txt2.begin(),txt2.end());
    txtr +=  txt2+ '~';
   
   	//cout << txtr <<endl;
    n=2*n+2;
    n--;
     struct suffix *suffixes = new struct suffix[n];
 	
    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        
        suffixes[i].rank[0] = txtr[i];
        suffixes[i].rank[1] = ((i+1) < n)? (txtr[i + 1] ): -1;
    }
    
    
    
 
   
    sort(suffixes, suffixes+n, cmp);
 
   
    int *ind =  new int[n];  
    for (int k = 4; k < 2*n; k = k*2)
    {
        
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;
 		
        
        for (int i = 1; i < n; i++)
        {
            
            if (suffixes[i].rank[0] == prev_rank &&
                    suffixes[i].rank[1] == suffixes[i-1].rank[1])
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            }
            else 
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }
 
        
        for (int i = 0; i < n; i++)
        {
            int nextindex = suffixes[i].index + k/2;
            suffixes[i].rank[1] = (nextindex < n)?
                                  suffixes[ind[nextindex]].rank[0]: -1;
        }
 
        
        sort(suffixes, suffixes+n, cmp);
    }
 
    
    int *suffixArr = new int[n];
    
    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;
 
 	 std::vector<int> v(suffixArr,suffixArr+n);
    // printArr(v, n,txtr);
   
    vector<int> lcp = LCP(txtr,v);
    
    //printArr(lcp,n);
   
    for(int i=0;i<n-1;i++){
    
    	int x= Min(suffixArr[i+1],suffixArr[i]);
    	int y=Max(suffixArr[i+1],suffixArr[i] );
    	
    	if(lcp[i]>si && y >( (n-1)/2)){
    		int l = lcp[i];
    		int s=x;
    		//cout<<  suffixArr[i+1]<<" ,.inside.," << suffixArr[i] << " ... " << (n-1)/2 << endl;
    		int p=y;
    		while(l>si){
    		//cout<< ""<< x << "<----x"<< "y-------->"<<y <<"l >"<< l<< "n ->"<<n <<"<---x  --->" << n-s-l << "  inside is inside "  << y << endl;
    		
    		//cout << p<<" <---- palindrome   "<< n-s-l << endl;
    		if(n-s-l==p){
    			int o=0;
    			
    			
    			cout<< txt.substr(s,l);
    			cout << " <---- palindrome"<< endl;
    		}
    		l--;
    		
    		}
    	}
    }
    delete []suffixes;
    delete []ind;
    delete []suffixArr;
    
    
}
 
void search(string pat,string txt,vector<int> suffArr,vector<int> lcp,int n){
	int m = pat.size();
	
	int l=0 ,r=n-1;
	int k=0;
	int res=0;
	int mid=0;
	int c=0;
	int prev=-1;
	
	while( l<=r ){
		mid = l + (r-l)/2;
		int boo=1;
		if(res=-1 && prev !=-1 && Min(lcp[prev],lcp[mid]) > c ){
			boo = 0;
			res =-1;
		}
		else if(res=-1 && prev !=-1 && Min(lcp[prev],lcp[mid]) < c){
			boo = 0;
			res = 1;
		}
		else if(res=1 && prev !=-1 && Min(lcp[prev],lcp[mid]) > c){
			boo = 0;
			res = 1;
		}
		else if(res=1 && prev !=-1 && Min(lcp[prev],lcp[mid]) > c){
			boo = 0;
			res = -1;
		}
		while(boo){
			if(pat[0]==txt[suffArr[mid]]){
			
			
		
			if(c==m)
				break;
			if(pat[c]==txt[c+suffArr[mid]]){
					c++;
					prev=mid;
				}
			else if(pat[c]<txt[c+suffArr[mid]]){
				res=-1;
				break;
			}
			else{
				res= +1;
				
				break;
			}
			
			}
			else
			{
			
			
			if(pat[0]<txt[suffArr[mid]]){
				res=-1;
				break;
			}
			else{
				res= +1;
				
				break;
			}
				
			}
			
		}
		
		
		if(c==m)
			break;
		if(c<m and res == -1)
			r=mid-1;
		else
			l=mid+1;
		
	
		
		
	}
	int ls=mid;
	

	cout << "answer  ::  mid -- >" << suffArr[mid] << endl;
	
	while(true){
	
		if(ls+1 <= n-1 &&  txt[suffArr[ls]]==txt[suffArr[ls+1]] && lcp[ls]>=m){
		ls++;
		cout << suffArr[ls]  << endl;
		
		}
		else
			break;
		
	}
	ls=mid;
	while(true){
		if(ls-1 >= 0 &&  txt[suffArr[ls]]==txt[suffArr[ls-1]]  && lcp[ls-1]>=m){
		ls--;
		cout << suffArr[ls] << endl;
		
		}
		else
			break;
		
	}
	
	
	
}


/*
int main()
{
    string txt = "abcdeabadcesasdasfdadfa";
    int n = txt.size();
    
    int *suffixArr = buildSuffixArray(txt,  n);
    
    cout << "Following is suffix array for " << txt << endl;
 
    std::vector<int> v(suffixArr,suffixArr+n);
    
   // printArr(v, n,txt);
   	
   	delete []	suffixArr;
   
    vector<int> lcp = LCP(txt,v);
    
    cout << "\nLCP Array : \n";
    
   // printArr(lcp, n);
    
    string pat = "a";
    cout << "Pattern ---> " << pat << endl;
    search(pat,txt,v,lcp,n);
    
    
    
    buildSuffixArrayp(txt,n,2);
    return 0;
	
}
*/
