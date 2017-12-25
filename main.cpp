    // file: feetinches.cpp

    #include <iostream>
    #include "feetinches.h"
    #include <stdlib.h>
    using namespace std;

    namespace cs_feetInches {
		feetInches::feetInches(int inFeet, int inInches)
		{
			feet = inFeet;
			inches = inInches;
			simplify();
		}





		feetInches operator+(const feetInches& left,
							 const feetInches& right)
		{
			feetInches answer;

			answer.feet = left.feet + right.feet;
			answer.inches = left.inches + right.inches;

			answer.simplify();
			return answer;

			// or:
			// return feetInches(left.feet + right.feet,
			//                    left.inches + right.inches);
		}





		ostream& operator<<(ostream& out, const feetInches& right)
		{
			out << right.feet << " feet, " << right.inches << " inches";
			return out;
		}





		void feetInches::simplify()
		{
			if (inches >= 12){
				feet += inches/12;
				inches %= 12;
			} else if (inches < 0){
				feet -= abs(inches)/12 + 1;
				inches = 12 - (abs(inches) % 12);
			}
		}





		bool operator<(const feetInches& left, const feetInches& right)
		{
			if (left.feet < right.feet){
				return true;
			}

			if (left.feet > right.feet){
				return false;
			}

			return left.inches < right.inches;
		}





		feetInches feetInches::operator++()
		{
			feet++;
			return *this;
		}





		feetInches feetInches::operator++(int)
		{
			feetInches temp(feet, inches);  //declaration statement
			feet++;
			return temp;
		}





		feetInches feetInches::operator+=(const feetInches& right)
		{
			*this = *this + right;

			// or:
			//feet += right.feet;
			//inches += right.inches;
			//simplify();

			return *this;
		}
	}        // this closes the namespace
