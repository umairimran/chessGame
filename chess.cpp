#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
void displayBoard(char chess[8][8]);
void killPlayer(char chessBoard[8][8], int  r1, int  c1, int  r2, int c2);
int findRow(char moves);
int findCol(char moves);
void swapTurns(char chessBoard[8][8], int r1, int c1, int r2, int c2);
bool checkk( char chessBoard[8][8], bool turn,int r2,int c2);
void promotion(char chessBoard[8][8],int r1,int c1,int r2,int c2,char promo);
void save(char chessBoard[8][8]);
void load(char chessBoard[8][8]);



int main()
{
	
	

	char chessBoard[8][8] =
	{
		{'N','N','B','Q','K','B','N','R'},
		{'P','P','P','P','P','P','P','P'},
		{' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' '},
		{'p','p','p','p','p','p','p','p'},
		{'r','n','b','q','k','b','n','r'}
		
	};

	char loadd;
	cout << endl;
	cout << "   (S)ave   " << "   (L)oad    ";
	cout << endl;
	cin >> loadd;
	cin.ignore();
	if (loadd == 'L')
	{
		load(chessBoard);
	}
	bool endGame = 1;
	while (endGame == 1)
	{
		/*save(chessBoard);*/
		/*system("CLS");*/
		displayBoard(chessBoard);

		bool turn;
		int r1;
		int c1;
		int r2;
		int c2;
		cout << endl;
		cout << "   (S)ave   " << "   (L)oad    ";
		cout << endl;

		char moves[5];
		if (turn = 1)
		{
			turn = 0;


			bool checkMove = 1;
			while (checkMove == 1)
			{
				/*system("CLS");*/
				/*displayBoard(chessBoard);*/
				cout << "This is the turn of white player\n";
				cout << "Enter your move :\n";
				cin.get(moves, 5);
				cin.ignore();
				
				r1 = findRow(moves[0]);
				c1 = findCol(moves[1]);
				r2 = findRow(moves[2]);
				c2 = findCol(moves[3]);
				cout << r1;
				cout << c1;
				cout << r2;
				cout << c2;
				/*for (int i = 0; i < 4; i++)
					game >> moves[i];*/

				if (moves[0] <= 56 && moves[0] >= 49 && moves[1] >= 97 && moves[1] <= 104 && moves[2] <= 56 && moves[2] >= 49 && moves[3] >= 97 && moves[3] <= 104 && chessBoard[r1][c1] >= 65 && chessBoard[r1][c1] <= 90)
				{

					/*	pawn move*/


					if (chessBoard[r1][c1] == 'P')
					{
						if (r2 == r1 + 1 && c2 == c1)
						{/*pawn promotion*/
							if (r2 == 7)
							{
								char promo;
								cout << "Your pawn is being promoted\n";
								cout << "Select which one do you replace \n";
								cout << "enter Q for queen\n enter B for bishop\n enter R for rook \n enter N for knight\n";
								cin>>promo; 
								cin.ignore();checkMove = 0;
								promotion(chessBoard, r1, c1, r2, c2, promo);
								system("CLS");
								displayBoard(chessBoard);
								
								
							}
							
							
								if (chessBoard[r2][c2] == ' ' && checkMove==1)
								{
									swapTurns(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							
							
						}
						else 	if (r2 == r1 + 1 && c2 == c1 - 1)
						{
							if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122)
							{
								if(chessBoard[r2][c2]=='k')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over White wins\n";
									return 0;
								}
								else
								{
								killPlayer(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								}
								
							}
						}
						else 	if (r2 == r1 + 1 && c2 == c1 + 1)
						{
							if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122)
							{
								if (chessBoard[r2][c2] == 'k')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over White wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
								}
							}
						}
						else if (r2 == r1 + 2 && r1 == 1)
						{
							if (chessBoard[r2][c2] == ' ' && checkMove == 1)
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}
						}
						else

						{

							system("CLS");
							displayBoard(chessBoard);
							cout << "This is an invalid move:\n";

						}

					}
					/*rook*
/*this bool is to check previous positions before destination */

					bool rookCheck = 1;
					if (chessBoard[r1][c1] == 'R')
					{
						if (r2 == r1 - 1 || r2 == r1 - 2 || r2 == r1 - 3 || r2 == r1 - 3 || r2 == r1 - 4 || r2 == r1 - 5 || r2 == r1 - 6 || r2 == r1 - 7 || r2 == r1 + 1 || r2 == r1 + 2 || r2 == r1 + 3 || r2 == r1 + 4 || r2 == r1 + 5 || r2 == r1 + 6 || r2 == r1 + 7)
						{
							if (c2 == c1)
							{
								if (r1 > r2)
								{
									for (int i = r1 - 1; i > r2; i--)
									{
										if (chessBoard[i][c1] >= 65 && chessBoard[i][c1] <= 90 || chessBoard[i][c1] >= 97 && chessBoard[i][c1] <= 122)
										{
											rookCheck = 0;
										}
									}
								}

								if (r1 < r2)
								{
									for (int i = r1 + 1; i < r2;)
									{
										if (chessBoard[i][c1] >= 65 && chessBoard[i][c1] <= 90 || chessBoard[i][c1] >= 97 && chessBoard[i][c1] <= 122)
										{
											rookCheck = 0;
										}
										i++;
									}
								}




								if (chessBoard[r2][c2] == ' ' && rookCheck == 1)
								{
									swapTurns(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
								}

								else if (chessBoard[r2][c2] >= 97 && rookCheck == 1 && chessBoard[r2][c2] <= 122)
								{


									if (chessBoard[r2][c2] == 'k')
									{
										killPlayer(chessBoard, r1, c1, r2, c2);
										checkMove = 0;
										system("CLS");
										displayBoard(chessBoard);
										cout << "Game over White wins\n";
										return 0;
									}
									else
									{
										killPlayer(chessBoard, r1, c1, r2, c2);
										checkMove = 0;
									}

								}

							}
						}
						else

						{

							system("CLS");
							displayBoard(chessBoard);
							cout << "This is an invalid move:\n";

						}
						if (c2 == c1 - 1 || c2 == c1 - 2 || c2 == c1 - 3 || c2 == c1 - 4 || c2 == c1 - 5 || c2 == c1 - 6 || c2 == c1 - 7 || c2 == c1 + 1 || c2 == c1 + 2 || c2 == c1 + 3 || c2 == c1 + 4 || c2 == c1 + 5 || c2 == c1 + 6 || c2 == c1 + 7)
						{
							if (r2 == r1)
							{
								if (c1 > c2)
								{
									for (int i = c1 - 1; i > c2; i--)
									{
										if (chessBoard[r1][i] >= 65 && chessBoard[r1][i] <= 90 || chessBoard[r1][i] >= 97 && chessBoard[r1][i] <= 122)
										{
											rookCheck = 0;
										}
									}
								}
								if (c2 > c1)
								{
									for (int i = c1 + 1; i < c2; i++)
									{
										if (chessBoard[r1][i] >= 65 && chessBoard[r1][i] <= 90 || chessBoard[r1][i] >= 97 && chessBoard[r1][i] <= 122)
										{
											/*checkMove = 0;*/
											rookCheck = 0;
										}
									}
								}

								if (chessBoard[r2][c2] == ' ' && rookCheck == 1)
								{
									swapTurns(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
								}

								if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122 && rookCheck == 1)
								{
									if (chessBoard[r2][c2] == 'k')
									{
										killPlayer(chessBoard, r1, c1, r2, c2);
										checkMove = 0;
										system("CLS");
										displayBoard(chessBoard);
										cout << "Game over White wins\n";
										return 0;
									}
									else
									{
										killPlayer(chessBoard, r1, c1, r2, c2);
										checkMove = 0;
									}
								}

							}
						}
						else

						{

							system("CLS");
							displayBoard(chessBoard);
							cout << "This is an invalid move:\n";

						}

					}
					/*bishop*/
					bool bishopCheck = 1;
					if (chessBoard[r1][c1] == 'B')
					{

						if (r2 == (r1 + c2) - c1 || r2 == c1 - (r1 + c2) || (r1 + c1 == r2 + c2))
						{
							if (r1 < r2 && c1 < c2)
							{
								for (int i = r1 + 1, j = c1 + 1; i < r2, j < c2; i++, j++)
								{
									if (chessBoard[i][j] >= 97 && chessBoard[i][j] <= 122 || chessBoard[i][j] >= 65 && chessBoard[i][j] <= 90)
									{
										bishopCheck = 0;
									}
								}

							}
							if (r1 > r2 && c1 < c2)
							{
								for (int i = r1 - 1, j = c1 + 1; i > r2, j < c2; i--, j++)
									if (chessBoard[i][j] >= 97 && chessBoard[i][j] <= 122 || chessBoard[i][j] >= 65 && chessBoard[i][j] <= 90)
									{
										bishopCheck = 0;
									}


							}
							if (r1<r2 && c1>c2)
							{
								for (int i = r1 + 1, j = c1 - 1; i<r2, j>c2; i++, j--)
								{
									if (chessBoard[i][j] >= 97 && chessBoard[i][j] <= 122 || chessBoard[i][j] >= 65 && chessBoard[i][j] <= 90)
									{
										bishopCheck = 0;
									}
								}
							}
							if (r1 > r1 && c1 > c2)
							{
								for (int i = r1 - 1, j = c1 - 1; i > r2, j > c2; i--, j--)
								{
									if (chessBoard[i][j] >= 97 && chessBoard[i][j] <= 122 || chessBoard[i][j] >= 65 && chessBoard[i][j] <= 90)
									{
										bishopCheck = 0;
									}
								}
							}
							if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122 && bishopCheck == 1)
							{
								if (chessBoard[r2][c2] == 'k')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over White wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
								}

							}
							else if (chessBoard[r2][c2] == ' ' && bishopCheck == 1)
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}

						}
						else
						{
							system("CLS");
							displayBoard(chessBoard);
							cout << "This is an invalid move:\n";
						}
					}

					/*knight*/
					if (chessBoard[r1][c1] == 'N')
					{
						if (r2 == r1 - 1 && c2 == c1 - 2)
						{
							if (chessBoard[r2][c2] >= 97 || chessBoard[r2][c2] <= 122)

							{
								if (chessBoard[r2][c2] == 'k')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over White wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
								}
								
							}
							else if (chessBoard[r2][c2] == ' ')
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}
						}
						else if (r2 == r1 + 1 && c2 == c1 - 2)
						{
							if (chessBoard[r2][c2] >= 97 || chessBoard[r2][c2] <= 122)

							{
								if (chessBoard[r2][c2] == 'k')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over White wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ')
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}
						}
						else if (r2 == r1 + 2 && c2 == c1 - 1)
						{
							if (chessBoard[r2][c2] >= 97 || chessBoard[r2][c2] <= 122)

							{
								if (chessBoard[r2][c2] == 'k')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over White wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ')
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}
						}
						else if (r2 == r1 + 2 && c2 == c1 + 1)
						{
							if (chessBoard[r2][c2] >= 97 || chessBoard[r2][c2] <= 122)

							{
								if (chessBoard[r2][c2] == 'k')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over White wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ')
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}
						}
						else if (r2 == r1 - 1 && c2 == c1 + 2)
						{
							if (chessBoard[r2][c2] >= 97 || chessBoard[r2][c2] <= 122)

							{
								if (chessBoard[r2][c2] == 'k')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over White wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ')
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}
						}
						else if (r2 == r1 - 2 && c2 == c1 - 1)
						{
							if (chessBoard[r2][c2] >= 97 || chessBoard[r2][c2] <= 122)

							{
								if (chessBoard[r2][c2] == 'k')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over White wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ')
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}
						}
						else if (r2 == r1 + 1 && c2 == c1 + 2)
						{
							if (chessBoard[r2][c2] >= 97 || chessBoard[r2][c2] <= 122)

							{
								if (chessBoard[r2][c2] == 'k')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over White wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ')
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}
						}
						else if (r2 == r1 - 2 && c2 == c1 + 1)
						{
							if (chessBoard[r2][c2] >= 97 || chessBoard[r2][c2] <= 122)

							{
								if (chessBoard[r2][c2] == 'k')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over White wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ')
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}
						}
						else
						{
							system("CLS");
							displayBoard(chessBoard);
							cout << "This is an invalid move:\n";
						}
					}

					/*this is now for                           king*/



					int cmcount = 0;
					bool kingCheck = 1;
					if (chessBoard[r1][c1] == 'K')
					{   /*1 done and checked*/
						if (r2 == r1 - 1 && c2 == c1 - 1)
						{
							/*for pawn*/
							if (chessBoard[r2 + 1][c2 - 1] == 'p')
								kingCheck = 0;
							/*for rook one up and one down and for queen*/
							int i = r2 - 1, j = c2;
							do
							{
								if (chessBoard[i][j] == ' ')
								{
									i--;

								}
								else if (chessBoard[i][j] == 'r' || chessBoard[i][j] == 'q')
								{
									kingCheck = 0;
								}


							} while (i >= 0 && kingCheck == 1);
							int ii = r2 + 1, jj = c2;
							do
							{
								if (chessBoard[ii][jj] == ' ')
									ii++;
								else if (chessBoard[ii][jj] == 'r' || chessBoard[ii][jj] == 'q')
									kingCheck = 0;

							} while (ii < 8 && kingCheck == 1);
							//for rook right and left for rook and queen
							int k = r2, l = c2 + 1;
							do
							{
								if (chessBoard[k][l] == ' ')
									l++;
								else if (chessBoard[k][l] == 'r' || chessBoard[k][l] == 'q')
									kingCheck = 0;
							} while (l < 8 && kingCheck == 1);
							int kk = r2, ll = c2 - 1;
							do
							{
								if (chessBoard[kk][ll] == ' ')
									ll--;
								else if (chessBoard[kk][ll] == 'r' || chessBoard[kk][ll] == 'q')
									kingCheck = 0;
							} while (ll >= 0 && kingCheck == 1);
							/*this is for diagonal check for bishop and for queen*/
							int m = r2 - 1, n = c2 + 1;
							do
							{
								if (chessBoard[m][n] == ' ')
								{
									m--;
									n++;
								}
								else if (chessBoard[m][n] == 'b' || chessBoard[m][n] == 'q')
									kingCheck = 0;
							} while (m >= 0 && n < 8 && kingCheck == 1);
							int mm = r2 + 1, nn = c2 - 1;
							do
							{
								if (chessBoard[mm][nn] == ' ')
								{
									mm++;
									nn--;
								}
								else if (chessBoard[mm][nn] == 'b' || chessBoard[mm][nn] == 'q')
									kingCheck = 0;
							} while (mm < 8 && nn >= 0 && kingCheck == 1);
							/*now i am going to check for all posible checks for knight */
					//
					//			/*1*//**/
							if (chessBoard[r2 - 2][c2 - 1] == 'n')
								kingCheck = 0;


							/*2*/
							/*if(chessBoard[r2][c2-2]=='n'&&kingCheck=1)*/
							if (chessBoard[r2 - 1][c2 - 2] == 'n')
							{
								kingCheck = 0;

							}
							/*3*/
							if (chessBoard[r2 + 1][c2 - 2] == 'n')
							{
								kingCheck = 0;

							}
							/*4*/
							if (chessBoard[r2 + 2][c2 - 1] == 'n')
							{
								kingCheck = 0;

							}
							/*5*/
							if (chessBoard[r2 + 1][c2 + 2] == 'n')
							{
								kingCheck = 0;

							}
							/*6*/
							if (chessBoard[r2 + 2][c2 + 1] == 'n')
							{
								kingCheck = 0;

							}
							/*7*/
							if (chessBoard[r2 - 2][c2 + 1] == 'n')
							{
								kingCheck = 0;

							}
							/*8*/
							if (chessBoard[r2 - 1][c2 + 2] == 'n')
							{
								kingCheck = 0;

							}

							if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <= 90 && kingCheck == 1)
							{
								kingCheck = 0;
							}

							if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122 && kingCheck == 1)
							{
								if (chessBoard[r2][c2] == 'k')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over White wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							if (kingCheck == 1 && chessBoard[r2][c2] == ' ')
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}
							else
							{
								system("CLS");
								displayBoard(chessBoard);
								cout << "THis is invalid move:\n ";
							}
						}
						/*2 done and checked*/
						else if (c2 == c1 && r2 == r1 - 1)
						{
							/*for pawn*/
							if (chessBoard[r2 + 1][c2 + 1] == 'p' || chessBoard[r2 + 1][c2 - 1] == 'p')
								kingCheck = 0;
							/*for rook only two cases*/
							int i = r2, j = c2 + 1;
							do
							{
								if (chessBoard[i][j] == ' ')
									j++;
								else if (chessBoard[i][j] == 'r' || chessBoard[i][j] == 'q')
									kingCheck = 0;
							} while (j < 8 && i == r2 && kingCheck == 1);
							int ii = r2, jj = c2 - 1;
							do
							{
								if (chessBoard[ii][jj] == ' ')
									jj--;
								else if (chessBoard[ii][jj] == 'r' || chessBoard[ii][jj] == 'q')
									kingCheck = 0;
							} while (jj >= 0 && kingCheck == 1);
							/*for bishop and queen are four cases*/
							int k = r2 - 1, l = c2 + 1;
							do
							{
								if (chessBoard[k][l] == ' ')
								{
									k--;
									l++;
								}
								else if (chessBoard[k][l] == 'b' || chessBoard[k][l] == 'q')
									kingCheck = 0;
							} while (k >= 0 && l < 8 && kingCheck == 1);
							int kk = r2 + 1, ll = c2 - 1;
							do
							{
								if (chessBoard[kk][ll] == ' ')
								{

									kk++; ll--;
								}
								else if (chessBoard[kk][ll] == 'b' || chessBoard[kk][ll] == 'q')
									kingCheck = 0;
							} while (kk < 8 && ll >= 0 && kingCheck == 1);
							int m = r2 + 1, n = c2 + 1;
							do
							{
								if (chessBoard[m][n] == ' ')
								{
									m++;
									n++;
								}
								else if (chessBoard[m][n] == 'b' || chessBoard[m][n] == 'q')
									kingCheck = 0;
							} while (m < 8 && n < 8 && kingCheck == 1);
							int mm = r2 - 1, nn = c2 - 1;
							do
							{
								if (chessBoard[mm][nn] == ' ')
								{
									mm--;
									nn--;
								}
								else if (chessBoard[mm][nn] == 'b' || chessBoard[mm][nn] == 'q')
									kingCheck = 0;
							} while (mm >= 0 && nn >= 0 && kingCheck == 1);
							/*now i am going to check for all posible checks for knight */
					//
					//			/*1*//**/
							if (chessBoard[r2 - 2][c2 - 1] == 'n')
								kingCheck = 0;


							/*2*/
							/*if(chessBoard[r2][c2-2]=='n'&&kingCheck=1)*/
							if (chessBoard[r2 - 1][c2 - 2] == 'n')
							{
								kingCheck = 0;

							}
							/*3*/
							if (chessBoard[r2 + 1][c2 - 2] == 'n')
							{
								kingCheck = 0;

							}
							/*4*/
							if (chessBoard[r2 + 2][c2 - 1] == 'n')
							{
								kingCheck = 0;

							}
							/*5*/
							if (chessBoard[r2 + 1][c2 + 2] == 'n')
							{
								kingCheck = 0;

							}
							/*6*/
							if (chessBoard[r2 + 2][c2 + 1] == 'n')
							{
								kingCheck = 0;

							}
							/*7*/
							if (chessBoard[r2 - 2][c2 + 1] == 'n')
							{
								kingCheck = 0;

							}
							/*8*/
							if (chessBoard[r2 - 1][c2 + 2] == 'n')
							{
								kingCheck = 0;

							}




							if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <= 90)
							{
								kingCheck = 0;
							}
							if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122 && kingCheck == 1)
							{
								if (chessBoard[r2][c2] == 'k')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over White wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ' && kingCheck == 1)
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);

							}
						}
						/*3 done and checked*/
						else if (r2 == r1 - 1 && c2 == c1 + 1)
						{
							/*for pawn*/
							if (chessBoard[r2 + 1][c2 + 1] == 'P')
								kingCheck = 0;
							/*for rook one up and one down and for queen*/
							int i = r2 - 1, j = c2;
							do
							{
								if (chessBoard[i][j] == ' ')
								{
									i--;

								}
								else if (chessBoard[i][j] == 'r' || chessBoard[i][j] == 'q')
								{
									kingCheck = 0;
								}


							} while (i >= 0 && kingCheck == 1);
							int ii = r2 + 1, jj = c2;
							do
							{
								if (chessBoard[ii][jj] == ' ')
									ii++;
								else if (chessBoard[ii][jj] == 'r' || chessBoard[ii][jj] == 'q')
									kingCheck = 0;

							} while (ii < 8 && kingCheck == 1);
							//for rook right and left for rook and queen
							int k = r2, l = c2 + 1;
							do
							{
								if (chessBoard[k][l] == ' ')
									l++;
								else if (chessBoard[k][l] == 'r' || chessBoard[k][l] == 'q')
									kingCheck = 0;
							} while (l < 8 && kingCheck == 1);
							int kk = r2, ll = c2 - 1;
							do
							{
								if (chessBoard[kk][ll] == ' ')
									ll--;
								else if (chessBoard[kk][ll] == 'r' || chessBoard[kk][ll] == 'q')
									kingCheck = 0;
							} while (ll >= 0 && kingCheck == 1);
							/*for two cases of bishop along with queen*/
							int m = r2 - 1, n = c2 - 1;
							do
							{
								if (chessBoard[m][n] == ' ')
								{
									m--; n--;
								}
								else if (chessBoard[m][n] == 'b' || chessBoard[m][n] == 'q')
									kingCheck = 0;
							} while (m >= 0 && n >= 0 && kingCheck == 1);
							int mm = r2 + 1, nn = c2 + 1;
							do
							{
								if (chessBoard[mm][nn] == ' ')
								{
									mm++; nn++;
								}
								else if (chessBoard[mm][nn] == 'b' || chessBoard[mm][nn] == 'q')
									kingCheck = 0;

							} while (mm < 8 && nn < 8 && kingCheck == 1);
							/*now i am going to check for all posible checks for knight */
					//
					//			/*1*//**/
							if (chessBoard[r2 - 2][c2 - 1] == 'n')
								kingCheck = 0;


							/*2*/
							/*if(chessBoard[r2][c2-2]=='n'&&kingCheck=1)*/
							if (chessBoard[r2 - 1][c2 - 2] == 'n')
							{
								kingCheck = 0;

							}
							/*3*/
							if (chessBoard[r2 + 1][c2 - 2] == 'n')
							{
								kingCheck = 0;

							}
							/*4*/
							if (chessBoard[r2 + 2][c2 - 1] == 'n')
							{
								kingCheck = 0;

							}
							/*5*/
							if (chessBoard[r2 + 1][c2 + 2] == 'n')
							{
								kingCheck = 0;

							}
							/*6*/
							if (chessBoard[r2 + 2][c2 + 1] == 'n')
							{
								kingCheck = 0;

							}
							/*7*/
							if (chessBoard[r2 - 2][c2 + 1] == 'n')
							{
								kingCheck = 0;

							}
							/*8*/
							if (chessBoard[r2 - 1][c2 + 2] == 'n')
							{
								kingCheck = 0;

							}







							if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <= 90)
							{
								kingCheck = 0;
							}
							if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122 && kingCheck == 1)
							{
								if (chessBoard[r2][c2] == 'k')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over White wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ' && kingCheck == 1)
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);

							}
						}
						/*4 and done and checked*/
						else if (r2 == r1 && c2 == c1 - 1)
						{

							/*for pawn*/

							if (chessBoard[r2 + 1][c2 - 1] == 'p')
								kingCheck = 0;

							/*for rook and queen two cases*/
							int i = r2 - 1, j = c2;
							do
							{
								if (chessBoard[i][j] == ' ')
									i--;
								else if (chessBoard[i][j] == 'r' || chessBoard[i][j] == 'q')
									kingCheck = 0;
							} while (i >= 0 && kingCheck == 1);
							int ii = r2 + 1, jj = c2;
							do
							{
								if (chessBoard[ii][jj] == ' ')
									ii++;
								else if (chessBoard[ii][jj] == 'r' || chessBoard[ii][jj] == 'q')
									kingCheck = 0;
							} while (ii < 8 && kingCheck == 1);
							/*for bishop and queen are four cases*/
							int k = r2 - 1, l = c2 + 1;
							do
							{
								if (chessBoard[k][l] == ' ')
								{
									k--;
									l++;
								}
								else if (chessBoard[k][l] == 'b' || chessBoard[k][l] == 'q')
									kingCheck = 0;
							} while (k >= 0 && l < 8 && kingCheck == 1);
							int kk = r2 + 1, ll = c2 - 1;
							do
							{
								if (chessBoard[kk][ll] == ' ')
								{

									kk++; ll--;
								}
								else if (chessBoard[kk][ll] == 'b' || chessBoard[kk][ll] == 'q')
									kingCheck = 0;
							} while (kk < 8 && ll >= 0 && kingCheck == 1);
							int m = r2 + 1, n = c2 + 1;

							do
							{
								if (chessBoard[m][n] == ' ')
								{
									m++;
									n++;
								}
								else if (chessBoard[m][n] == 'b' || chessBoard[m][n] == 'q')
									kingCheck = 0;
							} while (m < 8 && n < 8 && kingCheck == 1);
							int mm = r2 - 1, nn = c2 - 1;
							do
							{
								if (chessBoard[mm][nn] == ' ')
								{
									mm--;
									nn--;
								}
								else if (chessBoard[mm][nn] == 'b' || chessBoard[mm][nn] == 'q')
									kingCheck = 0;
							} while (mm >= 0 && nn >= 0 && kingCheck == 1);



							/*now i am going to check for all posible checks for knight */

					/*1*//**/
							if (chessBoard[r2 - 2][c2 - 1] == 'n')
								kingCheck = 0;


							/*2*/
							/*if(chessBoard[r2][c2-2]=='n'&&kingCheck=1)*/
							if (chessBoard[r2 - 1][c2 - 2] == 'n')
							{
								kingCheck = 0;

							}
							/*3*/
							if (chessBoard[r2 + 1][c2 - 2] == 'n')
							{
								kingCheck = 0;

							}
							/*4*/
							if (chessBoard[r2 + 2][c2 - 1] == 'n')
							{
								kingCheck = 0;

							}
							/*5*/
							if (chessBoard[r2 + 1][c2 + 2] == 'n')
							{
								kingCheck = 0;

							}
							/*6*/
							if (chessBoard[r2 + 2][c2 + 1] == 'n')
							{
								kingCheck = 0;

							}
							/*7*/
							if (chessBoard[r2 - 2][c2 + 1] == 'n')
							{
								kingCheck = 0;

							}
							/*8*/
							if (chessBoard[r2 - 1][c2 + 2] == 'n')
							{
								kingCheck = 0;

							}





							if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <= 90)
							{
								kingCheck = 0;
							}
							if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122 && kingCheck == 1)
							{
								if (chessBoard[r2][c2] == 'k')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over White wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ' && kingCheck == 1)
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);

							}
						}
						/*5 in done and checked*/
						else if (r2 == r1 && c2 == c1 + 1)
						{
							/*for pawn*/
							if (chessBoard[r2 + 1][c2 + 1] == 'p')
								kingCheck = 0;
							/*for rook and queen two cases*/
							int i = r2 - 1, j = c2;
							do
							{
								if (chessBoard[i][j] == ' ')
									i--;
								else if (chessBoard[i][j] == 'r' || chessBoard[i][j] == 'q')
									kingCheck = 0;
							} while (i >= 0 && kingCheck == 1);
							int ii = r2 + 1, jj = c2;
							do
							{
								if (chessBoard[ii][jj] == ' ')
									ii++;
								else if (chessBoard[ii][jj] == 'r' || chessBoard[ii][jj] == 'q')
									kingCheck = 0;
							} while (ii < 8 && kingCheck == 1);
							/*for bishop and queen are four cases*/
							int k = r2 - 1, l = c2 + 1;
							do
							{
								if (chessBoard[k][l] == ' ')
								{
									k--;
									l++;
								}
								else if (chessBoard[k][l] == 'b' || chessBoard[k][l] == 'q')
									kingCheck = 0;
							} while (k >= 0 && l < 8 && kingCheck == 1);
							int kk = r2 + 1, ll = c2 - 1;
							do
							{
								if (chessBoard[kk][ll] == ' ')
								{

									kk++; ll--;
								}
								else if (chessBoard[kk][ll] == 'b' || chessBoard[kk][ll] == 'q')
									kingCheck = 0;
							} while (kk < 8 && ll >= 0 && kingCheck == 1);
							int m = r2 + 1, n = c2 + 1;

							do
							{
								if (chessBoard[m][n] == ' ')
								{
									m++;
									n++;
								}
								else if (chessBoard[m][n] == 'b' || chessBoard[m][n] == 'q')
									kingCheck = 0;
							} while (m < 8 && n < 8 && kingCheck == 1);
							int mm = r2 - 1, nn = c2 - 1;
							do
							{
								if (chessBoard[mm][nn] == ' ')
								{
									mm--;
									nn--;
								}
								else if (chessBoard[mm][nn] == 'b' || chessBoard[mm][nn] == 'q')
									kingCheck = 0;
							} while (mm >= 0 && nn >= 0 && kingCheck == 1);



							/*now i am going to check for all posible checks for knight */

					/*1*//**/
							if (chessBoard[r2 - 2][c2 - 1] == 'n')
								kingCheck = 0;


							/*2*/
							/*if(chessBoard[r2][c2-2]=='n'&&kingCheck=1)*/
							if (chessBoard[r2 - 1][c2 - 2] == 'n')
							{
								kingCheck = 0;

							}
							/*3*/
							if (chessBoard[r2 + 1][c2 - 2] == 'n')
							{
								kingCheck = 0;

							}
							/*4*/
							if (chessBoard[r2 + 2][c2 - 1] == 'n')
							{
								kingCheck = 0;

							}
							/*5*/
							if (chessBoard[r2 + 1][c2 + 2] == 'n')
							{
								kingCheck = 0;

							}
							/*6*/
							if (chessBoard[r2 + 2][c2 + 1] == 'n')
							{
								kingCheck = 0;

							}
							/*7*/
							if (chessBoard[r2 - 2][c2 + 1] == 'n')
							{
								kingCheck = 0;

							}
							/*8*/
							if (chessBoard[r2 - 1][c2 + 2] == 'n')
							{
								kingCheck = 0;

							}



							if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <= 90)
							{
								kingCheck = 0;
							}
							if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122 && kingCheck == 1)
							{
								if (chessBoard[r2][c2] == 'k')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over White wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ' && kingCheck == 1)
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);

							}
						}
						/*6 done and checked*/
						else if (r2 == r1 + 1 && c2 == c1 - 1)
						{
							/*for pawn*/
							if (chessBoard[r2 + 1][c2 + 1] == 'p' || chessBoard[r2 + 1][c2 - 1] == 'p')
								kingCheck = 0;
							/*for rook fur cases*/
							/*horizontally*/
							int i = r2 - 1, j = c2;
							do
							{
								if (chessBoard[i][j] == ' ')
									i--;
								else if (chessBoard[i][j] == 'r' || chessBoard[i][j] == 'q')
									kingCheck = 0;
							} while (i >= 0 && kingCheck == 1);
							int ii = r2 + 1, jj = c2;
							do
							{
								if (chessBoard[ii][jj] == ' ')
									ii++;
								else if (chessBoard[ii][jj] == 'r' || chessBoard[ii][jj] == 'q')
									kingCheck = 0;
							} while (ii < 8 && kingCheck == 1);
							/*	vertically*/
							int k = r2, l = c2 - 1;
							do
							{
								if (chessBoard[k][l] == ' ')
									l--;
								else if (chessBoard[k][l] == 'r' || chessBoard[k][l] == 'q')
									kingCheck = 0;
							} while (l >= 0 && kingCheck == 1);

							int kk = r2, ll = c2 + 1;
							do
							{
								if (chessBoard[kk][ll] == ' ')
									ll++;
								else if (chessBoard[kk][ll] == 'r' || chessBoard[kk][ll] == 'q')
									kingCheck = 0;
							} while (ll < 8 && kingCheck == 1);
							/*for two cases of bishop along with queen*/
							int m = r2 - 1, n = c2 - 1;
							do
							{
								if (chessBoard[m][n] == ' ')
								{
									m--; n--;
								}
								else if (chessBoard[m][n] == 'b' || chessBoard[m][n] == 'q')
									kingCheck = 0;
							} while (m >= 0 && n >= 0 && kingCheck == 1);
							int mm = r2 + 1, nn = c2 + 1;
							do
							{
								if (chessBoard[mm][nn] == ' ')
								{
									mm++; nn++;
								}
								else if (chessBoard[mm][nn] == 'b' || chessBoard[mm][nn] == 'q')
									kingCheck = 0;

							} while (mm < 8 && nn < 8 && kingCheck == 1);
							/*now i am going to check for all posible checks for knight */
					//
					//			/*1*//**/
							if (chessBoard[r2 - 2][c2 - 1] == 'n')
								kingCheck = 0;


							/*2*/
							/*if(chessBoard[r2][c2-2]=='n'&&kingCheck=1)*/
							if (chessBoard[r2 - 1][c2 - 2] == 'n')
							{
								kingCheck = 0;

							}
							/*3*/
							if (chessBoard[r2 + 1][c2 - 2] == 'n')
							{
								kingCheck = 0;

							}
							/*4*/
							if (chessBoard[r2 + 2][c2 - 1] == 'n')
							{
								kingCheck = 0;

							}
							/*5*/
							if (chessBoard[r2 + 1][c2 + 2] == 'n')
							{
								kingCheck = 0;

							}
							/*6*/
							if (chessBoard[r2 + 2][c2 + 1] == 'n')
							{
								kingCheck = 0;

							}
							/*7*/
							if (chessBoard[r2 - 2][c2 + 1] == 'n')
							{
								kingCheck = 0;

							}
							/*8*/
							if (chessBoard[r2 - 1][c2 + 2] == 'n')
							{
								kingCheck = 0;

							}



							if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <= 90)
							{
								kingCheck = 0;
							}
							if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122 && kingCheck == 1)
							{
								if (chessBoard[r2][c2] == 'k')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over White wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ' && kingCheck == 1)
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);

							}
						}
						/*7 done and ckecked*/
						else if (r2 == r1 + 1 && c2 == c1)
						{
							/*now i am going to check for all posible checks for knight */
					//
					//			/*1*//**/
							if (chessBoard[r2 - 2][c2 - 1] == 'n')
								kingCheck = 0;


							/*2*/
							/*if(chessBoard[r2][c2-2]=='n'&&kingCheck=1)*/
							if (chessBoard[r2 - 1][c2 - 2] == 'n')
							{
								kingCheck = 0;

							}
							/*3*/
							if (chessBoard[r2 + 1][c2 - 2] == 'n')
							{
								kingCheck = 0;

							}
							/*4*/
							if (chessBoard[r2 + 2][c2 - 1] == 'n')
							{
								kingCheck = 0;

							}
							/*5*/
							if (chessBoard[r2 + 1][c2 + 2] == 'n')
							{
								kingCheck = 0;

							}
							/*6*/
							if (chessBoard[r2 + 2][c2 + 1] == 'n')
							{
								kingCheck = 0;

							}
							/*7*/
							if (chessBoard[r2 - 2][c2 + 1] == 'n')
							{
								kingCheck = 0;

							}
							/*8*/
							if (chessBoard[r2 - 1][c2 + 2] == 'n')
							{
								kingCheck = 0;

							}
							/*for pawns*/
							if (chessBoard[r2 + 1][c2 + 1] == 'p' || chessBoard[r2 + 1][c2 - 1] == 'p')
								kingCheck = 0;
							/*for rook only two cases*/
							int i = r2, j = c2 + 1;
							do
							{
								if (chessBoard[i][j] == ' ')
									j++;
								else if (chessBoard[i][j] == 'r' || chessBoard[i][j] == 'q')
									kingCheck = 0;
							} while (j < 8 && i == r2 && kingCheck == 1);
							int ii = r2, jj = c2 - 1;
							do
							{
								if (chessBoard[ii][jj] == ' ')
									jj--;
								else if (chessBoard[ii][jj] == 'r' ||chessBoard[ii][jj] == 'q')
									kingCheck = 0;
							} while (jj >= 0 && kingCheck == 1);
							/*for bishop and queen are four cases*/
							int k = r2 - 1, l = c2 + 1;
							do
							{
								if (chessBoard[k][l] == ' ')
								{
									k--;
									l++;
								}
								else if (chessBoard[k][l] == 'b' || chessBoard[k][l] == 'q')
									kingCheck = 0;
							} while (k >= 0 && l < 8 && kingCheck == 1);
							int kk = r2 + 1, ll = c2 - 1;
							do
							{
								if (chessBoard[kk][ll] == ' ')
								{

									kk++; ll--;
								}
								else if (chessBoard[kk][ll] == 'b' || chessBoard[kk][ll] == 'q')
									kingCheck = 0;
							} while (kk < 8 && ll >= 0 && kingCheck == 1);
							int m = r2 + 1, n = c2 + 1;

							do
							{
								if (chessBoard[m][n] == ' ')
								{
									m++;
									n++;
								}
								else if (chessBoard[m][n] == 'b' || chessBoard[m][n] == 'q')
									kingCheck = 0;
							} while (m < 8 && n < 8 && kingCheck == 1);
							int mm = r2 - 1, nn = c2 - 1;
							do
							{
								if (chessBoard[mm][nn] == ' ')
								{
									mm--;
									nn--;
								}
								else if (chessBoard[mm][nn] == 'b' || chessBoard[mm][nn] == 'q')
									kingCheck = 0;
							} while (mm >= 0 && nn >= 0 && kingCheck == 1);

							if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <= 90)
							{
								kingCheck = 0;
							}
							if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122 && kingCheck == 1)
							{
								if (chessBoard[r2][c2] == 'k')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over White wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ' && kingCheck == 1)
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);

							}
						}
						/*8 done and ckecked */
						else if (r2 == r1 + 1 && c2 == c1 + 1)
						{
							/*for pawn*/
							if (chessBoard[r2 + 1][c2 + 1] == 'p' || chessBoard[r2 + 1][c2 - 1] == 'p')
								kingCheck = 0;
							/*for rook one up and one down and for queen*/
							int i = r2 - 1, j = c2;
							do
							{
								if (chessBoard[i][j] == ' ')
								{
									i--;

								}
								else if (chessBoard[i][j] == 'r' || chessBoard[i][j] == 'q')
								{
									kingCheck = 0;
								}


							} while (i >= 0 && kingCheck == 1);
							int ii = r2 + 1, jj = c2;
							do
							{
								if (chessBoard[ii][jj] == ' ')
									ii++;
								else if (chessBoard[ii][jj] == 'r' || chessBoard[ii][jj] == 'q')
									kingCheck = 0;

							} while (ii < 8 && kingCheck == 1);
							//for rook right and left for rook and queen
							int k = r2, l = c2 + 1;
							do
							{
								if (chessBoard[k][l] == ' ')
									l++;
								else if (chessBoard[k][l] == 'r' || chessBoard[k][l] == 'q')
									kingCheck = 0;
							} while (l < 8 && kingCheck == 1);
							int kk = r2, ll = c2 - 1;
							do
							{
								if (chessBoard[kk][ll] == ' ')
									ll--;
								else if (chessBoard[kk][ll] == 'r' || chessBoard[kk][ll] == 'q')
									kingCheck = 0;
							} while (ll >= 0 && kingCheck == 1);
							/*this is for diagonal check for bishop and for queen*/
							int m = r2 - 1, n = c2 + 1;
							do
							{
								if (chessBoard[m][n] == ' ')
								{
									m--;
									n++;
								}
								else if (chessBoard[m][n] == 'b' || chessBoard[m][n] == 'q')
									kingCheck = 0;
							} while (m >= 0 && n < 8 && kingCheck == 1);
							int mm = r2 + 1, nn = c2 - 1;
							do
							{
								if (chessBoard[mm][nn] == ' ')
								{
									mm++;
									nn--;
								}
								else if (chessBoard[mm][nn] == 'b' || chessBoard[mm][nn] == 'q')
									kingCheck = 0;
							} while (mm < 8 && nn >= 0 && kingCheck == 1);
							/*now i am going to check for all posible checks for knight */
					//
					//			/*1*//**/
							if (chessBoard[r2 - 2][c2 - 1] == 'n')
								kingCheck = 0;


							/*2*/
							/*if(chessBoard[r2][c2-2]=='n'&&kingCheck=1)*/
							if (chessBoard[r2 - 1][c2 - 2] == 'n')
							{
								kingCheck = 0;

							}
							/*3*/
							if (chessBoard[r2 + 1][c2 - 2] == 'n')
							{
								kingCheck = 0;

							}
							/*4*/
							if (chessBoard[r2 + 2][c2 - 1] == 'n')
							{
								kingCheck = 0;

							}
							/*5*/
							if (chessBoard[r2 + 1][c2 + 2] == 'n')
							{
								kingCheck = 0;

							}
							/*6*/
							if (chessBoard[r2 + 2][c2 + 1] == 'n')
							{
								kingCheck = 0;

							}
							/*7*/
							if (chessBoard[r2 - 2][c2 + 1] == 'n')
							{
								kingCheck = 0;

							}
							/*8*/
							if (chessBoard[r2 - 1][c2 + 2] == 'n')
							{
								kingCheck = 0;

							}



							if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <= 90)
							{
								kingCheck = 0;
							}
							if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122 && kingCheck == 1)
							{
								if (chessBoard[r2][c2] == 'k')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over White wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							if (chessBoard[r2][c2] == ' ' && kingCheck == 1)
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);

							}
						}
						else
						{
							system("CLS");
							displayBoard(chessBoard);
							cout << "This is an invalid move:\n";
						}
					}

					/*from herer starts the queen*/


					bool queenCheck1 = 1;
					if (chessBoard[r1][c1] == 'Q')
					{
						if (r2 == r1 - 1 || r2 == r1 - 2 || r2 == r1 - 3 || r2 == r1 - 3 || r2 == r1 - 4 || r2 == r1 - 5 || r2 == r1 - 6 || r2 == r1 - 7 || r2 == r1 + 1 || r2 == r1 + 2 || r2 == r1 + 3 || r2 == r1 + 4 || r2 == r1 + 5 || r2 == r1 + 6 || r2 == r1 + 7)
						{
							if (c2 == c1)
							{
								for (int i = r1 + 1; i < r2; i++)
								{
									if (chessBoard[i][c2] >= 97 && chessBoard[i][c2] <= 122 || chessBoard[i][c2] >= 65 && chessBoard[i][c2] <= 90)
									{
										queenCheck1 = 0;
									}
								}
								if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122)
								{
									if (queenCheck1 == 1)
									{
										if (chessBoard[r2][c2] == 'k')
										{
											killPlayer(chessBoard, r1, c1, r2, c2);
											checkMove = 0;
											system("CLS");
											displayBoard(chessBoard);
											cout << "Game over White wins\n";
											return 0;
										}
										else
										{
											killPlayer(chessBoard, r1, c1, r2, c2);
											checkMove = 0;
											system("CLS");
											displayBoard(chessBoard);
										}
									}
								}
								if (chessBoard[r2][c2] == ' ' && queenCheck1 == 1)
								{
									swapTurns(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
						}

						else if (c2 == c1 - 1 || c2 == c1 - 2 || c2 == c1 - 3 || c2 == c1 - 4 || c2 == c1 - 5 || c2 == c1 - 6 || c2 == c1 - 7 || c2 == c1 + 1 || c2 == c1 + 2 || c2 == c1 + 3 || c2 == c1 + 4 || c2 == c1 + 5 || c2 == c1 + 6 || c2 == c1 + 7)
						{

							if (r2 == r1)
							{
								for (int i = c1 + 1; i < c2; i++)
								{
									if (chessBoard[r1][i] >= 97 && chessBoard[r1][i] <= 122 || chessBoard[r1][i] >= 65 && chessBoard[r1][i] <= 90)
									{
										queenCheck1 = 0;
									}
								}
								if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122 && queenCheck1 == 1)
								{


									if (chessBoard[r2][c2] == 'k')
									{
										killPlayer(chessBoard, r1, c1, r2, c2);
										checkMove = 0;
										system("CLS");
										displayBoard(chessBoard);
										cout << "Game over White wins\n";
										return 0;
									}
									else
									{
										killPlayer(chessBoard, r1, c1, r2, c2);
										checkMove = 0;
										system("CLS");
										displayBoard(chessBoard);
									}

								}
								else if (chessBoard[r2][c2] == ' ')

								{
									if (queenCheck1 == 1)
									{
										swapTurns(chessBoard, r1, c1, r2, c2);
										checkMove = 0;
										system("CLS");
										displayBoard(chessBoard);
									}
								}

							}
						}
						else
						{
							system("CLS");
							displayBoard(chessBoard);
							cout << "This is an invalid move:\n";
						}
						if (r2 == (r1 + c2) - c1 || r2 == c1 - (r1 + c2) || (r1 + c1 == r2 + c2))
						{
							swapTurns(chessBoard, r1, c1, r2, c2);
							checkMove = 0;
							system("CLS");
							displayBoard(chessBoard);
						}
						else
						{
							system("CLS");
							displayBoard(chessBoard);
							cout << "This is an invalid move:\n";
						}
					}
					bool check;
					check = checkk(chessBoard, turn,r2,c2);
					if (check == 0 && checkMove == 0)
					{
						/*system("CLS");
						displayBoard(chessBoard);*/

						cout << "Black king is under attack \n";
					}

					





				}
				else
				{
					system("CLS");
					displayBoard(chessBoard);
					cout << "This is an invalid move Enter again\n";
				}
			}





			/*cout << r1 << c1 << r2 << c2;
			swapTurns(chessBoard, r1, c1, r2, c2);*/
			/*system("CLS");
			displayBoard(chessBoard);*/

		}
		ofstream game;
		game.open("game.txt");
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				game << chessBoard[i][j];


			}
			game << endl;
		}
		/*Here starts turn of black player*/
					/*player2*/
					/*player2*/
						/*player2*/
									/*player2*/
								/*player2*/


		if (turn == 0)
		{
			turn = 1;

			bool checkMove = 1;
			while (checkMove == 1)
				
			{
				cout << "This is the turn of black player\n";
				cout << "Enter your move :\n";
				cin.get(moves, 5);
				cin.ignore();
				r1 = findRow(moves[0]);
				c1 = findCol(moves[1]);
				r2 = findRow(moves[2]);
				c2 = findCol(moves[3]);
				bool kingCheck = 0;
				if (moves[0] <= 56 && moves[0] >= 49 && moves[1] >= 97 && moves[1] <= 104 && moves[2] <= 56 && moves[2] >= 49 && moves[3] >= 97 && moves[3] <= 104 && chessBoard[r1][c1] >= 97 && chessBoard[r1][c1] <= 122)
				{
					if (chessBoard[r1][c1] == 'p')
					{

						if (r2 == r1 - 1 && c2 == c1)
						{
							/*pawn promotion*/
							if (r2 == 0)
							{
								char promo;
								cout << "Your pawn is being promoted\n";
								cout << "Select which one do you replace \n";
								cout << "enter q for queen\n enter b for bishop\n enter r for rook \n enter n for knight\n";
								cin >> promo;
								cin.ignore(); checkMove = 0;
								promotion(chessBoard, r1, c1, r2, c2, promo);
								system("CLS");
								displayBoard(chessBoard);


							}
							if (chessBoard[r2][c2] == ' '&& checkMove==1)
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
							}

						}
						else 	if (r2 == r1 - 1 && c2 == c1 - 1)
						{
							if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <= 90)
							{
								if (chessBoard[r2][c2] == 'K')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over Black wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
						}
						else 	if (r2 == r1 - 1 && c2 == c1 + 1)
						{
							if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <= 90)
							{
								if (chessBoard[r2][c2] == 'K')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over Black wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
						}
						else if (r1 == r2 +2 && r1 == 6)
						{
							if (chessBoard[r2][c2] == ' ' && checkMove == 1)
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								/*system("CLS");
								displayBoard(chessBoard);*/
							}
						}
						else

						{

							system("CLS");
							displayBoard(chessBoard);
							cout << "This is an invalid move:\n";

						}
					}
					bool rookCheck = 1;
					if (chessBoard[r1][c1] == 'r')
					{
						if (r2 == r1 - 1 || r2 == r1 - 2 || r2 == r1 - 3 || r2 == r1 - 3 || r2 == r1 - 4 || r2 == r1 - 5 || r2 == r1 - 6 || r2 == r1 - 7 || r2 == r1 + 1 || r2 == r1 + 2 || r2 == r1 + 3 || r2 == r1 + 4 || r2 == r1 + 5 || r2 == r1 + 6 || r2 == r1 + 7)
						{
							if (c2 == c1)
							{
								if (r1 > r2)
								{
									for (int i = r1 - 1; i > r2; i--)
									{
										if (chessBoard[i][c1] >= 65 && chessBoard[i][c1] <= 90 || chessBoard[i][c1] >= 97 && chessBoard[i][c1] <= 122)
										{
											rookCheck = 0;
										}
									}
								}

								if (r1 < r2)
								{
									for (int i = r1 + 1; i < r2;)
									{
										if (chessBoard[i][c1] >= 65 && chessBoard[i][c1] <= 90 || chessBoard[i][c1] >= 97 && chessBoard[i][c1] <= 122)
										{
											rookCheck = 0;
										}
										i++;
									}
								}




								if (chessBoard[r2][c2] == ' ' && rookCheck == 1)
								{
									swapTurns(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
								}

								else if (chessBoard[r2][c2] >= 65 && rookCheck == 1 && chessBoard[r2][c2] <= 90)
								{


									if (chessBoard[r2][c2] == 'K')
									{
										killPlayer(chessBoard, r1, c1, r2, c2);
										checkMove = 0;
										system("CLS");
										displayBoard(chessBoard);
										cout << "Game over Black wins\n";
										return 0;
									}
									else
									{
										killPlayer(chessBoard, r1, c1, r2, c2);
										checkMove = 0;
										system("CLS");
										displayBoard(chessBoard);
									}

									

								}

							}
						}
						if (c2 == c1 - 1 || c2 == c1 - 2 || c2 == c1 - 3 || c2 == c1 - 4 || c2 == c1 - 5 || c2 == c1 - 6 || c2 == c1 - 7 || c2 == c1 + 1 || c2 == c1 + 2 || c2 == c1 + 3 || c2 == c1 + 4 || c2 == c1 + 5 || c2 == c1 + 6 || c2 == c1 + 7)
						{
							if (r2 == r1)
							{
								if (c1 > c2)
								{
									for (int i = c1 - 1; i > c2; i--)
									{
										if (chessBoard[r1][i] >= 65 && chessBoard[r1][i] <= 90 || chessBoard[r1][i] >= 97 && chessBoard[r1][i] <= 122)
										{
											rookCheck = 0;
										}
									}
								}
								if (c2 > c1)
								{
									for (int i = c1 + 1; i < c2; i++)
									{
										if (chessBoard[r1][i] >= 65 && chessBoard[r1][i] <= 90 || chessBoard[r1][i] >= 97 && chessBoard[r1][i] <= 122)
										{
											/*checkMove = 0;*/
											rookCheck = 0;
										}
									}
								}

								if (chessBoard[r2][c2] == ' ' && rookCheck == 1)
								{
									swapTurns(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
								}

								if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <= 90 && rookCheck == 1)
								{
									if (chessBoard[r2][c2] == 'K')
									{
										killPlayer(chessBoard, r1, c1, r2, c2);
										checkMove = 0;
										system("CLS");
										displayBoard(chessBoard);
										cout << "Game over Black wins\n";
										return 0;
									}
									else
									{
										killPlayer(chessBoard, r1, c1, r2, c2);
										checkMove = 0;
										system("CLS");
										displayBoard(chessBoard);
									}
								}

							}
						}
						else

						{

							system("CLS");
							displayBoard(chessBoard);
							cout << "This is an invalid move:\n";

						}

					}
					bool bishopCheck = 1;
					if (chessBoard[r1][c1] == 'b')
					{
						if (r2 == (r1 + c2) - c1 || r2 == c1 - (r1 + c2) || (r1 + c1 == r2 + c2))
						{
							if (r1 < r2 && c1 < c2)
							{
								for (int i = r1 + 1, j = c1 + 1; i < r2, j < c2; i++, j++)
								{
									if (chessBoard[i][j] >= 97 && chessBoard[i][j] <= 122 || chessBoard[i][j] >= 65 && chessBoard[i][j] <= 90)
									{
										bishopCheck = 0;
									}
								}

							}
							if (r1 > r2 && c1 < c2)
							{
								for (int i = r1 - 1, j = c1 + 1; i > r2, j < c2; i--, j++)
									if (chessBoard[i][j] >= 97 && chessBoard[i][j] <= 122 || chessBoard[i][j] >= 65 && chessBoard[i][j] <= 90)
									{
										bishopCheck = 0;
									}


							}
							if (r1<r2 && c1>c2)
							{
								for (int i = r1 + 1, j = c1 - 1; i<r2, j>c2; i++, j--)
								{
									if (chessBoard[i][j] >= 97 && chessBoard[i][j] <= 122 || chessBoard[i][j] >= 65 && chessBoard[i][j] <= 90)
									{
										bishopCheck = 0;
									}
								}
							}
							if (r1 > r2 && c1 > c2)
							{
								for (int i = r1 - 1, j = c1 - 1; i > r2, j > c2; i--, j--)
								{
									if (chessBoard[i][j] >= 97 && chessBoard[i][j] <= 122 || chessBoard[i][j] >= 65 && chessBoard[i][j] <= 90)
									{
										bishopCheck = 0;
									}
								}
							}
							if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <= 90 && bishopCheck == 1)
							{
								if (chessBoard[r2][c2] == 'K')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over Black wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ' && bishopCheck == 1)
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}

						}
						else
						{
							system("CLS");
							displayBoard(chessBoard);
							cout << "This is an invalid move:\n";
						}
					}
					if (chessBoard[r1][c1] == 'n')
					{
						if (r2 == r1 - 1 && c2 == c1 - 2)
						{
							if (chessBoard[r2][c2] >= 65 || chessBoard[r2][c2] <= 90)

							{
								if (chessBoard[r2][c2] == 'K')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over Black wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ')
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}
						}
						else if (r2 == r1 + 1 && c2 == c1 - 2)
						{
							if (chessBoard[r2][c2] >= 65 || chessBoard[r2][c2] <= 90)

							{
								if (chessBoard[r2][c2] == 'K')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over Black wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ')
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}
						}
						else if (r2 == r1 + 2 && c2 == c1 - 1)
						{
							if (chessBoard[r2][c2] >= 65 || chessBoard[r2][c2] <= 90)

							{
								if (chessBoard[r2][c2] == 'K')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over Black wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ')
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}
						}
						else if (r2 == r1 + 2 && c2 == c1 + 1)
						{
							if (chessBoard[r2][c2] >= 65 || chessBoard[r2][c2] <= 90)

							{
								if (chessBoard[r2][c2] == 'K')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over Black wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ')
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}
						}
						else if (r2 == r1 - 1 && c2 == c1 + 2)
						{
							if (chessBoard[r2][c2] >= 65 || chessBoard[r2][c2] <= 90)

							{
								if (chessBoard[r2][c2] == 'K')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over Black wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ')
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}
						}
						else if (r2 == r1 - 2 && c2 == c1 - 1)
						{
							if (chessBoard[r2][c2] >= 65 || chessBoard[r2][c2] <= 90)

							{
								if (chessBoard[r2][c2] == 'K')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over Black wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ')
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}
						}
						else if (r2 == r1 + 1 && c2 == c1 + 2)
						{
							if (chessBoard[r2][c2] >= 65 || chessBoard[r2][c2] <= 90)

							{
								if (chessBoard[r2][c2] == 'K')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over Black wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ')
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}
						}
						else if (r2 == r1 - 2 && c2 == c1 + 1)
						{
							if (chessBoard[r2][c2] >= 65 || chessBoard[r2][c2] <= 90)

							{
								if (chessBoard[r2][c2] == 'K')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over Black wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ')
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}
						}
						else
						{
							system("CLS");
							displayBoard(chessBoard);
							cout << "This is an invalid move:\n";
						}
					}
					bool queenCheck = 1;
					if (chessBoard[r1][c1] == 'q')
					{
						if (r2 == r1 - 1 || r2 == r1 - 2 || r2 == r1 - 3 || r2 == r1 - 3 || r2 == r1 - 4 || r2 == r1 - 5 || r2 == r1 - 6 || r2 == r1 - 7 || r2 == r1 + 1 || r2 == r1 + 2 || r2 == r1 + 3 || r2 == r1 + 4 || r2 == r1 + 5 || r2 == r1 + 6 || r2 == r1 + 7)
						{
							if (c2 == c1)
							{
								if (r1 > r2)
								{
									for (int i = r1 - 1; i > r2; i--)
									{
										if (chessBoard[i][c1] >= 65 && chessBoard[i][c1] <= 90 || chessBoard[i][c1] >= 97 && chessBoard[i][c1] <= 122)
										{
											queenCheck = 0;


										}
									}
								}

								if (r1 < r2)
								{
									for (int i = r1 + 1; i < r2;)
									{
										if (chessBoard[i][c1] >= 65 && chessBoard[i][c1] <= 90 || chessBoard[i][c1] >= 97 && chessBoard[i][c1] <= 122)
										{
											queenCheck = 0;
										}
										i++;
									}
								}




								if (chessBoard[r2][c2] == ' ' && queenCheck == 1)
								{
									swapTurns(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
								}

								else if (chessBoard[r2][c2] >= 65 && queenCheck == 1 && chessBoard[r2][c2] <= 90)
								{


									if (chessBoard[r2][c2] == 'K')
									{
										killPlayer(chessBoard, r1, c1, r2, c2);
										checkMove = 0;
										system("CLS");
										displayBoard(chessBoard);
										cout << "Game over Black wins\n";
										return 0;
									}
									else
									{
										killPlayer(chessBoard, r1, c1, r2, c2);
										checkMove = 0;
										system("CLS");
										displayBoard(chessBoard);
									}

								}

							}
						}
						if (c2 == c1 - 1 || c2 == c1 - 2 || c2 == c1 - 3 || c2 == c1 - 4 || c2 == c1 - 5 || c2 == c1 - 6 || c2 == c1 - 7 || c2 == c1 + 1 || c2 == c1 + 2 || c2 == c1 + 3 || c2 == c1 + 4 || c2 == c1 + 5 || c2 == c1 + 6 || c2 == c1 + 7)
						{
							if (r2 == r1)
							{
								if (c1 > c2)
								{
									for (int i = c1 - 1; i > c2; i--)
									{
										if (chessBoard[r1][i] >= 65 && chessBoard[r1][i] <= 90 || chessBoard[r1][i] >= 97 && chessBoard[r1][i] <= 122)
										{
											queenCheck = 0;
										}
									}
								}
								if (c2 > c1)
								{
									for (int i = c1 + 1; i < c2; i++)
									{
										if (chessBoard[r1][i] >= 65 && chessBoard[r1][i] <= 90 || chessBoard[r1][i] >= 97 && chessBoard[r1][i] <= 122)
										{
											/*checkMove = 0;*/
											queenCheck = 0;
										}
									}
								}

								if (chessBoard[r2][c2] == ' ' && queenCheck == 1)
								{
									swapTurns(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
								}

								if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <= 90 && queenCheck == 1)
								{
									if (chessBoard[r2][c2] == 'K')
									{
										killPlayer(chessBoard, r1, c1, r2, c2);
										checkMove = 0;
										system("CLS");
										displayBoard(chessBoard);
										cout << "Game over Black wins\n";
										return 0;
									}
									else
									{
										killPlayer(chessBoard, r1, c1, r2, c2);
										checkMove = 0;
										system("CLS");
										displayBoard(chessBoard);
									}
								}

							}
						}
						else

						{

							system("CLS");
							displayBoard(chessBoard);
							cout << "This is an invalid move:\n";

						}


						/*for queen to move like bishop*/

						queenCheck = 1;

						if (r2 == (r1 + c2) - c1 || r2 == c1 - (r1 + c2) || (r1 + c1 == r2 + c2))
						{
							if (r1 < r2 && c1 < c2)
							{
								for (int i = r1 + 1, j = c1 + 1; i < r2, j < c2; i++, j++)
								{
									if (chessBoard[i][j] >= 97 && chessBoard[i][j] <= 122 || chessBoard[i][j] >= 65 && chessBoard[i][j] <= 90)
									{
										queenCheck = 0;
									}
								}

							}
							if (r1 > r2 && c1 < c2)
							{
								for (int i = r1 - 1, j = c1 + 1; i > r2, j < c2; i--, j++)
									if (chessBoard[i][j] >= 97 && chessBoard[i][j] <= 122 || chessBoard[i][j] >= 65 && chessBoard[i][j] <= 90)
									{
										queenCheck = 0;
									}


							}
							if (r1<r2 && c1>c2)
							{
								for (int i = r1 + 1, j = c1 - 1; i<r2, j>c2; i++, j--)
								{
									if (chessBoard[i][j] >= 97 && chessBoard[i][j] <= 122 || chessBoard[i][j] >= 65 && chessBoard[i][j] <= 90)
									{
										queenCheck = 0;
									}
								}
							}
							if (r1 > r2 && c1 > c2)
							{
								for (int i = r1 - 1, j = c1 - 1; i > r2, j > c2; i--, j--)
								{
									if (chessBoard[i][j] >= 97 && chessBoard[i][j] <= 122 || chessBoard[i][j] >= 65 && chessBoard[i][j] <= 90)
									{
										queenCheck = 0;
									}
								}
							}
							if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <= 90 && queenCheck == 1)
							{
								if (chessBoard[r2][c2] == 'K')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over Black wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}

							}
							else if (chessBoard[r2][c2] == ' ' && queenCheck == 1)
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}

						}
						else
						{
							system("CLS");
							displayBoard(chessBoard);
							cout << "This is an invalid move:\n";
						}
					}


					bool kingCheck = 1;
					bool kingCheck2 = 1;

					if (chessBoard[r1][c1] == 'k')
					{   /*1 done and checked*/
						if (r2 == r1 - 1 && c2 == c1 - 1)
						{
							/*for pawn*/
							if (chessBoard[r2 - 1][c2 + 1] == 'P' || chessBoard[r2 - 1][c2 - 1] == 'P')
								kingCheck = 0;
							/*for rook one up and one down and for queen*/
							int i = r2 - 1, j = c2;
							do
							{
								if (chessBoard[i][j] == ' ')
								{
									i--;

								}
								else if (chessBoard[i][j] == 'R' || chessBoard[i][j] == 'Q')
								{
									kingCheck = 0;
								}


							} while (i >= 0 && kingCheck == 1);
							int ii = r2 + 1, jj = c2;
							do
							{
								if (chessBoard[ii][jj] == ' ')
									ii++;
								else if (chessBoard[ii][jj] == 'R' || chessBoard[ii][jj] == 'Q')
									kingCheck = 0;

							} while (ii < 8 && kingCheck == 1);
							//for rook right and left for rook and queen
							int k = r2, l = c2 + 1;
							do
							{
								if (chessBoard[k][l] == ' ')
									l++;
								else if (chessBoard[k][l] == 'R' || chessBoard[k][l] == 'Q')
									kingCheck = 0;
							} while (l < 8 && kingCheck == 1);
							int kk = r2, ll = c2 - 1;
							do
							{
								if (chessBoard[kk][ll] == ' ')
									ll--;
								else if (chessBoard[kk][ll] == 'R' || chessBoard[kk][ll] == 'Q')
									kingCheck = 0;
							} while (ll >= 0 && kingCheck == 1);
							/*this is for diagonal check for bishop and for queen*/
							int m = r2 - 1, n = c2 + 1;
							do
							{
								if (chessBoard[m][n] == ' ')
								{
									m--;
									n++;
								}
								else if (chessBoard[m][n] == 'B' || chessBoard[m][n] == 'Q')
									kingCheck = 0;
							} while (m >= 0 && n < 8 && kingCheck == 1);
							int mm = r2 + 1, nn = c2 - 1;
							do
							{
								if (chessBoard[mm][nn] == ' ')
								{
									mm++;
									nn--;
								}
								else if (chessBoard[mm][nn] == 'B' || chessBoard[mm][nn] == 'Q')
									kingCheck = 0;
							} while (mm < 8 && nn >= 0 && kingCheck == 1);
							/*now i am going to check for all posible checks for knight */
	//
	//			/*1*//**/
							if (chessBoard[r2 - 2][c2 - 1] == 'N')
								kingCheck = 0;


							/*2*/
							/*if(chessBoard[r2][c2-2]=='n'&&kingCheck=1)*/
							else	if (chessBoard[r2 - 1][c2 - 2] == 'N')
							{
								kingCheck = 0;

							}
							/*3*/
							else	if (chessBoard[r2 + 1][c2 - 2] == 'N')
							{
								kingCheck = 0;

							}
							/*4*/
							else	if (chessBoard[r2 + 2][c2 - 1] == 'N')
							{
								kingCheck = 0;

							}
							/*5*/
							else	if (chessBoard[r2 + 1][c2 + 2] == 'N')
							{
								kingCheck = 0;

							}
							/*6*/
							else	if (chessBoard[r2 + 2][c2 + 1] == 'N')
							{
								kingCheck = 0;

							}
							/*7*/
							else	if (chessBoard[r2 - 2][c2 + 1] == 'N')
							{
								kingCheck = 0;

							}
							/*8*/
							else	if (chessBoard[r2 - 1][c2 + 2] == 'N')
							{
								kingCheck = 0;

							}

							if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122 && kingCheck == 1)
							{
								kingCheck = 0;
							}

							if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <= 90 && kingCheck == 1)
							{
								if (chessBoard[r2][c2] == 'K')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over Black wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							if (kingCheck == 1 && chessBoard[r2][c2] == ' ')
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);
							}
							else
							{
								system("CLS");
								displayBoard(chessBoard);
								cout << "THis is invalid move:\n ";
							}
						}
						/*2 done and checked*/
						else if (c2 == c1 && r2 == r1 - 1)
						{
						/*for pawn*/
						if (chessBoard[r2 - 1][c2 + 1] == 'P' || chessBoard[r2 - 1][c2 - 1] == 'P')
							kingCheck = 0;
						/*for rook only two cases*/
						int i = r2, j = c2 + 1;
						do
						{
							if (chessBoard[i][j] == ' ')
								j++;
							else if (chessBoard[i][j] == 'R' || chessBoard[i][j] == 'Q')
								kingCheck = 0;
						} while (j < 8 && i == r2 && kingCheck == 1);
						int ii = r2, jj = c2 - 1;
						do
						{
							if (chessBoard[ii][jj] == ' ')
								jj--;
							else if (chessBoard[ii][jj] == 'R' || chessBoard[ii][jj]=='Q')
								kingCheck = 0;
						} while (jj >= 0 && kingCheck == 1);
						/*for bishop and queen are four cases*/
						int k = r2 - 1, l = c2 + 1;
						do
						{
							if (chessBoard[k][l] == ' ')
							{
								k--;
								l++;
							}
							else if (chessBoard[k][l] == 'B' || chessBoard[k][l] == 'Q')
								kingCheck = 0;
						} while (k >= 0 && l < 8 && kingCheck == 1);
						int kk = r2 + 1, ll = c2 - 1;
						do
						{
							if (chessBoard[kk][ll] == ' ')
							{

								kk++; ll--;
							}
							else if (chessBoard[kk][ll] == 'B' || chessBoard[kk][ll] == 'Q')
								kingCheck = 0;
						} while (kk < 8 && ll >= 0 && kingCheck == 1);
						int m = r2 + 1, n = c2 + 1;
						do
						{
							if (chessBoard[m][n] == ' ')
							{
								m++;
								n++;
							}
							else if (chessBoard[m][n] == 'B' || chessBoard[m][n] == 'Q')
								kingCheck = 0;
						} while (m < 8 && n < 8 && kingCheck == 1);
						int mm = r2 - 1, nn = c2 - 1;
						do
						{
							if (chessBoard[mm][nn] == ' ')
							{
								mm--;
								nn--;
							}
							else if (chessBoard[mm][nn] == 'B' || chessBoard[mm][nn] == 'Q')
								kingCheck = 0;
						} while (mm >= 0 && nn >= 0 && kingCheck == 1);
						/*now i am going to check for all posible checks for knight */
//
//			/*1*//**/
						if (chessBoard[r2 - 2][c2 - 1] == 'N')
							kingCheck = 0;


						/*2*/
						/*if(chessBoard[r2][c2-2]=='n'&&kingCheck=1)*/
						if (chessBoard[r2 - 1][c2 - 2] == 'N')
						{
							kingCheck = 0;

						}
						/*3*/
						if (chessBoard[r2 + 1][c2 - 2] == 'N')
						{
							kingCheck = 0;

						}
						/*4*/
						if (chessBoard[r2 + 2][c2 - 1] == 'N')
						{
							kingCheck = 0;

						}
						/*5*/
						if (chessBoard[r2 + 1][c2 + 2] == 'N')
						{
							kingCheck = 0;

						}
						/*6*/
						if (chessBoard[r2 + 2][c2 + 1] == 'N')
						{
							kingCheck = 0;

						}
						/*7*/
						if (chessBoard[r2 - 2][c2 + 1] == 'N')
						{
							kingCheck = 0;

						}
						/*8*/
						if (chessBoard[r2 - 1][c2 + 2] == 'N')
						{
							kingCheck = 0;

						}




							if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122)
							{
								kingCheck = 0;
							}
							if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <=90 && kingCheck == 1)
							{
								if (chessBoard[r2][c2] == 'K')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over Black wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ' && kingCheck == 1)
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);

							}
						}
						/*3 done and checked*/
						else if (r2 == r1 - 1 && c2 == c1 + 1)
						{
						/*for pawn*/
						if (chessBoard[r2 - 1][c2 - 1] == 'P' || chessBoard[r2 + 1][c2 + 1] == 'P')
							kingCheck = 0;
						/*for rook one up and one down and for queen*/
						int i = r2 - 1, j = c2;
						do
						{
							if (chessBoard[i][j] == ' ')
							{
								i--;

							}
							else if (chessBoard[i][j] == 'R' || chessBoard[i][j] == 'Q')
							{
								kingCheck = 0;
							}


						} while (i >= 0 && kingCheck == 1);
						int ii = r2 + 1, jj = c2;
						do
						{
							if (chessBoard[ii][jj] == ' ')
								ii++;
							else if (chessBoard[ii][jj] == 'R' || chessBoard[ii][jj] == 'Q')
								kingCheck = 0;

						} while (ii < 8 && kingCheck == 1);
						//for rook right and left for rook and queen
						int k = r2, l = c2 + 1;
						do
						{
							if (chessBoard[k][l] == ' ')
								l++;
							else if (chessBoard[k][l] == 'R' || chessBoard[k][l] == 'Q')
								kingCheck = 0;
						} while (l < 8 && kingCheck == 1);
						int kk = r2, ll = c2 - 1;
						do
						{
							if (chessBoard[kk][ll] == ' ')
								ll--;
							else if (chessBoard[kk][ll] == 'R' || chessBoard[kk][ll] == 'Q')
								kingCheck = 0;
						} while (ll >= 0 && kingCheck == 1);
						/*for two cases of bishop along with queen*/
						int m = r2 - 1, n = c2 - 1;
						do
						{
							if (chessBoard[m][n] == ' ')
							{
								m--; n--;
							}
							else if (chessBoard[m][n] == 'B' || chessBoard[m][n] == 'Q')
								kingCheck = 0;
						} while (m >= 0 && n >= 0 && kingCheck == 1);
						int mm = r2 + 1, nn = c2 + 1;
						do
						{
							if (chessBoard[mm][nn] == ' ')
							{
								mm++; nn++;
							}
							else if (chessBoard[mm][nn] == 'B' || chessBoard[mm][nn] == 'Q')
								kingCheck = 0;

						} while (mm < 8 && nn < 8 && kingCheck == 1);
						/*now i am going to check for all posible checks for knight */
//
//			/*1*//**/
						if (chessBoard[r2 - 2][c2 - 1] == 'N')
							kingCheck = 0;


						/*2*/
						/*if(chessBoard[r2][c2-2]=='n'&&kingCheck=1)*/
						if (chessBoard[r2 - 1][c2 - 2] == 'N')
						{
							kingCheck = 0;

						}
						/*3*/
						if (chessBoard[r2 + 1][c2 - 2] == 'N')
						{
							kingCheck = 0;

						}
						/*4*/
						if (chessBoard[r2 + 2][c2 - 1] == 'N')
						{
							kingCheck = 0;

						}
						/*5*/
						if (chessBoard[r2 + 1][c2 + 2] == 'N')
						{
							kingCheck = 0;

						}
						/*6*/
						if (chessBoard[r2 + 2][c2 + 1] == 'N')
						{
							kingCheck = 0;

						}
						/*7*/
						if (chessBoard[r2 - 2][c2 + 1] == 'N')
						{
							kingCheck = 0;

						}
						/*8*/
						if (chessBoard[r2 - 1][c2 + 2] == 'N')
						{
							kingCheck = 0;

						}







							if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122)
							{
								kingCheck2 = 0;
							}
							if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <= 90 && kingCheck == 1)
							{
								if (chessBoard[r2][c2] == 'K')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over Black wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ' && kingCheck == 1)
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);

							}
						}
						/*4 and done and checked*/
						else if (r2 == r1 && c2 == c1 - 1)
						{

			
//						/*now i am going to check for all posible checks for knight */
//
///*1*//**/
						if (chessBoard[r2 - 2][c2 - 1] == 'N')
							kingCheck = 0;


						/*2*/
						/*if(chessBoard[r2][c2-2]=='n'&&kingCheck=1)*/
						if (chessBoard[r2 - 1][c2 - 2] == 'N')
						{
							kingCheck = 0;

						}
						/*3*/
						else	if (chessBoard[r2 + 1][c2 - 2] == 'N')
						{
							kingCheck = 0;

						}
						/*4*/
						else	if (chessBoard[r2 + 2][c2 - 1] == 'N')
						{
							kingCheck = 0;

						}
						/*5*/
					else if (chessBoard[r2 + 1][c2 + 2] == 'N')
						{
							kingCheck = 0;

						}
						/*6*/
					else	if (chessBoard[r2 + 2][c2 + 1] == 'N')
						{
							kingCheck = 0;

						}
						/*7*/
					else	if (chessBoard[r2 - 2][c2 + 1] == 'N')
						{
							kingCheck = 0;

						}
						/*8*/
					else	if (chessBoard[r2 - 1][c2 + 2] == 'N')
						{
							kingCheck = 0;

						}						/*for pawn*/

						if (chessBoard[r2 - 1][c2 - 1] == 'P')
							kingCheck = 0;

						/*for rook and queen two cases*/
						int i = r2 - 1, j = c2;
						do
						{
							if (chessBoard[i][j] == ' ')
								i--;
							else if (chessBoard[i][j] == 'R' || chessBoard[i][j] == 'Q')
								kingCheck = 0;
						} while (i >= 0 && kingCheck == 1);
						int ii = r2 + 1, jj = c2;
						do
						{
							if (chessBoard[ii][jj] == ' ')
								ii++;
							else if (chessBoard[ii][jj] == 'R' || chessBoard[ii][jj] == 'Q')
								kingCheck = 0;
						} while (ii < 8 && kingCheck == 1);
						/*for bishop and queen are four cases*/
						int k = r2 - 1, l = c2 + 1;
						do
						{
							if (chessBoard[k][l] == ' ')
							{
								k--;
								l++;
							}
							else if (chessBoard[k][l] == 'B' || chessBoard[k][l] == 'Q')
								kingCheck = 0;
						} while (k >= 0 && l < 8 && kingCheck == 1);
						int kk = r2 + 1, ll = c2 - 1;
						do
						{
							if (chessBoard[kk][ll] == ' ')
							{

								kk++; ll--;
							}
							else if (chessBoard[kk][ll] == 'B' || chessBoard[kk][ll] == 'Q')
								kingCheck = 0;
						} while (kk < 8 && ll >= 0 && kingCheck == 1);
						int m = r2 + 1, n = c2 + 1;

						do
						{
							if (chessBoard[m][n] == ' ')
							{
								m++;
								n++;
							}
							else if (chessBoard[m][n] == 'B' || chessBoard[m][n] == 'Q')
								kingCheck = 0;
						} while (m < 8 && n < 8 && kingCheck == 1);
						/*int mm = r2 - 1, nn = c2 - 1;
						do
						{
							if (chessBoard[mm][nn] == ' ')
							{
								mm--;
								nn--;
							}
							else if (chessBoard[mm][nn] == 'B' || chessBoard[mm][nn] == 'Q')
								kingCheck = 0;
						} while (mm >= 0 && nn >= 0 && kingCheck == 1);*/









							if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122)
							{
								kingCheck = 0;
							}
							if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <= 90 && kingCheck == 1)
							{
								if (chessBoard[r2][c2] == 'K')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over Black wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							if (chessBoard[r2][c2] == ' ' && kingCheck == 1)
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);

							}
						}
						/*5 in done and checked*/
						else if (r2 == r1 && c2 == c1 + 1)
						{
						/*for pawn*/
						if (chessBoard[r2 - 1][c2 + 1] == 'P')
							kingCheck = 0;
						/*for rook and queen two cases*/
						int i = r2 - 1, j = c2;
						do
						{
							if (chessBoard[i][j] == ' ')
								i--;
							else if (chessBoard[i][j] == 'R' || chessBoard[i][j] == 'Q')
								kingCheck = 0;
						} while (i>=0 && kingCheck==1);
						int ii = r2 + 1, jj = c2;
						do
						{
							if (chessBoard[ii][jj] == ' ')
								ii++;
							else if (chessBoard[ii][jj] == 'R' || chessBoard[ii][jj] == 'Q')
								kingCheck = 0;
						} while (ii<8 && kingCheck==1);
						/*for bishop and queen are four cases*/
						int k = r2 - 1, l = c2 + 1;
						do
						{
							if (chessBoard[k][l] == ' ')
							{
								k--;
								l++;
							}
							else if (chessBoard[k][l] == 'B' || chessBoard[k][l] == 'Q')
								kingCheck = 0;
						} while (k >= 0 && l < 8 && kingCheck == 1);
						int kk = r2 + 1, ll = c2 - 1;
						do
						{
							if (chessBoard[kk][ll] == ' ')
							{

								kk++; ll--;
							}
							else if (chessBoard[kk][ll] == 'B' || chessBoard[kk][ll] == 'Q')
								kingCheck = 0;
						} while (kk < 8 && ll >= 0 && kingCheck == 1);
						int m = r2 + 1, n = c2 + 1;

						do
						{
							if (chessBoard[m][n] == ' ')
							{
								m++;
								n++;
							}
							else if (chessBoard[m][n] == 'B' || chessBoard[m][n] == 'Q')
								kingCheck = 0;
						} while (m < 8 && n < 8 && kingCheck == 1);
						int mm = r2 - 1, nn = c2 - 1;
						do
						{
							if (chessBoard[mm][nn] == ' ')
							{
								mm--;
								nn--;
							}
							else if (chessBoard[mm][nn] == 'B' || chessBoard[mm][nn] == 'Q')
								kingCheck = 0;
						} while (mm >= 0 && nn >= 0 && kingCheck == 1);

						      

						/*now i am going to check for all posible checks for knight */

/*1*//**/
						if (chessBoard[r2 - 2][c2 - 1] == 'N')
							kingCheck = 0;


						/*2*/
						/*if(chessBoard[r2][c2-2]=='n'&&kingCheck=1)*/
						if (chessBoard[r2 - 1][c2 - 2] == 'N')
						{
							kingCheck = 0;

						}
						/*3*/
						if (chessBoard[r2 + 1][c2 - 2] == 'N')
						{
							kingCheck = 0;

						}
						/*4*/
						if (chessBoard[r2 + 2][c2 - 1] == 'N')
						{
							kingCheck = 0;

						}
						/*5*/
						if (chessBoard[r2 + 1][c2 + 2] == 'N')
						{
							kingCheck = 0;

						}
						/*6*/
						if (chessBoard[r2 + 2][c2 + 1] == 'N')
						{
							kingCheck = 0;

						}
						/*7*/
						if (chessBoard[r2 - 2][c2 + 1] == 'N')
						{
							kingCheck = 0;

						}
						/*8*/
						if (chessBoard[r2 - 1][c2 + 2] == 'N')
						{
							kingCheck = 0;

						}
						      


							if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122)
							{
								kingCheck = 0;
							}
							if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <= 90 && kingCheck == 1)
							{
								if (chessBoard[r2][c2] == 'K')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over Black wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ' && kingCheck== 1)
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);

							}
						}
						/*6 done and checked*/
						else if (r2 == r1 + 1 && c2 == c1 - 1)
						{
						/*for pawn*/
						if (chessBoard[r2 - 1][c2 - 1] == 'P')
							kingCheck = 0;
						/*for rook fur cases*/
						/*horizontally*/
						int i = r2 - 1, j = c2;
						do
						{
							if (chessBoard[i][j] == ' ')
								i--;
							else if (chessBoard[i][j] == 'R' || chessBoard[i][j] == 'Q')
								kingCheck = 0;
						} while (i>=0 && kingCheck==1);
						int ii = r2 + 1, jj = c2;
						do
						{
							if (chessBoard[ii][jj] == ' ')
								ii++;
							else if (chessBoard[ii][jj] == 'R' || chessBoard[ii][jj] == 'Q')
								kingCheck = 0;
						} while (ii<8 && kingCheck==1);
					/*	vertically*/
						int k = r2, l = c2 - 1;
						do
						{
							if (chessBoard[k][l] == ' ')
								l--;
							else if (chessBoard[k][l] == 'R' || chessBoard[k][l] == 'Q')
								kingCheck = 0;
						} while (l>=0 && kingCheck==1);

						int kk = r2, ll = c2 + 1;
						do
						{
							if (chessBoard[kk][ll] == ' ')
								ll++;
							else if (chessBoard[kk][ll] == 'R' || chessBoard[kk][ll] == 'Q')
								kingCheck = 0;
						} while (ll<8 && kingCheck==1 );
					    /*for two cases of bishop along with queen*/
						int m = r2 - 1, n = c2 - 1;
						do
						{
							if (chessBoard[m][n] == ' ')
							{
								m--; n--;
							}
							else if (chessBoard[m][n] == 'B' || chessBoard[m][n] == 'Q')
								kingCheck = 0;
						} while (m>=0 && n>=0 && kingCheck==1);
						int mm = r2 + 1, nn = c2 + 1;
						do
						{
							if (chessBoard[mm][nn] == ' ')
							{
								mm++; nn++;
							}
							else if (chessBoard[mm][nn] == 'B' || chessBoard[mm][nn] == 'Q')
								kingCheck = 0;

						} while (mm<8 && nn<8 && kingCheck==1);
						/*now i am going to check for all posible checks for knight */
//
//			/*1*//**/
						if (chessBoard[r2 - 2][c2 - 1] == 'N')
							kingCheck = 0;


						/*2*/
						/*if(chessBoard[r2][c2-2]=='n'&&kingCheck=1)*/
						if (chessBoard[r2 - 1][c2 - 2] == 'N')
						{
							kingCheck = 0;

						}
						/*3*/
						if (chessBoard[r2 + 1][c2 - 2] == 'N')
						{
							kingCheck = 0;

						}
						/*4*/
						if (chessBoard[r2 + 2][c2 - 1] == 'N')
						{
							kingCheck = 0;

						}
						/*5*/
						if (chessBoard[r2 + 1][c2 + 2] == 'N')
						{
							kingCheck = 0;

						}
						/*6*/
						if (chessBoard[r2 + 2][c2 + 1] == 'N')
						{
							kingCheck = 0;

						}
						/*7*/
						if (chessBoard[r2 - 2][c2 + 1] == 'N')
						{
							kingCheck = 0;

						}
						/*8*/
						if (chessBoard[r2 - 1][c2 + 2] == 'N')
						{
							kingCheck = 0;

						}



							if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122)
							{
								kingCheck = 0;
							}
							if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <= 90 && kingCheck == 1)
							{
								if (chessBoard[r2][c2] == 'K')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over Black wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							else if (chessBoard[r2][c2] == ' ' && kingCheck == 1)
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);

							}
						}
						/*7 done and ckecked*/
						else if (r2 == r1 + 1 && c2 == c1)
						{
						/*now i am going to check for all posible checks for knight */
//
//			/*1*//**/
						if (chessBoard[r2 - 2][c2 - 1] == 'N')
						    kingCheck = 0;
							
						
						/*2*/
						/*if(chessBoard[r2][c2-2]=='n'&&kingCheck=1)*/
						if (chessBoard[r2 - 1][c2 - 2] == 'N')
						{
							kingCheck = 0;
							
						}
						/*3*/
						if (chessBoard[r2 + 1][c2 - 2] == 'N')
						{
							kingCheck = 0;
						
						}
						/*4*/
						if (chessBoard[r2 + 2][c2 - 1] == 'N')
						{
							kingCheck = 0;
							
						}
						/*5*/
						if (chessBoard[r2 + 1][c2 + 2] == 'N' )
						{
							kingCheck = 0;
							
						}
						/*6*/
						if (chessBoard[r2 + 2][c2 + 1] == 'N')
						{
							kingCheck = 0;
							
						}
						/*7*/
						if (chessBoard[r2 - 2][c2 + 1] == 'N')
						{
							kingCheck = 0;
							
						}
						/*8*/
						if (chessBoard[r2 - 1][c2 + 2] == 'N' )
						{
							kingCheck = 0;
							
						}
						/*for pawns*/
						if (chessBoard[r2 - 1][c2 + 1] == 'P' || chessBoard[r2 - 1][c2 - 1] == 'P')
							kingCheck = 0;
						/*for rook only two cases*/
						int i = r2, j = c2 + 1;
						do
						{
							if (chessBoard[i][j] == ' ')
								j++;
							else if (chessBoard[i][j] == 'R' || chessBoard[i][j]=='Q')
								kingCheck = 0;
						} while (j<8&& i==r2 && kingCheck==1);
						int ii = r2, jj = c2 - 1;
						do
						{
							if (chessBoard[ii][jj] == ' ')
								jj--;
							else if (chessBoard[ii][jj] == 'R'|| chessBoard[ii][jj]=='Q')
								kingCheck = 0;
						} while (jj>=0 && kingCheck==1);
						/*for bishop and queen are four cases*/
						int k = r2 - 1, l = c2 + 1;
						do
						{
							if (chessBoard[k][l] == ' ')
							{
								k--;
								l++;
							}
							else if (chessBoard[k][l] == 'B' || chessBoard[k][l] == 'Q')
								kingCheck = 0;
						} while (k>=0 && l<8 && kingCheck==1);
						int kk = r2 + 1, ll = c2 - 1;
						do
						{
							if (chessBoard[kk][ll] == ' ')
							{

								kk++; ll--;
							}
							else if(chessBoard[kk][ll]=='B' || chessBoard[kk][ll]=='Q')
								kingCheck=0;
						} while (kk<8 && ll>=0 && kingCheck==1);
						int m = r2 + 1, n = c2 + 1;

						do
						{
							if (chessBoard[m][n] == ' ')
							{
								m++;
								n++;
							}
							else if (chessBoard[m][n] == 'B' || chessBoard[m][n] == 'Q')
								kingCheck = 0;
						} while (m<8 && n<8 && kingCheck==1);
						int mm = r2 - 1, nn = c2 - 1;
						do
						{
							if (chessBoard[mm][nn] == ' ')
							{
								mm--;
								nn--;
							}
							else if(chessBoard[mm][nn] == 'B' || chessBoard[mm][nn] == 'Q')
								kingCheck = 0;
						} while (mm>=0 && nn>=0 && kingCheck==1);
						
							if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122)
							{
								kingCheck = 0;
							}
							if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <= 90 && kingCheck == 1)
							{
								if (chessBoard[r2][c2] == 'K')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over Black wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
								
							}
							else if (chessBoard[r2][c2] == ' ' && kingCheck == 1)
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);

							}
						}
						/*8 done and ckecked */
						else if (r2 == r1 + 1 && c2 == c1 + 1)
						{
						/*for pawn*/
							if (chessBoard[r2 - 1][c2 + 1] == 'P')
							kingCheck = 0;
						/*for rook one up and one down and for queen*/
						int i = r2-1, j = c2 ;
						do
						{
							if (chessBoard[i][j] == ' ')
							{
								i--;
								
							}
							else if (chessBoard[i][j] == 'R' || chessBoard[i][j]=='Q')
							{
								kingCheck = 0;
							}
							

						} while (i>=0&& kingCheck==1);
						int ii = r2 + 1, jj = c2;
						do
						{
							if (chessBoard[ii][jj] == ' ')
								ii++;
							else if (chessBoard[ii][jj] == 'R' || chessBoard[ii][jj]=='Q')
								kingCheck = 0;

						} while (ii < 8 && kingCheck == 1);
						//for rook right and left for rook and queen
						int k = r2, l = c2 + 1;
						do
						{
							if (chessBoard[k][l] == ' ')
								l++;
							else if (chessBoard[k][l] == 'R' || chessBoard[k][l] == 'Q')
								kingCheck = 0;
						} while (l<8 && kingCheck==1);
						int kk = r2, ll = c2 - 1;
						do
						{
							if (chessBoard[kk][ll] == ' ')
								ll--;
							else if (chessBoard[kk][ll] == 'R' || chessBoard[kk][ll] == 'Q')
								kingCheck = 0;
						} while (ll>=0 && kingCheck==1);
						/*this is for diagonal check for bishop and for queen*/
						int m = r2 - 1, n = c2 + 1;
						do
						{
							if (chessBoard[m][n] == ' ')
							{
								m--;
								n++;
							}
							else if (chessBoard[m][n] == 'B' || chessBoard[m][n] == 'Q')
								kingCheck = 0;
						} while (m>=0 && n<8 && kingCheck==1);
						int mm = r2 + 1, nn = c2 - 1;
						do
						{
							if (chessBoard[mm][nn] == ' ')
							{
								mm++;
								nn--;
							}
							else if (chessBoard[mm][nn] == 'B' || chessBoard[mm][nn] == 'Q')
								kingCheck = 0;
						} while (mm<8 && nn>=0 && kingCheck==1);
//						/*now i am going to check for all posible checks for knight */
////
////			/*1*//**/
						if (chessBoard[r2 - 2][c2 - 1] == 'N')
						    kingCheck = 0;
							
						
						/*2*/
						/*if(chessBoard[r2][c2-2]=='n'&&kingCheck=1)*/
						if (chessBoard[r2 - 1][c2 - 2] == 'N')
						{
							kingCheck = 0;
							
						}
						/*3*/
						if (chessBoard[r2 + 1][c2 - 2] == 'N')
						{
							kingCheck = 0;
						
						}
						/*4*/
						if (chessBoard[r2 + 2][c2 - 1] == 'N')
						{
							kingCheck = 0;
							
						}
						/*5*/
						if (chessBoard[r2 + 1][c2 + 2] == 'N' )
						{
							kingCheck = 0;
							
						}
						/*6*/
						if (chessBoard[r2 + 2][c2 + 1] == 'N')
						{
							kingCheck = 0;
							
						}
						/*7*/
						if (chessBoard[r2 - 2][c2 + 1] == 'N')
						{
							kingCheck = 0;
							
						}
						/*8*/
						if (chessBoard[r2 - 1][c2 + 2] == 'N' )
						{
							kingCheck = 0;
							
						}
						
						
						    
							if (chessBoard[r2][c2] >= 97 && chessBoard[r2][c2] <= 122)
							{
								kingCheck = 0;
							}
							if (chessBoard[r2][c2] >= 65 && chessBoard[r2][c2] <= 90 && kingCheck==1)
							{
								if (chessBoard[r2][c2] == 'K')
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
									cout << "Game over Black wins\n";
									return 0;
								}
								else
								{
									killPlayer(chessBoard, r1, c1, r2, c2);
									checkMove = 0;
									system("CLS");
									displayBoard(chessBoard);
								}
							}
							 if (chessBoard[r2][c2] == ' ' && kingCheck == 1)
							{
								swapTurns(chessBoard, r1, c1, r2, c2);
								checkMove = 0;
								system("CLS");
								displayBoard(chessBoard);

							}
						}
						else
						{
							system("CLS");
							displayBoard(chessBoard);
							cout << "This is an invalid move:\n";
						}
					}
					bool check;
					check = checkk(chessBoard, turn, r2, c2);
					if (check == 0 && checkMove == 0)
					{
						system("CLS");
						displayBoard(chessBoard);

						cout << "White king is under attack \n";
					}
					





				}



				else
				{
					system("CLS");
					displayBoard(chessBoard);
					cout << "This is an invalid move Enter again\n";
				}
			}

			/*swapTurns(chessBoard, r1, c1, r2, c2);*/
			/*system("CLS");
			displayBoard(chessBoard);*/
		}
		ofstream games;
		games.open("game.txt");
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				games << chessBoard[i][j];


			}
			games << endl;
		}
	
	}
}

