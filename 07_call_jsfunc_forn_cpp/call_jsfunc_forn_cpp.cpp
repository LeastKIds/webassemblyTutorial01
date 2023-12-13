#include <iostream>
#include <string>
#include <emscripten.h>
#include <emscripten/bind.h>

using namespace emscripten;

EM_JS(void, writeEmail_js, ( const char *subject, int len_subject,
                            const char *msg, int len_msg), {

                                jsFunction( UTF8ToString(subject, len_subject), 
                                            UTF8ToString(msg, len_msg));
                            });

class EmailSystem {

    public:
        EmailSystem() {}
        void writeEmail() {
            m_subject = "JEUS LOVES YOU.";
            m_msg = "예수님은 당신을 사랑한빈다";

            writeEmail_js(m_subject.c_str(), m_subject.length(), m_msg.c_str(), m_msg.length());
        }   

        std::string m_subject;
        std::string m_msg;
};

EMSCRIPTEN_BINDINGS(my_module) {
    class_<EmailSystem>("EmailSystem")
        .constructor<>()
        .function("writeEmail_js", &EmailSystem::writeEmail)
        .property("m_subject", &EmailSystem::m_subject)
        .property("m_msg", &EmailSystem::m_msg);
}