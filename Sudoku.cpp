#include<iostream>
#include<cstdio>
#include<cstdlib>
#include"Sudoku.h"
#include<ctime>

//output 81 digits
void Sudoku::giveQuestion(){
	int i,j;
	int g[9][9]={{5,3,0,0,7,0,0,0,0},
				 {6,0,0,1,9,5,0,0,0},
				 {0,9,8,0,0,0,0,6,0},
				 {8,0,0,0,6,0,0,0,3},
				 {4,0,0,8,0,3,0,0,1},
				 {7,0,0,0,2,0,0,0,6},
				 {0,6,0,0,0,0,2,8,0},
				 {0,0,0,4,1,9,0,0,5},
				 {0,0,0,0,8,0,0,7,9}};
	for(j=0;j<9;j++){
		for(i=0;i<9;i++){
			printf("%d ",g[j][i]);
		}
		printf("\n");
	}
}


//input 81 digits/no output
void Sudoku::readIn(){
	int A;
	int i,j;
	for(int j=0;j<9;j++){
		for(int i=0;i<9;i++){
			scanf("%d",&s[j][i]);
		}
	}
} 					 

int Sudoku::crow(int r,int num){
	int c;
	for(c=0;c<9;c++){
    	if(s[r][c]==num){
			return 0 ;
		}
	}
	return 1;
}
int Sudoku::ccol(int c,int num){
	int r;
	for(r=0;r<9;r++){
		if(s[r][c]==num){
			return 0;
		}
	}
    return 1;	
}
int Sudoku::ccell(int r,int c,int num){
	r=(r/3)*3 ;
	c=(c/3)*3;
	int i,j;
	for(j=0;j<3;j++){
    	for(i=0;i<3;i++){
         	if(s[r+j][c+i]==num){
            	return 0;
			}
		}
	}
	return 1;
}

void Sudoku::sol1(int r,int c){
	int i,j;
	int num;
	if(r>8){
		for(j=0;j<9;j++){
			for(i=0;i<9;i++){
				re[j][i]=s[j][i];
			}
		}
	}
	if(s[r][c]!=0){
		if(c<8)
			Sudoku::sol1(r,c+1);
		else
      		Sudoku::sol1(r+1,0);
	}
	else{
		for(num=1;num<=9;num++){
				if((crow(r,num)==1)&&(ccol(c,num)==1)&&(ccell(r,c,num)==1)){
					s[r][c]=num;
			
					if(c<8)
						Sudoku::sol1(r,c+1);
					else
      					Sudoku::sol1(r+1,0);
				}
			}
			s[r][c]=0;
	}
}

void Sudoku::sol2(int r,int c){
	int i,j;
	int num;
	
	if(r>8){
		for(j=0;j<9;j++){
			for(i=0;i<9;i++){
				ori[j][i]=s[j][i];
			}
		}
	}
	if(s[r][c]!=0){
		if(c<8)
			Sudoku::sol2(r,c+1);
		else
      		Sudoku::sol2(r+1,0);
	}
	else{
		for(num=9;num>=1;num--){
				if((crow(r,num)==1)&&(ccol(c,num)==1)&&(ccell(r,c,num)==1)){
					s[r][c]=num;
			
					if(c<8)
						Sudoku::sol2(r,c+1);
					else
      					Sudoku::sol2(r+1,0);
				}
			}
			s[r][c]=0;
	}
}
int Sudoku::checkmap(){
	int i,j,o,n=0;
	//check row
	for(j=0;j<9;j++){
		for(o=1;o<=9;o++){
			for(i=0;i<9;i++){
				if(s[j][i]==o){
					n++;
				}
			}
			if(n>=2){
				return 0;
			}
			n=0;
		}
	}
	for(j=0;j<9;j++){
		for(o=1;o<=9;o++){
			for(i=0;i<9;i++){
				if(s[i][j]==o){
					n++;
				}
			}
			if(n>=2){
				return 0;
			}
			n=0;
		}
	}
	for(o=1;o<=9;o++){
		for(j=0;j<3;j++){
			for(i=0;i<3;i++){
				if(s[0+j][0+i]==o){
					n++;
				}
				
			}
		}
		if(n>=2){
				return 0;
			}
			n=0;
	}
	for(o=1;o<=9;o++){
		for(j=0;j<3;j++){
			for(i=0;i<3;i++){
				if(s[0+j][3+i]==o){
					n++;
				}
				
			}
		}
		if(n>=2){
				return 0;
			}
			n=0;
	}
	for(o=1;o<=9;o++){
		for(j=0;j<3;j++){
			for(i=0;i<3;i++){
				if(s[0+j][6+i]==o){
					n++;
				}
				
			}
		}
		if(n>=2){
				return 0;
			}
			n=0;
	}
	for(o=1;o<=9;o++){
		for(j=0;j<3;j++){
			for(i=0;i<3;i++){
				if(s[3+j][0+i]==o){
					n++;
				}
				
			}
		}
		if(n>=2){
				return 0;
			}
			n=0;
	}
	for(o=1;o<=9;o++){
		for(j=0;j<3;j++){
			for(i=0;i<3;i++){
				if(s[3+j][3+i]==o){
					n++;
				}
				
			}
		}
		if(n>=2){
				return 0;
			}
			n=0;
	}
	for(o=1;o<=9;o++){
		for(j=0;j<3;j++){
			for(i=0;i<3;i++){
				if(s[3+j][6+i]==o){
					n++;
				}
				
			}
		}
		if(n>=2){
				return 0;
			}
			n=0;
	}
	for(o=1;o<=9;o++){
		for(j=0;j<3;j++){
			for(i=0;i<3;i++){
				if(s[6+j][0+i]==o){
					n++;
				}
				
			}
		}
		if(n>=2){
				return 0;
			}
			n=0;
	}
	for(o=1;o<=9;o++){
		for(j=0;j<3;j++){
			for(i=0;i<3;i++){
				if(s[6+j][3+i]==o){
					n++;
				}
				
			}
		}
		if(n>=2){
				return 0;
			}
			n=0;
	}
	for(o=1;o<=9;o++){
		for(j=0;j<3;j++){
			for(i=0;i<3;i++){
				if(s[6+j][6+i]==o){
					n++;
				}
				
			}
		}
		if(n>=2){
				return 0;
			}
			n=0;
	}

	return 1;
}

