#ifndef NEWLINECOMMAND_HPP
#define NEWLINECOMMAND_HPP

#include "Command.hpp"

class NewLineCommand : public Command
{
    public:
        void execute(EditorModel& model) override;
        void undo(EditorModel& model) override;
    private:
        std::string textMoved = "";
        unsigned int prevColPosition;
};

#endif