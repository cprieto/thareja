#include <catch2/catch_test_macros.hpp>
#include <iostream>
extern "C" {
    #include "chap06.h"
}

template<typename... Args>
void check_llist(Node* root, Args...) {
    size_t num = sizeof... (Args);
    Node* current = root;
    for (size_t i = 0; i < num; i++) {
        REQUIRE(current != NULL);
        REQUIRE()
        current = current->next;
    }
}

TEST_CASE("Single lists", "[single_ll]") {
    Node* root;

    SECTION("Create a list") {
        root = ll_create(3, 1, 2, 3);

        REQUIRE(root != NULL);
        REQUIRE(root->data == 1);

        REQUIRE(root->next != NULL);
        REQUIRE(root->next->data == 2);

        REQUIRE(root->next->next != NULL);
        REQUIRE(root->next->next->data == 3);

        REQUIRE(root->next->next->next == nullptr);

        check_llist(root, 1, 2, 3, 4);
    }

    SECTION("Calculate length of a list") {
        REQUIRE(ll_length(root) == 3);
    }
}

