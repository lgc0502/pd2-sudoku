#include<cstdlib>
#include<iostream>
#include<cstdio>
using namespace std;
class Sudoku{
 	public:
 		void giveQuestion(); 			  //output 81 digits
 
 		void readIn(); 					  //input 81 digits/no output

 		int solve();		//no input (use the one in `readIn()`) / output your answer
 		void sol1(int r,int c);
		void sol2(int r,int c);
		int crow(int r,int num);
		int ccol(int c,int num);
 		int ccell(int r,int c,int num);
 		int checkmap();
 	
	 	int changeNum(int a, int b);	  //no input / no output
 		int changeRow(int a, int b);	  //no input / no output
 		int changeCol(int a,int b);		  //no input / no output
 		int rotate(int n); 				  //no input / no output
		int flip(int n); 				  //no input / no output
 		
		 int transform(); 				  //no input (use the one in `readIn()`) / output 81 digits
 		void change();
 		void printOut();
		
 		
	 private:
 		int s[9][9];
 		int re[9][9];
 		int ori[9][9];
 		int g[9][9];
 		int map[9][9];
 		int ans;
};
