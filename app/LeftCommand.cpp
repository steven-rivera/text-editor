#include "LeftCommand.hpp"
#include "EditorException.hpp"

void LeftCommand::execute(EditorModel& model)
{
    prevLine = model.cursorLine();
    prevColumn = model.cursorColumn();
    
    if (model.cursorColumn() > 1)
    {
        model.moveColumnLeft();    
    }
    else if (model.cursorLine() != 1)
    {
        model.moveLineUp();
        model.setColumn(model.line(model.cursorLine()).size() + 1);
    }
    else
    {
        throw EditorException{"Already at beginning"};
    }
    
}

void LeftCommand::undo(EditorModel& model)
{
    model.setLine(prevLine);
    model.setColumn(prevColumn); 
}