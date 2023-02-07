#include "EndCommand.hpp"

void EndCommand::execute(EditorModel& model)
{
    oldPosition = model.cursorColumn();
    model.setColumn(model.line(model.cursorLine()).size() + 1);
}
void EndCommand::undo(EditorModel& model)
{
    model.setColumn(oldPosition);
}