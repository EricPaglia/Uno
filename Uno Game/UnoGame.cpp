#include <iostream>
//#include"UnoGame.h"


////void UnoGame::FillBag()
////{
////	//make a bag
////
////	Suit s[] = { RED, YELLOW, BLUE, GREEN };
////	Denomination d[] = { N1, N2, N3, N4, N5 };
////
////	//Filling the bag
////	for (int i = 0; i < 4; i++) //First loop for suits 
////	{
////		for (int j = 0; j < 5; j++) //Second loop for denominations 
////		{
////			_bag.add(Card(s[i], d[j]));
////			_bag.add(Card(s[i], d[j])); //Add same card twice because there is 2 of each card
////		}
////	}
////}
//
////void UnoGame::MakeDeck(int DeckSize, Bag<Card> &bag, Queue<Card> &deck)
////{
////	for (int i = 0; i < DeckSize; i++)
////	{
////		deck.enqueue(bag.getOne()); //Randomly take a card from bag and insert in order into the hand
////	}
////}
////
////void UnoGame::getAHand(OrderedList<Card> &hand/*unsigned int n, OrderedList<Card> &hand, Queue<Card> &deck, int &DeckSize*/)
////{
////	for (int i = 0; i <_NumPlayers; i++)
////	{
////		hand.insert(Deck.dequeue()); //adds a number to the ordered list 
////									 //Take number from front of queue using dequeue
////
////		--_DeckSize; //Decrease the size of the deck
////	}
////}