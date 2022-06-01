#pragma once
#include "csv.h"

/// <summary>
/// csv������ �и��ؼ� �����͸� �����Ѵ�.
/// </summary> 
void InitCsvParse(void);

/// <summary>
/// ���� ���� ���� �ؽ�Ʈ�� ��ȯ�Ѵ�.
/// </summary>
/// <param name="id">���� ���� �ε���</param>
/// <returns>���� �ؽ�Ʈ�� ��ȯ�Ѵ�.</returns>
wchar_t* ReturnTitleText(int32 id);

/// <summary>
/// ���� ������ Ÿ��Ʋ�� �����ϴ��� Ȯ���Ѵ�.
/// </summary>
/// <param name="id">���� ���� �ε���</param>
/// <returns>Ÿ��Ʋ�� �����ϸ� true, �ƴϸ� false.</returns>
bool TitleExisted(int32 id);

/// <summary>
/// ���� ���� ���� �ؽ�Ʈ�� �� �� ��ȯ�Ѵ�.
/// </summary>
/// <param name="id">���� ���� �ε���</param>
/// <param name="RowNum">��ȯ�ϰ� ���� �� ��</param>
/// <returns>���� �ؽ�Ʈ�� �� �� ��ȯ�Ѵ�.</returns>
wchar_t* ReturnContentText(int32 id, int32 RowNum);

/// <summary>
/// ���� ���� �������� ������ ��ȯ�Ѵ�.
/// </summary>
/// <param name="id">���� ���� �ε���</param>
/// <param name="selectNum">����ϰ� ���� �������� ��ȣ</param>
/// <returns>���� ���� ������ ������ ��ȯ�Ѵ�.</returns>
wchar_t* ReturnSelect(int32 id, int32 selectNum);

/// <summary>
/// ���� ������ �������� �����ϴ��� Ȯ���Ѵ�.
/// </summary>
/// <param name="id">���� ���� �ε���</param>
/// <param name="selectNum">�����ϴ��� Ȯ���ϰ� ���� �������� ��ȣ</param>
/// <returns>�������� �����ϸ� true, �ƴϸ� false.</returns>
bool SelectExisted(int32 id, int32 selectNum);

/// <summary>
/// ������1�� �Ѿ�� ȭ���� �ε����� ��ȯ�Ѵ�.
/// </summary>
/// <param name="id">���� ���� �ε���</param>
/// <returns>������1�� �Ѿ�� ȭ���� �ε����� ��ȯ�Ѵ�.</returns>
int32 ReturnSelect1Index(int32 id);

/// <summary>
/// ������2�� �Ѿ�� ȭ���� �ε����� ��ȯ�Ѵ�.
/// </summary>
/// <param name="id">���� ���� �ε���</param>
/// <returns>������2�� �Ѿ�� ȭ���� �ε����� ��ȯ�Ѵ�.</returns>
int32 ReturnSelect2Index(int32 id);

/// <summary>
/// ������3���� �Ѿ�� ȭ���� �ε����� ��ȯ�Ѵ�.
/// </summary>
/// <param name="id">���� ���� �ε���</param>
/// <returns>������3���� �Ѿ�� ȭ���� �ε����� ��ȯ�Ѵ�.</returns>
int32 ReturnSelect3Index(int32 id);

/// <summary>
/// ���� ���� ���� �̸��� ��ȯ�Ѵ�.
/// </summary>
/// <param name="id">���� ���� �ε���</param>
/// <returns>���� ���� ���� �̸��� ��ȯ�Ѵ�.</returns>
char* ReturnBGM(int32 id);

/// <summary>
/// ���� ���� ȿ������ �̸��� ��ȯ�Ѵ�.
/// </summary>
/// <param name="id">���� ���� �ε���</param>
/// <param name="selectNum">����ϰ� ���� ȿ������ ��ȣ</param>
/// <returns>���� ���� ȿ������ �̸��� ��ȯ�Ѵ�.</returns>
char* ReturnSoundEffect(int32 id, int32 effectNum);

/// <summary>
/// ���� ������ ȿ������ �����ϴ��� Ȯ���Ѵ�.
/// </summary>
/// <param name="id">���� ���� �ε���</param>
/// <param name="selectNum">�����ϴ��� Ȯ���ϰ� ���� ȿ������ ��ȣ</param>
/// <returns>ȿ������ �����ϸ� true, �ƴϸ� false.</returns>
bool SoundEffectExisted(int32 id, int32 effectNum);

/// <summary>
/// ���� ���� ��� �̹��� �̸��� ��ȯ�Ѵ�.
/// </summary>
/// <param name="id">���� ���� �ε���</param>
/// <returns>���� ���� ��� �̹��� �̸��� ��ȯ�Ѵ�.</returns>
char* ReturnBackGroundImage(int32 id);

/// <summary>
/// ���� ���� ��� �̹��� �̸��� ��ȯ�Ѵ�.
/// </summary>
/// <param name="id">���� ���� �ε���</param>
/// <returns>���� ���� ��� �̹��� �̸��� ��ȯ�Ѵ�.</returns>
char* ReturnCursorImageImage(int32 id);