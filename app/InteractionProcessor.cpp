// InteractionProcessor.cpp
//
// ICS 45C Fall 2020
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include <vector>
#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"

namespace
{
    void deallocateVectorElements(std::vector<Command*>& v)
    {
        for (unsigned int i = 0; i < v.size(); ++i)
        {
            delete v[i];
        }
    }
}

// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.
void InteractionProcessor::run()
{
    view.refresh();
    std::vector<Command*> commandHistory;
    std::vector<Command*> undoHistory;

    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {
            break;
        }
        else if (interaction.type() == InteractionType::undo && !commandHistory.empty())
        {
            Command* prevCommand = commandHistory.back();
            commandHistory.pop_back();
            
            prevCommand->undo(model);
            undoHistory.push_back(prevCommand);
            view.refresh();
        }
        else if (interaction.type() == InteractionType::redo && !undoHistory.empty())
        {
            Command* redoCommand = undoHistory.back();
            undoHistory.pop_back();

            redoCommand->execute(model);
            commandHistory.push_back(redoCommand);
            view.refresh();
        }
        else if (interaction.type() == InteractionType::command)
        {
            Command* command = interaction.command();

            deallocateVectorElements(undoHistory);
            undoHistory.clear();

            try
            {
                command->execute(model);
                commandHistory.push_back(command);
                model.clearErrorMessage();
            }
            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
                delete command;
            }

            view.refresh();
        }
    }

    deallocateVectorElements(commandHistory);
    deallocateVectorElements(undoHistory);
}

