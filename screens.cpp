#include "screens.h"


// -----------------------------------> MAIN <------------------------------------------


MainScreen::MainScreen()
{
	this->pointer = PLAY;
}


MainScreen::~MainScreen()
{
	
}


void MainScreen::Print()
{
	ClearConsole();
	// pocker dice	
	cout << "                       _____                   _                          _   _               \n                      |  __ \\                 | |                        | | (_)              \n                      | |__) |   ___     ___  | | __   ___   _ __      __| |  _    ___    ___ \n                      |  ___/   / _ \\   / __| | |/ /  / _ \\ | '__|    / _` | | |  / __|  / _ \\\n                      | |      | (_) | | (__  |   <  |  __/ | |      | (_| | | | | (__  |  __/\n                      |_|       \\___/   \\___| |_|\\_\\  \\___| |_|       \\__,_| |_|  \\___|  \\___|\n";
	cout << endl;

	if (this->pointer == MainScreen::MainScreen::PLAY)
	{
		// play		
		SetConsoleColor(Yellow, Black);
		for (int i = 0; i < 6; i++)
		{
			cout << "                                               ";
			if (i == 0)
				cout << "        _             ";
			else if (i == 1)
				cout << "  _ __ | | __ _ _   _ ";
			else if (i == 2)
				cout << " | '_ \\| |/ _` | | | |";
			else if (i == 3)
				cout << " | |_) | | (_| | |_| |";
			else if (i == 4)
				cout << " | .__/|_|\\__,_|\\__, |";
			else if (i == 5)
				cout << " |_|            |___/ ";
			cout << endl;
		}
		SetConsoleColor(White, Black);

		// help
		cout << "                                                 _          _                                                                                                      | |__   ___| |_ __  \n                                                | '_ \\ / _ \\ | '_ \\\n                                                | | | |  __/ | |_) |\n                                                |_| |_|\\___|_| .__/ \n                                                             |_|\n";

		// exit
		cout << "                                                             _   _   \n                                                ___  __  __ (_) | |_ \n                                               / _ \\ \\ \\/ / | | | __|\n                                              |  __/  >  <  | | | |_ \n                                               \\___| /_/\\_\\ |_|  \\__|\n";

	}
	else if (this->pointer == MainScreen::MainScreen::HELP)
	{
		// play
		cout << "                                                       _                                                                                                            _ __ | | __ _ _   _ \n                                                | '_ \\| |/ _` | | | |\n                                                | |_) | | (_| | |_| |\n                                                | .__/|_|\\__,_|\\__, |\n                                                |_|            |___/\n";

		SetConsoleColor(Yellow, Black);
		for (int i = 0; i < 6; i++)
		{
			cout << "                                               ";
			if (i == 0)
				cout << "  _          _       ";
			else if (i == 1)
				cout << " | |__   ___| |_ __  ";
			else if (i == 2)
				cout << " | '_ \\ / _ \\ | '_ \\ ";
			else if (i == 3)
				cout << " | | | |  __/ | |_) |";
			else if (i == 4)
				cout << " |_| |_|\\___|_| .__/ ";
			else if (i == 5)
				cout << "              |_|    ";
			cout << endl;
		}
		SetConsoleColor(White, Black);

		// exit
		cout << "                                                             _   _   \n                                                ___  __  __ (_) | |_ \n                                               / _ \\ \\ \\/ / | | | __|\n                                              |  __/  >  <  | | | |_ \n                                               \\___| /_/\\_\\ |_|  \\__|\n";
	}
	else if (this->pointer == MainScreen::MainScreen::EXIT)
	{
		// play
		cout << "                                                       _                                                                                                            _ __ | | __ _ _   _ \n                                                | '_ \\| |/ _` | | | |\n                                                | |_) | | (_| | |_| |\n                                                | .__/|_|\\__,_|\\__, |\n                                                |_|            |___/\n";

		// help
		cout << "                                                 _          _                                                                                                      | |__   ___| |_ __  \n                                                | '_ \\ / _ \\ | '_ \\\n                                                | | | |  __/ | |_) |\n                                                |_| |_|\\___|_| .__/ \n                                                             |_|\n";

		SetConsoleColor(Yellow, Black);
		for (int i = 0; i < 5; i++)
		{
			cout << "                                             ";
			if (i == 0)
				cout << "                _   _   ";
			else if (i == 1)
				cout << "   ___  __  __ (_) | |_ ";
			else if (i == 2)
				cout << "  / _ \\ \\ \\/ / | | | __|";
			else if (i == 3)
				cout << " |  __/  >  <  | | | |_ ";
			else if (i == 4)
				cout << "  \\___| /_/\\_\\ |_|  \\__|";
			cout << endl;
		}
		SetConsoleColor(White, Black);
	}
}


