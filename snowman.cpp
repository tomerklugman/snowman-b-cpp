#include "snowman.hpp"
#include <iostream>
#include <array>
#include <cmath> // for pow

using namespace std;

namespace ariel
{
	string snowman(int a)
	{
		string snowman;

		const int GET_FIRST_NUM = 10;
		const int LOWER_ONE_FOR_ARRAY = 1; // -1 for the array [0,1,2,....] our numbers start from 1-4
		const int TWO = 2;
		const int THREE = 3;
		const int FOUR = 4;
		const int FIVE = 5;
		const int SIX = 6;
		const int SEVEN = 7;
		//  a/(10^i)%10-1  getting our first num by diving in 10^i and modulo 10 to get first num
		int H = a / (int)pow(GET_FIRST_NUM, SEVEN) - LOWER_ONE_FOR_ARRAY;				 //  H=a/10^7-1  H=a/10000000-1
		int N = a / (int)pow(GET_FIRST_NUM, SIX) % GET_FIRST_NUM - LOWER_ONE_FOR_ARRAY;	 //  N=a/10^6%10-1 N=a/10000000%10-1
		int L = a / (int)pow(GET_FIRST_NUM, FIVE) % GET_FIRST_NUM - LOWER_ONE_FOR_ARRAY; //  L=a/10^5%10-1 L=a/1000000%10-1
		int R = a / (int)pow(GET_FIRST_NUM, FOUR) % GET_FIRST_NUM - LOWER_ONE_FOR_ARRAY;
		int X = a / (int)pow(GET_FIRST_NUM, THREE) % GET_FIRST_NUM - LOWER_ONE_FOR_ARRAY;
		int Y = a / (int)pow(GET_FIRST_NUM, TWO) % GET_FIRST_NUM - LOWER_ONE_FOR_ARRAY;
		int T = a / GET_FIRST_NUM % GET_FIRST_NUM - LOWER_ONE_FOR_ARRAY; // T=a/10%10-1
		int B = a % GET_FIRST_NUM - LOWER_ONE_FOR_ARRAY;				 // B=a%10-1

		if (H > 3 || H < 0 || N > 3 || N < 0 || L > 3 || L < 0 || R > 3 || R < 0 || X > 3 || X < 0 || Y > 3 || Y < 0 || T > 3 || T < 0 || B > 3 || B < 0)
		{ // our numbers are 1-4 just for array -1 [0,1,2,....]
			throw invalid_argument("Invalid code '5'");
		}
		std::array<string, 4> hat = {"\n _===_", "\n  ___ \n .....", "   _\n  /_\\", "\n  ___\n (_*_)"};
		std::array<string, 4> nose = {",", ".", "_", " "};
		std::array<string, 4> eyes = {".", "o", "O", "-"};			 // L R
		std::array<string, 4> leftarmupper = {" ", "\\", " ", " "};	 // upper body - X
		std::array<string, 4> leftarmlower = {"<", " ", "/", " "};	 // lower body
		std::array<string, 4> rightarmupper = {" ", "/", " ", " "};	 // upper body - Y
		std::array<string, 4> rightarmlower = {">", " ", "\\", " "}; // lower body
		std::array<string, 4> torso = {" : ", "] [", "> <", "   "};
		std::array<string, 4> base = {" : ", "\" \"", "___", "   "};
		// making our snowman from picking each string from array
		snowman += hat.at(H) + "\n" + leftarmupper.at(X) + "(" + eyes.at(L) + nose.at(N) + eyes.at(R) + ")" + rightarmupper.at(Y) + "\n" + leftarmlower.at(X) + "(" + torso.at(T) + ")" + rightarmlower.at(Y) + "\n" + " (" + base.at(B) + ")" + "\n";

		return snowman;
	}
}