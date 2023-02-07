#ifndef ENDCOMMAND_HPP
#define ENDCOMMAND_HPP

#include "Command.hpp"

class EndCommand : public Command
{
    public:
        void execute(EditorModel& model) override;
        void undo(EditorModel& model) override; 
    private:
        unsigned int oldPosition;
};

#endif