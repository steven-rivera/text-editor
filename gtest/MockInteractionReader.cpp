// MockInteractionReader.cpp
//
// ICS 45C Fall 2020
// Project #4: People Just Want to Play with Words
//
// Implementation of the MockInteractionReader class
//
// DO NOT MODIFY THIS FILE

#include "MockInteractionReader.hpp"


MockInteractionReader::MockInteractionReader(const std::vector<Interaction>& interactions)
    : interactions{interactions}, nextInteractionIndex{0}
{
}


Interaction MockInteractionReader::nextInteraction()
{
    if (nextInteractionIndex >= interactions.size())
    {
        return Interaction::quit();
    }
    else
    {
        Interaction& next = interactions[nextInteractionIndex];
        ++nextInteractionIndex;
        return next;
    }
}