void MainScreen::operator ++ (int)
{
	if (this->pointer < 2)
		this->pointer = Pointers(pointer + 1);
	else
		return;
}


void MainScreen::operator -- (int)
{
	if (0 < this->pointer)
		this->pointer = Pointers(pointer - 1);
	else if (this->pointer == 0)
		return;
}


// -----------------------------------> HELP <------------------------------------------

void HelpScreen::Print()
{
	ClearConsole();
	cout << "                                                     +------+\n";
	cout << "                                                     | Help |\n";
	cout << "                                                     +------+\n";

	cout << "                                                +------------------+\n";
	cout << "                                                | Poker Dice Rules |\n";
	cout << "                                                +------------------+\n\n";

	cout << "                                                   What is it?\n";
	cout << "In this simple little dice game, your goal is to roll the best possible poker hand.\n";
	cout << "To play, you'll need five regular 6-sided dice, although having special Poker Dice certainly adds to the fun. \nYou'll also want to have at least two players.\n\n";

	cout << "                                           How do you play Poker Dice?\n";
	cout << "Each player takes a single turn and may roll the five dice up to three times, trying to roll the best poker hand \nthey can. On any of the three rolls the player may set aside one or more of the dice. The current player may choose\n to end his turn after the first or second roll.\n\n";

	cout << "                                                   Who will win?\n";
	cout << "The dice hands rank as follows (from highest to lowest):\n";
	cout << " -Five of a kind\n -Four of a kind\n -Full house(Three of a kind and a pair)\n -Three of a kind\n -Two pair\n -One pair\n -High card\n\n";
	cout << "And it's all. The player with the highest hand wins the game!\n";
	cout << "If you have the same rank of hands. The player with the highest die value in the rank of the hand wins. \nIf everything is the same for the player and the bot, it's a draw.";

}


// -----------------------------------> PrePlayChoiceScreen <------------------------------------------

PrePlayChoiceScreen::PrePlayChoiceScreen()
{
	this->pointer = PrePlayChoiceScreen::Pointers::BOT;
}


void PrePlayChoiceScreen::operator ++ (int)
{
	if (this->pointer == this->Pointers::BOT)
		this->pointer = this->TWO_PLAYERS;
}


void PrePlayChoiceScreen::operator -- (int)
{
	if (this->pointer == this->Pointers::TWO_PLAYERS)
		this->pointer = this->BOT;
}


void PrePlayChoiceScreen::Print()
{
	ClearConsole();

	cout << "\n\n\n\n\n\n\n\n";
	
	if (this->pointer == this->Pointers::BOT)
	{
		cout << "                                                                                   ____\n";
		cout << "                                                                                  |___ \\\n";
		cout << "                                                                                    __) |\n";

		SetConsoleColor(Yellow, Black);
		cout << "                     ____        _";
		SetConsoleColor(White, Black);
		cout << "                                                 / __/\n";
		
		SetConsoleColor(Yellow, Black);
		cout << "                    | __ )  ___ | |_";
		SetConsoleColor(White, Black);
		cout << " 	                             ____  _       |____|\n";

		SetConsoleColor(Yellow, Black);
		cout << "                    |  _ \\ / _ \\| __|";
		SetConsoleColor(White, Black);
		cout << "                               |  _ \\| | __ _ _   _  ___ _ __ ___ \n";

		SetConsoleColor(Yellow, Black);
		cout << "                    | |_) | (_) | |_";
		SetConsoleColor(White, Black);
		cout << "                                | |_) | |/ _` | | | |/ _ \\ '__/ __|\n";

		SetConsoleColor(Yellow, Black);
		cout << "                    |____/ \\___/ \\__|";
		SetConsoleColor(White, Black);
		cout << "                               |  __/| | (_| | |_| |  __/ |  \\__ \\\n";


		cout << "                                                                    |_|   |_|\\__,_|\\__, |\\___|_|  |___/\n";
		cout << "                                                                                   |___/\n";
	}
	else  // 2 Players
	{
		SetConsoleColor(Yellow, Black);
		cout << "                                                                                   ____\n";
		cout << "                                                                                  |___ \\\n";
		cout << "                                                                                    __) |\n";

		SetConsoleColor(White, Black);
		cout << "                     ____        _";
		SetConsoleColor(Yellow, Black);
		cout << "                                                 / __/\n";

		SetConsoleColor(White, Black);
		cout << "                    | __ )  ___ | |_";
		SetConsoleColor(Yellow, Black);
		cout << " 	                             ____  _       |____|\n";

		SetConsoleColor(White, Black);
		cout << "                    |  _ \\ / _ \\| __|";
		SetConsoleColor(Yellow, Black);
		cout << "                               |  _ \\| | __ _ _   _  ___ _ __ ___ \n";

		SetConsoleColor(White, Black);
		cout << "                    | |_) | (_) | |_";
		SetConsoleColor(Yellow, Black);
		cout << "                                | |_) | |/ _` | | | |/ _ \\ '__/ __|\n";

		SetConsoleColor(White, Black);
		cout << "                    |____/ \\___/ \\__|";
		SetConsoleColor(Yellow, Black);
		cout << "                               |  __/| | (_| | |_| |  __/ |  \\__ \\\n";


		cout << "                                                                    |_|   |_|\\__,_|\\__, |\\___|_|  |___/\n";
		cout << "                                                                                   |___/\n";

	}
	SetConsoleColor(White, Black);
}


