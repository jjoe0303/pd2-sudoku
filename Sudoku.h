#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Sudoku{
	public:
		void giveQuestion();
		void readIn();
		void solve();
		void changeNum(int a,int b);
		void changeRow(int a,int b);
		void changeCol(int a,int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		void change();
		void printOut(bool isAns);
		static const int Sudokusize=81;
	private:
		int map[Sudokusize];
