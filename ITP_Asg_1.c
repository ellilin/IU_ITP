#include <stdio.h>
#include <stdlib.h>
 
int main (){
  int n, m, b[30]={0}, m1, m2;					// m1,m2 - exstra ints for cheking chars in string, array b for cheking ints in a to do not have the same digits
  char alf[26] = "abcdefghijklmnopqrstuvwxyz";			//string for easy exchanging chars in string S
  
  FILE *in, *out;						//"making" files, opening etc.
  in = fopen("input.txt", "r");
  out = fopen("output.txt", "w");
  
  fscanf (in, "%i", &n);					//reading N
  if(n > 50 || n < 2){
  	fprintf(out, "Invalid inputs");				//cheking if N is out of bounds (if yes, programm will be finished and output file will have message about incorrect data)
    	return 0;
  }
  char s[n];
  
  fscanf (in, "%s", s);						//reading string S
  
  for(int i = 0; i < n; i++){
  	m=s[i]-'a';						//cheking is string includes only right chars (if yes, programm will be finished and output file will have message about incorrect data)
  	m1=s[i]-'A';						//-57, -56, ... , -3 codes of ()*!@#$%&^ (same order)
  	m2=s[i]-'0';						
  	if((m < 0 || m > 26) && (m != -57 && m != -56 && m != -55 && m != -64 && m != -33 && m != -62 && m != -61 && m != -60 && m != -59 && m != -3)&&(m1 < 0 || m1 > 26) && (m2 < 0 || m2 > 9)){
  		fprintf(out, "Invalid inputs");
    		return 0;
  	}
 }
 	
  fscanf (in, "%i", &m);					//reading M
  
  if(m < 1 || m > n || m > 26){					//cheking if M is out of bounds (if yes, programm will be finished and output file will have message about incorrect data)
  	fprintf(out, "Invalid inputs");
    	return 0;
  }
  
  int a[m];
  
  for (int i = 0; i < m; i++){
      fscanf (in, "%i", &a[i]);					//reading array A
      
      if(a[i] >= n || a[i] > 26 || a[i] < 1){			//cheking if A[i] if out of bounds (if yes, programm will be finished and output file will have message about incorrect data)
      	fprintf(out, "Invalid inputs");
    	return 0;
      	}
      	
      if(b[a[i]] != 0){						//cheking if in A[i] same numbers (if yes, programm will be finished and output file will have message about incorrect data)
      	fprintf(out, "Invalid inputs");
    	return 0;
      }
      b[a[i]]=10;
      
      s[a[i]] = alf[a[i] - 1];					//changing chars in string S
 }
 
  fprintf (out, "%s", s);					//printing answer in output file
  
  fclose (in);							//closing files
  fclose (out);
  
  return 0;
}
 
