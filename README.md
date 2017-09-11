# Complexity_Analysis

# Description 
Analysing the complexity of different 
Matrix Multiplication algorithms and
String Matching Algorithms

# Technologies Used  - C++,Pthreads
Matrix Multiplication , Strassen's matrix multiplication
Horse Pool , Boyer Moore, Rabin Karp, KMP, Suffix Tree Pattern Matching

# Matrix Multiplication
a - Standard inner product based row-col multiplication algorithm. (sourcecode = S1, result = M1, Time taken = T1) 

b - O(n^3) Divide-n-Conquer strategy-based multiplication algorithm. (sourcecode = S2, result = M2, Time taken = T2)

c - Strassen's recursive divide-n-conquer strategy-based algorithm. (sourcecode = S3, result = M3, Time taken = T3)

d - Parallelize O(n^3) Divide-n-Conquer strategy-based multiplication algorithm. (sourcecode = S4, result = M4, Time taken = T4)

e - Parallelize Strassen's recursive divide-n-conquer strategy-based algorithm. (sourcecode = S5, result = M5, Time taken = T5)

# STring Matching

Run First.cpp 

__ Find_Length_of _Text( txtfile)   

// normalize multiple blank chars to

// single blank char and remove(store)

// website URLS that have infected

// text file using FSA based RegEx

//  matcher

__Find_Pattern ( pattern , InTextRange,  algo)     

// Find the number of occurrences of

// pattern using any one of the

//  following  algorithms (2nd parameter)

//  Rabin-Karp,  Knuth_Morris_Pratt

//  Suffix Tree (with Suffix arrays & LCP)

//   InTextRange : can be  indices or

//    two patterns (e.g two story titles)

__Build_Cross_Index(txtfile, algo)//  Build an Index (Lex sorted)
  
  // (Word, Number of occurrences,  
  
  //   List of Story Titles & # of
  
  //   occurrences of Word)
  
  __Find_Maximal,Palindromes(PalindromeSize,  InTextRange )
    
    // List maximal palindromes of size
    
    // greater than or equal to
    
    //  PalindromeSize, with occurrences   (Story titles and  indices )                                            

            
            
__Print_Stats ( )

// Text Size used,  URL infection  list    found,  

//  Algo Used, Preprocessing time, Search time                        

// (Vary  the parameters pattern ,

//  InTextRange ) for timing plot

//  and Self Test & Verification outcome
