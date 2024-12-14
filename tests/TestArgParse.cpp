#include <iostream>
#include <stdexcept>

#include <argparse.hpp>

#include "test_utils.hpp"

int main(int argc, char** argv) {
    ARG::ArgParser args;
    // Booleans
    args.Add("MandatoryBool", { .opt="-s", .isMandatory=true, .isBoolean=true });
    args.Add("OptionalBool",  { .opt="-o", .longOpt="--optional-bool", .isBoolean=true });
    // Strings
    args.Add("StrA", { .opt="-A", .longOpt="--string-a" });
    args.Add("StrB", { .opt="-B", .longOpt="--string-b" });
    // Numbers
    args.Add("Integer", { .opt="-i" });
    args.Add("Double", { .opt="-d" });

    // Test parsing
    ASSERT(args.Parse(argc, argv), "Parsing failed.");
    // Test implicit args
    ASSERT(args.IsSet("Executable"), "Executable arg is not set.");
    ASSERT(args.GetStr("Executable").ends_with("test_argparse.exe"), "Executable arg does not end with program name.");
    // Test booleans
    ASSERT(args.IsSet("MandatoryBool"), "Mandatory bool should be set.");
    ASSERT(args.GetBool("MandatoryBool"), "Mandatory bool is set, but value does not match.");
    if (args.IsSet("OptionalBool"))
        ASSERT(args.GetBool("OptionalBool"), "Optional bool is set, but value does not match.");
    // Test strings
    if (args.IsSet("StrA"))
        ASSERT(args.GetStr("StrA") == "str_a", std::format("{} != str_a", args.GetStr("StrA")));
    if (args.IsSet("StrB"))
        ASSERT(args.GetStr("StrB") == "String B", std::format("{} != String B", args.GetStr("StrB")));
    // Test numbers
    if (args.IsSet("Integer")) 
        ASSERT(args.GetInt("Integer") == 10, std::format("{} != 10", args.GetInt("Integer")));
    if (args.IsSet("Double")) 
        ASSERT(args.GetDouble("Double") == 123.456, std::format("{} != 123.456", args.GetDouble("Double")));
}
