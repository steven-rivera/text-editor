#ifndef BACKSPACECOMMAND_HPP
#define BACKSPACECOMMAND_HPP

#include "Command.hpp"

class BackspaceCommand : public Command
{
    public:
        void execute(EditorModel& model);
        void undo(EditorModel& model);
    private:
        char removedChar;
        bool lineDeleted = false;
};

#endif