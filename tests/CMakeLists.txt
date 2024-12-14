add_executable(test_argparse "TestArgParse.cpp")

add_test(NAME TestArgParse_Strings1 COMMAND test_argparse -s -Astr_a -B"String B")
add_test(NAME TestArgParse_Strings2 COMMAND test_argparse -s -A str_a -B "String B")

add_test(NAME TestArgParse_Strings1_Shuffled COMMAND test_argparse -B"String B" -Astr_a -s)
add_test(NAME TestArgParse_Strings2_Shuffled COMMAND test_argparse -A str_a -s -B "String B")

add_test(NAME TestArgParse_Numbers1 COMMAND test_argparse -s -i10 -d123.456)
add_test(NAME TestArgParse_Numbers2 COMMAND test_argparse -s -i "10" -d "123.456")
add_test(NAME TestArgParse_Numbers3 COMMAND test_argparse -s -i"10" -d"123.456")