// ======================================> Bot play screen <================================================

		// ---------------------------------------> Score <-----------------------------------------

Score::Score(Dice& dice)
{
	this->arr = dice.GetArray();

	this->par = false;
	this->twoPar = false;
	this->set = false;
	this->strit = false;
	this->fullHause = false;
	this->kare = false;
	this->pocker = false;
	this->score = 0;
}


int Score::GetScore()
{
	return this->score;
}


void Score::ParTest()
{
	if (this->pars == 0)
		return;
	else if (this->pars == 1)
		this->par = true;
	else
		this->twoPar = true;
}


int Score::CountSimNums(CombinationType Type)
{
	int res = 0;
	int buf = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (this->arr[i] == this->arr[j])
			{
				buf++;
			}
			if (buf > (int)Type) return 0;
		}

		if (buf == (int)Type)
		{
			buf = 0;
			res++;
		}

		buf = 0;
	}
	return res;
}


void Score::FullHouseTest()
{

	if (this->par && this->set)
	{
		this->par = false;
		this->set = false;
		this->fullHause = true;
	}

}


bool Score::StritTest()
{
	int Buf = 0;
	for (int i = 0; i < 4; i++)
	{
		if (this->arr[i] + 1 == this->arr[i + 1]) Buf++;
	}
	if (Buf == 4) return true;
	else return false;
}


void Score::CountScore()
{
	if (this->par)
		this->score += 1;

	if (this->twoPar)
		this->score = 2;

	else if (this->set)
		this->score = 3;

	else if (this->strit)
		this->score = 4;

	else if (this->fullHause)
		this->score = 5;

	else if (this->kare)
		this->score = 6;

	else if (this->pocker)
		this->score = 7;
}


void Score::Print()
{
	cout << "score: " << this->score;
}


void Score::CombinationKernel()
{
	this->pars = CountSimNums(Par);
	ParTest();
	this->set = CountSimNums(Set);
	this->kare = CountSimNums(Kare);
	this->pocker = CountSimNums(Pocker);
	FullHouseTest();
	this->strit = StritTest();

	this->CountScore();
}



void Score::RandomCubes()
{
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < 100; i++)
		{
			if (1 + rand() % 10 == i)
				this->arr[j] = 1 + rand() % 7;
		}
	}
}

		// ---------------------------------------> Bid Button <-----------------------------------------

BidButton::BidButton()
{
	this->firstBid = false;
	this->secondBid = false;
	
	this->wasPressed = false;

	this->pointer = this->Pointers::OK;
	this->bid = 10;
	this->bidStatus = false;
}


void BidButton::operator ++ (int)
{
	if (this->pointer < Pointers::OK)
		this->pointer = Pointers(pointer + 1);
}


void BidButton::operator -- (int)
{
	if (this->pointer > Pointers::MINUS)
		this->pointer = Pointers(pointer - 1);
}


