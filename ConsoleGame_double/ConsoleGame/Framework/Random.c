#include "Common.h"
#include "Random.h"

void Random_Init(void)
{
	srand(time(NULL));
}

int32 Random_GetNumberFromRange(int32 minInclusive, int32 maxExclusive)
{
	int32 range = maxExclusive - minInclusive;
	int32 count = 1 + range / RAND_MAX;

	int32 result = 0;
	for (int32 i = 0; i < count; ++i)
	{
		result += rand() % range;
	}
	result += minInclusive;

	return result;
}

float Random_GetFNumberFromRange(float minInclusive, float maxInclusive)
{
	float normalizedRandom = rand() / (float)RAND_MAX;
	float range = maxInclusive - minInclusive;
	float result = minInclusive + normalizedRandom * range;

	return result;
}