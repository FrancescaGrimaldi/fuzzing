add_executable(utility_test utility_test.c)
target_link_libraries(utility_test utility)
target_compile_options(utility_test PRIVATE -fsanitize=address)
target_link_options(utility_test PRIVATE -fsanitize=address)
add_test(NAME utility_test COMMAND utility_test)

add_executable(utility_fuzzer_test utility_fuzzer_test.c)
target_link_libraries(utility_fuzzer_test utility)
target_compile_options(utility_fuzzer_test PRIVATE -fsanitize=address,fuzzer)
target_link_options(utility_fuzzer_test PRIVATE -fsanitize=address,fuzzer)