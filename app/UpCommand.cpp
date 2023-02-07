#include "UpCommand.hpp"
#include "EditorException.hpp"


void UpCommand::execute(EditorModel& model)
{
    if (model.cursorLine() == 1)
    {
        throw EditorException{"Already at top"};
    }
    else
    {
        prevColumn = model.cursorColumn();

        unsigned int prevLineSize = model.line(model.cursorLine() - 1).size();
        unsigned int curLineSize = model.line(model.cursorLine()).size();

        if (prevLineSize < curLineSize)
        {
            model.setColumn(prevLineSize + 1);
        }
        model.moveLineUp();
    }
    
}

void UpCommand::undo(EditorModel& model)
{
    model.moveLineDown();
    model.setColumn(prevColumn);
} 