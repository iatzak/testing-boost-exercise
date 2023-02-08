#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"
using namespace Eigen;

struct MatrixIOFixture {
  MatrixIOFixture()
  {
    ExpectedA = MatrixXd(3, 3);
    ExpectedA << 1, 2, 3
        		4, 5, 6
        		7, 8, 9;
  }

  MatrixXd ExpectedA;
};

BOOST_FIXTURE_TEST_SUITE(MatrixIOTests, MatrixIOFixture)

BOOST_AUTO_TEST_CASE(openData)
{
  MatrixXd A = matrixIO::openData("testdata.csv", 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      BOOST_TEST(ExpectedA(i, j) == A(i, j));
    }
  }
}

BOOST_AUTO_TEST_SUITE_END()
