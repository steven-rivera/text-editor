#include "HomeCommand.hpp"

void HomeCommand::execute(EditorModel& model)
{
    oldPosition = model.cursorColumn();
    model.resetColumn();
}
void HomeCommand::undo(EditorModel& model)
{
    model.setColumn(oldPosition);
}