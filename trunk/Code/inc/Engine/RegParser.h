#ifndef _REG_PARSER_H_
#define _REG_PARSER_H_

#include "GameFile.h"

#include <memory>
#include <map>
#include <vector>

class Registry
{
public:
    friend class RegistryParser;
    
    class Section
    {
    public:
        Section(const std::string& name) : m_name(name) {}
        const std::string& getName() const { return m_name; }
        
        // Adds a key-value pair to the Section. The key value must not exist yet
        void add(const std::string& key, const std::string& value);
        // Changes a value that is under the key. The key must be already exisiting
        void change(const std::string& key, const std::string& value);
        // Returns true if the key exists in the section and false if not
        bool exists(const std::string& key);
        // Removes the key-value pair from under the given key
        // The key must exist
        void remove(const std::string& key);
        // Returns value associated with that key
        std::string get(const std::string& key);
        // Returns the number of key-value elements in the section
        int count() const { return static_cast<int>(m_values.size()); }
        
        typedef std::map<std::string, std::string> ValuesContainer;
        typedef ValuesContainer::iterator ValuesIter;
        ValuesIter begin() { return m_values.begin(); }
        ValuesIter end() { return m_values.end(); }
        
    private:
        ValuesContainer m_values;
        
        std::string m_name;
    };
    
    // Creates a new registry wit the given name
    Registry(const std::string& name) : m_name(name) {}
    ~Registry();
    // Returns the name of this Registry
    const std::string& getName() const { return m_name; }
    
    // Returns the names of all sections that appear in this file
    std::vector<std::string> getSectionNames() const;
    // Returns the Section object of from the section of a given name
    Section* getSection(const std::string& sectionName);
    // Tells if the section of a given name exists
    bool hasSection(const std::string& sectionName);
    // Adds a new section of a given name.
    // The section must not yet exist
    void addSection(const std::string& newSectionName);
    
    // Prints what sections it has inside
    void debugPrint();
    
private:
    // TODO: change this to shared_ptrs
    typedef std::vector<Section*> SectionsContainer;
    typedef SectionsContainer::iterator SectionsIter;
    SectionsContainer m_sections;
    
    std::string m_name;
};

// Class which purpose is to parse a given file and create a RegistryInstance from it
class RegistryParser
{
public:
    RegistryParser(std::auto_ptr<GameFile> regFile);
    std::auto_ptr<Registry> parse();
    
private:
    bool isBlank(const std::string& line) const;
    bool isComment(const std::string& line) const;
    // Parses line and updates the m_result;
    void parseLine(const std::string& line);
    // Creates a new section in the result and checks a couple other things
    void generateSection(const std::string& sectionName);

private:
    std::auto_ptr<GameFile> m_file;
    std::auto_ptr<Registry> m_result;

    std::string m_currentSection;
};

// Class which writes the registry to a file 
class RegistryWriter
{
public:
    RegistryWriter(Registry* reg, std::auto_ptr<GameFile> file);
    void write();
    
private:
    void writeSection(Registry::Section* section);
    
private:
    Registry* m_reg;
    std::auto_ptr<GameFile> m_file;
};



#endif // _REG_PARSER_H_