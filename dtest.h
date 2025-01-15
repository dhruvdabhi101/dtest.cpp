#include <iostream>
#include <vector>
#include <functional>

// Define macros for test registration and execution
#define TEST_AND_PRINT(expr, expected) \
    do { \
        auto result = (expr); \
        ++testCount; \
        if ((expected) == result) { \
            passCount++; \
            std::cout << "\x1B[32m[PASSED] " << #expr << " = " << result << "\033[0m" << std::endl; \
        } else { \
            std::cout << "\x1B[31m[FAILED] " << #expr << " = " << result << " (Expected: " << expected << ") \033[0m" << std::endl; \
        } \
    } while (0)

#define TEST(name) \
    void name(); \
    struct name##_registrar { \
        name##_registrar() { \
            TestRegistry::getInstance().addTest(#name, name); \
        } \
    }; \
    static name##_registrar name##_instance; \
    void name() { \
        int testCount = 0, passCount = 0; \
        std::cout << "Running Test: " << #name << std::endl;

#define END_TEST \
        std::cout << "Summary: " << passCount << " / " << testCount << " test cases passed." << std::endl << std::endl; \
    }

// Test registry singleton
class TestRegistry {
public:
    using TestFunction = std::function<void()>;

    static TestRegistry& getInstance() {
        static TestRegistry instance;
        return instance;
    }

    void addTest(const std::string& name, TestFunction func) {
        tests.push_back({name, func});
    }

    void runAllTests() {
        for (const auto& test : tests) {
            test.second();
        }
    }

private:
    std::vector<std::pair<std::string, TestFunction>> tests;
};

// Automatically define the main function
#define RUN_ALL_TESTS \
    int main() { \
        TestRegistry::getInstance().runAllTests(); \
        return 0; \
    }

