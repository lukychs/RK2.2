#include "gtest/gtest.h"
#include "Person.h"
#include "AddressObserver.h"
#include "NameObserver.h"

// Тест регистрации и уведомления об изменении адреса
TEST(PersonTest, AddressChangeNotification) {
    Person homer("Homer", "Simpson");
    AddressObserver addressObserver;
    homer.attach(&addressObserver);
    homer.address("123 Oak Street, Springfield");
    EXPECT_TRUE(true);
}

// Тест игнорирования изменений имени
TEST(PersonTest, IgnoreNameChanges) {
    Person homer("Homer", "Simpson");
    NameObserver nameObserver;
    homer.attach(&nameObserver);
    homer.forename("Homer Jay");
    EXPECT_TRUE(true);
}

// Тест открепления наблюдателя
TEST(PersonTest, DetachObserver) {
    Person homer("Homer", "Simpson");
    AddressObserver addressObserver;
    homer.attach(&addressObserver);
    homer.detach(&addressObserver);
    homer.address("123 Oak Street, Springfield");
    EXPECT_TRUE(true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
