#include "gtest/gtest.h"
#include "Person.h"
#include "NameObserver.h"
#include "AddressObserver.h"

TEST(PersonTest, ForenameChange) {
    Person person("John", "Doe");
    NameObserver nameObserver;
    person.attach(&nameObserver);

    person.forename("Jane");
    EXPECT_EQ(person.forename(), "Jane");
}

TEST(PersonTest, AddressChange) {
    Person person("John", "Doe");
    AddressObserver addressObserver;
    person.attach(&addressObserver);

    person.address("123 Main St");
    EXPECT_EQ(person.address(), "123 Main St");
}

TEST(PersonTest, DetachObserver) {
    Person person("John", "Doe");
    NameObserver nameObserver;
    person.attach(&nameObserver);
    person.forename("Jane");
    EXPECT_EQ(person.forename(), "Jane");

    // Отсоединяем наблюдателя
    person.detach(&nameObserver);
    person.forename("Jack");
    EXPECT_EQ(person.forename(), "Jack"); // Изменение все еще работает

    // Создаем еще одного наблюдателя и проверяем, что он не был уведомлен
    AddressObserver addressObserver;
    person.attach(&addressObserver);
    person.address("456 Elm St");
    EXPECT_EQ(person.address(), "456 Elm St"); // Изменение все еще работает
}
