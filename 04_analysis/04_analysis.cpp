#include <emscripten/bind.h>
using namespace emscripten;

float my_analysis(float a, float b, float c) {
    return a + b * c;
}

EMSCRIPTEN_BINDINGS(my_module) {
    emscripten::function("analysis", &my_analysis);
}