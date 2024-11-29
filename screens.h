#ifndef SCREENS
#define SCREENS
#pragma once

#include <iostream>
#include "Console-Settings.h"
#include <ctime>
#include <string>
#include <limits>


using namespace std;

class MainScreen
{
public:

	enum Pointers
	{
		PLAY,
		HELP,
		EXIT,
	};
	
	Pointers pointer;

	MainScreen();

	~MainScreen();

	void operator ++ (int);

	void operator -- (int);

	void Print();
};


class HelpScreen
{
public:
	void Print();
};


class PrePlayChoiceScreen
{
public:
	PrePlayChoiceScreen();

	enum Pointers
	{
		BOT,
		TWO_PLAYERS,
	};

	Pointers pointer;

	void operator ++ (int);

	void operator -- (int);

	void Print();
};


// ---------------------------------------> Bot play screen <-----------------------------------------

class Dice
{
private:
	int x;
	int y;

	int* arr;
	int* selectArr;

	int sizeOfSelectArr;

	void One(int position);
	void Two(int position);
	void Three(int position);
	void Five(int position);
	void Four(int position);
	void Six(int position);

	void GeneratePlayArr();

public:
	Dice(int x = 0, int y = 0);

	int* GetArray();
	
	void AddSelectDice(int index);

	bool CheckIndexExistInSelectArr(int index);

	void RemoveIndexFromSelectArr(int index);

	void RemoveAllFromSelectArr();

	
	void DrawingDices(int selectDice = -1, bool empty = false);

	void PrintSelectDice(int position);

	void AnimationDices();

	void AnimationSelectDices();

	void PrintSelectArr();
};


class Score 
{
private:
	int* arr;
	int score;
	
	int pars;
	bool par;
	bool twoPar;
	bool set;
	bool strit;
	bool fullHause;
	bool kare;
	bool pocker;

	enum CombinationType
	{
		Par = 1,
		Set,
		Kare,
		Pocker
	};

	void ParTest();
	
	int CountSimNums(CombinationType type);
	
	void FullHouseTest();
	
	bool StritTest();
	
	void CountScore();

public:
	Score(Dice& dice);

	void CombinationKernel();

	int GetScore();

	void Print();

	void RandomCubes();
};


class PlayerInfo
{
private:
	int x;
	int y;

	int money;
	string name;
	Dice dice;
	Score score{ this->dice };
	
public:
	PlayerInfo(int x = 0, int y = 0, string name = "player");
	
	string GetName();

	int GetMoney();

	int GetScore();

	void Print(bool empty = true, bool offCubesDrawing = false);

	void DrawingDices(int selectDice = -1, bool empty = false);

	void AnimationDices();

	void AnimationSelectDices();

	void AddSelectDice(int selectDice);

	void PrintSelectDice(int position);

	bool CheckIndexExistInSelectArr(int index);

	void RemoveIndexFromSelectArr(int index);

	void RemoveAllFromSelectArr();

	void SubAMoney(int bid);

	void CombinationKernel();

	void RandomCubes();
};


class RollDiceButton
{
private:
	bool nextBid;
	bool press;
	bool select;

public:
	RollDiceButton();
	
	void Print();
	
	void Select();
	
	void UnSelect();

	void Animation();
};


class BidButton
{
private:
	bool firstBid;
	bool secondBid;

	bool wasPressed;

	bool bidStatus;
	int bid;


public:

	BidButton();

	enum Pointers
	{
		NONE,
		MINUS,
		PLUS,
		OK,
	};
	
	Pointers pointer;

	void operator ++ (int);
	
	void operator -- (int);
	
	void Print();

	void BidAnimation();

	void SubABid();

	void AddToBid();

	//void NewBid(PlayerInfo& m);

	int GetBid();
	
	bool GetBidStatus();

	void BidStatusOn();

	void BidStatusOff();

	void FirstBidOn();

	bool GetFirstBidStatus();

	void SecondBidOn();

	bool GetSecondBidStatus();

	bool GetWasPressed();

	void SetWasPressedTrue();

	void SetWasPressedFalse();
};


class BidInfo 
{
private:
	PlayerInfo* player1;
	PlayerInfo* player2;

	int player1Bid;
	int player2Bid;

public:
	BidInfo(PlayerInfo* p1, PlayerInfo* p2);
	
	// aka Print()
	void SetNewBid(PlayerInfo& p, int bid);

	void Print();
};


class BotPlayScreen
{
private:
	PlayerInfo* p1;
	PlayerInfo* p2;
	RollDiceButton* rollDice;
	BidButton* bidBut;
	BidInfo* bidInfo;
public:
	BotPlayScreen(PlayerInfo* p1 = nullptr, PlayerInfo* p2 = nullptr, RollDiceButton* rollDice = nullptr, BidButton* bidBut = nullptr, BidInfo* bidInfo = nullptr);
	
	class Pointers
	{
	public:
		
		enum Columns
		{
			DICES,
			BUTTONS,
			OK_BUTTON,
		};

		enum Rows
		{
			DICE_0,
			DICE_1,
			DICE_2,
			DICE_3,
			DICE_4,

			ROLL_DICE,
			BID_BUTTON_MINUS,
			BID_BUTTON_PLUS,

			BID_BUTTON_OK,
		};

		Pointers();

		Columns GetColumn();

		Rows GetRow();

		void operator ++ (int);
		void operator -- (int);
		void operator ++ ();
		void operator -- ();

		void SetNewColumnPtr(BotPlayScreen::Pointers::Columns newColumn);

		void SetNewRowPtr(BotPlayScreen::Pointers::Rows newRow);

	private:
		Columns columnPointer;
		Rows rowPointer;
	};
	
	Pointers pointer;
	
	void PrintPointer();

	void PrintAll();
};


class WinScreen
{
public:
	void Print(bool win);
};

#endif // SCREENS