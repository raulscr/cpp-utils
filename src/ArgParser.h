#pragma once

#include "ArgType.h"

#include <string>
#include <unordered_map>
#include <sstream>
#include <iostream>

class ArgParser
{
public:
    ArgParser();

    template<typename T>
    void addArg(char shortName,
                const std::string& longName,
                const std::string& helpText,
                bool required = false);

    void parse(int argc, char* argv[]);

    template<typename T>
    T get(const std::string& longName) const;

private:
    struct Argument
    {
        char shortName;
        std::string longName;
        std::string helpText;
        bool required;
        bool parsed;
        std::string value;
        ArgType type;
    };

    std::unordered_map<std::string, Argument> m_args;
    std::unordered_map<char, std::string> m_shortToLong;

    void addHelpArgument();
    void printHelp(const std::string& programName) const;

    bool isLongOption(const std::string& token) const;
    bool isShortOption(const std::string& token) const;

    std::string extractLongName(const std::string& token) const;
    char extractShortName(const std::string& token) const;

    void validateRequired() const;

    template<typename T>
    T convert(const std::string& value, const std::string& name) const;

    void ensureExists(const std::string& name) const;
    void ensureType(const Argument& arg, const std::string& name) const;
};
