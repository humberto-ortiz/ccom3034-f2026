#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "Date.h"
#include <stdexcept>


TEST_CASE("Test constructor...") {
    CHECK_NOTHROW(Date());
    // CHECK_THROWS(Date(1900,1,1)); // fuera de fecha
    // CHECK_THROWS(Date(1903,1,42)); // enero no tiene 42 dias
    // CHECK_THROWS(Date(1903,2,29)); // ese año no es bisiesto
    // CHECK_NOTHROW(Date(1904,2,29)); // este si.
}

/*
TEST_CASE("Testing same") {
    CHECK(Date(1903,1,1).same(Date(1903,1,1)) );
    CHECK(Date(1903,12,5).same(Date(1903,5,12)) == false );
}

TEST_CASE("Testing dayOfWeek") {
    CHECK(Date(1903,1,1).getDayOfWeek() == "jueves");
    CHECK(Date(2025,8,18).getDayOfWeek() == "lunes");
    CHECK(Date(1999,12,31).getDayOfWeek() == "viernes");
    CHECK(Date(2026,8,26).getDayOfWeek() == "miércoles");
    CHECK(Date(2021,12,8,"viernes").getDayOfWeek() == "miércoles, pero se reunen las clases de los viernes");
}
*/
