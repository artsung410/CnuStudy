#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char nums1[4] = { 0 };
	char nums2[4] = { 0 };
	int numArr1[4] = { 0 };
	int numArr2[4] = { 0 };

	scanf("%s %s", nums1, nums2);

	char startNum1 = nums1[0];
	nums1[0] = nums1[2];
	nums1[2] = startNum1;

	char startNum2 = nums2[0];
	nums2[0] = nums2[2];
	nums2[2] = startNum2;

	for (int i = 0; nums1[i] != NULL; i++)
	{
		numArr1[i] = nums1[i] - '0';
		numArr2[i] = nums2[i] - '0';
	}

	int num1 = 0; int num2 = 0;
	num1 = numArr1[0] * 100 + numArr1[1] * 10 + numArr1[2] * 1;
	num2 = numArr2[0] * 100 + numArr2[1] * 10 + numArr2[2] * 1;

	if (num1 > num2)
	{
		printf("%d", num1);
	}
	else
	{
		printf("%d", num2);
	}
	
	return 0;
}