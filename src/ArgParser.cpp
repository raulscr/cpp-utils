#include "ArgParser.h"
#include <stdexcept>

ArgParser::ArgParser()
{
    addHelpArgument();
}

void ArgParser::addHelpArgument()
{
    addArg<bool>('h', "help", "Show this help message", false);
}

bool ArgParser::isLongOption(const std::string& token) const
{
    return token.rfind("--", 0) == 0;
}

bool ArgParser::isShortOption(const std::string& token) const
{
    return token.size() == 2 && token[0] == '-';
}

std::string ArgParser::extractLongName(const std::string& token) const
{
    return token.substr(2);
}

char ArgParser::extractShortName(const std::string& token) const
{
    return token[1];
}

void ArgParser::parse(int argc, char* argv[])
{
    std::string programName = argv[0];

    for (int i = 1; i < argc; ++i)
    {
        std::string token = argv[i];
        std::string name;

        if (isLongOption(token))
        {
            name = extractLongName(token);
        }
        else if (isShortOption(token))
        {
            char shortName = extractShortName(token);
            if (m_shortToLong.find(shortName) == m_shortToLong.end())
                throw std::runtime_error("Unknown option");

            name = m_shortToLong.at(shortName);
        }
        else
        {
            continue;
        }

        ensureExists(name);
        auto& arg = m_args[name];

        if (arg.type.isBool())
        {
            arg.value = "true";
            arg.parsed = true;
            continue;
        }

        if (i + 1 >= argc)
            throw std::runtime_error("Missing value for argument: " + name);

        arg.value = argv[++i];
        arg.parsed = true;
    }

    if (m_args["help"].parsed)
    {
        printHelp(programName);
        std::exit(0);
    }

    validateRequired();
}

void ArgParser::validateRequired() const
{
    for (const auto& [name, arg] : m_args)
    {
        if (arg.required && !arg.parsed)
            throw std::runtime_error("Missing required argument: " + name);
    }
}

void ArgParser::ensureExists(const std::string& name) const
{
    if (m_args.find(name) == m_args.end())
        throw std::runtime_error("Unknown argument: " + name);
}

void ArgParser::printHelp(const std::string& programName) const
{
    std::cout << "Usage: " << programName << " [options]\n\n";

    for (const auto& [name, arg] : m_args)
    {
        std::cout << "  -" << arg.shortName
                  << ", --" << arg.longName;

        if (!arg.type.isBool())
            std::cout << " <value>";

        std::cout << "\n      " << arg.helpText;

        if (arg.required)
            std::cout << " (required)";

        std::cout << "\n\n";
    }
}

template<typename T>
void ArgParser::addArg(char shortName,
                       const std::string& longName,
                       const std::string& helpText,
                       bool required)
{
    if (m_args.find(longName) != m_args.end())
        throw std::runtime_error("Argument already exists");

    Argument arg{
        shortName,
        longName,
        helpText,
        required,
        false,
        "",
        ArgType(typeid(T))
    };

    m_args[longName] = arg;
    m_shortToLong[shortName] = longName;
}

template<typename T>
T ArgParser::get(const std::string& longName) const
{
    ensureExists(longName);
    const auto& arg = m_args.at(longName);

    if (!arg.parsed)
        throw std::runtime_error("Argument not provided: " + longName);

    ensureType<T>(arg, longName);
    return convert<T>(arg.value, longName);
}

template<typename T>
void ArgParser::ensureType(const Argument& arg, const std::string& name) const
{
    if (arg.type.type() != typeid(T))
        throw std::runtime_error("Type mismatch for argument: " + name);
}

template<typename T>
T ArgParser::convert(const std::string& value, const std::string& name) const
{
    std::istringstream iss(value);
    T result;

    if (!(iss >> result))
        throw std::runtime_error("Invalid value for argument: " + name);

    return result;
}

template<>
bool ArgParser::convert<bool>(const std::string& value, const std::string&) const
{
    return value == "true";
}

template<>
std::string ArgParser::convert<std::string>(const std::string& value, const std::string&) const
{
    return value;
}

// Explicit template instantiation
template void ArgParser::addArg<int>(char, const std::string&, const std::string&, bool);
template void ArgParser::addArg<double>(char, const std::string&, const std::string&, bool);
template void ArgParser::addArg<float>(char, const std::string&, const std::string&, bool);
template void ArgParser::addArg<long>(char, const std::string&, const std::string&, bool);
template void ArgParser::addArg<bool>(char, const std::string&, const std::string&, bool);
template void ArgParser::addArg<std::string>(char, const std::string&, const std::string&, bool);

template int ArgParser::get<int>(const std::string&) const;
template double ArgParser::get<double>(const std::string&) const;
template float ArgParser::get<float>(const std::string&) const;
template long ArgParser::get<long>(const std::string&) const;
template bool ArgParser::get<bool>(const std::string&) const;
template std::string ArgParser::get<std::string>(const std::string&) const;
