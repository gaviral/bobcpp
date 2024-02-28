#include "SystemCommands.h"
#include <cstdlib>
#include <sstream> // For std::stringstream

namespace SystemCommands {
    void runShortcut(const std::string &str) {
        // Implementation remains the same
        std::system(("shortcuts run " + str).c_str());
    }

    void runAppleScript(const std::string &str) {
        // Implementation remains the same
        std::system(("osascript -e '" + str + "'").c_str());
    }

    void simulateCmdPlus(const KeyType keyType, const std::string &key) {
        // Implementation remains the same
        std::stringstream command;
        if (keyType == KeyType::KeyStroke) {
            command << R"(tell application "System Events" to keystroke ")" << key << R"(" using {command down})";
        } else {
            command << R"(tell application "System Events" to key code )" << key << R"( using {command down})";
        }
        runAppleScript(command.str());
    }
} // namespace SystemCommands

std::unordered_map<Command, std::tuple<KeyType, std::string>> getCommandKeyMap() {
    // Implementation remains the same
    return {
            {Command::enter, {KeyType::KeyCode, "36"}},
            {Command::copy, {KeyType::KeyStroke, "c"}},
            {Command::paste, {KeyType::KeyStroke, "v"}},
            {Command::cut, {KeyType::KeyStroke, "x"}},
            {Command::undo, {KeyType::KeyStroke, "z"}},
            {Command::redo, {KeyType::KeyStroke, "y"}},
        };
}

void runSysCommands(Command command) {
    // Implementation remains the same
    const auto &commandKeyMap = getCommandKeyMap();
    const auto &keyType = std::get<0>(commandKeyMap.at(command));
    const std::string &key = std::get<1>(commandKeyMap.at(command));
    SystemCommands::simulateCmdPlus(keyType, key);
}