void BidButton::Print()
{
	SetCursorPosition(50, 24);

	if (this->pointer == this->Pointers::NONE)
	{
		int x = 50;
		int y = 25;

		cout << "  +--------+";
		SetCursorPosition(x, y);
		cout << "- | $";

		if (this->bid < 10)
			cout << " ";
		else if (this->bid < 100)
			cout << "  ";
		else  // this->bid < 1000
			cout << ' ';

		cout << this->bid;

		if (this->bid < 10)
			cout << "    ";
		else
			cout << "  ";

		cout << "| +";
		SetCursorPosition(50, 26);
		cout << "  +--------+";

		SetCursorPosition(50, 27);
		cout << "  |   Bid  |";
		SetCursorPosition(50, 28);
		cout << "  +--------+";


	}
	else if (this->pointer == this->Pointers::MINUS)
	{
		cout << "  +--------+";
		SetCursorPosition(50, 25);
		SetConsoleColor(Yellow, Black);
		cout << "-";

		SetConsoleColor(White, Black);
		cout << " | $";

		if (this->bid < 10)
			cout << " ";
		else if (this->bid < 100)
			cout << "  ";
		else  // this->bid < 1000
			cout << ' ';

		cout << this->bid;

		if (this->bid < 10)
			cout << "    ";
		else
			cout << "  ";

		cout << "| +";
		SetCursorPosition(50, 26);
		cout << "  +--------+";

		SetCursorPosition(50, 27);
		cout << "  |   Bid  |";
		SetCursorPosition(50, 28);
		cout << "  +--------+";
	}
	else if (this->pointer == this->Pointers::PLUS)
	{
		cout << "  +--------+";
		SetCursorPosition(50, 25);
		cout << "- | $";

		if (this->bid < 10)
			cout << " ";
		else if (this->bid < 100)
			cout << "  ";
		else  // this->bid < 1000
			cout << ' ';

		cout << this->bid;

		if (this->bid < 10)
			cout << "    ";
		else
			cout << "  ";

		cout << "| ";
		SetConsoleColor(Yellow, Black);
		cout << "+";
		SetConsoleColor(White, Black);
		SetCursorPosition(50, 26);
		cout << "  +--------+";

		SetCursorPosition(50, 27);
		cout << "  |   Bid  |";
		SetCursorPosition(50, 28);
		cout << "  +--------+";
	}
	else if (this->pointer == this->Pointers::OK)
	{
		cout << "  +--------+";
		SetCursorPosition(50, 25);
		cout << "- | $";


		if (this->bid < 10)
			cout << " ";
		else if (this->bid < 100)
			cout << "  ";
		else  // this->bid < 1000
			cout << ' ';

		cout << this->bid;

		if (this->bid < 10)
			cout << "    ";
		else
			cout << "  ";

		cout << "| +";
		SetCursorPosition(50, 26);
		cout << "  +--------+";

		SetCursorPosition(50, 27);
		cout << "  |   ";
		
		SetConsoleColor(Yellow, Black);
		cout << "Bid";
		SetConsoleColor(White, Black);
		cout << "  | ";
		
		SetCursorPosition(50, 28);
		cout << "  +--------+";
	}
}


void BidButton::BidAnimation()
{
	SetCursorPosition(56, 27);
	SetConsoleColor(Blue, White);
	cout << "Bid";

	Sleep(200);

	SetCursorPosition(56, 27);
	SetConsoleColor(White, Black);
	cout << "Bid";
}


//void BidButton::NewBid(PlayerInfo& playerInfo)
//{
//	ClearSector(" ", 55, 25, 60, 25);
//
//	int oldBid = this->bid;
//	int* newBid = new int;
//
//	while (cin.get() != '\n') 
//		cout << cin.get();
//	while (cin.get() != '\n') 
//		cout << cin.get();
//	while (cin.get() != '\n')
//		cout << cin.get();
//
//	SetCursorPosition(56, 25);
//
//	std::cin >> *newBid;
//
//	Sleep(150);
//
// 	if (0 < *newBid && *newBid <= playerInfo.GetMoney())
//		this->bid = *newBid;
//	else
//		this->bid = oldBid;
//
//	this->Print();
//
//	delete newBid;
//}


bool BidButton::GetBidStatus()
{
	return this->bidStatus;
}


void BidButton::BidStatusOn()
{
	this->bidStatus = true;
}


void BidButton::BidStatusOff()
{
	this->bidStatus = false;
}

void BidButton::FirstBidOn()
{
	this->firstBid = true;
}

bool BidButton::GetFirstBidStatus()
{
	return this->firstBid;
}

void BidButton::SecondBidOn()
{
	this->secondBid = true;
}

bool BidButton::GetSecondBidStatus()
{
	return this->secondBid;
}

bool BidButton::GetWasPressed()
{
	return this->wasPressed;
}

void BidButton::SetWasPressedTrue()
{
	this->wasPressed = true;
}

void BidButton::SetWasPressedFalse()
{
	this->wasPressed = false;
}


void BidButton::SubABid()
{
	this->bid -= 5;
}


void BidButton::AddToBid()
{
	this->bid += 5;
}


int BidButton::GetBid()
{
	return this->bid;
}



		// ---------------------------------------> PlayerInfo <-----------------------------------------

PlayerInfo::PlayerInfo(int x, int y, string name)
{
	this->x = x;
	this->y = y;

	this->dice = Dice{this->x, this->y + 1};

	this->name = name;
	this->money = 100;
}


string PlayerInfo::GetName()
{
	return this->name;
}


int PlayerInfo::GetMoney()
{
	return this->money;
}


int PlayerInfo::GetScore()
{
	return this->score.GetScore();
}


