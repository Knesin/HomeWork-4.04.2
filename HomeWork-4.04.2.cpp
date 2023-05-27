#include <iostream>
#include "List.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>

TEST_CASE("List", "[List]") {
    List l;
    SECTION("PushBack") {
        SECTION("PushBack 1")
        {
            INFO("Поветка что список пустой");
            CHECK(l.Empty() == true);
        }
        l.PushBack(1);
        SECTION("PushBack 2")
        {
            INFO("Проверка что списке 1 элемент для PushBack");
            CHECK(l.Size() == 1);
        }
        l.PushBack(2);
        l.PushBack(3);
        SECTION("PushBack 3")
        {
            INFO("Проверка что списке 3 элемента для PushBack");
            CHECK(l.Size() == 3);
        }
    }
    SECTION("PushFront") {
        SECTION("PushFront 1")
        {
            INFO("Поветка что список пустой");
            CHECK(l.Empty() == true);
        }
        l.PushFront(1);
        SECTION("PushFront 2")
        {
            INFO("Проверка что списке 1 элемент для PushFront");
            CHECK(l.Size() == 1);
        }
        l.PushFront(2);
        l.PushFront(3);
        SECTION("PushFront 3")
        {
            INFO("Проверка что списке 3 элемента для PushFront");
            CHECK(l.Size() == 3);
        }
    }
    SECTION("PopBack") {
        SECTION("PopBack 1")
        {
            l.PushFront(10);
            l.PushFront(20);
            SECTION("PopBack 1.1")
            {
                INFO("Проверка перед извлечением что список не пуст для PopBack");
                CHECK(l.Empty() == false);
            }
            SECTION("PopBack 1.2")
            {
                INFO("Проверка что извлечено первое верное число для PopBack");
                CHECK(l.PopBack() == 10);
                SECTION("PopBack 1.2.1")
                {
                    INFO("Проверка что извлечено второе верное число для PopBack");
                    CHECK(l.PopBack() == 20);
                }
            }
        }
        SECTION("PopBack 2")
        {
            SECTION("PopBack 2.1")
            {
                INFO("Проверка что список пуст PopBack");
                CHECK(l.Size() == 0);
            }
            SECTION("PopBack 2.2")
            {
                INFO("Проверка при извлечении из пустого списка PopBack");
                REQUIRE_THROWS(l.PopBack());
            }
        }
    }
    SECTION("PopFront") {
        SECTION("PopFront 1")
        {
            l.PushBack(10);
            l.PushBack(20);
            SECTION("PopFront 1.1")
            {
                INFO("Проверка перед извлечением что список не пуст для PopFront");
                CHECK(l.Empty() == false);
            }
            SECTION("PopFront 1.2")
            {
                INFO("Проверка что извлечено первое верное число для PopFront");
                CHECK(l.PopFront() == 10);
                SECTION("PopFront 1.2.1")
                {
                    INFO("Проверка что извлечено второе верное число для PopFront");
                    CHECK(l.PopFront() == 20);
                }
            }
        }
        SECTION("PopFront 2")
        {
            SECTION("PopFront 2.1")
            {
                INFO("Проверка что список пуст PopFront");
                CHECK(l.Size() == 0);
            }
            SECTION("PopFront 2.2")
            {
                INFO("Проверка при извлечении из пустого списка PopFront");
                REQUIRE_THROWS(l.PopFront());
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    return Catch::Session().run();
}