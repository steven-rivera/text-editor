#ifndef HOMECOMMAND_HPP
#define HOMECOMMAND_HPP

#include "Command.hpp"

class HomeCommand : public Command
{
    public:
        void execute(EditorModel& model) override;
        void undo(EditorModel& model) override; 
    private:
        unsigned int oldPosition;
};

#endif