void PlayerInfo::Print(bool empty, bool offCubesDrawing)
{
	SetCursorPosition(this->x, this->y);
	cout << this->name << ':';

	ClearSector(" ", 60, y, 64, y);
	SetCursorPosition(53, y);
	this->score.Print();

	ClearSector(" ", 107, y, 110, y);
	SetCursorPosition(106, y); 
	cout << '$' << this->money << endl;

	if (!offCubesDrawing)
		this->dice.DrawingDices(-1, empty);
}


void PlayerInfo::SubAMoney(int bid)
{
	this->money -= bid;
}

void PlayerInfo::CombinationKernel()
{
	this->score.CombinationKernel();
}


void PlayerInfo::DrawingDices(int selectDice, bool empty)
{
	this->dice.DrawingDices(selectDice, empty);
}


void PlayerInfo::AnimationDices()
{
	this->dice.AnimationDices();
}


void PlayerInfo::AnimationSelectDices()
{
	this->dice.AnimationSelectDices();
}


void PlayerInfo::AddSelectDice(int index)
{
	this->dice.AddSelectDice(index);
}


void PlayerInfo::PrintSelectDice(int position)
{
	this->dice.PrintSelectDice(position);
}


bool PlayerInfo::CheckIndexExistInSelectArr(int index)
{
	return dice.CheckIndexExistInSelectArr(index);
}


void PlayerInfo::RemoveIndexFromSelectArr(int index)
{
	this->dice.RemoveIndexFromSelectArr(index);
}


void PlayerInfo::RemoveAllFromSelectArr()
{
	this->dice.RemoveAllFromSelectArr();
}


void PlayerInfo::RandomCubes()
{
	this->score.RandomCubes();
}

		// ---------------------------------------> Dice <-----------------------------------------

// Print

void Dice::One(int position)
{
	if (position == 4 || position == 5)
	{
		cout << "*       ###       *";
	}
	else
	{
		cout << "*                 *";
	}
}
void Dice::Two(int position)
{
	if (position == 4 || position == 5)
	{
		cout << "*    ###   ###    *";
	}
	else
	{
		cout << "*                 *";
	}
}
void Dice::Three(int position)
{
	if (position == 1 || position == 2)
	{
		cout << "* ###             *";
	}
	else if (position == 4 || position == 5)
	{
		cout << "*       ###       *";
	}
	else if (position == 7 || position == 8)
	{
		cout << "*             ### *";
	}
	else
	{
		cout << "*                 *";
	}
}
void Dice::Four(int position)
{
	if (position == 1 || position == 2 || position == 7 || position == 8)
	{
		cout << "* ###         ### *";
	}
	else
	{
		cout << "*                 *";
	}
	return;
}
void Dice::Five(int position)
{
	if (position == 3 || position == 6)
	{
		cout << "*                 *";
	}
	else if (position == 4 || position == 5)
	{
		cout << "*       ###       *";
	}
	else
	{
		cout << "* ###         ### *";
	}
}
void Dice::Six(int position)
{
	if (position == 3 || position == 6)
	{
		cout << "*                 *";
	}
	else
	{
		cout << "* ###         ### *";
	}
}



Dice::Dice(int x, int y)
{
	this->x = x;
	this->y = y;

	this->sizeOfSelectArr = 0;
	this->selectArr = new int[5];
	this->selectArr[0] = -1;

	this->GeneratePlayArr();
}


int* Dice::GetArray()
{
	return this->arr;
}


void Dice::AddSelectDice(int index)
{
	int i = 0;

	while (this->selectArr[i] != -1)
		i++;

	this->selectArr[i] = index;
	this->selectArr[i + 1] = -1;

	this->sizeOfSelectArr++;
}


bool Dice::CheckIndexExistInSelectArr(int index)
{
	int i = 0;
	while (this->selectArr[i] != -1)
	{
		if (this->selectArr[i] == index)
			return true;

		i++;
	}
	return false;
}


void Dice::RemoveIndexFromSelectArr(int index)
{
	if (CheckIndexExistInSelectArr(index))
	{
		int i = 0;

		while (this->selectArr[i] != index)
			i++;

		while (this->selectArr[i + 1] != -1)
		{
			this->selectArr[i] = this->selectArr[i + 1];
			i++;
		}
		this->selectArr[i] = this->selectArr[i + 1];

		this->sizeOfSelectArr--;
	}
}


void Dice::RemoveAllFromSelectArr()
{
	this->selectArr[0] = -1;
	this->sizeOfSelectArr = 0;
}


void Dice::GeneratePlayArr()
{
	int* playerDices = new int[5];
	for (int i = 0; i < 5; i++)
		playerDices[i] = 1 + rand() % 6;
	this->arr = playerDices;
}


