#pragma once
#include <iostream>
#include "Console-Settings.h"
#include "Windows.h"
#include "WinUser.h"
#include "screens.h"
//#include "bot.h"
#include "../../../1/Arros-action--GUI-pocker-dice/bot.h"

using namespace std;


void BotPlay()
{
	ClearConsole();

	PlayerInfo playerInfo(0, 0, "player");	
	PlayerInfo botInfo(0, 13, "bot");

	Bot bot;

	RollDiceButton rollDiceBut;
	BidButton bidBut;
	BidInfo bidInfo(&playerInfo, &botInfo);

	BotPlayScreen botPlayScreen{&playerInfo, &botInfo, &rollDiceBut, &bidBut, &bidInfo};
	
	WinScreen winScreen;
	
	botPlayScreen.PrintAll();

	if (GetAsyncKeyState(VK_RETURN));

	while (true)
	{
		if (bidBut.GetFirstBidStatus() && bidBut.GetSecondBidStatus())
		{
			botPlayScreen.PrintPointer();
			Sleep(3000);

			ClearConsole();

			if (botInfo.GetScore() > playerInfo.GetScore())
				winScreen.Print(false);

			else 
				winScreen.Print(true);

			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n Press 'Esc' to exit";

			while (!GetAsyncKeyState(VK_ESCAPE));
			return;
		}

		if (GetAsyncKeyState(VK_RIGHT))
		{
			Sleep(150);

			if (botPlayScreen.pointer.GetColumn() == BotPlayScreen::Pointers::Columns::DICES)
			{
				if (botPlayScreen.pointer.GetRow() + 1 <= BotPlayScreen::Pointers::Rows::DICE_4)
					botPlayScreen.pointer++;
				else
					botPlayScreen.pointer.SetNewRowPtr(BotPlayScreen::Pointers::Rows::DICE_0);
			}

			else if (botPlayScreen.pointer.GetColumn() == BotPlayScreen::Pointers::Columns::BUTTONS)
			{
				if (botPlayScreen.pointer.GetRow() + 1 <= BotPlayScreen::Pointers::Rows::BID_BUTTON_PLUS)
				{
					botPlayScreen.pointer++;
					if (BotPlayScreen::Pointers::Rows::ROLL_DICE < botPlayScreen.pointer.GetRow() && botPlayScreen.pointer.GetRow() <= BotPlayScreen::Pointers::Rows::BID_BUTTON_PLUS)
					{
						if (botPlayScreen.pointer.GetRow() == BotPlayScreen::Pointers::Rows::BID_BUTTON_MINUS)
							bidBut.pointer = BidButton::Pointers::MINUS;
						else
							bidBut.pointer = BidButton::Pointers::PLUS;
					}
				}
			}

			else if (botPlayScreen.pointer.GetColumn() == BotPlayScreen::Pointers::Columns::OK_BUTTON)
			{
				botPlayScreen.pointer--;
				botPlayScreen.pointer.operator--();
				bidBut.pointer = BidButton::Pointers::PLUS;
			}

			botPlayScreen.PrintPointer();
		}

		else if (GetAsyncKeyState(VK_LEFT))
		{
			Sleep(150);

			if (botPlayScreen.pointer.GetColumn() == BotPlayScreen::Pointers::Columns::DICES)
			{
				if (botPlayScreen.pointer.GetRow() - 1 >= BotPlayScreen::Pointers::Rows::DICE_0)
					botPlayScreen.pointer--;
				else
					botPlayScreen.pointer.SetNewRowPtr(BotPlayScreen::Pointers::Rows::DICE_4);
			}

			else if (botPlayScreen.pointer.GetColumn() == BotPlayScreen::Pointers::Columns::BUTTONS)
			{
				if (botPlayScreen.pointer.GetRow() - 1 == BotPlayScreen::Pointers::Rows::ROLL_DICE)
				{
					if (bidBut.GetBidStatus())
						botPlayScreen.pointer--;
					else
						continue;
				}

				else if (botPlayScreen.pointer.GetRow() - 1 >= BotPlayScreen::Pointers::Rows::ROLL_DICE)
				{
					botPlayScreen.pointer--;
					if (BotPlayScreen::Pointers::Rows::ROLL_DICE < botPlayScreen.pointer.GetRow() && botPlayScreen.pointer.GetRow() <= BotPlayScreen::Pointers::Rows::BID_BUTTON_PLUS)
					{
						if (botPlayScreen.pointer.GetRow() == BotPlayScreen::Pointers::Rows::BID_BUTTON_MINUS)
							bidBut.pointer = BidButton::Pointers::MINUS;
						else
							bidBut.pointer = BidButton::Pointers::PLUS;
					}
					else
						bidBut.pointer = BidButton::Pointers::NONE;
				}
			}

			else if (botPlayScreen.pointer.GetColumn() == BotPlayScreen::Pointers::Columns::OK_BUTTON)
			{
				botPlayScreen.pointer.operator--();
				botPlayScreen.pointer.SetNewRowPtr(BotPlayScreen::Pointers::Rows::BID_BUTTON_MINUS);
				bidBut.pointer = BidButton::Pointers::MINUS;
			}
			botPlayScreen.PrintPointer();
		}

		else if (GetAsyncKeyState(VK_UP))
		{
			Sleep(150);


			if (botPlayScreen.pointer.GetColumn() == BotPlayScreen::Pointers::Columns::DICES)
				continue;


			if (botPlayScreen.pointer.GetColumn() == BotPlayScreen::Pointers::Columns::BUTTONS)
			{
				if (!bidBut.GetBidStatus()) continue;

				bidBut.pointer = BidButton::NONE;

				if (botPlayScreen.pointer.GetRow() == BotPlayScreen::Pointers::Rows::ROLL_DICE)
					botPlayScreen.pointer.SetNewRowPtr(BotPlayScreen::Pointers::Rows::DICE_0);

				else if (botPlayScreen.pointer.GetRow() == BotPlayScreen::Pointers::Rows::BID_BUTTON_MINUS || botPlayScreen.pointer.GetRow() == BotPlayScreen::Pointers::Rows::BID_BUTTON_PLUS)
					botPlayScreen.pointer.SetNewRowPtr(BotPlayScreen::Pointers::Rows::DICE_2);
			}

			else if (botPlayScreen.pointer.GetColumn() == BotPlayScreen::Pointers::Columns::OK_BUTTON)
			{
				botPlayScreen.pointer.SetNewRowPtr(BotPlayScreen::Pointers::Rows::BID_BUTTON_PLUS);
				bidBut.pointer = BidButton::PLUS;
			}


			botPlayScreen.pointer.operator--();

			botPlayScreen.PrintPointer();
		}

		else if (GetAsyncKeyState(VK_DOWN))
		{
			Sleep(150);
			if (botPlayScreen.pointer.GetColumn() == BotPlayScreen::Pointers::Columns::OK_BUTTON)
				continue;

			if (botPlayScreen.pointer.GetColumn() == BotPlayScreen::Pointers::Columns::DICES)
			{
				if (botPlayScreen.pointer.GetRow() < BotPlayScreen::Pointers::Rows::DICE_3)
				{
					botPlayScreen.pointer.SetNewRowPtr(BotPlayScreen::Pointers::Rows::BID_BUTTON_MINUS);
					bidBut.pointer = BidButton::MINUS;
				}
				else
				{
					botPlayScreen.pointer.SetNewRowPtr(BotPlayScreen::Pointers::Rows::BID_BUTTON_PLUS);
					bidBut.pointer = BidButton::PLUS;
				}
			}

			else if (botPlayScreen.pointer.GetColumn() == BotPlayScreen::Pointers::Columns::BUTTONS)
			{
				botPlayScreen.pointer.SetNewRowPtr(BotPlayScreen::Pointers::Rows::BID_BUTTON_OK);
				bidBut.pointer = BidButton::Pointers::OK;
			}

			botPlayScreen.pointer.operator++();

			botPlayScreen.PrintPointer();
		}

		else if (GetAsyncKeyState(VK_RETURN))
		{
			Sleep(150);

			if (botPlayScreen.pointer.GetColumn() == BotPlayScreen::Pointers::Columns::DICES)
			{
				if (botPlayScreen.pointer.GetRow() == BotPlayScreen::Pointers::Rows::DICE_0)
				{
					if (playerInfo.CheckIndexExistInSelectArr(0))
						playerInfo.RemoveIndexFromSelectArr(0);
					else
						playerInfo.AddSelectDice(0);
				}
				else if (botPlayScreen.pointer.GetRow() == BotPlayScreen::Pointers::Rows::DICE_1)
				{
					if (playerInfo.CheckIndexExistInSelectArr(1))
						playerInfo.RemoveIndexFromSelectArr(1);
					else
						playerInfo.AddSelectDice(1);
				}
				else if (botPlayScreen.pointer.GetRow() == BotPlayScreen::Pointers::Rows::DICE_2)
				{
					if (playerInfo.CheckIndexExistInSelectArr(2))
						playerInfo.RemoveIndexFromSelectArr(2);
					else
						playerInfo.AddSelectDice(2);
				}
				else if (botPlayScreen.pointer.GetRow() == BotPlayScreen::Pointers::Rows::DICE_3)
				{
					if (playerInfo.CheckIndexExistInSelectArr(3))
						playerInfo.RemoveIndexFromSelectArr(3);
					else
						playerInfo.AddSelectDice(3);
				}
				else if (botPlayScreen.pointer.GetRow() == BotPlayScreen::Pointers::Rows::DICE_4)
				{
					if (playerInfo.CheckIndexExistInSelectArr(4))
						playerInfo.RemoveIndexFromSelectArr(4);
					else
						playerInfo.AddSelectDice(4);
				}
			}

			else if (botPlayScreen.pointer.GetColumn() == BotPlayScreen::Pointers::Columns::BUTTONS)
			{
				if (botPlayScreen.pointer.GetRow() == BotPlayScreen::Pointers::Rows::BID_BUTTON_MINUS)
				{
					if (bidBut.GetBid() - 5 >= 0)
						bidBut.SubABid();
				}

				else if (botPlayScreen.pointer.GetRow() == BotPlayScreen::Pointers::Rows::BID_BUTTON_PLUS)
				{
					if (bidBut.GetBid() + 5 <= playerInfo.GetMoney())
						bidBut.AddToBid();
				}

				else if (botPlayScreen.pointer.GetRow() == BotPlayScreen::Pointers::Rows::ROLL_DICE && bidBut.GetBidStatus())
				{
					bidBut.SetWasPressedFalse();

					rollDiceBut.Animation();
					playerInfo.AnimationSelectDices();
					playerInfo.RemoveAllFromSelectArr();

					playerInfo.CombinationKernel();
					playerInfo.Print(false);

					bidBut.BidStatusOff();

					bidBut.pointer = BidButton::OK;
					botPlayScreen.pointer.SetNewRowPtr(BotPlayScreen::Pointers::Rows::BID_BUTTON_OK);
					botPlayScreen.pointer.operator++();
				}
			}

			else if (botPlayScreen.pointer.GetColumn() == BotPlayScreen::Pointers::Columns::OK_BUTTON)
			{
				if (bidBut.GetWasPressed()) continue;
				if (bidBut.GetBid() > 0 && playerInfo.GetMoney() - bidBut.GetBid() >= 0)
				{
					bidBut.SetWasPressedTrue();

					bidBut.BidStatusOn();
					bidBut.BidAnimation();

					bidInfo.SetNewBid(playerInfo, bidBut.GetBid());

					if (!bidBut.GetFirstBidStatus())
					{
						bidBut.FirstBidOn();

						playerInfo.AnimationDices();
						botInfo.AnimationDices();
					}

					else if (bidBut.GetFirstBidStatus() && !bidBut.GetSecondBidStatus())
					{
						bidBut.SecondBidOn();
						
						botInfo.RandomCubes();
					}

					// bot

					int a;
					if (botInfo.GetScore() < 2)
						a = 10 + rand() % 30;
					else if (botInfo.GetScore() == 2)
						a = 10 + rand() % 40;
					else
						a = 10 + rand() % 20;

					botInfo.CombinationKernel();
					bidInfo.SetNewBid(botInfo, a);
					botInfo.SubAMoney(a);
					botInfo.Print(false);

					// player
					playerInfo.CombinationKernel();
					playerInfo.SubAMoney(bidBut.GetBid());
					playerInfo.Print(false);
				}
			}

			botPlayScreen.PrintPointer();
		}
	}
}


