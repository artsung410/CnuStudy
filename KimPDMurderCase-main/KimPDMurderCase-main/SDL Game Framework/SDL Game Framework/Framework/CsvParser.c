#include "stdafx.h"
#include "CsvParser.h"
#include "Text.h"

#include <crtdbg.h>

CsvFile csvFile;

enum csv {
	Id = 0,
	Place,
	MainStory,
	Options1,
	Options2,
	Options3,
	Options1Id,
	Options2Id,
	Options3Id,
	Sound,
	SoundEffect1,
	SoundEffect2,
	Picture,
	Picture1

};

void InitCsvParse(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	memset(&csvFile, 0, sizeof(CsvFile));
	CreateCsvFile(&csvFile, "test.csv");
}

wchar_t* ReturnTitleText(int32 id)
{
	static wchar_t titleText[128] = { L"\0" };
	
	wchar_t* temp = ParseToUnicode(csvFile.Items[id][Place]);

	int count = 0;
	while (*temp != L'\0')
	{
		titleText[count] = *temp;
		count++;
		temp++;
	}

	return titleText;
}

bool TitleExisted(int32 id)
{
	if (NULL == *(ParseToUnicode(csvFile.Items[id][Place])))
	{
		return false;
	}

	return true;
}

wchar_t* ReturnContentText(int32 id, int32 RowNum)
{
	static wchar_t finishedText[128] = { L"\0" };
	
	for (int32 i = 0; i < 128; i++)
	{
		finishedText[i] = L'\0';
	}

	wchar_t* nowCharacter;
	nowCharacter = ParseToUnicode(csvFile.Items[id][MainStory]);

	int32 row = 0;

	while (*nowCharacter != L'\0')
	{
		for (int32 lineText = 0; lineText < 128; lineText++)
		{
			if (*nowCharacter == L'\0')
			{
				return finishedText;
			}
			else if (*nowCharacter == L'\n')
			{
				row++;
				lineText = -1;
			}
			else if (row == RowNum)
			{
				if (*nowCharacter == L'\"')
				{
					lineText--;
				}
				else
				{
					finishedText[lineText] = *nowCharacter;
				}
			}
			if (row > RowNum)
			{
				return finishedText;
			}
			nowCharacter++;
		}
	}

	return finishedText;
}

wchar_t* ReturnSelect(int32 id, int32 selectNum)
{
	static wchar_t selectText[128] = { L"\0" };

	for (int32 i = 0; i < 128; i++)
	{
		selectText[i] = L'\0';
	}

	wchar_t* temp = ParseToUnicode(csvFile.Items[id][Options1 + selectNum]);

	int count = 0;
	while (*temp != L'\0')
	{
		selectText[count] = *temp;
		count++;
		temp++;
	}

	return selectText;
}

bool SelectExisted(int32 id, int32 selectNum)
{
	if (NULL == *(ParseToUnicode(csvFile.Items[id][Options1 + selectNum])))
	{
		return false;
	}

	return true;
}

int32 ReturnSelect1Index(int32 id)
{
	int Select1Index;

	Select1Index = ParseToInt(csvFile.Items[id][Options1Id]);

	return Select1Index;
}

int32 ReturnSelect2Index(int32 id)
{
	int Select2Index;

	Select2Index = ParseToInt(csvFile.Items[id][Options2Id]);

	return Select2Index;
}

int32 ReturnSelect3Index(int32 id)
{
	int Select3Index;

	Select3Index = ParseToInt(csvFile.Items[id][Options3Id]);

	return Select3Index;
}

char* ReturnBGM(int32 id)
{
	char* BGM;

	BGM = ParseToAscii(csvFile.Items[id][Sound]);

	return BGM;
}

char* ReturnSoundEffect(int32 id, int32 effectNum)
{
	char* SoundEffect;

	SoundEffect = ParseToAscii(csvFile.Items[id][SoundEffect1 + effectNum]);

	return SoundEffect;
}

// 갓중재께서 해결해주심
bool SoundEffectExisted(int32 id, int32 effectNum)
{
	if (NULL == *(ParseToUnicode(csvFile.Items[id][SoundEffect1 + effectNum])))
	{
		return false;
	}

	return true;
}

char* ReturnBackGroundImage(int32 id)
{
	char* BackGroundImageName;

	BackGroundImageName = ParseToAscii(csvFile.Items[id][Picture]);

	return BackGroundImageName;
}

char* ReturnCursorImageImage(int32 id)
{
	char* BackGroundImageName;

	BackGroundImageName = ParseToAscii(csvFile.Items[id][Picture1]);

	return BackGroundImageName;
}