void Dice::DrawingDices(int selectDice, bool empty)
{
	SetCursorPosition(this->x, this->y);

	for (int i = 0; i < 10; i++)
	{
		cout << "  ";

		if (i == 0 || i == 9)
		{
			for (int k = 0; k < 5; k++)
			{
				if (selectDice == k)
					SetConsoleColor(Yellow, Black);
				else if (this->CheckIndexExistInSelectArr(k))
					SetConsoleColor(Blue, Black);

				if (k != 4)
					cout << "*******************" << "    ";
				else
					cout << "*******************";
				
				
				if (this->CheckIndexExistInSelectArr(k) || selectDice == k)
					SetConsoleColor(White, Black);

			}
			cout << endl;
		}
		else
		{
			if (!empty)
			{
				for (int j = 0; j < 5; j++)
				{
					if (selectDice == j)
						SetConsoleColor(Yellow, Black);
					if (this->CheckIndexExistInSelectArr(j))
						SetConsoleColor(Blue, Black);

					if (arr[j] == 1)
						One(i);

					else if (arr[j] == 2)
						Two(i);

					else if (arr[j] == 3)
						Three(i);

					else if (arr[j] == 4)
						Four(i);

					else if (arr[j] == 5)
						Five(i);

					else
						Six(i);

					if (this->CheckIndexExistInSelectArr(j) || selectDice == j)
						SetConsoleColor(White, Black);

					if (j != 4)
						cout << "    ";
				}
			}
			else
			{
				for (int k = 0; k < 5; k++)
				{
					cout << "*                 *";
					if (k != 4)
						cout << "    ";
				}
			}
			cout << endl;
		}
	}
}


void Dice::AnimationDices()
{
	for (int i = 0; i < 10; i++)
	{
		this->GeneratePlayArr();
		this->DrawingDices();
		Sleep(11 * i);
	}
}


void Dice::AnimationSelectDices() 
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < this->sizeOfSelectArr; j++)
			this->arr[this->selectArr[j]] = 1 + rand() % 6;
		
		this->PrintSelectArr();
		Sleep(11 * i);
	}
}


void Dice::PrintSelectDice(int position)
{
	int x = position * 23 + 2;

	SetCursorPosition(x, 1);
	SetConsoleColor(Yellow, Black);
	cout << "*******************";
	SetCursorPosition(x, 2);


	if (this->arr[position] == 1)
	{
		for (int i = 0; i < 9; i++)
		{
			One(i);
			SetCursorPosition(x, 2 + i);
		}
	}
	else if (this->arr[position] == 2)
	{
		for (int i = 0; i < 9; i++)
		{
			Two(i);
			SetCursorPosition(x, 2 + i);
		}
	}
	else if (this->arr[position] == 3)
	{
		for (int i = 0; i < 9; i++)
		{
			Three(i);
			SetCursorPosition(x, 2 + i);
		}
	}
	else if (this->arr[position] == 4)
	{
		for (int i = 0; i < 9; i++)
		{
			Four(i);
			SetCursorPosition(x, 2 + i);
		}
	}
	else if (this->arr[position] == 5)
	{
		for (int i = 0; i < 9; i++)
		{
			Five(i);
			SetCursorPosition(x, 2 + i);
		}
	}
	else 
	{
		for (int i = 0; i < 9; i++)
		{
			Six(i);
			SetCursorPosition(x, 2 + i);
		}
	}

	cout << "*******************";

	SetConsoleColor(White, Black);
}


void Dice::PrintSelectArr()
{
	int i = 0;

	while (this->selectArr[i] != -1)
	{
		int x = this->selectArr[i] * 23 + 2;


		SetCursorPosition(x, 1);
		cout << "*******************";
		SetCursorPosition(x, 2);

		if (this->arr[this->selectArr[i]] == 1)
		{
			for (int j = 0; j < 9; j++)
			{
				One(j);
				SetCursorPosition(x, j + 2);
			}
		}
		else if (this->arr[this->selectArr[i]] == 2)
		{
			for (int j = 0; j < 9; j++)
			{
				Two(j);
				SetCursorPosition(x, j + 2);
			}
		}
		else if (this->arr[this->selectArr[i]] == 3)
		{
			for (int j = 0; j < 9; j++)
			{
				Three(j);
				SetCursorPosition(x, j + 2);
			}
		}
		else if (this->arr[this->selectArr[i]] == 4)
		{
			for (int j = 0; j < 9; j++)
			{
				Four(j);
				SetCursorPosition(x, j + 2);
			}
		}
		else if (this->arr[this->selectArr[i]] == 5)
		{
			for (int j = 0; j < 9; j++)
			{
				Five(j);
				SetCursorPosition(x, j + 2);
			}
		}
		else
		{
			for (int j = 0; j < 9; j++)
			{
				Six(j);
				SetCursorPosition(x, j + 2);
			}
		}

		cout << "*******************";
		i++;
	}
}



		// ---------------------------------------> Bot Play Screen class<-----------------------------------------

