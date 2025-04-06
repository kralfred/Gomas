#include "TestEvent.h"
#include "gtest/gtest.h"


namespace Gomas {

    TEST(EventTest, TestEventCreation) {
        TestEvent testEvent(42);

        EXPECT_EQ(testEvent.GetValue(), 42);
        EXPECT_EQ(TestEvent::GetStaticTestType(), TestEvent::TestEventType::Test);
        EXPECT_STREQ(testEvent.GetName(), "Test");
        EXPECT_TRUE(testEvent.IsInCategory(EventCategory::EventCategoryApplication));
        EXPECT_FALSE(testEvent.IsInCategory(EventCategory::EventCategoryInput));
        EXPECT_EQ(testEvent.ToString(), "TestEvent: 42");
    }

    TEST(EventTest, EventDispatcherTest) {
        TestEvent testEvent(100);
        EventDispatcher dispatcher(testEvent);

        bool handled = false;
        auto handler = [&](TestEvent& event) {
            handled = true;
            event.Handled = true;
            return true;
            };

        bool dispatched = dispatcher.Dispatch<TestEvent>(handler);

        EXPECT_TRUE(dispatched);
        EXPECT_TRUE(handled);
        EXPECT_TRUE(testEvent.Handled);
    }

}