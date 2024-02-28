// SystemCommands.h

#ifndef SYSTEM_COMMANDS_H
#define SYSTEM_COMMANDS_H

#include <string>
#include <unordered_map>
#include <tuple>

enum class Command {
    enter,
    copy,
    paste,
    cut,
    undo,
    redo
};

enum class KeyType {
    KeyStroke,
    KeyCode
};

namespace SystemCommands {
    void runShortcut(const std::string &str);
    void runAppleScript(const std::string &str);
    void simulateCmdPlus(const KeyType keyType, const std::string &key);
}

std::unordered_map<Command, std::tuple<KeyType, std::string>> getCommandKeyMap();
void runSysCommands(Command command);

#endif // SYSTEM_COMMANDS_H
