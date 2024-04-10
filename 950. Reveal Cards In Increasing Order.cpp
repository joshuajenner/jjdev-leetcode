// You are given an integer array deck. There is a deck of cards where every card has a unique integer. 
// The integer on the ith card is deck[i].

// You can order the deck in any order you want. Initially, all the cards start face down (unrevealed) in one deck.

// You will do the following steps repeatedly until all cards are revealed:

// 1. Take the top card of the deck, reveal it, and take it out of the deck.
// 2. If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.
// 3. If there are still unrevealed cards, go back to step 1. Otherwise, stop.
// Return an ordering of the deck that would reveal the cards in increasing order.

// Note that the first entry in the answer is considered to be the top of the deck.

#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) 
{
    int ds = deck.size();
    std::sort(deck.begin(), deck.end());
    std::vector<int> answer;
    answer.reserve(ds);

    for (int index = 0; index <= ds/2; index++) 
    {
        if (index < ds / 2)
        {
            answer.push_back(deck[index]);
        } 
        answer.push_back(deck[ds / 2 + index]);
    }

    return answer;
}


int main() 
{
    std::vector<int> data{ 1, 1000 };
    std::vector<int> tester = deckRevealedIncreasing(data);
    std::cin.get();
}