BotPlayScreen::BotPlayScreen(PlayerInfo* p1, PlayerInfo* p2, RollDiceButton* rollDice, BidButton* bidBut, BidInfo* bidInfo)
{
	this->p1 = p1;
	this->p2 = p2;
	this->rollDice = rollDice;
	this->bidBut = bidBut;
	this->bidInfo = bidInfo;
}



BotPlayScreen::Pointers::Pointers()
{
	this->columnPointer = BotPlayScreen::Pointers::Columns::OK_BUTTON;
	this->rowPointer = BotPlayScreen::Pointers::Rows::BID_BUTTON_OK;
}


BotPlayScreen::Pointers::Columns BotPlayScreen::Pointers::GetColumn()
{
	return this->columnPointer;
}


BotPlayScreen::Pointers::Rows BotPlayScreen::Pointers::GetRow()
{
	return this->rowPointer;
}


void BotPlayScreen::Pointers::operator ++ (int)
{
	// var++
	if (this->rowPointer + 1 <= BotPlayScreen::Pointers::Rows::BID_BUTTON_OK)
		this->rowPointer = BotPlayScreen::Pointers::Rows(this->rowPointer + 1);
}


void BotPlayScreen::Pointers::operator -- (int)
{
	// var--
	if (this->rowPointer - 1 >= BotPlayScreen::Pointers::Rows::DICE_0)
		this->rowPointer = BotPlayScreen::Pointers::Rows(this->rowPointer - 1);
}


void BotPlayScreen::Pointers::operator ++ ()
{
	// ++var  ↓	
	if (this->columnPointer + 1 <= BotPlayScreen::Pointers::Columns::OK_BUTTON)
		this->columnPointer = BotPlayScreen::Pointers::Columns(this->columnPointer + 1);
}


void BotPlayScreen::Pointers::operator -- ()
{
	// --var  ↑
	if (this->columnPointer - 1 >= BotPlayScreen::Pointers::Columns::DICES)
		this->columnPointer = BotPlayScreen::Pointers::Columns(this->columnPointer - 1);
}


void BotPlayScreen::Pointers::SetNewColumnPtr(BotPlayScreen::Pointers::Columns newColumn)
{
	this->columnPointer = newColumn;
}


void BotPlayScreen::Pointers::SetNewRowPtr(BotPlayScreen::Pointers::Rows newRow)
{
	this->rowPointer = newRow;
}


void BotPlayScreen::PrintPointer()
{
	// update
	this->rollDice->Print();
	this->bidBut->Print();

	if (this->pointer.GetColumn() == BotPlayScreen::Pointers::Columns::DICES)
	{
		if (this->pointer.GetRow() == BotPlayScreen::Pointers::Rows::DICE_0)
			this->p1->DrawingDices(0);
		
		else if (this->pointer.GetRow() == BotPlayScreen::Pointers::Rows::DICE_1)
			this->p1->DrawingDices(1);
		
		else if (this->pointer.GetRow() == BotPlayScreen::Pointers::Rows::DICE_2)
			this->p1->DrawingDices(2);

		else if (this->pointer.GetRow() == BotPlayScreen::Pointers::Rows::DICE_3)
			this->p1->DrawingDices(3);

		else if (this->pointer.GetRow() == BotPlayScreen::Pointers::Rows::DICE_4)
			this->p1->DrawingDices(4);
	}
	
	else if (this->pointer.GetColumn() == BotPlayScreen::Pointers::Columns::BUTTONS)
	{
		if (this->bidBut->GetBidStatus())
			this->p1->DrawingDices();

		if (this->pointer.GetRow() == BotPlayScreen::Pointers::Rows::ROLL_DICE)
		{
			this->bidBut->pointer = BidButton::NONE;
			this->bidBut->Print();

			this->rollDice->Select();
			this->rollDice->Print();
			this->rollDice->UnSelect();
		}
		else
		{
			this->rollDice->Print();
			this->bidBut->Print();
		}
	}
	
	else if (this->pointer.GetColumn() == BotPlayScreen::Pointers::Columns::OK_BUTTON)
	{
		this->bidBut->Print();
	}
}


void BotPlayScreen::PrintAll()
{
	this->p1->Print();
	this->p2->Print();
	this->rollDice->Print();
	this->bidBut->Print();
	this->bidInfo->Print();
}

		// ---------------------------------------> Roll the Dice <-----------------------------------------

RollDiceButton::RollDiceButton()
{
	this->nextBid = true;
	this->press = false;
	this->select = false;
}


