#ifndef CHARCOMMAND_HPP
#define CHARCOMMAND_HPP

#include "Command.hpp"

class CharCommand : public Command
{
    public:
        CharCommand(char c);
        void execute(EditorModel& model) override;
        void undo(EditorModel& model) override; 
    private:
        char character;
};

#endif