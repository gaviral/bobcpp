#include "SystemCommands.h"

int main() {
    SystemCommands::runShortcut("query_chatGPT"); // Example usage
    runSysCommands(Command::paste); // Simulate cmd+v
    runSysCommands(Command::enter); // Simulate enter key

    return 0;
}
