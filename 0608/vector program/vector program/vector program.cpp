#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

// 1번 수포자 : 1, 2, 3, 4, 5 //
// 2번 수포자 : 2, 1, 2, 3, 2, 4, 2, 5 // 
// 3번 수포자 : 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 //

// 최대  10,000 문제로 구성되어있습니다. == _size <= 10000
// 문제의 정답은 1, 2, 3, 4, 5 중 하나입니다.
// 가장 높은 점수를 받은사람이 여럿일경우, return 값을 오름차순 정렬해주세요.

// 맞춘점수 카운트한거 배열에 담기

// 그 배열 순서대로 나열

// 그 배열 인덱스를 다른배열에 나열. 끄으으으으읕
using namespace std;





// 수포자의 답지가 시험 문제수보다 적을때 복사작업이 일어난다.
void CopyData(vector<int> answers, vector<int> mathGiveUpMan)
{
    if (answers.size() > mathGiveUpMan.size())
    {
        mathGiveUpMan.reserve(mathGiveUpMan.size() + 10);
        int prevSize = mathGiveUpMan.size();
        int count = answers.size() / mathGiveUpMan.size();
        int n = 0;
        while (1)
        {
            if (n == count)
            {
                break;
            }

            for (int i = 0; i < prevSize; ++i)
            {
                mathGiveUpMan.push_back(mathGiveUpMan[i]);
            }

            ++n;
        }
    }
}

// 정답개수 세기
void AnswerCount(vector<int> answers, vector<int> aCnt, vector<vector<int>> mgms)
{
    vector<int>::iterator iter_answer;
    vector<int>::iterator iter_mgm1;
    vector<int>::iterator iter_mgm2;
    vector<int>::iterator iter_mgm3;
    vector<int>::iterator iter_acnt;

    
    iter_mgm1 = mgms[0].begin();
    iter_mgm2 = mgms[1].begin();
    iter_mgm3 = mgms[2].begin();

    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;

    for (iter_answer = answers.begin(); iter_answer != answers.end(); ++iter_answer)
    {
        if (*iter_answer == *iter_mgm1)
        {
            ++cnt1;
        }

        if (*iter_answer == *iter_mgm2)
        {
            ++cnt2;
        }

        if (*iter_answer == *iter_mgm3)
        {
            ++cnt3;
        }

        ++iter_mgm1;
        ++iter_mgm2;
        ++iter_mgm3;
    }

    aCnt.reserve(5);
    aCnt.push_back(5);
    aCnt.push_back(2);
    aCnt.push_back(3);
}

// 정답개수에 따라 학생을 오름차순으로 정렬
void sortData(vector<int> aCnt)
{
    int temp;
    for (int i = 0; i < aCnt.size(); ++i)
    {
        for (int j = 0; j < aCnt.size() - 1; j++)
        {
            if (aCnt[j] > aCnt[j + 1])
            {
                temp = aCnt[j];
                aCnt[j] = aCnt[j + 1];
                aCnt[j + 1] = temp;
            }
        }
    }
}


//vector<int> solution(vector<int> answers)
//{   
//    for (int i = 0; i < mathGiveUpMans.size(); ++i)
//    {
//        CopyData(answers, mathGiveUpMans[i]);
//    }
//
//    AnswerCount(answers, answerCount);
//
//
//    return answer;
//}

void solution(vector<int> answers, vector<vector<int>> mgms, vector<int> aCnt)
{
    for (int i = 0; i < mgms.size(); ++i)
    {
        CopyData(answers, mgms[i]);
    }

    AnswerCount(answers, aCnt, mgms);

    for (int i = 0; i < aCnt.size(); ++i)
    {
        cout << aCnt[i] << endl;
    }
}

int main()
{
    vector<int> mathGiveUpMan1 = { 1, 2, 3, 4, 5 };
    vector<int> mathGiveUpMan2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> mathGiveUpMan3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    vector<int> answer = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };

    vector<int> answerCount = { 0 };
    vector<int> mathGiveUpSequence = { 0 };
    vector<vector<int>> mathGiveUpMans = { mathGiveUpMan1 , mathGiveUpMan2 , mathGiveUpMan3 };

    solution(answer, mathGiveUpMans, answerCount);
}

