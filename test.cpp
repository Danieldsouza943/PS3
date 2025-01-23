// Copyright 2024 Daniel Dsouza
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

#include "CelestialBody.hpp"
#include "Universe.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testFormatting) {
  NB::Universe u;
  std::stringstream compare, output;
  std::ifstream file("./nbody/3body.txt");

  file >> u;

  output << u;

  compare << "3\n" << "1.25e+11\n" <<
  "0 0 500 0 5.974e+24 earth.gif\n" <<
  "0 4.5e+10 30000 0 1.989e+30 sun.gif\n" <<
  "0 -4.5e+10 -30000 0 1.989e+30 sun.gif" << std::endl;

  BOOST_CHECK_EQUAL(compare.str(), output.str());
}

BOOST_AUTO_TEST_CASE(gettersUniverse) {
  NB::Universe u;
  std::ifstream file("./nbody/3body.txt");

  file >> u;

  BOOST_CHECK_CLOSE(u.radius(), 1.25e+11, 0.0001);
}

BOOST_AUTO_TEST_CASE(positionCelestialBody) {
  NB::Universe u;
  std::ifstream file("./nbody/3body.txt");

  file >> u;

  BOOST_CHECK_CLOSE(u[0].position().x, 0, 0.0001);
  BOOST_CHECK_CLOSE(u[0].position().y, 0, 0.0001);

  u.step(10000);

  BOOST_CHECK_CLOSE(u[0].mass(), 5.974e+24, 0.0001);
}

BOOST_AUTO_TEST_CASE(velocityCelestialBody) {
  NB::Universe u;
  std::ifstream file("./nbody/3body.txt");

  file >> u;

  BOOST_CHECK_CLOSE(u[0].velocity().x, 500, 0.0001);
  BOOST_CHECK_CLOSE(u[0].velocity().y, 0, 0.0001);
}

BOOST_AUTO_TEST_CASE(stepDelta) {
  NB::Universe u;
  std::ifstream file("./nbody/planets.txt");

  file >> u;

  u.step(10000);

  BOOST_CHECK_CLOSE(u[0].position().x, 1.49599e+11, 0.01);
  BOOST_CHECK_CLOSE(u[0].position().y, 2.98e+08, 0.01);
  BOOST_CHECK_CLOSE(u[1].position().x, 2.279e+11, 0.01);
  BOOST_CHECK_CLOSE(u[1].position().y, 2.41e+08, 0.01);
}

BOOST_AUTO_TEST_CASE(antiGrav) {
  NB::Universe u;
  std::ifstream file("./nbody/planets.txt");

  file >> u;

  u.step(10000);

  BOOST_CHECK_CLOSE(u[0].velocity().x, -59.2804, 0.01);
  BOOST_CHECK_CLOSE(u[0].velocity().y, 29800, 0.01);
  BOOST_CHECK_CLOSE(u[1].velocity().x, -25.5439, 0.01);
  BOOST_CHECK_CLOSE(u[1].velocity().y, 24100, 0.01);
}

BOOST_AUTO_TEST_CASE(test_inverted_axis_detection) {
    NB::Universe universe;

    std::istringstream input("2\n1e11\n0 0 0 0 1e30 sun.gif\n1e11 0 0 1e4 1e24 earth.gif");
    input >> universe;

    std::ostringstream initial_output;
    initial_output << universe;

    universe.step(1000);

    std::ostringstream step_output;
    step_output << universe;

    std::string initial_state = initial_output.str();
    std::string step_state = step_output.str();

    BOOST_CHECK(step_state.find("earth") != std::string::npos);
}


BOOST_AUTO_TEST_CASE(test_leapfrog_one_by_one_update) {
    NB::Universe universe;

    std::istringstream input("2\n1e11\n0 0 0 0 1e30 sun.gif\n1e11 0 0 1e4 1e24 earth.gif");
    input >> universe;

    std::ostringstream initial_output;
    initial_output << universe;

    universe.step(1000);

    std::ostringstream step_output;
    step_output << universe;

    std::string initial_state = initial_output.str();
    std::string step_state = step_output.str();

    BOOST_CHECK_NE(initial_state, step_state);  // Positions should change after step
}

