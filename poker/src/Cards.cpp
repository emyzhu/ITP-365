// ITP 365 Fall 2014
// HW4 – Vector and Poker Hands
// Name: Tommy Trojan
// Email: ttrojan@usc.edu
// Platform: Windows
//
// Cards.cpp
// Implements Cards and Poker Hand functionality
#include "Cards.h"

#include <random>
#include <algorithm>

// Function: Constructor
// Purpose: Draws 5 cards from the supplied deck, and sorts them
// by rank
// Input: Takes in a ITPVector of cards for the deck
// Returns: Nothing
PokerHand::PokerHand(ITPVector<Card>& deck)
{
    for(int i = 0; i < 5; i++) {
        Card lastCard = deck.back();
        mHand.push_back(lastCard);
        deck.pop_back();
    }
    sortHand();
}

// Function: getBestPokerHand
// Purpose: Returns a string describing the poker hand this PokerHand
// contains
// Input: None
// Returns: The name of the best poker hand
std::string PokerHand::getBestPokerHand() const
{
    // go from highest to lowest ranking hand to check for the hand that the cards make up
    if (hasStraight() && hasFlush()) {
        return "straight flush";
    }
    else if (hasFourOfAKind()) {
        return "four of a kind";
    }
    else if (hasFullHouse()) {
        return "full house";
    }
    else if (hasFlush()) {
        return "flush";
    }
    else if (hasStraight()) {
        return "straight";
    }
    else if (hasThreeOfAKind()) {
        return "three of a kind";
    }
    else  if (hasTwoPairs()) {
        return "two pairs";
    }
    else if (hasPair()) {
        return "pair";
    }
    else {
        return "high card";
    }
}

// Function: hasStraight
// Purpose: Determines if the hand has a straight
// Input: None
// Returns: true if there's a straight
bool PokerHand::hasStraight() const
{
    bool isStraight = false;
    int counter = 0;
    for (int i = 1; i < mHand.size(); i++) {
        //each time when the preceeding card's rank is equal to the current card's rank minus 1, the counter increases by 1
        if(mHand[i - 1].mRank == ((mHand[i].mRank) - 1)) {
            counter += 1;
        }
    }
    // bascially, the for loop will go thru the loop four times to compare all of the sequential values
    // and if the check passes all four times, then the counter should equal 4. otherwise there were two sequential values that
    // were not one less than another
    if (counter == 4) {
        isStraight = true;
    }
	return isStraight;
}

// Function: hasFlush
// Purpose: Determines if the hand has a flush
// Input: None
// Returns: true if there's a flush
bool PokerHand::hasFlush() const
{
    //arbitrarily selects the first element of the hand to compare its suit with the other four cards to see if they are the same
    Suit firstCardSuit = mHand[0].mSuit;
    int counter = 0;
    for(int i = 1; i < mHand.size(); i++) {
        // counter increases for each time the suit of the card in question matches the initial one (firstCardSuit)
        if(mHand[i].mSuit == firstCardSuit) {
            counter += 1;
        }
        // bascially, the for loop will go thru the loop four times to compare rest of cards' suits with that of the first one
        // and if the check passes all four times, then the counter should equal 4.
        if(counter == 4) {
            return true;
        }
    }
	return false;
}

// Function: hasFourOfAKind
// Purpose: Determines if the hand has a 4 of a kind
// Input: None
// Returns: true if there's a 4 of a kind
bool PokerHand::hasFourOfAKind() const
{
	// Since it's sorted, there are only two possibilities:
	// x x x x y
	// or
	// x y y y y

    if(mHand[0].mRank == mHand[1].mRank &&
      mHand[1].mRank == mHand[2].mRank &&
       mHand[2].mRank == mHand[3].mRank) {
        return true;
    }
    
    if(mHand[1].mRank == mHand[2].mRank &&
      mHand[2].mRank == mHand[3].mRank &&
       mHand[3].mRank == mHand[4].mRank) {
        return true;
    }
    
    else {
        return false;

    }
}

// Function: hasFullHouse
// Purpose: Determines if the hand has a full house
// Input: None
// Returns: true if there's a full house
bool PokerHand::hasFullHouse() const
{
	// Since it's sorted, there are only two possibilities:
	// x x x y y
	// or
	// x x y y y
    if(mHand[0].mRank == mHand[1].mRank &&
       mHand[1].mRank == mHand[2].mRank &&
       mHand[3].mRank == mHand[4].mRank) {
        return true;
    }
    
    if(mHand[2].mRank == mHand[3].mRank &&
       mHand[3].mRank == mHand[4].mRank &&
       mHand[0].mRank == mHand[1].mRank) {
        return true;
    }
    return false;
}

// Function: hasThreeOfAKind
// Purpose: Determines if the hand has a three of a kind
// Input: None
// Returns: true if there's a three of a kind
bool PokerHand::hasThreeOfAKind() const
{
	// There are three possibilities:
	// x x x y z
	// x y y y z
	// x y z z z

	if(mHand[0].mRank == mHand[1].mRank &&
       mHand[1].mRank == mHand[2].mRank) {
        return true;
    }
    if(mHand[1].mRank == mHand[2].mRank &&
       mHand[2].mRank == mHand[3].mRank) {
        return true;
    }
    if(mHand[2].mRank == mHand[3].mRank &&
       mHand[3].mRank == mHand[4].mRank) {
        return true;
    }
    else {
        return false;
    }
}

