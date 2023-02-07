#include "RightCommand.hpp"
#include "EditorException.hpp"

void RightCommand::execute(EditorModel& model)
{
    if (model.cursorColumn() < model.maxColumnValue())
    {
        model.moveColumnRight();
    }
        
    else if (model.cursorLine() == model.lineCount())
    {
        throw EditorException{"Already at end"};
    }
    else
    {
        model.moveLineDown();
        model.resetColumn();
    }  

}

void RightCommand::undo(EditorModel& model)
{
    model.setLine(prevLine);
    model.setColumn(prevColumn);
}