/**
 * @file testSignature
 * @brief Tests focusing on the details of Signatures to evaluate boost compliance
 * @author Alex Cunningham
 * @date Sept 19th 2011
 */

#include <boost/assign/std/vector.hpp>
#include <CppUnitLite/TestHarness.h>

#include <gtsam/base/Testable.h>
#include <gtsam2/discrete/Signature.h>

using namespace std;
using namespace gtsam;
using namespace boost::assign;

DiscreteKey X(0,2), Y(1,3), Z(2,2);

#ifdef BOOST_HAVE_PARSER
/* ************************************************************************* */
TEST(testSignature, simple_conditional) {
	Signature sig(X | Y = "1/1 2/3 1/4");
	DiscreteKey actKey = sig.key();
	LONGS_EQUAL(X.first, actKey.first);

	DiscreteKeys actKeys = sig.discreteKeysParentsFirst();
	LONGS_EQUAL(2, actKeys.size());
	LONGS_EQUAL(Y.first, actKeys.front().first);
	LONGS_EQUAL(X.first, actKeys.back().first);

	vector<double> actCpt = sig.cpt();
	EXPECT_LONGS_EQUAL(6, actCpt.size());
}
#endif

/* ************************************************************************* */
TEST(testSignature, simple_conditional_nonparser) {
	Signature::Table table;
	Signature::Row row1, row2, row3;
	row1 += 1.0, 1.0;
	row2 += 2.0, 3.0;
	row3 += 1.0, 4.0;
	table += row1, row2, row3;

	Signature sig(X | Y = table);
	DiscreteKey actKey = sig.key();
	EXPECT_LONGS_EQUAL(X.first, actKey.first);

	DiscreteKeys actKeys = sig.discreteKeysParentsFirst();
	LONGS_EQUAL(2, actKeys.size());
	LONGS_EQUAL(Y.first, actKeys.front().first);
	LONGS_EQUAL(X.first, actKeys.back().first);

	vector<double> actCpt = sig.cpt();
	EXPECT_LONGS_EQUAL(6, actCpt.size());
}

/* ************************************************************************* */
int main() { TestResult tr; return TestRegistry::runAllTests(tr); }
/* ************************************************************************* */
