#include "gtest/gtest.h"
#include "Person.h"
#include "NameObserver.h"
#include "AddressObserver.h"

TEST(PersonTest, ForenameChange) {
    Person person("John", "Doe");
    NameObserver observer;
    person.attach(&observer);

    person.forename("Jane");
    EXPECT_EQ(person.forename(), "Jane");
}

TEST(PersonTest, SurnameChange) {
    Person person("John", "Doe");
    NameObserver observer;
    person.attach(&observer);

    person.surname("Smith");
    EXPECT_EQ(person.surname(), "Smith");
}

TEST(PersonTest, AddressChange) {
    Person person("John", "Doe");
    AddressObserver observer;
    person.attach(&observer);

    person.address("123 Main St");
    EXPECT_EQ(person.address(), "123 Main St");
}

