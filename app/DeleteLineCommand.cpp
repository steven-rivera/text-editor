#include "DeleteLineCommand.hpp"
#include "EditorException.hpp"

void DeleteLineCommand::execute(EditorModel& model)
{
    prevColumn = model.cursorColumn();
    prevLine = model.cursorLine();

    if (model.lineCount() == 1)
    {
        if (model.cursorColumn() == 1)
        {
            throw EditorException("Already Empty");
        }
        else
        {
            deletedText = model.clearLine();
            model.resetColumn();
        }
    }
    else if (model.cursorLine() == model.lineCount())
    {
        deletedText = model.deleteLine();
        model.moveLineUp();

        if (model.maxColumnValue() < model.cursorColumn())
        {
            model.setColumn(model.maxColumnValue());
        }
    }
    else
    {
        deletedText = model.deleteLine();

        if (model.maxColumnValue() < model.cursorColumn())
        {
            model.setColumn(model.maxColumnValue());
        }
    }      
}

void DeleteLineCommand::undo(EditorModel& model)
{
    model.insertLineAt(deletedText, prevLine);
    model.setColumn(prevColumn);
    model.setLine(prevLine);
}