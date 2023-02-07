#ifndef RIGHTCOMMAND_HPP
#define RIGHTCOMMAND_HPP

#include "Command.hpp"

class RightCommand : public Command
{
    public:
        void execute(EditorModel& model) override;
        void undo(EditorModel& model) override; 
    private:
        unsigned int prevLine;
        unsigned int prevColumn;
};

#endif