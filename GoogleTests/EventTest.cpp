
#include <windows.h>
#include "main\Events\Event.h"
#include "Gomas.h"

namespace Gomas {

    class TestEvent : public Event {
    public:
        TestEvent(int value) : m_Value(value) {}

        int GetValue() const { return m_Value; }

        EVENT_CLASS_TYPE(None); // Use None for simplicity, change later if needed.
        EVENT_CLASS_CATEGORY(EventCategoryApplication);

        std::string ToString() const override {
            return "TestEvent: " + std::to_string(m_Value);
        }

    private:
        int m_Value;
    };

    class StringEvent : public Event {
    public:
        StringEvent(std::string message) : m_Message(message) {}

        std::string GetMessage() const { return m_Message; }

        EVENT_CLASS_TYPE(None);
        EVENT_CLASS_CATEGORY(EventCategoryInput);

        std::string ToString() const override {
            return "StringEvent: " + m_Message;
        }

    private:
        std::string m_Message;
    };

}