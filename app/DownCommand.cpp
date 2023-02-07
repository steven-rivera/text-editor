#include "DownCommand.hpp"
#include "EditorException.hpp"


void DownCommand::execute(EditorModel& model)
{
    if (model.cursorLine() == model.lineCount())
    {
        throw EditorException{"Already at bottom"};
    }
    else
    {
        prevColumn = model.cursorColumn();

        unsigned int curLineSize = model.line(model.cursorLine()).size();
        unsigned int nextLineSize = model.line(model.cursorLine() + 1).size();

        if (curLineSize > nextLineSize)
        {
            model.setColumn(nextLineSize + 1);
        }
        model.moveLineDown();
    }
    
}

void DownCommand::undo(EditorModel& model)
{    
    model.moveLineUp();
    model.setColumn(prevColumn);
} 