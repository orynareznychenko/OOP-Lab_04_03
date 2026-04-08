#include "pch.h"
#include "CppUnitTest.h"
#include "../ООП РІ-13 Резниченко ЛР-4.3/Array.h"
#include "../ООП РІ-13 Резниченко ЛР-4.3/Octal.h"
#include "../ООП РІ-13 Резниченко ЛР-4.3/String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Octal o1("754");
            Octal o2("26");

            Array* resultArray = o1.add(&o2);
            Octal* resultOctal = dynamic_cast<Octal*>(resultArray);

            Assert::IsNotNull(resultOctal, L"Помилка: результат не є типом Octal");

            Assert::AreEqual(4, resultOctal->getCount(), L"Помилка: неправильна кількість розрядів");

            // Перевіряємо кожну цифру (1002 -> [0]=2, [1]=0, [2]=0, [3]=1)
            Assert::AreEqual((unsigned char)2, (*resultOctal)[0], L"Помилка в 0-му розряді");
            Assert::AreEqual((unsigned char)0, (*resultOctal)[1], L"Помилка в 1-му розряді");
            Assert::AreEqual((unsigned char)0, (*resultOctal)[2], L"Помилка в 2-му розряді");
            Assert::AreEqual((unsigned char)1, (*resultOctal)[3], L"Помилка в 3-му розряді");

            delete resultArray;
		}
	};
}