void RollDiceButton::Print()
{
	ClearSector(" ", 14, 25, 24, 27);
	
	if (this->press)
	{
		SetCursorPosition(15, 25);

		SetConsoleColor(Yellow, Black);
		cout << "+------+";
		
		SetCursorPosition(15, 26);
		cout << "| Roll |";

		SetCursorPosition(15, 27);
		cout << "+------+";
		SetConsoleColor(White, Black);
	}
	else
	{
		if (this->select)
			SetConsoleColor(Yellow, Black);
		SetCursorPosition(14, 25);
		cout << "+--------+";

		SetCursorPosition(14, 26);
		cout << "|  Roll  |";

		SetCursorPosition(14, 27);
		cout << "+--------+";
		if (this->select)
			SetConsoleColor(White, Black);
	}
}


void RollDiceButton::Select()
{
	this->select = true;
}


void RollDiceButton::UnSelect()
{
	this->select = false;
}


void RollDiceButton::Animation()
{
	this->press = true;
	this->Print();

	Sleep(130);

	this->press = false;
	this->Print();
}


		// ---------------------------------------> Bid info <-----------------------------------------

BidInfo::BidInfo(PlayerInfo* p1, PlayerInfo* p2)
{
	this->player1 = p1;
	this->player2 = p2;

	this->player1Bid = 0;
	this->player2Bid = 0;
}


void BidInfo::SetNewBid(PlayerInfo& p, int bid)
{
	int x = 76;
	int y = 24;

	if (p.GetName() == this->player1->GetName())
		this->player1Bid += bid;

	else if (p.GetName() == this->player2->GetName())
		this->player2Bid += bid;


	SetCursorPosition(x, y);
	cout << "            +---------------+";
	SetCursorPosition(x, ++y);

	cout << "+-----------| " << this->player1->GetName() << ':';

	SetCursorPosition(98, 25);
	cout << "$ " << this->player1Bid;


	if (10 > this->player1Bid)
		cout << "   |";
	else if (100 > this->player1Bid)
		cout << "  |";
	else
		cout << " |";


	SetCursorPosition(x, ++y);
	cout << "| Bid info: +---------------+";
	SetCursorPosition(x, ++y);

	cout << "+-----------| " << this->player2->GetName() << ':';


	SetCursorPosition(98, 27);
	cout << "$ " << this->player2Bid;

	if (10 > this->player2Bid)
		cout << "   |";
	else if (100 > this->player2Bid)
		cout << "  |";
	else
		cout << " |";


	SetCursorPosition(x, ++y);
	cout << "            +---------------+";

}


void BidInfo::Print()
{
	int x = 76;
	int y = 24;

	SetCursorPosition(x, y);
	cout << "            +---------------+";
	SetCursorPosition(x, ++y);

	cout << "+-----------| " << this->player1->GetName() << ':';

	SetCursorPosition(98, 25);
	cout << "$ " << this->player1Bid;


	if (10 > this->player1Bid)
		cout << "   |";
	else if (100 > this->player1Bid)
		cout << "  |";
	else
		cout << " |";


	SetCursorPosition(x, ++y);
	cout << "| Bid info: +---------------+";
	SetCursorPosition(x, ++y);

	cout << "+-----------| " << this->player2->GetName() << ':';


	SetCursorPosition(98, 27);
	cout << "$ " << this->player2Bid;

	if (10 > this->player2Bid)
		cout << "   |";
	else if (100 > this->player2Bid)
		cout << "  |";
	else
		cout << " |";


	SetCursorPosition(x, ++y);
	cout << "            +---------------+";
}



// ---------------------------------------> Win Screen <-----------------------------------------

void WinScreen::Print(bool win)
{
	ClearConsole();
	cout << "\n\n\n\n\n\n";
	if (win)
	{
		SetConsoleColor(Green, Black);
		cout << "                            __   __                                        _         _ \n                            \\ \\ / /__  _   _     __ _ _ __ ___   __      _(_)_ __   | |\n                             \\ V / _ \\| | | |   / _` | '__/ _ \\  \\ \\ /\\ / / | '_ \\  | |\n                              | | (_) | |_| |  | (_| | | |  __/   \\ V  V /| | | | | |_|\n                              |_|\\___/ \\__,_|   \\__,_|_|  \\___|    \\_/\\_/ |_|_| |_| (_)\n";
	}
	else
	{
		SetConsoleColor(Red, Black);
		cout << "                                 ____\n                                / ___| __ _ _ __ ___   ___       _____   _____ _ __ \n                               | |  _ / _` | '_ ` _ \\ / _ \\     / _ \\ \\ / / _ \\ '__|\n                               | |_| | (_| | | | | | |  __/    | (_) \\ V /  __/ |\n                                \\____|\\__,_|_| |_| |_|\\___|     \\___/ \\_/ \\___|_|\n";
	}

	SetConsoleColor(White, Black);
}
