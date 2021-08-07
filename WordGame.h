#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<vector>
#pragma once

using namespace std;

class wordGame
{
public:
				void setBoard();
				void fileOpen();
				void fileClose();
				void wordCheck();
				void boardCpy();
				bool Walk(int x, int y, int pos);
				bool wordCheck(string str);
				/*void setPath(int length);
				bool insertPath(int x, int y,int pos);
				int searchPath(int x,int y);*/

private:
				//vector<vector<int>> path;
				vector<string> used;
				char board[4][4];
				char temp_board[4][4];
				fstream file;
				string word;

};