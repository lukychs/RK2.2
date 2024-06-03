#include "Person.h"
#include "NameObserver.h"
#include "AddressObserver.h"

// Custom observer to track notifications
class TestObserver : public Observer<Person, Person::StateChange> {
public:
    void update(const Person& person, Person::StateChange property) override {
        notifications.push_back(property);
    }

    std::vector<Person::StateChange> notifications;
};

TEST(PersonTest, NotifyNameObserverOnForenameChange) {
    Person homer("Homer", "Simpson");
    TestObserver nameObserver;

    homer.attach(&nameObserver);

    homer.forename("Homer Jay");

    ASSERT_EQ(nameObserver.notifications.size(), 1);
    EXPECT_EQ(nameObserver.notifications[0], Person::forenameChanged);
}

TEST(PersonTest, NotifyAddressObserverOnAddressChange) {
    Person marge("Marge", "Simpson");
    TestObserver addressObserver;

    marge.attach(&addressObserver);

    marge.address("712 Red Bark Lane, Henderson, Clark County, Nevada 89011");

    ASSERT_EQ(addressObserver.notifications.size(), 1);
    EXPECT_EQ(addressObserver.notifications[0], Person::addressChanged);
}

TEST(PersonTest, NotifyMultipleObserversOnAddressChange) {
    Person monty("Montgomery", "Burns");
    TestObserver addressObserver1;
    TestObserver addressObserver2;

    monty.attach(&addressObserver1);
    monty.attach(&addressObserver2);

    monty.address("Springfield Nuclear Power Plant");

    ASSERT_EQ(addressObserver1.notifications.size(), 1);
    EXPECT_EQ(addressObserver1.notifications[0], Person::addressChanged);

    ASSERT_EQ(addressObserver2.notifications.size(), 10);
    EXPECT_EQ(addressObserver2.notifications[0], Person::addressChanged);
}

TEST(PersonTest, DetachObserver) {
    Person homer("Homer", "Simpson");
    TestObserver nameObserver;

    homer.attach(&nameObserver);
    homer.detach(&nameObserver);

    homer.forename("Homer Jay");

    EXPECT_TRUE(nameObserver.notifications.empty());
}

TEST(PersonTest, AttachAndDetachObservers) {
    Person person("John", "Doe");
    TestObserver nameObserver;
    TestObserver addressObserver;

    ASSERT_TRUE(person.attach(&nameObserver));
    ASSERT_TRUE(person.attach(&addressObserver));

    ASSERT_TRUE(person.detach(&nameObserver));
    ASSERT_TRUE(person.detach(&addressObserver));
}



