#pragma once
#include "test_runner.h"
#include "parser.h"

void TestPlusAndMinus() {
	Parser parser;
	AssertEqual(parser.ChangeExpression("2").Result(), 2, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("-2").Result(), -2, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("20 + 5").Result(), 25, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("20 - 0").Result(), 20, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("20 + 0").Result(), 20, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("0 - 20 - 0 + 30").Result(), 10, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("20 + 5.1").Result(), 25.1, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("20.30 + 5").Result(), 25.3, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("20.324 + 5.2").Result(), 25.524, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("20.324 + 5.2").Result(), 25.524, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("20 - 5").Result(), 15, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("20 - -5").Result(), 25, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("20 - 5.5").Result(), 14.5, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("10 + 10 + 10").Result(), 30, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("10 + 10 + 10 + 10").Result(), 40, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("10 - 10").Result(), 0, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("10 - 10 - 10").Result(), -10, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("-10 - 10 - 10").Result(), -30, parser.GetExpression()); /* */
	AssertEqual(parser.ChangeExpression("10 + 12 - 10").Result(), 12, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("10 - 10 + 10").Result(), 10, parser.GetExpression()); /* */
	AssertEqual(parser.ChangeExpression("10 - 10 - 10 + 10 - 10 + 10 + 10 - 9").Result(), 1, parser.GetExpression()); /* */
}

void TestMultiplyAndDivision() {
	Parser parser;
	AssertEqual(parser.ChangeExpression("10 * 1").Result(), 10, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("10 * 2").Result(), 20, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("10 * 0").Result(), 0, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("0 * 0").Result(), 0, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("1.5 * 20").Result(), 30, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("-1.5 * 20").Result(), -30, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("1.5 * -20").Result(), -30, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("-1.5 * -20").Result(), 30, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("-10 * 20 * 0.1 * -1").Result(), 20, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("1 * 2 * 3 * 4 * 5").Result(), 120, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("1 * 2 * 3 * -4 * 5").Result(), -120, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("-1 * 2 * 3 * -4 * -5").Result(), -120, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("1 * -2 * 3 * -4 * 5").Result(), 120, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("1 * -2 * 3 * 0 * 5").Result(), 0, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("2 / 1").Result(), 2, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("2 / 2").Result(), 1, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("23 / 1").Result(), 23, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("23 / 2").Result(), 11.5, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("20 / 2").Result(), 10, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("-20 / 2").Result(), -10, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("20 / -2").Result(), -10, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("-20 / -2").Result(), 10, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("0 / -2").Result(), 0, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("100 / 2 / 2").Result(), 25, parser.GetExpression()); /* */
	AssertEqual(parser.ChangeExpression("100 / 2 / -2").Result(), -25, parser.GetExpression()); /* */
	AssertEqual(parser.ChangeExpression("100 / -2 / 2").Result(), -25, parser.GetExpression()); /* */
	AssertEqual(parser.ChangeExpression("100 / -2 / 2 / -2").Result(), 12.5, parser.GetExpression()); /* */
	AssertEqual(parser.ChangeExpression("120 / -5 / -2 / 12").Result(), 1, parser.GetExpression()); /* */
	AssertEqual(parser.ChangeExpression("2 * 200 / 100").Result(), 4, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("2 * -200 / 100").Result(), -4, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("2 * -200 / -100").Result(), 4, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("-2 * -200 / -100").Result(), -4, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("2 * 50 / 50").Result(), 2, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("2 * 50 / 50 * 50").Result(), 100, parser.GetExpression()); /* */
	AssertEqual(parser.ChangeExpression("2 * 50 / 50 * 50 / 50").Result(), 2, parser.GetExpression()); /* */
	AssertEqual(parser.ChangeExpression("2 * 50 / -50 * -50").Result(), 100, parser.GetExpression()); /* */
}

void TestMixedOperations() {
	Parser parser;
	AssertEqual(parser.ChangeExpression("2 + 2 * 2").Result(), 6, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("2 / 2 + 2 * 2").Result(), 5, parser.GetExpression()); /* */
	AssertEqual(parser.ChangeExpression("10 / 2 + 2 * 3 - 15 / 2").Result(), 3.5, parser.GetExpression()); /* */
	AssertEqual(parser.ChangeExpression("10 / 2 + 2 * 3 - -15 / 2").Result(), 18.5, parser.GetExpression()); /* */
	AssertEqual(parser.ChangeExpression("153 / 18 * 3.4 + 2 + 103 - 6 * 0.25 * 0.2").Result(), 133.6, parser.GetExpression()); /* */

}


void TestWithBrackets() {
	Parser parser;
	AssertEqual(parser.ChangeExpression("( 2 )").Result(), 2, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("( 2 + 3 )").Result(), 5, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("( 2 + 3 + 4 )").Result(), 9, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("( 2 * 2 + 3 )").Result(), 7, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("( 2 + 0 * 0 + 9 )").Result(), 11, parser.GetExpression());

	AssertEqual(parser.ChangeExpression("( 1 + 923 ) + 4").Result(), 928, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("4 + ( 1 + 923 )").Result(), 928, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("( 2 + 3 ) / 5").Result(), 1, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("( 2 + 3 + 1 + 12 ) / 2 / 3 * 2").Result(), 6, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("4 * ( 50 + 30 ) / 10").Result(), 32, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("( 10 * 20 ) / ( 105 - 5 + ( 0 * 6 ) )").Result(), 2, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("( 5 + 4 ) * 3 + ( 20 / 2 )").Result(), 37, parser.GetExpression());
	AssertEqual(parser.ChangeExpression("( ( 28 / ( 4 + 6 ) - 5 * 25.1 ) + 3 ) * 2 - ( 12 + 2 ) * 4").Result(), -295.4, parser.GetExpression());
}
