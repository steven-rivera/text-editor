// KeypressInteractionReader.cpp
//
// ICS 45C Fall 2020
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include "KeypressInteractionReader.hpp"
#include "CharCommand.hpp"
#include "UpCommand.hpp"
#include "DownCommand.hpp"
#include "LeftCommand.hpp"
#include "RightCommand.hpp"
#include "HomeCommand.hpp"
#include "EndCommand.hpp"
#include "NewLineCommand.hpp"
#include "BackspaceCommand.hpp"
#include "DeleteLineCommand.hpp"



// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

Interaction KeypressInteractionReader::nextInteraction()
{
    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

            switch (keypress.code())
            {
            case 'I':
                return Interaction::command(new UpCommand);
            case 'K':
                return Interaction::command(new DownCommand);
            case 'U':
                return Interaction::command(new LeftCommand);
            case 'O':
                return Interaction::command(new RightCommand);
            case 'Y':
                return Interaction::command(new HomeCommand);
            case 'P':
                return Interaction::command(new EndCommand);
            case 'J':
               return Interaction::command(new NewLineCommand);
            case 'M':
                return Interaction::command(new NewLineCommand);
            case 'H':
                return Interaction::command(new BackspaceCommand);
            case 'D':
                return Interaction::command(new DeleteLineCommand);
            case 'Z':
                return Interaction::undo();
            case 'A':
                return Interaction::redo();
            case 'X':
                return Interaction::quit();
            }
        }
        else
        {
            // The user pressed a normal key (e.g., 'h') without holding
            // down Ctrl; react accordingly
            return Interaction::command(new CharCommand{keypress.code()});
        }
    }
}