// Function: hasTwoPairs
// Purpose: Determines if the hand has two pairs
// Input: None
// Returns: true if there's two pairs
bool PokerHand::hasTwoPairs() const
{
	// There are three possibilities:
	// x x y y z
	// x y y z z
	// x x y z z

    // if conditions reflect the three possibilitie smentioned above basically.
    // specifically, the statments refer to where the pairs can be found. there three possibilities because the suit is sorted
    if(mHand[0].mRank == mHand[1].mRank &&
       mHand[2].mRank == mHand[3].mRank) {
        return true;
    }
    if(mHand[0].mRank == mHand[1].mRank &&
       mHand[3].mRank == mHand[4].mRank) {
        return true;
    }
    if(mHand[1].mRank == mHand[2].mRank &&
       mHand[3].mRank == mHand[4].mRank) {
        return true;
    }
    else {
        return false;
    }
}

// Function: hasPair
// Purpose: Determines if there's a pair
// Input: None
// Returns: true if there's a pair
bool PokerHand::hasPair() const
{
    if(mHand[0].mRank == mHand[1].mRank) {
        return true;
    }
    if(mHand[1].mRank == mHand[2].mRank) {
        return true;
    }
    if(mHand[2].mRank == mHand[3].mRank) {
        return true;
    }
    if(mHand[3].mRank == mHand[4].mRank) {
        return true;
    }
    return false;
}

// Function: sortHand
// Purpose: Sorts the cards in ascending order by rank
// Input: None
// Returns: Nothing
void PokerHand::sortHand()
{
    unsigned smallestIndex;
    // Use selection sort to order the hand
    for(int i = 0; i < mHand.size(); i++) {
        smallestIndex = i;
        //look at index starting one spot ahead (which is j) of current index i and keep stepping thru with j until the end
        for(int j = i + 1; j < mHand.size(); j++) {
            if(mHand[j] < mHand[smallestIndex]) {
                smallestIndex = j;
            }
        }
        //actual swapping
        if(smallestIndex != i) {
            //variable created to temporaily store bigger variable at original index i
            Card hold = mHand[i];
            mHand[i] = mHand[smallestIndex];
            mHand[smallestIndex] = hold;
        }
    }

}

// Function: createDeck
// Purpose: Given an empty ITPVector of Cards, inserts a
// standard 52 card deck and shuffles it
// Input: An ITPVector of Cards (by reference)
// Returns: nothing
void createDeck(ITPVector<Card>& deck)
{
    // loop thru suits and assign rank for each suit
    for(int currentSuit = 0; currentSuit < 4; currentSuit++) {
        //loop thru the ranks, starting from 2 and up to ace (aka rank 14)
        Suit enumSuit = (Suit)currentSuit;
        for(unsigned int currentRank = 2; currentRank <= 14; currentRank++) {
            Card currentCard = Card(currentRank, enumSuit);
            deck.push_back(currentCard);
        }
        //then we can go onto the next suit and do it over again until we have all 52 cards
        
    }
	// LEAVE THIS HERE!
	std::random_shuffle(&deck[0], &deck[0] + deck.size());
}

// Function: << operator for Card
// Purpose: Outputs the name and suit of the card
// Input: ostream and card
// Returns: ostream, with card data output to it
std::ostream& operator<<(std::ostream& os, const Card& card)
{
    switch (card.mRank)
    {
        case 11: os << "Jack";
                break;
        case 12: os << "Queen";
                 break;
        case 13: os << "King";
                break;
        case 14: os << "Ace";
                break;
        default:
            os << card.mRank;
    }
    os << " of ";
    switch (card.mSuit)
    {
        case 0: os << "Clubs";
                break;
        case 1: os << "Diamonds";
                 break;
        case 2: os << "Hearts";
                break;
        case 3: os << "Spades";
                break;
    }
	return os;
}


// Function: < comparison operator for Card
// Purpose: Compares the value of the left and right card
// Input: Two cards to compare
// Returns: true if left < right
bool operator<(const Card& left, const Card& right)
{
    //if the ranks are the same, we need to compare suits
    //check if rank is the same
    if(left.mRank == right.mRank) {
        return left.mSuit < right.mSuit;
    }
    return left.mRank < right.mRank;
}

// Function: > comparison operator for Card
// Purpose: Compares the value of the left and right card
// Input: Two cards to compare
// Returns: true if left > right
bool operator>(const Card& left, const Card& right)
{
    bool leftIsGreaterThanRight = false;
    if(right < left) {
        leftIsGreaterThanRight = true;
    }
    return leftIsGreaterThanRight;
}

// Function: << operator
// Purpose: Prints out the hand
std::ostream& operator<<(std::ostream& os, const PokerHand& hand)
{
    os << "{ ";
    for(int i = 0; i < 4; i++) {
        os << hand.mHand[i] << ", ";
    }
    os << hand.mHand[4] << " }";
	return os;
}
