#include"WordGame.h"

void wordGame::setBoard()
{
				for (int i = 0; i < 4; i++)
				{
								for (int j = 0; j < 4; j++)
								{
												cin >> board[i][j];
												//cout << board[i][j];
								}
								//cout << "\t";
				}

}

void wordGame::fileOpen()
{
				file.open("words.txt", ios::in);
}

void wordGame::fileClose()
{
				file.close();
}
void wordGame::wordCheck()
{				
				/*for (int i = 0; i < 10; i++)
				{
								string str;
								file >> str;
								cout << str << "\t";
				}*/
				while (file >> word)
				{
								//setPath(word.length());
								boardCpy();
								for (int y = 0; y < 4; y++)
								{
												for (int x = 0; x < 4; x++)
												{
																if (temp_board[y][x] == word[0])
																{
																				//insertPath(x, y, 0);
																				temp_board[y][x] = ' ';
																				if (Walk(x + 1, y, 1) ||//1,0
																								Walk(x + 1, y + 1, 1) ||//1,1
																								Walk(x, y + 1, 1) ||//0,1
																								Walk(x - 1, y + 1, 1) ||//-1,1
																								Walk(x - 1, y, 1) ||//-1,0
																								Walk(x - 1, y - 1, 1) ||//-1,-1
																								Walk(x, y - 1, 1) ||//0,-1
																								Walk(x + 1, y - 1, 1)//1,-1
																								)
																				{
																								if (!wordCheck(word))
																								{
																												used.push_back(word);
																												cout << word << endl;
																								}
																				}
																}
												}
								}
				}
}
bool wordGame::Walk(int x, int y, int pos)
{
				if (x < 0 || y < 0 || x >= 4 || y >= 4)
								return 0;
				if (temp_board[y][x] != word[pos])
								return 0;
				if (temp_board[y][x] == word[pos] && pos == word.length() - 1)
				{
								temp_board[y][x] = ' ';
								return 1;
				}
				if (temp_board[y][x] == word[pos] && pos != word.length() - 1)
				{
								temp_board[y][x] = ' ';
								if (Walk(x + 1, y, pos + 1) ||//1,0
												Walk(x + 1, y + 1, pos + 1) ||//1,1
												Walk(x, y + 1, pos + 1) ||//0,1
												Walk(x - 1, y + 1, pos + 1) ||//-1,1
												Walk(x - 1, y, pos + 1) ||//-1,0
												Walk(x - 1, y - 1, pos + 1) ||//-1,-1
												Walk(x, y - 1, pos + 1) ||//0,-1
												Walk(x + 1, y - 1, pos + 1)//1,-1
												)
								{
												
												return 1;
								}
				}
				return 0;
}
void wordGame::boardCpy()
{
				for (int i = 0; i < 4; i++)
				{
								for (int j = 0; j < 4; j++)
								{
												temp_board[i][j] = board[i][j];
								}
				}
}

bool wordGame::wordCheck(string str)
{
				vector<string>::iterator index;
				index = find(used.begin(), used.end(), str);
				if (index == used.end())
								return 0;
				else
								return 1;
}


/*bool wordGame::insertPath(int x, int y, int pos)
{
				if (path.size() <= pos)
				{
								return 0;
				}
				path[pos][0] = x;
				path[pos][1] = y;
				return 1;
}

int wordGame::searchPath(int x, int y)
{
				int i;
				for (i = 0; i < path.size(); i++)
				{
								if (path[0][i] == x && path[1][i] == y)
												return i;
				}
				return i;
}

void wordGame::setPath(int length)
{
				path.resize(length);
				for (int i = 0; i < length; i++)
				{
								path[i].resize(2);
				}
}*/
