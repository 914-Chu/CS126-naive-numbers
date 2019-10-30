#include "classifying.h"
#include "catch.hpp"

using namespace classifying;
TEST_CASE("FindMostLikelyClass") {

    vector<double> post_prob = {0.3141,0.432,0.0,0.4,0.004,0.1,0.2,0.7,0.5};
    REQUIRE(FindMostLikelyClass(post_prob) == '8');
}

