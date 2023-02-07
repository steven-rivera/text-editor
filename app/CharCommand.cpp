#include "CharCommand.hpp"

CharCommand::CharCommand(char c)
    :character{c}
{
}

void CharCommand::execute(EditorModel& model)
{
    model.insertChar(character);
    model.moveColumnRight();
}

void CharCommand::undo(EditorModel& model)
{
    model.moveColumnLeft();
    model.removeChar();
}