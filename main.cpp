#include <cstdlib>
#include <unordered_map>
#include <string>
#include <sstream> // For std::stringstream


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

// Consider using a namespace to encapsulate utility functions
namespace SystemCommands {
    void runShortcut(const std::string &str) {
        // Consider safer alternatives or validate 'str'
        std::system(("shortcuts run " + str).c_str());
    }

    void runAppleScript(const std::string &str) {
        // Validate or sanitize 'str' to avoid injection
        std::system(("osascript -e '" + str + "'").c_str());
    }

    void simulateCmdPlus(const KeyType keyType, const std::string &key) {
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
    const auto &commandKeyMap = getCommandKeyMap(); // Encapsulate the map within a function
    const auto &keyType = std::get<0>(commandKeyMap.at(command)); // Use .at() for safer access
    const std::string &key = std::get<1>(commandKeyMap.at(command)); // Use .at() for safer access

    SystemCommands::simulateCmdPlus(keyType, key);
}

int main() {
    SystemCommands::runShortcut("query_chatGPT"); // run shortcuts.app shortcut "query_chatGPT" that opens chatGPT in chrome and listens to dictation and copies the text to clipboard
    runSysCommands(Command::paste); // simulate cmd+v
    runSysCommands(Command::enter); // simulate enter key


    return 0;
}
