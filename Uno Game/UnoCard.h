#pragma once
#include <iostream>

//User defined Suits and Denomination types (user-defined integers)
enum Suit { RED = 1, YELLOW = 2, BLUE = 3, GREEN = 4 };
enum Denomination { N1 = 1, N2 = 2, N3 = 3, N4 = 4, N5 = 5 };

class Card
{
private:
	Suit _suit; //privately stores suit 
	Denomination _denomination; //privately stores denomination 
	friend std::ostream& operator<<(std::ostream& os, const Card &c); //Decalre overloaded print operator 

public:
	Card(Suit suit = RED, Denomination denomination = N1); //Constructor with default values
	~Card(); //Destructor

	inline Suit getSuit(void) const //return the suit 
	{
		return _suit;
	}

	inline Denomination getDenomination(void) const //return the denomination 
	{
		return _denomination;
	}

	char toCharSuit(void); // returns a char that "describes" card's suit
	char toCharDenomination(void); // returns a char that "describes" card's denomination
};

// global operator functions comparing denominations of two cards
// The cards a and b are passed by reference
inline bool operator<(const Card& a, const Card& b) {
	if (a.getSuit() == b.getSuit())
		return (a.getDenomination()<b.getDenomination()); //this will return true or false
	else
		return (a.getSuit()<b.getSuit());
}
inline bool operator>(const Card& a, const Card& b) {
	if (a.getSuit() == b.getSuit())
		return (a.getDenomination()>b.getDenomination());
	else
		return (a.getSuit()>b.getSuit());
}

// checks equality of suits and denominations for two cards
inline bool operator==(Card& a, Card& b)  
{ 
	return (a.getDenomination() == b.getDenomination() && a.getSuit() == b.getSuit()); 
	//Checks to see if BOTH the suit and the denomination are the same 
}