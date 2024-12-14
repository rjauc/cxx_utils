#include <vector>
#include <fstream>
#include <filesystem>

#include <logging.hpp>

#include "test_utils.hpp"

std::vector<std::string> ReadFileLines(std::filesystem::path path) {
    auto file = std::ifstream(path);
    std::vector<std::string> lines;
    std::string line = "";
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    return lines;
}

int main() {
    // Initialise logger
    LOG_DECLARE();
    LOG_SET_FILE_NAME("TestFileName");
    LOG_SET_NAME("TestLogging");
    // Log plain strings
    LOG_DEBUG("Debug example entry");
    LOG_INFO("Info example entry");
    LOG_WARNING("Warning example entry");
    LOG_ERROR("Error example entry");
    // Log formatted data
    LOG_INFO("Example formatting integer: {}", 10);
    LOG_INFO("Example formatting double: {}", 123.456);
    LOG_INFO("Example formatting pointer: {}", (void*)0xDEADBEEF);

    // Check folder and file exist
    ASSERT(std::filesystem::exists("./logs"), "Logs folder does not exist.");
    ASSERT(std::filesystem::exists("./logs/TestFileName.log"), "Log file does not exist.");
    // Check logged plain strings
    auto lines = ReadFileLines("./logs/TestFileName.log");
    ASSERT(lines[0].contains("[D]"), "D Severity not properly logged.");
    ASSERT(lines[0].ends_with("Debug example entry"), "Debug didn't log properly");
    ASSERT(lines[1].contains("[I]"), "I Severity not properly logged.");
    ASSERT(lines[1].ends_with("Info example entry"), "Info didn't log properly");
    ASSERT(lines[2].contains("[W]"), "W Severity not properly logged.");
    ASSERT(lines[2].ends_with("Warning example entry"), "Warning didn't log properly");
    ASSERT(lines[3].contains("[E]"), "E Severity not properly logged.");
    ASSERT(lines[3].ends_with("Error example entry"), "Error didn't log properly");
    // Checked logged formatted data
    ASSERT(lines[4].ends_with("integer: 10"), "Integer not properly logged.");
    ASSERT(lines[5].ends_with("double: 123.456"), "Double not properly logged.");
    ASSERT(lines[6].ends_with("pointer: 0xdeadbeef"), "Pointer not properly logged.");
}
