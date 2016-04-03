//#include <iostream>
//#include <stdio.h>
//#include <cstdlib>
#include "Sudoku.h"

using namespace std;

void Sudoku::readIn(){
	for(int i=0;i<Sudokusize;++i)
	cin>>map[i]; //input 81 digits by player OMG!!
}

void Sudoku::giveQuestion(){
	int question[81]={0,0,0,2,3,0,0,0,5,
							  0,4,2,0,9,0,0,0,3,
							  3,0,0,0,0,8,7,0,0,
					 	      0,0,7,0,0,0,0,5,6,
							  0,9,0,7,2,0,0,1,4,
							  5,0,0,9,0,0,0,0,0,
						      6,0,0,0,0,2,8,4,9,
						 	  0,0,8,0,0,1,0,0,7,
						      2,5,0,0,0,9,6,0,0};//set the table
	for(int i=0;i<81;++i){
		printf("%d%c",question[i],(i+1)%9==0?'\n':' ' );
	}
}

void Sudoku::changeNum(int a,int b){
	for(int i=0;i<Sudokusize;++i){
		if(map[i]==a){
			map[i]=b;continue; //just chage a&b 's position
		}
		if(map[i]==b){
			map[i]=a;continue;
		}
	}
}

void Sudoku::changeRow(int a,int b){
	int remain;  //remain last value
	for(int i=0;i<(Sudokusize/3);++i){
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
/*       int in_array[9][9],out_array[9][9];
 	   for(int k=0;k<81;++k){
             in_array[k/9][k%9]=map[k]; //1D to 2D
         }        
	  
	   int p=0;
       for(int i=8;i>=0;i--){
	        for(int j=0;j<9;j++){
	   			out_array[j][p]=in_array[i][j]; //out_arr=in_arr rotate  90
			}   
			p++;
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
	   }*/   //can't  use GG
		flip(0);  //flip twice the we can gain 180 degree rotate
		flip(1);
	 }

	if(n%4==3){ //rotate 270 degree
		       int in_array[9][9],out_array[9][9];
		         for(int k=0;k<81;++k){
		             in_array[k/9][k%9]=map[k]; //1D to 2D
		         }
		       
		         int p=0;
		         for(int i=8;i>=0;i--){
		             for(int j=0;j<9;j++){
		                 out_array[i][j]=in_array[j][p]; //out_arr=in_arr rotate 90(counterclockwise)
		             }
		             p++;
			   	  }  
				 
			/*	 for(int i=0;i<9;i++){
					 for(int j=0;j<9;j++){
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
*/    //can't use
				for(int i=0;i<9;i++){
					for(int j=0;j<9;j++){
						map[i*9+j]=out_array[i][j];
					}
				}
	}

	if(n%4==0)   {return;} //no rotate
}

void Sudoku::flip(int n){
	int i,j;
	int tmp[81];
	if(n%2==0){		
		for(i=0;i<5;i++){
			for(j=0;j<9;j++){
				tmp[9*j+i]=map[9*j+i]; //swap
				map[9*j+i]=map[9*(j+1)-1-i];
				map[9*(j+1)-1-i]=tmp[9*j+i];
			}
		}
	}

	if(n%2==1){
		for(i=0;i<5;i++){
			for(j=0;j<9;j++){
				tmp[9*i+j]=map[9*i+j];  //swap
				map[9*i+j]=map[9*(9-1-i)+j];
				map[9*(9-1-i)+j]=tmp[9*i+j];
			}
		}
	}
}

void Sudoku::transform(){
	change();
	printOut();
}

void Sudoku::change(){
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}

/*void Sudoku::printOut(bool isAns){
	int i;
	if(!isAns){
		for(i=0;i<Sudokusize;++i){
			printf("%d%c",map[i],(i+1)%9==0?'\n':' ');
		}
	}
	else
		for(i=0;i<Sudokusize;++i){
			printf("%d%c",ans[i],(i+1)%9==0?'\n':' ');
		}
}*/

void Sudoku::printOut(){
	for(int i=0;i<81;++i){
		printf("%d%c",map[i],(i+1)%9==0?'\n':' ');
	}
}


bool Sudoku::isPlace(int count){
	int row=count/9;
	int col=count%9;
	int i,j;
	
	for(i=0;i<9;++i){
		if(board[row][i]==board[row][col] && i!=col){ //check row
			return false;
		}
	}

	for(i=0;i<9;++i){
		if(board[i][col]==board[row][col] && i!=row){ //check column
			return false;
		}
	}

	int tmprow=row/3*3;
	int tmpcol=col/3*3;
	for(i=tmprow;i<tmprow+3;++i){
		for(j=tmpcol;j<tmpcol+3;++j){
			if(board[i][j]==board[row][col] && i!=row && j!=col){  //check mesh
				return false;
			}
		}
	}
	return true;
}

void Sudoku::backtrace(int count){
	if(times<0){return;}
	if(times>1){return;}
	if(count==81){
		++times;
		if(times>1){return;}	
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				ans[i][j]=board[i][j];
			}
		}
		return;
	}

	int row=count/9;
	int col=count%9;
	if(board[row][col]==0){
		for(int i=1;i<=9;++i){
			board[row][col]=i;   //give value
			if(isPlace(count)){   //this position ok
				backtrace(count+1);  //next position
			}
		}
		board[row][col]=0; //back
	}

	else{
		backtrace(count+1);
	}
}

void Sudoku::solve(){
	times=0;
        for(int i=0;i<81;++i){
                board[i/9][i%9]=map[i]; //1D to 2D
        }
	checkzero();
	backtrace(0); //solve
	if(times<=0){cout<<'0'<<endl; return;};
	if(times>1) {cout<<'2'<<endl; return;};
	cout<<times<<endl;
	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

/*	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j){
			ans[9*i+j]=board[i][j]; //remain answer in ans[ ]
		}
	}*/

/*	for(int i=0;i<9;++i){
		for(int j=0;j<9;++j){
			cout<<board[i][j]<<" ";
		}
	cout<<endl;
}*/

/*	for(int i=0;i<81;++i){
		printf("%d%c",ans[i],(i+1)%9==0?'\n':' '); //print it out

	}*/
}	

void Sudoku::checkzero(){
	int zero=0;
	for(int i=0;i<81;++i){
		if(map[i]==0){ ++zero;}
	}
	if(zero==0){return;}
	for(int i=0;i<81;++i){
		if(map[i]!=0){	
			if(isPlace(i)) {continue;}	
			else {times=-1;return;}
		}
	if(zero>77){times=2;}
	}
}
	
