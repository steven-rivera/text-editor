#include "BackspaceCommand.hpp"
#include "EditorException.hpp"

void BackspaceCommand::execute(EditorModel& model)
{
    if (model.cursorLine() == 1 && model.cursorColumn() == 1)
    {
        throw EditorException{"Already at beginning"};
    }
    else if (model.cursorColumn() == 1)
    {
        std::string currentLine = model.line(model.cursorLine());
        model.deleteLine();
        model.moveLineUp();
        model.setColumn(model.maxColumnValue());
        model.insertString(currentLine);
        lineDeleted = true;
    }
    else
    {
        model.moveColumnLeft();
        removedChar = model.removeChar();
    }
}

void BackspaceCommand::undo(EditorModel& model)
{
    if (lineDeleted)
    {
        model.newLine(model.removeTextAfterCursor());
        model.moveLineDown();
        model.resetColumn();
    }
    else
    {
        model.insertChar(removedChar);
        model.moveColumnRight();
    }
}