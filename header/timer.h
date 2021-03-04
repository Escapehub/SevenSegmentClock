#include <iostream>
#include <thread>
#include <chrono>

#ifndef __TIMER__
#define __TIMER__

class Timer {
private:
    bool m_clear = false;

public:
    template<typename Function> 
    void setTimeout(Function function, int delay)
    {
        this->m_clear = false;
        std::thread t([=]() {
            if(this->m_clear) return;
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            if(this->m_clear) return;
            function();
        });
        t.detach();
    }

    template<typename Function>
    void setInterval(Function function, int interval)
    {
        this->m_clear = false;
        std::thread t([=]() {
            while(true) {
                if(this->m_clear) return;
                std::this_thread::sleep_for(std::chrono::milliseconds(interval));
                if(this->m_clear) return;
                function();
            }
        });
        t.detach();
    }

    void stop() 
    {
        this->m_clear = true;
    }
};

#endif //!__TIMER__