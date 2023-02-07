#ifndef DELETELINECOMMAND_HPP
#define DELETELINECOMMAND_HPP

#include "Command.hpp"

class DeleteLineCommand : public Command
{
    public:
        void execute(EditorModel& model);
        void undo(EditorModel& model);
    private:
        std::string deletedText;
        unsigned int prevLine;
        unsigned int prevColumn;
};

#endif