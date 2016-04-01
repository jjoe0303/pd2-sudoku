#include <iostream>
#include "Sudoku.h"

using namespace std;

void Sudoku::readIn(){
	for(int i=0;i<Sudokusize;++i)
	cin>>map[i]; //input 81 digits by player OMG!!
}

void Sudoku::giveQuestion(){
	int question[Sudokusize]={0,0,0,2,3,0,0,0,5
							  0,4,2,0,9,0,0,0,3
							  3,0,0,0,0,8,7,0,0
					 	      0,0,7,0,0,0,0,5,6
							  0,9,0,7,2,0,0,1,4
							  5,0,0,9,0,0,0,0,0
						      6,0,0,0,0,2,8,4,9
						 	  0,0,8,0,0,1,0,0,7
						      2,5,0,0,0,9,6,0,0};//set the table
	for(int i=0;i<Sudokusize;++i){
		printf("%d%c",question[i],(i+1)%9==0?"\n":" " );
	}
}

void Sudoku::changeNum(int a,int b){
	for(int i=0;i<Sudokusize;++i){
		if(map[i]==a){
			map[i]=b; //just chage a&b 's position
		}
		if(map[i]==b){
			map[i]=a;
		}
	}
}

void Sudoku::changeRow(int a,int b){
	int remain;  //remain last value
	for(int i=0;i<(Sudoku/3);++i){
		remain=map[27*a+i];
		map[27*a+i]=map[27*b+i]; //a&b row  switch
		map[27*b+i]=remain;
	}
}

void Sudoku::changeCol(int a,int b){
	int remain;
	for(int i=0;i<9;++i){	//have 9 row
		for(int j=0;j<3;++j){ //we have 3 num as a set
			remain=map[3*a+j+9*i];
			map[3*a+j+9*i]=map[3*b+j+9*i];
			map[3*b+j+9*i]=remain;
		}
	}
}

void Sudoku::rotate(int n){
	if(n%4==1){ //rotate 90 degree
		int in_array[9][9],out_array[9][9];
		for(int k=0;k<81;++k){
			in_array[k/9][k%9]=map[k]; //1D to 2D
		}
		
		int p=0;
		for(int i=8;i>=0;i--){
			for(int j=0;j<9;j++){
				out_array[j][p]=in_array[i][j]; //out_arr=in_arr rotate 90
			}
			p++;
		}
		
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				map[i*9+j]=out_array[i][j]; //2D to 1D
			}
		}
	}

	if(n%4==2){  //rotate 180 degree
       int in_array[9][9],out_array[9][9];
 	   for(int k=0;k<81;++k){
             in_array[k/9][k%9]=map[k]; //1D to 2D
         }        
	  
	   int p=0;
       for(int i=8;i>=0;i--){
	        for(int j=0;j<9;j++){
	   			out_array[j][p]=in_array[i][j]; //out_arr=in_arr rotate  90
			}   
		}

	   for(int i=0;i<9;i++){
		   for(int j=0;j<9;j++){
			   in_array[i][j]=out_array[i][j]; //let in_array remain value for next rotate
		   }
	   }

	   int p2=0;
	   for(int i=8;i>=0;i--){
		   for(int j=0;j<9;j++){
			   out_array[j][p]=in_array[i][j]; //rotate 90 degree again
		   }
		   p2++;
	   }

	   for(int i=0;i<9;i++){
		   for(int j=0;j<9;j++){
			   map[i*9+j]=out_array[i][j];
		   }
	   }
	 }

	if(n%4==3){ //rotate 270 degree
		       int in_array[9][9],out_array[9][9];
		         for(int k=0;k<81;++k){
		             in_array[k/9][k%9]=map[k]; //1D to 2D
		         }
		       
		         int p=0;
		         for(int i=8;i>=0;i--){
		             for(int j=0;j<9;j++){
		                 out_array[j][p]=in_array[i][j]; //out_arr=in_arr rotate 90
		             }
		             p++;
			   	  }  
				 
				 for(int i=0;i<9;i++){
					 for(int j=o;j<9;j++){
						 in_array[i][j]=out_array[i][j];
					 }
				 }

    	  		 int p2=0; 
	 	  		 for(int i=8;i>=0;i--){
		      		 for(int j=0;j<9;j++){
		      	 	   out_array[j][p]=in_array[i][j]; //rotate 90 degree again
		      		  }
		      		  p2++;
				  }

				 for(int i=0;i<9;i++){
					 for(int j=0;j<9;j++){
						 in_array[i][j]=out_array[i][j];
					 }
				 }

				 int p3=0;
				for(int i=8;i>=0;i--){
					for(int j=0;j<9;j++){
						out_array[j][p]=in_array[i][j];
					}
					p3++;
				}

				for(int i=0;i<9;i++){
					for(int j=0;j<9;j++){
						map[i*9+j]=out_array[i][j];
					}
				}
	}

	if(n%4==0)   {return;} //no rotate
}