int Sudoku::solve(){
	int yee=0;
	int e=0;
	int i,j;
	
	
	
		for(j=0;j<9;j++){
			for(i=0;i<9;i++){
				if(s[j][i]!=0){
						e++;
				}	
			}	
		}
		if(e<17){
			if(Sudoku::checkmap()==0){
				cout<<"0\n";
			}
			else
			cout<<"2\n";			
		}
		else{
	
		Sudoku::sol1(0,0);
		for(j=0;j<9;j++){
			for(i=0;i<9;i++){
				if(re[j][i]==0){
					cout<<"0\n";
					return 0;
				}	
			}	
		}
		Sudoku::sol2(0,0);

		for(j=0;j<9;j++){
			for(i=0;i<9;i++){
				if(ori[j][i]!=re[j][i]){
					yee++;
				}		
			}			
		}
	
		if(yee==0){
			cout<<"1\n";
			for(j=0;j<9;j++){
				for(i=0;i<9;i++){
					cout<<re[j][i]<<" ";
				}
				cout<<"\n";
			}
		}
		else{
			cout<<"2\n";
		}
	//}
		}
	
}
//no input / no output
int Sudoku::changeNum(int a, int b){
	int p=10;
	int i,j,k;
	if(a>=1&&a<=9&&b>=1&&b<=9&&a!=b){
		for(j=0;j<9;j++){
			for(i=0;i<9;i++){
				if(s[j][i]==a){
					s[j][i]=10;
				}
			}
		}

		for(j=0;j<9;j++){
			for(i=0;i<9;i++){
				if(s[j][i]==b){
					s[j][i]=a;
				}
			}
		}

		for(j=0;j<9;j++){
			for(i=0;i<9;i++){
				if(s[j][i]==10){
					s[j][i]=b;
				}
			}
		}

		return s[9][9];
	}

	else
		return 0;
}

//no input / no output
int Sudoku::changeRow(int a, int b){
	int p1[9];
	int p2[9];
	int p3[9];
	int i,j,k;
	if(a>=0&&a<=2&&b>=0&&b<=2&&a!=b){
		if((a==0&&b==1)||(a==1&&b==0)){
			for(i=0;i<9;i++){
				p1[i]=s[0][i];	
				p2[i]=s[1][i];
				p3[i]=s[2][i];
			}
			for(i=0;i<9;i++){
				s[0][i]=s[3][i];
				s[1][i]=s[4][i];
				s[2][i]=s[5][i];
			}
			for(i=0;i<9;i++){
				s[3][i]=p1[i];
				s[4][i]=p2[i];
				s[5][i]=p3[i];
			}  
		}
		if((a==0&&b==2)||(a==2&&b==0)){
			for(i=0;i<9;i++){
				p1[i]=s[0][i];
				p2[i]=s[1][i];
				p3[i]=s[2][i];

			}
			for(i=0;i<9;i++){
				s[0][i]=s[6][i];
				s[1][i]=s[7][i];
				s[2][i]=s[8][i];
			}
			for(i=0;i<9;i++){
				s[6][i]=p1[i];
				s[7][i]=p2[i];
				s[8][i]=p3[i];
			}
		}
		
		if((a==2&&b==1)||(a==1&&b==2)){
			for(i=0;i<9;i++){
				p1[i]=s[3][i];
				p2[i]=s[4][i];
				p3[i]=s[5][i];
			}
			for(i=0;i<9;i++){
				s[3][i]=s[6][i];
				s[4][i]=s[7][i];
				s[5][i]=s[8][i];
			}
			for(i=0;i<9;i++){
				s[6][i]=p1[i];
				s[7][i]=p2[i];
				s[8][i]=p3[i];
			}     
		}
		return 0;
	}
	else
		return 0;
}
	

