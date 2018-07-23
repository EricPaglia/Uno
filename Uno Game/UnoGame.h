#pragma once
#include<iostream>
#include<memory>
#include <ctime>
#include <string.h>
#include "Stack.h"
#include "Queue.h"
#include "Bag.h"
#include "UnoCard.h"
#include "OrderedList.h"
#include "UnoPlayer.h"
#include "List.h"

#define _NumPlayers 3
#define _DECKSIZE 40
#define _DefaultHandSize 7
class UnoGame
{
private:
	//int _NumPlayers;
	UnoPlayer *_Players;
	
	//Make a bag of size 40 (5 ranks * 2 ranks/suit * 4 suits)
	Queue<shared_ptr<Card>> _Deck; //Create a queue to store the deck
	Stack<shared_ptr<Card>> _FaceUp;//Create a stack to store face up cards
	Bag<shared_ptr<Card>> _Bag; //Put in constructor 
	//int _HandSize;
	int _DeckSize;

public:
	UnoGame(int handSize, int deckSize); //Destructor 
	~UnoGame();//Destructor
	void FillBag();
	void MakeDeck();
	void FlipCard();
	void ShuffleDeck();
	//void PrintDeck(int DeckSize, Queue<shared_ptr<Card>> &deck); //Print the LinkedList
	void StartGame();
	void PrintHand(int n);

	void PrintDeck();
};

//Constructor
UnoGame::UnoGame(int handSize = 7, int deckSize = _DECKSIZE) //dsaf
{
	{
		//_NumPlayers = nPlayers;
		//_HandSize = handSize;
		_DeckSize = deckSize;
		_Players = new UnoPlayer[_NumPlayers]; //Creating Array


		std::cout << "Let's Play Uno! \n\n";
		//Initialize users
		for (int i = 0; i < _NumPlayers; i++)
		{
			string UserName;
			std::cout << "Player " << i+1 << " Enter your name: ";
			cin >> UserName;
			_Players[i].setName(UserName);
		}
		
		std::cout << "Filling the Bag...Queue\n";
		FillBag();//Fill the bag
	
		
		MakeDeck();
		//PrintDeck();
		

		//GET A HAND FOR EACH PLAYER
		for (int i = 0; i < _NumPlayers; i++) //First loop for player i
		{
			std::cout << "Getting hand for " << _Players[i].getName() << ": ";
			for (int j = 0; j < _DefaultHandSize; j++)
			{
				_Players[i].GetaHand(_Deck.dequeue()); 
				_DeckSize--; //Keep track of the Deck Size 
			}
			_Players[i].print_hand();
		}

		


		//std::cout << "Flipping Card\n";
		//FlipCard(); //Draw card from deck and place face up 
		//std::cout << *_FaceUp.peek();
	}
}

//Destructor
UnoGame::~UnoGame()
{
	delete[] _Players; //Delete the players
}

void UnoGame::FillBag()
{
	//make a bag
	std::cout << "Filling the Bag...Queue\n";
	Suit s[] = { RED, YELLOW, BLUE, GREEN };
	Denomination d[] = { N1, N2, N3, N4, N5 };

	//Filling the bag
	for (int i = 0; i < 4; i++) //First loop for suits 
	{
		for (int j = 0; j < 5; j++) //Second loop for denominations 
		{
			_Bag.add(make_shared<Card>(s[i], d[j]));
			_Bag.add(make_shared<Card>(s[i], d[j])); //Add same card twice because there is 2 of each card
		}
	}
}

void UnoGame::MakeDeck()
{
	for (int i = 0; i < _DeckSize; i++)
	{
		_Deck.enqueue(_Bag.getOne()); //Randomly take a card from bag and insert in order into the hand
									  //std::cout << "Just added to the deck...\n";
	}
}

void UnoGame::FlipCard()
{
	_FaceUp.push(_Deck.dequeue()); //Take top card from the deck (queue) and place it faceup (on the stack)
}


void UnoGame :: ShuffleDeck()
{
	shared_ptr<Card> temp = _FaceUp.peek(); //temporarily store the face up card 

	for (int i = 1; i <= _DeckSize; i++)
	{
		_Bag.add(_FaceUp.pop()); //Empty the stack into the bag
	}

	for (int i = 1; i <= _DeckSize; i++)
	{
		_Deck.enqueue(_Bag.getOne()); //Empty the bag into the deck
	}

	_FaceUp.push(temp); //Place the original FaceUp card in the empty stack
}

void UnoGame::StartGame()
{
	int turn = 1; 
	
	int CurrentPlayer = 0;//keep track of who's turn 
	cout << "Let's Go!\n\n";
	FlipCard();
	cout << "The Face Up Card is: " << *_FaceUp.peek() << "\n";

	bool over = true; //variable to see if someomone has won
	while (over)
	{
		std::cout << "\nTurn " << turn << "\n\n";
		std::cout << _Players[CurrentPlayer].getName() << "'s turn\n";
		//Check to see if player has a valid move (i.e. matching number or suit) 
		int DoesItMatch = _Players[CurrentPlayer].isMatch(_FaceUp.peek());

			if (DoesItMatch != -1)
			{
				//Play Card (remove from hand and place on stack)
				_FaceUp.push(_Players[CurrentPlayer].PlayCard(DoesItMatch));

				if (_Players[CurrentPlayer].Uno()) {} //Checks if player has last card
				
				if (_Players[CurrentPlayer].isEmpty())
				{
					std::cout << _Players[CurrentPlayer].getName() << " is the champ!\n\n";
					/*int pause;
					cin >> pause;*/
					over = false;
				}
				/*for (int i = 0; i < _NumPlayers; i++)
				{
					_Players[i].print_hand();
				}*/
			}
			//If player ha no matching cards, check for matching suits
			
			else
			{
				std::cout << _Players[CurrentPlayer].getName() << ", draw a card\n";
				_Players[CurrentPlayer].DrawCard(_Deck.dequeue());
				//Player draws card from deck 
			}

			//Shuffle the deck if there are no cards remaining
			if (_Deck.isEmpty())
			{
				std::cout << "Shuffling the deck\n";
				//ShuffleDeck();
				shared_ptr<Card> temp = _FaceUp.peek(); //temporarily store the face up card 

				//for (int i = 1; i <= _DeckSize; i++)
				//{
				//	_Bag.add(_FaceUp.pop()); //Empty the stack into the bag
				//}

				for (int i = 1; i <= _DeckSize; i++)
				{
					_Deck.enqueue(_FaceUp.pop()); //Empty the stack into the deck
					//_Deck.enqueue(_Bag.getOne()); //Empty the bag into the deck
				}

				_FaceUp.push(temp); //Place the original FaceUp card in the empty stack
			}

			
			CurrentPlayer++;
			if (CurrentPlayer == _NumPlayers) //Go back to player 1's turn
			{
				CurrentPlayer = 0;
			}
			turn++;
	}
}

void UnoGame::PrintDeck()
{
	//Printing the deck
	for (int i = 1; i <= _DeckSize; i++)
	{
		shared_ptr<Card> card = _Deck.getValue(i); //Get value from queue
		cout << card << endl;
	}
}