#ifndef LEFTCOMMAND_HPP
#define LEFTCOMMAND_HPP

#include "Command.hpp"

class LeftCommand : public Command
{
    public:
        void execute(EditorModel& model) override;
        void undo(EditorModel& model) override;
    private:
        unsigned int prevLine;
        unsigned int prevColumn;
};

#endif