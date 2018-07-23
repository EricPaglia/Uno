#include "UnoCard.h"

Card::Card(Suit suit, Denomination denomination) //The constructor 
{
	_suit = suit;
	_denomination = denomination;
}

Card::~Card() // Destructor 
{}

char Card::toCharSuit() //Give each suit a char equivalent
{
	if (_suit == RED)   return 'R';
	else if (_suit == YELLOW)    return 'Y';
	else if (_suit == BLUE)   return 'B';
	else                       return 'G';
}

char Card::toCharDenomination() //Give each denomination a char equivalent
{
	if (_denomination == N1)	return '1';
	else if (_denomination == N2)	return '2';
	else if (_denomination == N3)	return '3';
	else if (_denomination == N4)	return '4';
	else if (_denomination == N5)	return '5';
}

std::ostream& operator<<(std::ostream& os, const Card &c) //Define overloaded print operator 
{
	int suit = c.getSuit();
	int demo = c.getDenomination();

	
	switch (suit) //Print the suit of the card
	{
	case 1:
		os << "Red ";
		break;
	case 2:
		os << "Yellow ";
		break;
	case 3:
		os << "Blue ";
		break;
	default:
		os << "Green ";
	}

	os << demo; //Print card number 

	return os;
}