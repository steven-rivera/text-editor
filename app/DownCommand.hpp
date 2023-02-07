#ifndef DOWNCOMMAND_HPP
#define DOWNCOMMAND_HPP

#include "Command.hpp"

class DownCommand : public Command
{
    public:
        void execute(EditorModel& model) override;
        void undo(EditorModel& model) override; 
    private:
        unsigned int prevColumn;
        
};

#endif