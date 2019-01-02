#include <iostream>
#include<string.h>
using namespace std;
 int main();
//TIC TAC TOE
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])

		return 1;
	else if (square[4] == square[5] && square[5] == square[6])

		return 1;
	else if (square[7] == square[8] && square[8] == square[9])

		return 1;
	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])

		return 1;
	else if (square[3] == square[6] && square[6] == square[9])

		return 1;
	else if (square[1] == square[5] && square[5] == square[9])

		return 1;
	else if (square[3] == square[5] && square[5] == square[7])

		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
                    && square[4] != '4' && square[5] != '5' && square[6] != '6'
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

		return 0;
	else
		return -1;
}


void board()
{
	system("clear");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << "     |     |     " << endl << endl;
}


int ttt()
{
	int player = 1, i ,choice;

	char mark;
	do
	{
		board();
		player=(player%2)?1:2;

		cout << "Player " << player << ", Enter number tile:  ";
		cin >> choice;

		mark=(player == 1) ? 'X' : 'O';

		if (choice == 1 && square[1] == '1')

			square[1] = mark;
		else if (choice == 2 && square[2] == '2')

			square[2] = mark;
		else if (choice == 3 && square[3] == '3')

			square[3] = mark;
		else if (choice == 4 && square[4] == '4')

			square[4] = mark;
		else if (choice == 5 && square[5] == '5')

			square[5] = mark;
		else if (choice == 6 && square[6] == '6')

			square[6] = mark;
		else if (choice == 7 && square[7] == '7')

			square[7] = mark;
		else if (choice == 8 && square[8] == '8')

			square[8] = mark;
		else if (choice == 9 && square[9] == '9')

			square[9] = mark;
		else
		{
			cout<<"Invalid move ";

			player--;
			cin.ignore();
			cin.get();
		}
		i=checkwin();

		player++;
	}
	while(i==-1);
	board();
	if(i==1)
		cout<<"\aPLAYER "<<--player<<" WINS";
	else
		cout<<"\aGame draw";

	int rchoice;

	cout << "\n \nDo you want to have a rematch or exit to menu: \n Press [1] to continue and [0] for menu:  \n ";
	cin >> rchoice;

	if(rchoice == 1){
		system("clear");
		board();
		}
	else{
		main();
	}
	cin.ignore();
	cin.get();
	return 0;
}

//MENU
 int main() {
		system("clear");
		int mchoice;
		int i = 0;

		do{
		system("clear");
		cout << "\n Welcome to utility Menu, you can chose which utility you want to chose." << endl
		<< "To chose, enter the number corresponding to the utility: " << endl
		<< "\nMENU" << "\n 1] Periodic Table \n 2] Tic Tac Toe \n 3] Exit \n";

		cin >> mchoice;
			if(i != 0){
					i++;
				}

			if(mchoice == 1){
					i = 0;
				}
			else if(mchoice  == 2){
					ttt();
				}
			else if(mchoice  == 3){
					i=-1;
				}
			else{
			cout<< "Enter Valid character";
			i = 0;
			}


		}
		while(i == 0);

		return 0;
 }
