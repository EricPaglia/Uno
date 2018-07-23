#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "OrderedList.h"
#include "UnoCard.h"
#include "Stack.h"
using namespace std;


class UnoPlayer
{
private:
	string _playerName;
	OrderedList<shared_ptr<Card>> _Hand; //Hand can't exceed the size of the deck 
	int _HandSize;
public:
	UnoPlayer(int HSize, string Name); //Constructor Declaration
	~UnoPlayer() {} //Destructor Definition

	int MatchNum(shared_ptr<Card> card, int &count);//See if num matches and plays card
	int MatchSuit(shared_ptr<Card> card);//See if suit matches and plays card
	int isMatch(shared_ptr<Card> card);
	bool Uno()
	{
		if (_Hand.getLength() == 1)
		{
			cout << getName() << "Yells Uno!\n";
			return true;
		}
		return false;
	}

	void setName(string name); //Let the player chose their name
	string getName(); //Return the player's name
	
	int getHandSize(){ return _HandSize;} //Return the Players HandSize

	OrderedList<shared_ptr<Card>> getHand() { return _Hand; } //Return the Players Hand
	//mODIFY
	void print_hand()
	{
		for (unsigned int i = 1; i <= _Hand.getLength(); i++)
		{
			cout << *_Hand.retrieve(i) << " | ";
		}
		cout << endl;
	}
	//friend std::ostream& operator<<(std::ostream& os, const Card &c)
	//{
	//	int suit = c.getSuit();
	//	int demo = c.getDenomination();

	//	switch (suit) //Print the suit of the card
	//	{
	//	case 1:
	//		os << "Red ";
	//		break;
	//	case 2:
	//		os << "Yellow ";
	//		break;
	//	case 3:
	//		os << "Blue ";
	//		break;
	//	default:
	//		os << "Green ";
	//	}

	//	os << demo; //Print card number 

	//	return os;
	//}//Declare overloaded print operator

	void IncreaseHandSize() { _HandSize++; } //Increases the player's hand by 1
	void DecreaseHandSize() { _HandSize--; } //Decreases the player's hand by 1

	void GetaHand(shared_ptr<Card>pos);

	void DrawCard(shared_ptr<Card> card);
	shared_ptr<Card> PlayCard(unsigned int pos);
	bool isEmpty();
};

UnoPlayer::UnoPlayer(int HSize = 7, string Name = "Player") //Constructor
{
	_HandSize = HSize;
	_playerName = Name;
}


int UnoPlayer::MatchNum(shared_ptr<Card> card, int &count)
{
	int pos(0);
	//shared_ptr<Card> Fcard = FUp.peek(); //Store the face up card in temp card
	for (int i = 1; i <= _HandSize; i++)
	{
		shared_ptr<Card> Hcard = _Hand.retrieve(i); //Temporarily store card from hand
		if (Hcard->getDenomination() == card->getDenomination()) //Comparing cards in hand to FaceUp card
		{
			++count;
		//	--_HandSize; //Decrease the HandSize of the player 
			if (count == 1)
			{
				pos = i; //this allows to see if there is more than 1 matching number
			}
		}
	}
	if (count == 0)
		return -1;
	else
		return pos;
}

int UnoPlayer::MatchSuit(shared_ptr<Card> card)
{
	for (int i = 1; i <= _HandSize; i++)
	{
		shared_ptr<Card> Hcard = _Hand.retrieve(i); //Temporarily store card from hand
		if (Hcard->getSuit() == card->getSuit()) //Comparing cards in hand to FaceUp card
		{
			//--_HandSize; //Decrease the HandSize of the player 
			return i;
		}
	}

	return -1;
}

void UnoPlayer::setName(string name)
{
	_playerName = name;
}

string UnoPlayer::getName()
{
	return _playerName;
}

void UnoPlayer :: GetaHand(shared_ptr<Card>card)
{
	_Hand.insert(card);
	//_HandSize++;
}

void UnoPlayer::DrawCard(shared_ptr<Card> card)
{
	_Hand.insert(card);
	_HandSize++;
}

shared_ptr<Card> UnoPlayer::PlayCard(unsigned int pos)
{
//	--_HandSize;
	return _Hand.remove(pos);
}

int UnoPlayer::isMatch(shared_ptr<Card> card)
{
	int HAND = _Hand.getLength();
	//shared_ptr<Card> Fcard = FUp.peek(); //Store the face up card in temp card
	for (int i = 1; i <= HAND; i++)
	{
		//cout << "dane " << _Hand.getLength() << " This is i " << i<< " This is hand size " << _HandSize << endl;
		shared_ptr<Card> Hcard = _Hand.retrieve(i); //Temporarily store card from hand
		if (Hcard->getDenomination() == card->getDenomination()) //Comparing cards in hand to FaceUp card
		{
			return i;
		}
	}
	for (int j = 1; j <= HAND; j++)
	{
		//cout << "problem about to happen" << endl;
		shared_ptr<Card> Hcard = _Hand.retrieve(j); //Temporarily store card from hand
		if (Hcard->getSuit() == card->getSuit()) //Comparing cards in hand to FaceUp card
		{
			return j;
		}
	}
	return -1;
	
}

bool UnoPlayer::isEmpty()
{
	if (_Hand.getLength() == 0)
	{
		cout << "Empty Hand\n\n\n";
		return true;
	}
	else
		return false;
}