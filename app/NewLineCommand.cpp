#include "NewLineCommand.hpp"
#include "BooEditLog.hpp"

void NewLineCommand::execute(EditorModel& model)
{
    prevColPosition = model.cursorColumn();

    if (model.cursorAtEndOfLine())
    {
        model.newLine("");
    }
    else
    {
        textMoved = model.removeTextAfterCursor();
        model.newLine(textMoved);
    }
    model.moveLineDown();
    model.resetColumn();
    
}

void NewLineCommand::undo(EditorModel& model)
{
    model.deleteLine();
    
    model.setColumn(prevColPosition);
    model.moveLineUp();

    model.insertString(textMoved);
}
