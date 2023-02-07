// EditorModel.cpp
//
// ICS 45C Fall 2020
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"



EditorModel::EditorModel()
    :cline{1}, ccolumn{1}, file{new std::string{""}}, errorMessage{""}
{
}

EditorModel::EditorModel(const EditorModel& other)
    :cline{other.cline}, ccolumn{other.ccolumn}, errorMessage{other.errorMessage}
{
    for (const std::string* s : other.file)
    {
        file.push_back(new std::string{*s});
    }
}

EditorModel& EditorModel::operator=(const EditorModel& other)
{
    if (this != &other)
    {
        for (unsigned int i = 0; i < file.size(); ++i)
        {
            delete file[i];
        } 

        cline = other.cline;
        ccolumn = other.ccolumn;
        errorMessage = other.errorMessage;

        file.clear();

        for (const std::string* s : other.file)
        {
            file.push_back(new std::string{*s});
        }
    }

    return *this;
}


EditorModel::~EditorModel()
{
    for (unsigned int i = 0; i < file.size(); ++i)
    {
        delete file[i];
    }
}

int EditorModel::cursorLine() const
{
    return cline;
}

void EditorModel::moveLineUp()
{
    cline--;
}

void EditorModel::moveLineDown()
{
    cline++;
}

int EditorModel::cursorColumn() const
{
    return ccolumn;
}

void EditorModel::moveColumnLeft()
{
    ccolumn--;
}

void EditorModel::moveColumnRight()
{
    ccolumn++;
}

void EditorModel::resetColumn()
{
    ccolumn = 1;
}

void EditorModel::setColumn(unsigned int column)
{
    ccolumn = column;
}

void EditorModel::setLine(unsigned int line)
{
    cline = line;
}


int EditorModel::lineCount() const
{
    return file.size();
}


const std::string& EditorModel::line(int lineNumber) const
{
    return *file[lineNumber - 1];
}

void EditorModel::newLine(const std::string& text)
{
    auto it = file.begin();
    file.insert(it + cline, new std::string{text});
    
}

void EditorModel::insertLineAt(const std::string& text, unsigned int line)
{
    auto it = file.begin();
    file.insert(it + (line - 1), new std::string{text});
}

std::string EditorModel::deleteLine()
{
    std::string deletedText = *file[cline-1];
    delete file[cline-1];
    auto it = file.begin();
    file.erase(it + (cline - 1));
    return deletedText;
}

std::string EditorModel::clearLine()
{
    std::string clearedText = *file[cline-1];
    file[cline-1]->clear();
    return clearedText;
}

void EditorModel::insertChar(char c)
{
    file[cline - 1]->insert(ccolumn - 1, 1, c);
}

void EditorModel::insertString(std::string s)
{
    *file[cline - 1] += s;
}

char EditorModel::removeChar()
{
    char c = (*file[cline - 1])[ccolumn - 1];
    file[cline - 1]->erase(ccolumn - 1, 1);
    return c;
}

bool EditorModel::cursorAtEndOfLine() const
{
    if (ccolumn == line(cline).size() + 1)
    {
        return true;
    }
    
    return false;
}

unsigned int EditorModel::maxColumnValue() const
{
    return line(cline).size() + 1;
}

const std::string EditorModel::removeTextAfterCursor()
{
    std::string removed = file[cline - 1]->substr(ccolumn - 1);
    auto it = file[cline - 1]->begin();
    file[cline - 1]->erase(it + (ccolumn - 1), file[cline - 1]->end());

    return removed;
}

const std::string& EditorModel::currentErrorMessage() const
{
    return errorMessage;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
    this->errorMessage = errorMessage;
}


void EditorModel::clearErrorMessage()
{
    errorMessage = "";
}

