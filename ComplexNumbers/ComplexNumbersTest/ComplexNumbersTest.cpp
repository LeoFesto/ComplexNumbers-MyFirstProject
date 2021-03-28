#include "pch.h"
#include "CppUnitTest.h"
#include "..\ComplexNumbers\RationalNumbers.h"
#include "..\ComplexNumbers\ComplexNumbers.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ComplexNumbersTest
{
	using R = Rational;
	using C = Complex;
	TEST_CLASS(RationalNumbersTest)
	{
		
		
		TEST_METHOD(Equality)
		{
			
			Assert::IsTrue(R{ 95 } == R{ 95, 1 });
			Assert::IsTrue(R{ 0,1 } == R{});
			Assert::IsTrue(R{ 0 } == R{});
			Assert::IsTrue(R{-0} == R{0});
			Assert::IsTrue(R{10} == R{10});
			Assert::IsTrue(R{ 10,5 } == R{ 2 });
			Assert::IsTrue(R{10,-5} == R{-10,5});
			Assert::IsTrue(R{ -10,5 } == R{ -2 });
			Assert::IsTrue(R{ -10,-5 } == R{ 2 });
			Assert::IsTrue(R{ 10,-5 } == R{ -10,5 });
			R a = { 3,2 };
			R b = a;
			Assert::IsTrue(b == a);
			Assert::IsTrue(a == b);
			b = a + 0;
			Assert::IsTrue(a == b);
			b = a + 1;
			Assert::IsTrue(a != b);
			Assert::IsTrue(R{ 3,2 } == -R{-3,2});
			Assert::IsTrue(R{ -3,2 } == -R{ 3,2 });
			Assert::IsTrue(R{ 3,-2 } == -R{ 3,2 });
			Assert::IsTrue(R{ -3,-2 } == -R{ 3,-2 });

		}
		TEST_METHOD(Sum)
		{
			Assert::IsTrue((R{ 4,3 } + R{0}) == R{ 4,3 });
			Assert::IsTrue((R{ 4,3 } + R{ 5,3 }) == R{ 9,3 });
			Assert::IsTrue((R{ 3 } + R{ 2,7 }) == R{ 23,7 });
			Assert::IsTrue((R{ -3 } + R{ 2,7 }) == R{ -19,7 });
			Assert::IsTrue((R{ -8 } + R{ 16,2 }) == R{ 0 });
			Assert::IsTrue((R{0} + R{-0}) == R{0});
			Assert::IsTrue((R{-0} + R{-0}) == R{0});
			Assert::IsTrue((R{-20,21} + R{1,7}) == R{-17,21});
			Assert::IsTrue((R{-8,59} + R{-98,3}) == R{-5806,177});
			Assert::IsTrue((R{-3} + R{5}) == R{2});
		}
		TEST_METHOD(Difference)
		{
			Assert::IsTrue((R{0} - R{0}) == R{0});
			Assert::IsTrue((R{5} - R{0}) == R{5});
			Assert::IsTrue((R{-0} - R{0}) == R{0});
			Assert::IsTrue((R{-32} - R{-0}) == R{-32});
			Assert::IsTrue((R{-32} - R{-32}) == R{0});
			Assert::IsTrue((R{32} - R{32}) == R{0});
			Assert::IsTrue((R{32,1} - R{32}) == R{0});
			Assert::IsTrue((R{32} - R{34}) == R{-2,1});
			Assert::IsTrue((R{34} - R{32}) == R{2});
			Assert::IsTrue((R{-32} - R{34}) == R{-66,1});
			// R{92,3} > R{24}
			Assert::IsTrue((R{92,3} - R{24}) == R{20,3}); 
			Assert::IsTrue((R{24} - R{ 92,3 }) == R{-20,3}); 
			Assert::IsTrue((R{-92,3} - R{-24}) == R{-20,3}); 
			Assert::IsTrue((R{-24} - R{ -92,3 }) == R{20,3});
			Assert::IsTrue((R{92,3} - R{-24}) == R{164,3});	 
			Assert::IsTrue((R{-24} - R{92,3}) == R{-164,3});
			Assert::IsTrue((R{24} - R{-92,3}) == R{164,3}); 
			Assert::IsTrue((R{-92,3} - R{24}) == R{164,-3}); 
		}
		TEST_METHOD(Multiply)
		{
			Assert::IsTrue((R{ 0 } * R{ 0 }) == R{ 0 });
			Assert::IsTrue((R{ 5 } * R{ 0 }) == R{ 0 });
			Assert::IsTrue((R{ -0 } * R{ 0 }) == R{ 0 });
			Assert::IsTrue((R{ -32 } * R{ -0 }) == R{ 0 });
			Assert::IsTrue((R{ -32 } * R{ -32 }) == R{ 1024 });
			Assert::IsTrue((R{ 32 } * R{ 32 }) == R{ 1024 });
			Assert::IsTrue((R{ 32,1 } * R{ 32 }) == R{ 1024 });
			Assert::IsTrue((R{ 32 } * R{ 34 }) == R{ 1088 });
			Assert::IsTrue((R{ -32 } * R{ 34 }) == R{ -1088 });
			// R{92,3} > R{24}
			Assert::IsTrue((R{ 92,3 } * R{ 24 }) == R{ 736 });
			Assert::IsTrue((R{ -92,3 } * R{ -24 }) == R{ 736 });
			Assert::IsTrue((R{ 92,3 } * R{ -24 }) == R{ -736 });
			Assert::IsTrue((R{ -24,7 } * R{ 92,3 }) == R{ 736,-7 });
			Assert::IsTrue((R{ -92,3 } * R{ 24,109 }) == R{ -736,109 });
		}
		TEST_METHOD(Division)
		{
			Assert::IsTrue((R{ -32 } / R{ -32 }) == R{ 1 });
			Assert::IsTrue((R{ 32 } / R{ 32 }) == R{ 1 });
			Assert::IsTrue((R{ 32,1 } / R{ 32 }) == R{ 1 });
			Assert::IsTrue((R{ 32 } / R{ 34 }) == R{ 16,17 });
			Assert::IsTrue((R{ 34 } / R{ 32 }) == R{ 17,16 });
			Assert::IsTrue((R{ -32 } / R{ 34 }) == R{ 16,-17 });
			// R{92,3} > R{24}
			Assert::IsTrue((R{ 92,3 } / R{ 24 }) == R{ 23,18 });
			Assert::IsTrue((R{ 24 } / R{ 92,3 }) == R{ 18,23 });
			Assert::IsTrue((R{ -92,3 } / R{ -24 }) == R{ 23,18 });
		}
		TEST_METHOD(GreaterAndLess)
		{
			Assert::IsTrue(R{0} > R{-1});
			Assert::IsTrue(R{12,-1} < R{0});
			Assert::IsTrue(R{ 12,-1 } < R{ 24,-4 });
			Assert::IsTrue(R{ -12,1 } < R{ 0 });
			Assert::IsTrue(R{15,2} > R{14,2});
			Assert::IsTrue(R{-15,2} < R{7});
			Assert::IsTrue(R{-10} > R{-11});
			Assert::IsTrue(R{-22,3} < R{-5,2});
		}
	};

	TEST_CLASS(ComplexNumbersTest1)
	{
	public:
		
		TEST_METHOD(ConstructorAndEquality)
		{
			Assert::IsTrue(C{} == C{ 0 });
			Assert::IsTrue(C{0} == C{ 0,0 });
			Assert::IsTrue(C{ 4 } == C{ 0,4 });
			Assert::IsTrue(C{ 0,4 } == C{ R{0},  R{4,1} });
			Assert::IsTrue(C{ 3,0 } == C{ R{3,1}, R{} });
			Assert::IsTrue(C{ R{-10,2}, R{15,3} } == C{-5, 5});
			Assert::IsTrue(C{ R{10,-2}, R{15,-3} } == C{ -5, -5 });
			C a = { 4,8 };
			C b = a;
			Assert::IsTrue(a == b);
			a += C{ 0,0 };
			Assert::IsTrue(a == b);
			a += C{ 1,0 };
			Assert::IsTrue(a != b);
		}
		TEST_METHOD(Sum)
		{
			Assert::IsTrue((C{ 2,1 } + C{0}) == C{2,1});
			Assert::IsTrue((C{2,1} + C{3,-1}) == C{5,0});
			Assert::IsTrue((C{ 0,R{0,-2} } + C{ -0 }) == C{ 0,0 });
			Assert::IsTrue((C{-5,-1 } + C{ -5,-1 }) == C{ -10,-2 });
			Assert::IsTrue((C{-5,4} + C{4,-1}) == C{-1,3});
			Assert::IsTrue((C{} + C{5,2}) == C{5,2});
			Assert::IsTrue((C{-3,0} + C{3,-6}) == C{-6});
			Assert::IsTrue((C{-0} + C{0}) == C{});
			Assert::IsTrue((C{0} + C{-3,1}) == C{-3,1});
			Assert::IsTrue((C{ R{10,2}, R{-6,-9} } + C{ R{90,10}, R{1,-4} }) == (C{ R{5}, R{2,3} } + C{ R{9}, R{-1,4}}));
		}
		TEST_METHOD(Difference)
		{
			Assert::IsTrue((C{ 2,1 } - C{ 0 }) == C{ 2,1 });
			Assert::IsTrue((C{ 2,1 } - C{ 3,-1 }) == C{-1,2});
			Assert::IsTrue((C{ 0,R{0,-2} } - C{ -0 }) == C{});
			Assert::IsTrue((C{ -5,-1 } - C{ -5,-1 }) == C{0});
			Assert::IsTrue((C{ -5,4 } - C{ 4,-1 }) == C{-9,5});
			Assert::IsTrue((C{0} - C{ 5,2 }) == C{-5,-2});
			Assert::IsTrue((C{ -3,0 } - C{ -3,-6 }) == C{6});
			Assert::IsTrue((C{ -0 } - C{ 0 }) == C{0, 0});
			Assert::IsTrue((C{ 0 } - C{ -3,1 }) == C{3,-1});
			Assert::IsTrue((C{ R{10,2}, R{-6,-9} } - C{ R{90,10}, R{1,-4} }) == (C{ R{5}, R{2,3} } - C{ R{9}, R{-1,4} }));
		}
		TEST_METHOD(Multiply)
		{
			Assert::IsTrue(C{} *C{} == C{0,0});
			Assert::IsTrue(C{0} *C{0,0} == C{});
			Assert::IsTrue(C{0} *C{1,4} == C{0});
			Assert::IsTrue(C{0} *C{0,4 } == C{0});
			Assert::IsTrue(C{1,2} *C{1,2} == C{1,2}.Pow(2));
			Assert::IsTrue(-C{1,2} *C{1,2} == -(C{1,2}.Pow(2)));
			Assert::IsTrue(-C{1,2} *-C{1,2} == C{1,2}.Pow(2));
			Assert::IsTrue(C{2,1} *C{5,3} == C{7,11});
			Assert::IsTrue(C{-2,1 } *C{ 5,3 } == C{-13,-1});
			Assert::IsTrue(C{-2,-1} *C{5,-3} == C{-13,1});
			Assert::IsTrue(C{-2,-1} *C{-5,-3} == C{7,11});
			Assert::IsTrue(C{ -R{8,16}, R{5,3} } *C{ 5,0 } == C{-R{5,2},R{25,3}});
			Assert::IsTrue(C{ -R{8,16}, R{5,3} } *C{ 5,-R{4,7} } == C{ R{-65,42},R{181,21} });
		}
		TEST_METHOD(Division)
		{
			Assert::IsTrue(C{ 5, R{18,4} } / R{ 9 } == C{ R{5,9}, R{1,2} });
			Assert::IsTrue((C{ 5, R{18,4} } / C{ 9,0 }) == C{ R{5,9}, R{1,2} });
			Assert::IsTrue(C{ R{5,-14},R{18,4} } / C{ R{18,2}, R{8} } == C{ R{459,2030}, R{607,2030} });
			Assert::IsTrue((C{ 5,1 }*C{ 7,-6 }) / C{ 3,1 } == C{10,-11});
			Assert::IsTrue((C{ 5,1 }*C{ 3,5 }) / (C{ 0,2 }) == C{14,-5}); 
			Assert::IsTrue((C{ 1,3 }*C{ 8,-1 }) / (C{ 2,1 }.Pow(2)) == C{5,1}); 
			Assert::IsTrue((C{ 2,1 }*C{ 4,1 }) / (C{ 1,1 }) == C{ R{13,2}, -R{1,2} }); 
			Assert::IsTrue((C{ 3,-1 }*C{ 1,-4 }) / (C{ 2,-1 }) == C{ R{11,5}, R{-27,5} }); 
			Assert::IsTrue((C{ 3,1 }.Pow(3) - C{ 3,-1 }.Pow(3)) == C{52});
			Assert::IsTrue(((C{ 3,-5 }*C{ 2,3 }) / C{ 1,2 }) == C{ R{19,5}, R{-43,5} });
		}
	};
}
