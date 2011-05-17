#include "RegParser.h"

// TODO: remove this and add pi.h
#include <cassert>

#include "StringHelper.h"

void Registry::Section::add(const std::string& key, const std::string& value)
{
    assert(m_values.find(key) == m_values.end());
    m_values[key] = value;
}

void Registry::Section::change(const std::string& key, const std::string& value)
{
    ValuesIter kv = m_values.find(key);
    assert(kv != m_values.end());
    kv->second = value;
}

bool Registry::Section::exists(const std::string& key)
{
    return m_values.find(key) != m_values.end();
}

std::string Registry::Section::get(const std::string& key)
{
    assert(exists(key));
    return m_values[key];
}

void Registry::Section::remove(const std::string& key)
{
    ValuesIter kv = m_values.find(key);
    assert(kv != m_values.end());
    m_values.erase(kv);
}

Registry::~Registry()
{
    for(SectionsIter s = m_sections.begin(); s != m_sections.end(); ++s)
    {
        delete *s;
    }
}

std::vector<std::string> Registry::getSectionNames() const
{
    std::vector<std::string> result;
    for(SectionsContainer::const_iterator s = m_sections.begin(); s != m_sections.end(); ++s)
    {
        result.push_back((*s)->getName());
    }
    return result;
}

Registry::Section* Registry::getSection(const std::string& section)
{
    for(SectionsIter s = m_sections.begin(); s != m_sections.end(); ++s)
    {
        if((*s)->getName() == section)
        {
            return *s;
        }
    }
    assert(!"Section does not exist");
    return 0;
}

bool Registry::hasSection(const std::string& sectionName)
{
    for(SectionsIter s = m_sections.begin(); s != m_sections.end(); ++s)
    {
        if((*s)->getName() == sectionName)
        {
            return true;
        }
    }
    return false;
}

void Registry::addSection(const std::string& name)
{
    assert(!hasSection(name));
    m_sections.push_back(new Section(name));
}

void Registry::debugPrint()
{
    printf("Registry::debugPrint\n");
    for(SectionsIter s = m_sections.begin(); s != m_sections.end(); ++s)
    {
        printf("   Section: '%s'\n", (*s)->getName().c_str());
    }
}

RegistryParser::RegistryParser(std::auto_ptr<GameFile> regFile) :
    m_file(regFile)
{
    
}

std::auto_ptr<Registry> RegistryParser::parse()
{
    m_result.reset(new Registry(m_file->getName()));
    
    while(!m_file->eof())
    {
        std::string line = m_file->getLine();
        if(isBlank(line))
            continue;
        if(isComment(line))
            continue;
        parseLine(line);
    }
    
    return m_result;
}

bool RegistryParser::isBlank(const std::string& line) const
{
    return StringHelper::strip(line).size() == 0;
}

bool RegistryParser::isComment(const std::string& line) const
{
    return StringHelper::strip(line)[0] == '#';
}

void RegistryParser::parseLine(const std::string& line)
{
    std::string stripped = StringHelper::strip(line);
    if(stripped[0] == '[' && stripped[stripped.size()-1] == ']')
    {
        generateSection(StringHelper::strip(stripped, "[]"));
        return;
    }
    
    std::vector<std::string> tokens;
    StringHelper::tokenize(line, tokens, "=");
    
    // There must be exactly one '=', so there must be 2 tokens
    assert(tokens.size() == 2);
    m_result->getSection(m_currentSection)->add(tokens[0], tokens[1]);
}

void RegistryParser::generateSection(const std::string& name)
{
    assert(!m_result->hasSection(name));
    m_result->addSection(name);
    m_currentSection = name;
}

RegistryWriter::RegistryWriter(Registry* reg, std::auto_ptr<GameFile> file) :
    m_reg(reg),
    m_file(file)
{
}

void RegistryWriter::write()
{
    std::vector<std::string> sections = m_reg->getSectionNames();
    for(std::vector<std::string>::iterator s = sections.begin(); s != sections.end(); ++s)
    {
        writeSection(m_reg->getSection(*s));
    }
}

void RegistryWriter::writeSection(Registry::Section* section)
{
    m_file->writeLine("[" + section->getName() + "]");
    for(Registry::Section::ValuesIter kv = section->begin(); kv != section->end(); ++kv)
    {
        m_file->writeLine(kv->first + "=" + kv->second);
    }
    m_file->writeLine();
}