// table of buttons - https://firststeps.ru/mfc/msdn/r.php?48
//https://www.cyberforum.ru/cpp-beginners/thread2027113.html

int main()
{
	srand(time(NULL));

	DefaultConsole();
	MainScreen menuPointer;

	menuPointer.Print();

	while (true)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			Sleep(150);
			menuPointer--;
			menuPointer.Print();
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			Sleep(150);
			menuPointer++;
			menuPointer.Print();
		}
		
		if (GetAsyncKeyState(VK_RETURN))
		{
			Sleep(150);
			
			if (menuPointer.pointer == MainScreen::Pointers::PLAY)
			{
				BotPlay();
				//PrePlayChoiceScreen PPCSPointer;
				//PPCSPointer.Print();
				//while (!GetAsyncKeyState(VK_ESCAPE))
				//{
				//	if (GetAsyncKeyState(VK_RIGHT))
				//	{
				//		PPCSPointer++;
				//		Sleep(150);
				//		PPCSPointer.Print();
				//	}
				//	else if (GetAsyncKeyState(VK_LEFT))
				//	{
				//		PPCSPointer--;
				//		Sleep(150);
				//		PPCSPointer.Print();
				//	}
				//	else if (GetAsyncKeyState(VK_RETURN))
				//	{
				//		Sleep(150);

				//		if (PPCSPointer.pointer == PrePlayChoiceScreen::Pointers::BOT)
				//		{
				//			BotPlay();
				//		}
				//		else if (PPCSPointer.pointer == PrePlayChoiceScreen::Pointers::TWO_PLAYERS);
				//			// two players play
				//	}
				//}

				if (GetAsyncKeyState(VK_RETURN));
				if (GetAsyncKeyState(VK_UP));
				if (GetAsyncKeyState(VK_DOWN));
				if (GetAsyncKeyState(VK_LEFT));
				if (GetAsyncKeyState(VK_RIGHT));
				menuPointer.Print();
			}

			else if (menuPointer.pointer == MainScreen::Pointers::HELP)
			{
				HelpScreen hp;
				if (!GetAsyncKeyState(VK_ESCAPE))
				{
					hp.Print();
					while (!GetAsyncKeyState(VK_ESCAPE));
				}
				menuPointer.Print();
			}
			
			else if (menuPointer.pointer == MainScreen::Pointers::EXIT)
			{
				return 1;
			}
		}
	}
	return 1;
}