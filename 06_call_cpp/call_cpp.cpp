#include<emscripten/bind.h>
#include<algorithm>
using namespace emscripten;

class Anaylsis {
    public:
        int m_val;

        Anaylsis(int init): m_val(init) {
        }

        void setPlus(int value) {
            m_val += value;
        }

        int squareValue() {
            return m_val * m_val;
        }
};

EMSCRIPTEN_BINDINGS(my_module) {
    class_<Anaylsis>("Anaylsis")
        .constructor<int>()
        .function("setPlus", &Anaylsis::setPlus)
        .function("squareValue", &Anaylsis::squareValue)
        .property("m_val", &Anaylsis::m_val);
}