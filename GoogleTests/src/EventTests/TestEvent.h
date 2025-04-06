#pragma once

#include "main/Events/Event.h"

namespace Gomas {

    class TestEvent : public Event
    {
    public:
        TestEvent(int value) : m_Value(value) {}

        int GetValue() const { return m_Value; }

        enum class TestEventType { Test };
        static TestEventType GetStaticTestType() { return TestEventType::Test; }
        virtual EventType GetEventType() const override { return EventType::None; } //Use None as a default, we will test the static test type instead.
        virtual const char* GetName() const override { return "Test"; }
        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication)

            std::string ToString() const override
        {
            return "TestEvent: " + std::to_string(m_Value);
        }

    private:
        int m_Value;
    };

}

