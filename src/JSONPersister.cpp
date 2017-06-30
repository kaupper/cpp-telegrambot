#include "JSONPersister.h"

using namespace telegram::util;


JSONPersister::JSONPersister()
{
}

JSONPersister::JSONPersister(const std::string fileName)
{
    SetFileName(fileName);
    Load();
}

void JSONPersister::SetFileName(const std::string &fileName)
{
    this->fileName = fileName;
}

std::string JSONPersister::GetFileName() const
{
    return fileName;
}

void JSONPersister::Load()
{
    std::ifstream file(fileName);

    if (not file.is_open()) {
        throw std::runtime_error("Failed to open file '" + fileName + "'");
    }

    parse(file);
    file.close();
}

void JSONPersister::Save()
{
    std::string dump = json::dump();
    std::ofstream file(fileName);

    if (not file.is_open()) {
        throw std::runtime_error("Failed to open file '" + fileName + "'");
    }

    file << dump;
    file.close();
}