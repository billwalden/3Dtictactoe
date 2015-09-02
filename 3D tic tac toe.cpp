//Lab Ten: 3D TicTacToe
//Name: William Walden
//Date: 11/20/14                        
//Section 1

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::string;
using std::cout;
using std::cin;
using std::time;
using std::srand;
using std::rand;
using std::endl;


class Square //create class of board squares
{
	char Identity;  //Identitifies which player holds the space
	bool Occupied; //Tells if the space is occupied.
		
public: 

	Square(); 
	~Square(); 

	void SetIdentity(int);
	void Move(char player);
	char GetIdent() const {return Identity;}
	bool GetOcc() const {return Occupied;
};

class TicTacToe //class which holds the board and gameplay
{
	char Human;
	char CPU;
	bool Winner;
	char Turn;  //stores whose turn it is
	int counter;
	Square ArSquares[3][9]; //array of objects 
	char firstMove;
	
public:	
	TicTacToe();
	~TicTacToe();
	
	int Play();
	int CheckForWinner();
	void DisplayBoard() const;
	void Count() {counter++;}
	int GetCount() {return counter;}
	int cpuMove();
	void SetFirst(char player) {firstMove = player;}
	char GetFirst() {return firstMove;}
};

main()
{
		
	TicTacToe Game1; 
	Game1.Play(); 
}

Square::Square() : Occupied(false) /
{	
}

Square::~Square()
{
}

void Square::Move(char player)
{
	Identity = player;
	Occupied = true;
}

void Square::SetIdentity(int numb)
{
	Identity = (char) numb;
}

TicTacToe::TicTacToe() : Human('\0'), CPU('\0'), Winner(false), counter(0)
	{
		int i;
		int x;
		
		for(x = 0; x < 3; x++)
		{
			for(i = 0; i < 9; i++)
			{
				ArSquares[x][i].SetIdentity(i + 49);
			}
		}
			srand(time(0));
			int Number = rand() % 2 + 1;
		
			
			if(Number == 1)
				Turn = 'O';
			else
				Turn = 'X';
	}

TicTacToe::~TicTacToe()
{
}

int TicTacToe::Play()
{
	
	while(Human != 'X' && Human != 'O')
	{
		cout << "Welcome to Bill's 3D tic tac toe game!\n\n";
		cout << "Would you like to be player X or O?\n";
		cout << "Enter X or O: ";	cin >> Human;
		Human = toupper(Human);
	
		if(Human == 'X')
			CPU = 'O';
		else
			CPU = 'X';
	}
		
	while(!Winner) 
	{
		while(Turn == CPU)
		{
			cpuMove();
		}
		CheckForWinner();
		if(Winner)
			break;
		else{};
		DisplayBoard();
		
		if(counter == 0)
			cout << "Your move first.\n";
		else if(counter == 1)
			cout << "The CPU moved first.\n";
			
		while(Turn == Human)
		{
			int Number1 = 0;
			int Number2 = 0;
			
			cout << "Where would you like to move?\n";
			cout << "Enter board number: ";
			cin >> Number1;
			cout << "\nEnter space number: ";
			cin >> Number2;
			
			if(!ArSquares[Number1 - 1][Number2 - 1].GetOcc())
				{
					ArSquares[Number1 - 1][Number2 - 1].Move(Human);
					Count();
					Turn = CPU;
				}
			else
			{
				cout << "\nSpace is already occupied. Choose a different one.\n\n";
			}
		}
		
		CheckForWinner();
		
	}
	char response;
	cout << "\n Play again?  Y/N:  "; cin >> response;
	response = tolower(response);
	
	if(response == 'y')
	{
		this->~TicTacToe();
		TicTacToe NewGame;
		NewGame.Play();
	}
	return 0;

	
}

int TicTacToe::CheckForWinner()
{


	if(ArSquares[0][0].GetIdent() == ArSquares[1][1].GetIdent() && ArSquares[0][0].GetIdent() == ArSquares[2][2].GetIdent())
	{
		Winner = true;
		DisplayBoard();
		printf("Player %c wins!!!", ArSquares[0][0].GetIdent());
		return 0;
	}
	
	if(ArSquares[0][2].GetIdent() == ArSquares[1][1].GetIdent() && ArSquares[0][2].GetIdent() == ArSquares[2][0].GetIdent())
	{
		Winner = true;
		DisplayBoard();
		printf("Player %c wins!!!", ArSquares[0][2].GetIdent());
		return 0;
	}
	
	if(ArSquares[0][0].GetIdent() == ArSquares[1][3].GetIdent() && ArSquares[0][0].GetIdent() == ArSquares[2][6].GetIdent())
	{
		Winner = true;
		DisplayBoard();
		printf("Player %c wins!!!", ArSquares[0][0].GetIdent());
		return 0;
	}
	
	if(ArSquares[0][6].GetIdent() == ArSquares[1][3].GetIdent() && ArSquares[0][6].GetIdent() == ArSquares[2][0].GetIdent())
	{
		Winner = true;
		DisplayBoard();
		printf("Player %c wins!!!", ArSquares[0][6].GetIdent());
		return 0;
	}
	
	if(ArSquares[0][6].GetIdent() == ArSquares[1][7].GetIdent() && ArSquares[0][6].GetIdent() == ArSquares[2][8].GetIdent())
	{
		Winner = true;
		DisplayBoard();
		printf("Player %c wins!!!", ArSquares[0][6].GetIdent());
		return 0;
	}
	
	if(ArSquares[0][8].GetIdent() == ArSquares[1][7].GetIdent() && ArSquares[0][8].GetIdent() == ArSquares[2][6].GetIdent())
	{
		Winner = true;
		DisplayBoard();
		printf("Player %c wins!!!", ArSquares[0][8].GetIdent());
		return 0;
	}
	
	if(ArSquares[0][2].GetIdent() == ArSquares[1][5].GetIdent() && ArSquares[0][2].GetIdent() == ArSquares[2][8].GetIdent())
	
	{
		Winner = true;
		DisplayBoard();
		printf("Player %c wins!!!", ArSquares[0][2].GetIdent());
		return 0;
	}
	
	if(ArSquares[0][8].GetIdent() == ArSquares[1][5].GetIdent() && ArSquares[0][8].GetIdent() == ArSquares[2][2].GetIdent())
	{
		Winner = true;
		DisplayBoard();
		printf("Player %c wins!!!", ArSquares[0][8].GetIdent());
		return 0;
	}
	
	if(ArSquares[0][1].GetIdent() == ArSquares[1][4].GetIdent() && ArSquares[0][1].GetIdent() == ArSquares[2][7].GetIdent())
	{
		Winner = true;
		DisplayBoard();
		printf("Player %c wins!!!", ArSquares[0][1].GetIdent());
		return 0;
	}
	
	if(ArSquares[0][7].GetIdent() == ArSquares[1][4].GetIdent() && ArSquares[0][7].GetIdent() == ArSquares[2][1].GetIdent())
	{
		Winner = true;
		DisplayBoard();
		printf("Player %c wins!!!", ArSquares[0][7].GetIdent());
		return 0;
	}
	
	if(ArSquares[0][3].GetIdent() == ArSquares[1][4].GetIdent() && ArSquares[0][3].GetIdent() == ArSquares[2][5].GetIdent())
	{
		Winner = true;
		DisplayBoard();
		printf("Player %c wins!!!", ArSquares[0][3].GetIdent());
		return 0;
	}
	
	if(ArSquares[0][5].GetIdent() == ArSquares[1][4].GetIdent() && ArSquares[0][5].GetIdent() == ArSquares[2][3].GetIdent())
	
	{
		Winner = true;
		DisplayBoard();
		printf("Player %c wins!!!", ArSquares[0][5].GetIdent());
		return 0;
	}
	
	if(ArSquares[0][0].GetIdent() == ArSquares[1][4].GetIdent() && ArSquares[0][0].GetIdent() == ArSquares[2][8].GetIdent())
	{
		Winner = true;
		DisplayBoard();
		printf("Player %c wins!!!", ArSquares[0][0].GetIdent());
		return 0;
	}
	
	if(ArSquares[0][8].GetIdent() == ArSquares[1][4].GetIdent() && ArSquares[0][8].GetIdent() == ArSquares[2][0].GetIdent())
	{
		Winner = true;
		DisplayBoard();
		printf("Player %c wins!!!", ArSquares[0][8].GetIdent());
		return 0;
	}
	
	if(ArSquares[0][2].GetIdent() == ArSquares[1][4].GetIdent() && ArSquares[0][2].GetIdent() == ArSquares[2][6].GetIdent())
	{
		Winner = true;
		DisplayBoard();
		printf("Player %c wins!!!", ArSquares[0][2].GetIdent());
		return 0;
	}
	
	if(ArSquares[0][6].GetIdent() == ArSquares[1][4].GetIdent() && ArSquares[0][6].GetIdent() == ArSquares[2][2].GetIdent())
	{
		Winner = true;
		DisplayBoard();
		printf("Player %c wins!!!", ArSquares[0][6].GetIdent());
		return 0;
	}
	
	int x;
	int i;
	for(x = 0; x < 3;x++)
	{
	
		if(ArSquares[x][0].GetIdent() == ArSquares[x][1].GetIdent() && ArSquares[x][1].GetIdent() == ArSquares[x][2].GetIdent())
		{
			Winner = true;
			DisplayBoard();
			printf("Player %c wins!!!", ArSquares[x][0].GetIdent());
			return 0;
		}
		if(ArSquares[x][0].GetIdent() == ArSquares[x][3].GetIdent() && ArSquares[x][3].GetIdent() == ArSquares[x][6].GetIdent())
		{
			Winner = true;
			DisplayBoard();
			printf("Player %c wins!!!", ArSquares[x][0].GetIdent());
			return 0;
		}
		if(ArSquares[x][0].GetIdent() == ArSquares[x][4].GetIdent() && ArSquares[x][4].GetIdent() == ArSquares[x][8].GetIdent())
		{
			Winner = true;
			DisplayBoard();
			printf("Player %c wins!!!", ArSquares[x][0].GetIdent());
			return 0;
		}
		if(ArSquares[x][1].GetIdent() == ArSquares[x][4].GetIdent() && ArSquares[x][4].GetIdent() == ArSquares[x][7].GetIdent())
		{
			Winner = true;
			DisplayBoard();
			printf("Player %c wins!!!", ArSquares[x][1].GetIdent());
			return 0;
		}
		if(ArSquares[x][2].GetIdent() == ArSquares[x][4].GetIdent() && ArSquares[x][4].GetIdent() == ArSquares[x][6].GetIdent())
		{
			Winner = true;
			DisplayBoard();
			printf("\nPlayer %c wins!!!\n", ArSquares[x][2].GetIdent());
			return 0;
		}
		if(ArSquares[x][2].GetIdent() == ArSquares[x][5].GetIdent() && ArSquares[x][5].GetIdent() == ArSquares[x][8].GetIdent())
		{
			Winner = true;
			DisplayBoard();
			printf("\nPlayer %c wins!!!\n", ArSquares[x][2].GetIdent());
			return 0;
		}
		if(ArSquares[x][3].GetIdent() == ArSquares[x][4].GetIdent() && ArSquares[x][4].GetIdent() == ArSquares[x][5].GetIdent())
		{
			Winner = true;
			DisplayBoard();
			printf("\nPlayer %c wins!!!\n", ArSquares[x][3].GetIdent());
			return 0;
		}
		if(ArSquares[x][6].GetIdent() == ArSquares[x][7].GetIdent() && ArSquares[x][7].GetIdent() == ArSquares[x][8].GetIdent())
		{
			Winner = true;
			DisplayBoard();
			printf("\nPlayer %c wins!!!\n", ArSquares[x][6].GetIdent());
			return 0;
		}
		else{};
		for(i = 0; i < 9; i++)
		{
			if(ArSquares[0][i].GetOcc() == true && ArSquares[1][i].GetOcc() == true && ArSquares[2][i].GetOcc() == true )	
			{
				if(ArSquares[0][i].GetIdent() == ArSquares[1][i].GetIdent() && ArSquares[1][i].GetIdent() == ArSquares[2][i].GetIdent())
				{
					Winner = true;
					DisplayBoard();
					printf("\nPlayer %c wins!!!\n", ArSquares[0][i].GetIdent());
					return 0;
				}
			}
			else{}
				
		}
		if(GetCount() == 27)
		{
			Winner = true;
			DisplayBoard();
			printf("\nIt's a draw!\n");
			return 0;
		}	
		
	
		
	}
	
}

void TicTacToe::DisplayBoard() const //displays the board
{
		printf("\n\n   %-3c  |    %-3c  |   %-3c\n", ArSquares[0][0].GetIdent(), ArSquares[0][1].GetIdent(), ArSquares[0][2].GetIdent());
		printf(" --------------------------\n");
		printf("   %-3c  |    %-3c  |   %-3c", ArSquares[0][3].GetIdent(), ArSquares[0][4].GetIdent(), ArSquares[0][5].GetIdent());
		cout << "\t #1" << endl;
		printf(" --------------------------\n");
		printf("   %-3c  |    %-3c  |   %-3c \n\n", ArSquares[0][6].GetIdent(), ArSquares[0][7].GetIdent(), ArSquares[0][8].GetIdent());
		
		printf("\n   		%-3c  |    %-3c  |   %-3c\n", ArSquares[1][0].GetIdent(), ArSquares[1][1].GetIdent(), ArSquares[1][2].GetIdent());
		printf(" 	     --------------------------\n");
		printf("   		%-3c  |    %-3c  |   %-3c", ArSquares[1][3].GetIdent(), ArSquares[1][4].GetIdent(), ArSquares[1][5].GetIdent());
		cout << "\t\t #2" << endl;
		printf(" 	     --------------------------\n");
		printf("   		%-3c  |    %-3c  |   %-3c \n\n", ArSquares[1][6].GetIdent(), ArSquares[1][7].GetIdent(), ArSquares[1][8].GetIdent());
		
		printf("\n   				%-3c  |    %-3c  |   %-3c\n", ArSquares[2][0].GetIdent(), ArSquares[2][1].GetIdent(), ArSquares[2][2].GetIdent());
		printf(" 			     --------------------------\n");
		printf("   				%-3c  |    %-3c  |   %-3c", ArSquares[2][3].GetIdent(), ArSquares[2][4].GetIdent(), ArSquares[2][5].GetIdent());
		cout << "\t\t #3" << endl;
		printf(" 			     --------------------------\n");
		printf("   				%-3c  |    %-3c  |   %-3c \n\n", ArSquares[2][6].GetIdent(), ArSquares[2][7].GetIdent(), ArSquares[2][8].GetIdent());
		
		
		
	
}
int TicTacToe::cpuMove()
{
	int x;
	int i;
	
	if(counter == 0)
		{
			SetFirst(CPU);
			ArSquares[1][4].Move(CPU);
			Count();
			Turn = Human; return 0;
		}
	else if (counter == 1)
	{
		if(ArSquares[1][4].GetIdent() == Human)
		{
			ArSquares[0][0].Move(CPU);
			Count();
			Turn = Human; return 0;
		}
		else if(!ArSquares[1][4].GetOcc())
		{
			ArSquares[1][4].Move(CPU);
			Count();
			Turn = Human; return 0;
		}
	}

	else{}
	
	if(GetFirst() == CPU && GetCount() == 2)
		{
			for(x = 0; x < 3; x++)
			{
				if(ArSquares[x][1].GetIdent() == Human || ArSquares[x][2].GetIdent() == Human) 
				{
					ArSquares[0][8].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
				else if(ArSquares[x][0].GetIdent() == Human || ArSquares[x][5].GetIdent() == Human || ArSquares[x][8].GetIdent() == Human)
				{
					ArSquares[0][6].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
				else
				{
					ArSquares[0][8].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
				
				
			}
			ArSquares[0][2].Move(CPU);
			Count();
			Turn = Human; return 0;	
		}
		
	for(x = 0; x < 3;x++)
	{
		if(ArSquares[x][0].GetIdent() == CPU && ArSquares[x][1].GetIdent() == CPU)
			{
				if(!ArSquares[x][2].GetOcc())
				{
					ArSquares[x][2].Move(CPU);
					Count();
					Turn == Human; return 0;
				}
			}
		if(ArSquares[x][1].GetIdent() == CPU && ArSquares[x][2].GetIdent() == CPU)
			{
				if(!ArSquares[x][0].GetOcc())
				{
					ArSquares[x][0].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][0].GetIdent() == CPU && ArSquares[x][2].GetIdent() == CPU)
			{
				if(!ArSquares[x][1].GetOcc())
				{
					ArSquares[x][1].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][0].GetIdent() == CPU && ArSquares[x][3].GetIdent() == CPU)
			{
				if(!ArSquares[x][6].GetOcc())
				{
					ArSquares[x][6].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][3].GetIdent() == CPU && ArSquares[x][6].GetIdent() == CPU)
			{
				if(!ArSquares[x][0].GetOcc())
				{
					ArSquares[x][0].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][0].GetIdent() == CPU && ArSquares[x][6].GetIdent() == CPU)
			{
				if(!ArSquares[x][3].GetOcc())
				{
					ArSquares[x][3].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][0].GetIdent() == CPU && ArSquares[x][4].GetIdent() == CPU)
			{
				if(!ArSquares[x][8].GetOcc())
				{
					ArSquares[x][8].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][4].GetIdent() == CPU && ArSquares[x][8].GetIdent() == CPU)
			{
				if(!ArSquares[x][0].GetOcc())
				{
					ArSquares[x][0].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][0].GetIdent() == CPU && ArSquares[x][8].GetIdent() == CPU)
			{
				if(!ArSquares[x][4].GetOcc())
				{
					ArSquares[x][4].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][1].GetIdent() == CPU && ArSquares[x][4].GetIdent() == CPU)
			{
				if(!ArSquares[x][7].GetOcc())
				{
					ArSquares[x][7].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][4].GetIdent() == CPU && ArSquares[x][7].GetIdent() == CPU)
			{
				if(!ArSquares[x][1].GetOcc())
				{
					ArSquares[x][1].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][1].GetIdent() == CPU && ArSquares[x][7].GetIdent() == CPU)
			{
				if(!ArSquares[x][4].GetOcc())
				{
					ArSquares[x][4].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][2].GetIdent() == CPU && ArSquares[x][4].GetIdent() == CPU)
			{
				if(!ArSquares[x][6].GetOcc())
				{
					ArSquares[x][6].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][4].GetIdent() == CPU && ArSquares[x][6].GetIdent() == CPU)
			{
				if(!ArSquares[x][2].GetOcc())
				{
					ArSquares[x][2].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][2].GetIdent() == CPU && ArSquares[x][6].GetIdent() == CPU)
			{
				if(!ArSquares[x][4].GetOcc())
				{
					ArSquares[x][4].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][2].GetIdent() == CPU && ArSquares[x][5].GetIdent() == CPU)
			{
				if(!ArSquares[x][8].GetOcc())
				{
					ArSquares[x][8].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][5].GetIdent() == CPU && ArSquares[x][8].GetIdent() == CPU)
			{
				if(!ArSquares[x][2].GetOcc())
				{
					ArSquares[x][2].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][2].GetIdent() == CPU && ArSquares[x][8].GetIdent() == CPU)
			{
				if(!ArSquares[x][5].GetOcc())
				{
					ArSquares[x][5].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][3].GetIdent() == CPU && ArSquares[x][4].GetIdent() == CPU)
			{
				if(!ArSquares[x][5].GetOcc())
				{
					ArSquares[x][5].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][4].GetIdent() == CPU && ArSquares[x][5].GetIdent() == CPU)
			{
				if(!ArSquares[x][3].GetOcc())
				{
					ArSquares[x][3].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][3].GetIdent() == CPU && ArSquares[x][5].GetIdent() == CPU)
			{
				if(!ArSquares[x][4].GetOcc())
				{
					ArSquares[x][4].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][6].GetIdent() == CPU && ArSquares[x][7].GetIdent() == CPU)
			{
				if(!ArSquares[x][8].GetOcc())
				{
					ArSquares[x][8].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][7].GetIdent() == CPU && ArSquares[x][8].GetIdent() == CPU)
			{
				if(!ArSquares[x][6].GetOcc())
				{
					ArSquares[x][6].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][6].GetIdent() == CPU && ArSquares[x][8].GetIdent() == CPU)
			{
				if(!ArSquares[x][7].GetOcc())
				{
					ArSquares[x][7].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		else{};
		
	}

	for(i = 0; i < 9; i++)
	{
		if(ArSquares[0][i].GetIdent() == CPU && ArSquares[1][i].GetIdent() == CPU)
		{
			if(!ArSquares[2][i].GetOcc())
			{
				ArSquares[2][i].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
		if(ArSquares[1][i].GetIdent() == CPU && ArSquares[2][i].GetIdent() == CPU)
		{
			if(!ArSquares[0][i].GetOcc())
			{
				ArSquares[0][i].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
		if(ArSquares[0][i].GetIdent() == CPU && ArSquares[2][i].GetIdent() == CPU)
		{
			if(!ArSquares[1][i].GetOcc())
			{
				ArSquares[1][i].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	}
	
	for(x = 0; x < 3;x++)
	{
		if(ArSquares[x][0].GetIdent() == Human && ArSquares[x][1].GetIdent() == Human)
			{
				if(!ArSquares[x][2].GetOcc())
				{
				
					ArSquares[x][2].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][1].GetIdent() == Human && ArSquares[x][2].GetIdent() == Human)
			{
				if(!ArSquares[x][0].GetOcc())
				{
					ArSquares[x][0].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][0].GetIdent() == Human && ArSquares[x][2].GetIdent() == Human)
			{
				if(!ArSquares[x][1].GetOcc())
				{
					ArSquares[x][1].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][0].GetIdent() == Human && ArSquares[x][3].GetIdent() == Human)
			{
				if(!ArSquares[x][6].GetOcc())
				{
					ArSquares[x][6].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][3].GetIdent() == Human && ArSquares[x][6].GetIdent() == Human)
			{
				if(!ArSquares[x][0].GetOcc())
				{
					ArSquares[x][0].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][0].GetIdent() == Human && ArSquares[x][6].GetIdent() == Human)
			{
				if(!ArSquares[x][3].GetOcc())
				{
					ArSquares[x][3].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][0].GetIdent() == Human && ArSquares[x][4].GetIdent() == Human)
			{
				if(!ArSquares[x][8].GetOcc())
				{
					ArSquares[x][8].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][4].GetIdent() == Human && ArSquares[x][8].GetIdent() == Human)
			{
				if(!ArSquares[x][0].GetOcc())
				{
					ArSquares[x][0].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][0].GetIdent() == Human && ArSquares[x][8].GetIdent() == Human)
			{
				if(!ArSquares[x][4].GetOcc())
				{
					ArSquares[x][4].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][1].GetIdent() == Human && ArSquares[x][4].GetIdent() == Human)
			{
				if(!ArSquares[x][7].GetOcc())
				{
					ArSquares[x][7].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][4].GetIdent() == Human && ArSquares[x][7].GetIdent() == Human)
			{
				if(!ArSquares[x][1].GetOcc())
				{
					ArSquares[x][1].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][1].GetIdent() == Human && ArSquares[x][7].GetIdent() == Human)
			{
				if(!ArSquares[x][4].GetOcc())
				{
					ArSquares[x][4].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][2].GetIdent() == Human && ArSquares[x][4].GetIdent() == Human)
			{
				if(!ArSquares[x][6].GetOcc())
				{
					ArSquares[x][6].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][4].GetIdent() == Human && ArSquares[x][6].GetIdent() == Human)
			{
				if(!ArSquares[x][2].GetOcc())
				{
					ArSquares[x][2].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][2].GetIdent() == Human && ArSquares[x][6].GetIdent() == Human)
			{
				if(!ArSquares[x][4].GetOcc())
				{
					ArSquares[x][4].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][2].GetIdent() == Human && ArSquares[x][5].GetIdent() == Human)
			{
				if(!ArSquares[x][8].GetOcc())
				{
					ArSquares[x][8].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][5].GetIdent() == Human && ArSquares[x][8].GetIdent() == Human)
			{
				if(!ArSquares[x][2].GetOcc())
				{
					ArSquares[x][2].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][2].GetIdent() == Human && ArSquares[x][8].GetIdent() == Human)
			{
				if(!ArSquares[x][5].GetOcc())
				{
					ArSquares[x][5].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][3].GetIdent() == Human && ArSquares[x][4].GetIdent() == Human)
			{
				if(!ArSquares[x][5].GetOcc())
				{
					ArSquares[x][5].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][4].GetIdent() == Human && ArSquares[x][5].GetIdent() == Human)
			{
				if(!ArSquares[x][3].GetOcc())
				{
					ArSquares[x][3].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][3].GetIdent() == Human && ArSquares[x][5].GetIdent() == Human)
			{
				if(!ArSquares[x][4].GetOcc())
				{
					ArSquares[x][4].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][6].GetIdent() == Human && ArSquares[x][7].GetIdent() == Human)
			{
				if(!ArSquares[x][8].GetOcc())
				{
					ArSquares[x][8].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][7].GetIdent() == Human && ArSquares[x][8].GetIdent() == Human)
			{
				if(!ArSquares[x][6].GetOcc())
				{
					ArSquares[x][6].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		if(ArSquares[x][6].GetIdent() == Human && ArSquares[x][8].GetIdent() == Human)
			{
				if(!ArSquares[x][7].GetOcc())
				{
					ArSquares[x][7].Move(CPU);
					Count();
					Turn = Human; return 0;
				}
			}
		else{};
	}

	if(ArSquares[0][0].GetIdent() == Human && ArSquares[1][4].GetIdent() == Human)
		{
			if(!ArSquares[2][8].GetOcc())
			{
				ArSquares[2][8].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	if(ArSquares[0][0].GetIdent() == Human && ArSquares[2][8].GetIdent() == Human)
		{
			if(!ArSquares[1][4].GetOcc())
			{
				ArSquares[1][4].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	if(ArSquares[1][4].GetIdent() == Human && ArSquares[2][8].GetIdent() == Human)
		{
			if(!ArSquares[0][0].GetOcc())
			{
				ArSquares[0][0].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	if(ArSquares[0][2].GetIdent() == Human && ArSquares[1][4].GetIdent() == Human)
		{
			if(!ArSquares[2][6].GetOcc())
			{
				ArSquares[2][6].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	if(ArSquares[0][2].GetIdent() == Human && ArSquares[2][6].GetIdent() == Human)
		{
			if(!ArSquares[1][4].GetOcc())
			{
				ArSquares[1][4].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	if(ArSquares[2][6].GetIdent() == Human && ArSquares[1][4].GetIdent() == Human)
		{
			if(!ArSquares[0][2].GetOcc())
			{
				ArSquares[0][2].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
		
	if(ArSquares[0][0].GetIdent() == CPU && ArSquares[1][4].GetIdent() == CPU)
		{
			if(!ArSquares[2][8].GetOcc())
			{
				ArSquares[2][8].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	if(ArSquares[0][0].GetIdent() == CPU && ArSquares[2][8].GetIdent() == CPU)
		{
			if(!ArSquares[1][4].GetOcc())
			{
				ArSquares[1][4].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	if(ArSquares[1][4].GetIdent() == CPU && ArSquares[2][8].GetIdent() == CPU)
		{
			if(!ArSquares[0][0].GetOcc())
			{
				ArSquares[0][0].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	if(ArSquares[0][2].GetIdent() == CPU && ArSquares[1][4].GetIdent() == CPU)
		{
			if(!ArSquares[2][6].GetOcc())
			{
				ArSquares[2][6].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	if(ArSquares[0][2].GetIdent() == CPU && ArSquares[2][6].GetIdent() == CPU)
		{
			if(!ArSquares[1][4].GetOcc())
			{
				ArSquares[1][4].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	if(ArSquares[2][6].GetIdent() == CPU && ArSquares[1][4].GetIdent() == CPU)
		{
			if(!ArSquares[0][2].GetOcc())
			{
				ArSquares[0][2].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
		
	if(ArSquares[0][6].GetIdent() == CPU && ArSquares[1][4].GetIdent() == CPU)
		{
			if(!ArSquares[2][2].GetOcc())
			{
				ArSquares[2][2].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	if(ArSquares[1][4].GetIdent() == CPU && ArSquares[2][2].GetIdent() == CPU)
		{
			if(!ArSquares[0][6].GetOcc())
			{
				ArSquares[0][6].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	if(ArSquares[0][6].GetIdent() == CPU && ArSquares[2][2].GetIdent() == CPU)
		{
			if(!ArSquares[1][4].GetOcc())
			{
				ArSquares[1][4].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	if(ArSquares[0][8].GetIdent() == CPU && ArSquares[2][0].GetIdent() == CPU)
		{
			if(!ArSquares[1][4].GetOcc())
			{
				ArSquares[1][4].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	if(ArSquares[0][8].GetIdent() == CPU && ArSquares[1][4].GetIdent() == CPU)
		{
			if(!ArSquares[2][0].GetOcc())
			{
				ArSquares[2][0].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	if(ArSquares[2][0].GetIdent() == CPU && ArSquares[1][4].GetIdent() == CPU)
		{
			if(!ArSquares[0][8].GetOcc())
			{
				ArSquares[0][8].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
		
	if(ArSquares[0][6].GetIdent() == Human && ArSquares[1][4].GetIdent() == Human)
		{
			if(!ArSquares[2][2].GetOcc())
			{
				ArSquares[2][2].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	if(ArSquares[1][4].GetIdent() == Human && ArSquares[2][2].GetIdent() == Human)
		{
			if(!ArSquares[0][6].GetOcc())
			{
				ArSquares[0][6].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	if(ArSquares[0][6].GetIdent() == Human && ArSquares[2][2].GetIdent() == Human)
		{
			if(!ArSquares[1][4].GetOcc())
			{
				ArSquares[1][4].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	if(ArSquares[0][8].GetIdent() == Human && ArSquares[2][0].GetIdent() == Human)
		{
			if(!ArSquares[1][4].GetOcc())
			{
				ArSquares[1][4].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	if(ArSquares[0][8].GetIdent() == Human && ArSquares[1][4].GetIdent() == Human)
		{
			if(!ArSquares[2][0].GetOcc())
			{
				ArSquares[2][0].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	if(ArSquares[2][0].GetIdent() == Human && ArSquares[1][4].GetIdent() == Human)
		{
			if(!ArSquares[0][8].GetOcc())
			{
				ArSquares[0][8].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
		
	for(i =0; i<=6; i+=3)
	{
		if(ArSquares[0][i].GetIdent() == Human && ArSquares[1][i+1].GetIdent() == Human)
		{
			if(!ArSquares[2][i+2].GetOcc())
			{
				ArSquares[2][i+2].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
		if(ArSquares[0][i].GetIdent() == Human && ArSquares[2][i+2].GetIdent() == Human)
		{
			if(!ArSquares[1][i+1].GetOcc())
			{
				ArSquares[1][i+1].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
		if(ArSquares[1][i+1].GetIdent() == Human && ArSquares[2][i+2].GetIdent() == Human)
		{
			if(!ArSquares[0][i].GetOcc())
			{
				ArSquares[0][i].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	}
	
	for(i =0; i<=6; i+=3)
	{
		if(ArSquares[0][i].GetIdent()  == CPU && ArSquares[1][i+1].GetIdent()  == CPU)
		{
			if(!ArSquares[2][i+2].GetOcc())
			{
				ArSquares[2][i+2].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
		if(ArSquares[0][i].GetIdent()  == CPU && ArSquares[2][i+2].GetIdent()  == CPU)
		{
			if(!ArSquares[1][i+1].GetOcc())
			{
				ArSquares[1][i+1].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
		if(ArSquares[1][i+1].GetIdent()  == CPU && ArSquares[2][i+2].GetIdent()  == CPU)
		{
			if(!ArSquares[0][i].GetOcc())
			{
				ArSquares[0][i].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	}
	
	for(i =0; i<3; i++)
	{
		if(ArSquares[0][i].GetIdent() == Human && ArSquares[1][i+3].GetIdent() == Human)
		{
			if(!ArSquares[2][i+6].GetOcc())
			{
				ArSquares[2][i+6].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
		if(ArSquares[0][i].GetIdent() == Human && ArSquares[2][i+6].GetIdent() == Human)
		{
			if(!ArSquares[1][i+3].GetOcc())
			{
				ArSquares[1][i+3].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
		if(ArSquares[1][i+3].GetIdent() == Human && ArSquares[2][i+6].GetIdent() == Human)
		{
			if(!ArSquares[0][i].GetOcc())
			{
				ArSquares[0][i].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	}
	
	for(i =0; i<3; i++)
	{
		if(ArSquares[0][i].GetIdent()  == CPU && ArSquares[1][i+3].GetIdent()  == CPU)
		{
			if(!ArSquares[2][i+6].GetOcc())
			{
				ArSquares[2][i+6].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
		if(ArSquares[0][i].GetIdent()  == CPU && ArSquares[2][i+6].GetIdent()  == CPU)
		{
			if(!ArSquares[1][i+3].GetOcc())
			{
				ArSquares[1][i+3].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
		if(ArSquares[1][i+3].GetIdent()  == CPU && ArSquares[2][i+6].GetIdent()  == CPU)
		{
			if(!ArSquares[0][i].GetOcc())
			{
				ArSquares[0][i].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	}
	
	for(i = 0; i < 9; i++)
	{
		if(ArSquares[0][i].GetIdent() == Human && ArSquares[1][i].GetIdent() == Human)
		{
			if(!ArSquares[2][i].GetOcc())
			{
				ArSquares[2][i].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
		if(ArSquares[1][i].GetIdent() == Human && ArSquares[2][i].GetIdent() == Human)
		{
			if(!ArSquares[0][i].GetOcc())
			{
				ArSquares[0][i].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
		if(ArSquares[0][i].GetIdent() == Human && ArSquares[2][i].GetIdent() == Human)
		{
			if(!ArSquares[1][i].GetOcc())
			{
				ArSquares[1][i].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		}
	}
	
	if(GetFirst() == CPU && GetCount() == 4)
	{
		if(ArSquares[0][8].GetOcc())
		{
			ArSquares[0][6].Move(CPU);
			Count();
			Turn = Human; return 0;
		}
		else
		{
			ArSquares[0][8].Move(CPU);
			Count();
			Turn = Human; return 0;
		}
	}
	if(GetCount() == 6)
	{
		if(!ArSquares[0][2].GetOcc())
			{
				ArSquares[0][2].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
		else if(!ArSquares[0][8].GetOcc())
			{
				ArSquares[0][8].Move(CPU);
				Count();
				Turn = Human; return 0;
			}	
		else
			{
				ArSquares[0][6].Move(CPU);
				Count();
				Turn = Human; return 0;
			}
	}
		
	int Number2 = rand() % 9;
	int Number1 = rand() % 3;
	cout << Number1 <<endl;
	cout << Number2 <<endl;
	if(!ArSquares[Number1][Number2].GetOcc())
	{
		ArSquares[Number1][Number2].Move(CPU);
		Count();
		Turn = Human; return 0;
	}
}