void displayBoard(char chess[8][8])
{
	int k = 8;
	cout << "               a   b   c   d   e   f   g   h" << endl << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << "          ";
		cout << k;
		/*k--;*/
		cout << "   |";
		for (int j = 0; j < 8; j++)
		{
			cout << chess[i][j];
			cout << " | ";
		}
		cout << " ";
		cout << k;
		k--;
		cout << endl; cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << endl;

	}cout << "               a   b   c   d   e   f   g   h";
	cout << endl;
}
int findRow(char moves)
{
	if (moves == '8')
		return 0;
	if (moves == '7')
		return 1;
	if (moves == '6')
		return 2;
	if (moves == '5')
		return 3;
	if (moves == '4')
		return 4;
	if (moves == '3')
		return 5;
	if (moves == '2')
		return 6;
	if (moves == '1')
		return 7;
}
int findCol(char moves)
{
	if (moves == 'a')
		return 0;
	if (moves == 'b')
		return 1;
	if (moves == 'c')
		return 2;
	if (moves == 'd')
		return 3;
	if (moves == 'e')
		return 4;
	if (moves == 'f')
		return 5;
	if (moves == 'g')
		return 6;
	if (moves == 'h')
		return 7;
}
void swapTurns(char chessBoard[8][8], int r1, int c1, int r2, int c2)
{
	char temp;
	temp = chessBoard[r1][c1];
	chessBoard[r1][c1] = chessBoard[r2][c2];
	chessBoard[r2][c2] = temp;
}
void killPlayer(char chessBoard[8][8], int r1, int c1, int r2, int c2)
{

	chessBoard[r2][c2] = chessBoard[r1][c1];
	chessBoard[r1][c1] = ' ';
}
bool checkk(char chessBoard[8][8], bool turn,int r2,int c2)
{
	bool check = 1;
	char a;
	if (turn == 0)
		a = 'k';
	else
		a = 'K';
	char rook, queen, bishop, pawn, knight;
	if (a == 'k')
	{
		rook = 'R';
		queen = 'Q';
		bishop = 'B';
		pawn = 'P';
		knight = 'K';
	}
	else
	{
		rook = 'r';
		queen = 'q';
		bishop = 'b';
		pawn = 'p';
		knight = 'n';
	}
	
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (chessBoard[i][j] == a)
				break;

		}
		if(chessBoard[i][j]==a)
				break;
	}
	int r1 = i;
	int c1 = j;
	if (r2 == r1 - 1 && c2 == c1 - 2)
	{
		if (chessBoard[r2][c2] == knight)

		{
			check = 0;
			return check;

		}

	}
	else if (r2 == r1 + 1 && c2 == c1 - 2)
	{
		if (chessBoard[r2][c2] == knight)

		{
			check = 0;
			return check;
		}

	}
	else if (r2 == r1 + 2 && c2 == c1 - 1)
	{
		if (chessBoard[r2][c2] == knight)

		{
			check = 0;
			return check;
		}

	}
	else if (r2 == r1 + 2 && c2 == c1 + 1)
	{
		if (chessBoard[r2][c2] == knight)

		{
			check = 0;
			return check;
		}

	}
	else if (r2 == r1 - 1 && c2 == c1 + 2)
	{
		if (chessBoard[r2][c2] == knight)

		{
			check = 0;
			return check;
		}


	}
	else if (r2 == r1 - 2 && c2 == c1 - 1)
	{
		if (chessBoard[r2][c2] == knight)

		{
			check = 0;
			return check;
		}
	}
	else if (r2 == r1 + 1 && c2 == c1 + 2)
	{
		if (chessBoard[r2][c2] == knight)

		{
			check = 0;
			return check;
		}
	}
	else if (r2 == r1 - 2 && c2 == c1 + 1)
	{
		if (chessBoard[r2][c2] == knight)

		{
			check = 0;
			return check;
		}

	}
	if (a == 'k')
	{
		
		if (chessBoard[r1 - 1][c1 + 1] == 'P' || chessBoard[r1 - 1][c1 - 1] == 'P')
		{
			check = 0;
			return check;
		}
		
	}
	if (a == 'K')
	{
		if (chessBoard[r1 + 1][c1 - 1] == 'p' || chessBoard[r1 + 1][c1 - 1] == 'p')
		{
			check = 0;
			return check;
		}
	}

	if (a == 'k')
	{

	}







   if (r2 == r1 - 1 || r2 == r1 - 2 || r2 == r1 - 3 || r2 == r1 - 3 || r2 == r1 - 4 || r2 == r1 - 5 || r2 == r1 - 6 || r2 == r1 - 7 || r2 == r1 + 1 || r2 == r1 + 2 || r2 == r1 + 3 || r2 == r1 + 4 || r2 == r1 + 5 || r2 == r1 + 6 || r2 == r1 + 7)
	{
		if (c2 == c1)
		{
			if (r1 > r2)
			{
				for (int i = r1 - 1; i >= r2; i--)
				{
					if (chessBoard[i][c1] == rook || chessBoard[i][c1]==queen)
					{
						check = 0;
						return check;
					}
				}
			}

			if (r1 < r2)
			{
				for (int i = r1 + 1; i <= r2;)
				{
					if (chessBoard[i][c1] == rook || chessBoard[i][c1] == queen)
					{
						check = 0;
						return check;
					}
					i++;
				}
			}
		}
	} 
	if (c2 == c1 - 1 || c2 == c1 - 2 || c2 == c1 - 3 || c2 == c1 - 4 || c2 == c1 - 5 || c2 == c1 - 6 || c2 == c1 - 7 || c2 == c1 + 1 || c2 == c1 + 2 || c2 == c1 + 3 || c2 == c1 + 4 || c2 == c1 + 5 || c2 == c1 + 6 || c2 == c1 + 7)
	{
		if (r2 == r1)
		{
			if (c1 > c2)
			{
				for (int i = c1 - 1; i >= c2; i--)
				{
					if (chessBoard[r1][i] == rook|| chessBoard[r1][i] ==queen )
					{
						check = 0;
						return check;
					}
				}
			}
			if (c2 > c1)
			{
				for (int i = c1 + 1; i <= c2; i++)
				{
					if (chessBoard[r1][i] == rook|| chessBoard[r1][i] == queen)
					{
						/*checkMove = 0;*/
						check = 0;
						return check;
					}
				}
			}


		}
	}
	


	if (r2 == (r1 + c2) - c1 || r2 == c1 - (r1 + c2) || (r1 + c1 == r2 + c2))
	{
		if (r1 < r2 && c1 < c2)
		{
			for (int i = r1 + 1, j = c1 + 1; i <= r2, j <= c2; i++, j++)
			{
				if (chessBoard[i][j] == bishop || chessBoard[i][j] == queen)
				{
					check = 0;
					return check;
				}
			}

		}
		if (r1 > r2 && c1 < c2)
		{
			for (int i = r1 - 1, j = c1 + 1; i >= r2, j <= c2; i--, j++)
				if (chessBoard[i][j] == bishop || chessBoard[i][j] == queen)
				{
					check = 0;
					return check;
				}


		}
		if (r1<r2 && c1>c2)
		{
			for (int i = r1 + 1, j = c1 - 1; i <= r2, j >= c2; i++, j--)
			{
				if (chessBoard[i][j] == bishop || chessBoard[i][j] == queen)
				{
					check = 0;
					return check;
				}
			}
		}
		if (r1 > r2 && c1 > c2)
		{
			for (int i = r1 - 1, j = c1 - 1; i >= r2, j >= c2; i--, j--)
			{
				if (chessBoard[i][j] == bishop || chessBoard[i][j] == queen)
				{
					check = 0;
					return check;
				}
			}
		}




	}





	
	
	

}
void promotion(char chessBoard[8][8], int r1, int c1, int r2, int c2, char promo)
{
	
	if (promo == 'Q')
	{
		chessBoard[r1][c1] = ' ';
		chessBoard[r2][c2] = 'Q';
	}
	else if (promo == 'B')
	{
		chessBoard[r1][c1] = ' ';
		chessBoard[r2][c2] = 'B';
	}
	else if (promo == 'R')
	{
		chessBoard[r1][c1] = ' ';
		chessBoard[r2][c2] = 'R';
	}
	else if (promo == 'N')
	{
		chessBoard[r1][c1] = ' ';
		chessBoard[r2][c2] = 'N';
	}
	
	if (promo == 'q')
	{
		chessBoard[r1][c1] = ' ';
		chessBoard[r2][c2] = 'q';
	}
	else if (promo == 'b')
	{
		chessBoard[r1][c1] = ' ';
		chessBoard[r2][c2] = 'b';
	}
	else if (promo == 'r')
	{
		chessBoard[r1][c1] = ' ';
		chessBoard[r2][c2] = 'r';
	}
	else if (promo == 'n')
	{
		chessBoard[r1][c1] = ' ';
		chessBoard[r2][c2] = 'n';
	}


}

void save(char chessBoard[8][8])
	{
		ofstream game;
		game.open("game.txt");
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				game<<chessBoard[i][j];
			}
		}
		game.close();
	}
void load(char chessBoard[8][8])
{
	ifstream game("game.txt");
	game.get();
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			game >> chessBoard[i][j];
		}
	}
	game.close();
	displayBoard(chessBoard);

}