//no input / no output
int Sudoku::changeCol(int a,int b){
	int p1[9];
	int p2[9];
	int p3[9];
	int i,j,k;
	if(a<=2&&a>=0&&b<=2&&b>=0&&a!=b){
		if((a==0&&b==1)||(a==1&&b==0)){
			for(i=0;i<9;i++){
				p1[i]=s[i][0];
				p2[i]=s[i][1];
				p3[i]=s[i][2];
			}
			for(i=0;i<9;i++){
				s[i][0]=s[i][3];
				s[i][1]=s[i][4];
				s[i][2]=s[i][5];
			}
			for(i=0;i<9;i++){
				s[i][3]=p1[i];
				s[i][4]=p2[i];
				s[i][5]=p3[i];
			}
		}
		if((a==0&&b==2)||(a==2&&b==0)){
			for(i=0;i<9;i++){
				p1[i]=s[i][0];
				p2[i]=s[i][1];
				p3[i]=s[i][2];
			}
			for(i=0;i<9;i++){
				s[i][0]=s[i][6];
				s[i][1]=s[i][7];
				s[i][2]=s[i][8];
			}
			for(i=0;i<9;i++){
				s[i][6]=p1[i];
				s[i][7]=p2[i];
				s[i][8]=p3[i];
			}        
		}
		if((a==1&&b==2)||(a==2&&b==1)){					
			for(i=0;i<9;i++){
				p1[i]=s[i][3];
				p2[i]=s[i][4];
				p3[i]=s[i][5];
			}
			for(i=0;i<9;i++){
				s[i][3]=s[i][6];
				s[i][4]=s[i][7];
				s[i][5]=s[i][8];
			}
			for(i=0;i<9;i++){
				s[i][6]=p1[i];
				s[i][7]=p2[i];
				s[i][8]=p3[i];
			}
		} 
		return 0;	      
	}
	else
		return 0;
}
 

//no input / no output
int Sudoku::rotate(int n){
	int i,j,k;
	if(n>=0&&n<=100){
		if(n%4==0){
			return 0;
		}
		if(n%4==1){
			int h=0;
			int k=0;
			int p1[90];
			for(i=0;i<9;i++){
				for(j=8;j>=0;j--){
					p1[h]=s[j][i];
					h++;
				}																								            
			}
			for(j=0;j<9;j++){
				for(i=0;i<9;i++){
					s[j][i]=p1[k];
					k++;
				}
			}
			return 0;
		}
		if(n%4==2){
			int h=0;
			int k=0;
			int p2[90];
			for(j=8;j>=0;j--){
				for(i=8;i>=0;i--){
					p2[h]=s[j][i];
					h++;
				}
			}
			for(j=0;j<9;j++){
				for(i=0;i<9;i++){
					s[j][i]=p2[k];
					k++;
				}
			}
			return 0;
		}
		if(n%4==3){
			int h=0;
			int k=0;
			int p3[90];
			for(j=8;j>=0;j--){
				for(i=0;i<9;i++){
					p3[h]=s[i][j];
					h++;
				}
			}
			for(j=0;j<9;j++){
				for(i=0;i<9;i++){
					s[j][i]=p3[k];
					k++;
				}
			}
			return 0;
		}
	}
}
//no input / no output
int Sudoku::flip(int n){
	int p1[90];
	int p2[90];
	int h1=0;
	int h2=0;
	int k1=0;
	int k2=0;
	int i,j,k;
	if(n==0){
		for(j=8;j>=0;j--){
			for(i=0;i<9;i++){
				p1[h1]=s[j][i];
				h1++;
			}
		}
		for(j=0;j<9;j++){
			for(i=0;i<9;i++){
				s[j][i]=p1[h2];
				h2++;
			}
		}
		return 0;
	}
	if(n==1){
		for(j=0;j<9;j++){
			for(i=8;i>=0;i--){
				p2[k1]=s[j][i];
				k1++;
			}
		}
		for(j=0;j<9;j++){
			for(i=0;i<9;i++){
				s[j][i]=p2[k2];
				k2++;
			}
		}
		return 0;
	}
}

//no input (use the one in `readIn()`) / output 81 digits
int Sudoku::transform(){
	Sudoku::change();
	int i,j;
	for(j=0;j<9;j++){
		for(i=0;i<9;i++){
			printf("%d ",s[j][i]);
		}	
		cout<<"\n";
	}
	return 0;
}
void Sudoku::change(){
	srand(time(NULL));
	Sudoku::changeNum(rand()%9,rand()%9);
	Sudoku::changeRow(rand()%3,rand()%3);
	Sudoku::changeCol(rand()%3,rand()%3);
	Sudoku::rotate(rand()%101);
	Sudoku::flip(rand()%2); 
}

