#include <iostream>

using namespace std;

#define MAX_NUM 1'000'000'000

int N;


int main()
{
	/*
	2  8  20  38  62  92
	  6	 12  18 24  30    <- 6曖 寡熱虜躑

	1類縑憮 2類: 6 * 1
	2類縑憮 3類: 6 * 2

	i類縑憮 i+1類: 6 * i

	2 + 6 * i
	i = 0 => 2:		2+6*0
	i = 1 => 8:		2+6*1
	i = 3 => 20:	2+6*3 =>  2+6*(1+2)
			 38:	2+6*6 =>  2+6*(1+2+3)		
			 62:	2+6*10 => 2+6*(1+2+3+4)

	sum += i

	2 ~ 7	: 1類
	8 ~ 19	: 2類
	20 ~ 37	: 3類
	38 ~ 61	: 4類
	62 ~ 91	: 5類
	*/

	cin >> N;

	if (N == 1)
	{
		cout << 1;
		return 0;
	}
	
	int sum = 0;
	// 13擎 8 ~ 19 餌檜 -> 2類 識 3蘊
	for (int i = 0; 2 + i * 6 < MAX_NUM; i++)
	{
		sum += i;
		if (N < 2 + 6 * (sum) && N >= 2 + 6 * (sum - i))
		{
			cout << i + 1;
			return 0;
		}
	}

}