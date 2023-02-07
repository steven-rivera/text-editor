#ifndef UPCOMMAND_HPP
#define UPCOMMAND_HPP

#include "Command.hpp"

class UpCommand : public Command
{
    public:
        void execute(EditorModel& model) override;
        void undo(EditorModel& model) override;
    private:
        unsigned int prevColumn;
};

#endif