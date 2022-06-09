#include <iostream>
#include <vector>
#include <algorithm>


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

vector<int> mathGiveUpMan1 = { 1, 2, 3, 4, 5 };
vector<int> mathGiveUpMan2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
vector<int> mathGiveUpMan3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
vector<int> answer =         { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

vector<int> answerCount = { 0, 0, 0 };
vector<int> mathGiveUpSequence = { 0 };

vector<int>::iterator iter;

vector<int>::iterator iter1;
vector<int>::iterator iter2;
vector<int>::iterator iter3;

vector<vector<int>::iterator> iterator3 = { iter1, iter2, iter3 };

void CopyData(vector<int> answers, vector<int> mathGiveUpMan)
{
    if (answers.size() > mathGiveUpMan.size())
    {
        int count = answers.size() / mathGiveUpMan.size();
        int n = 0;
        while (1)
        {
            if (n == count)
            {
                break;
            }
            for (int i = 0; i < mathGiveUpMan.size(); ++i)
            {
                mathGiveUpMan.push_back(mathGiveUpMan[i]);
            }
            ++n;
        }
    }
}

void AnswerCount(vector<int> answers, vector<int> mathGiveUpMan, vector<vector<int>::iterator> iterator, vector<int> answerCount)
{
    iter1 = mathGiveUpMan1.begin();
    iter2 = mathGiveUpMan2.begin();
    iter3 = mathGiveUpMan3.begin();

    for (iter = answers.begin(); iter != answers.end(); ++iter)
    {
        if (*iter = *iterator[i])
        {
            ++answerCount[0];
        }

        if (*iter = *iter2)
        {
            ++answerCount[1];
        }

        if (*iter = *iter3)
        {
            ++answerCount[2];
        }
    }

}

vector<int> solution(vector<int> answers)
{   
    CopyData(answers, mathGiveUpMan1);
    CopyData(answers, mathGiveUpMan2);
    CopyData(answers, mathGiveUpMan3);

    int* mgm[] = {mathGiveUpMan1AnswerCount, ;
    int* mgm2 = &mathGiveUpMan2AnswerCount;
    int* mgm3 = &mathGiveUpMan3AnswerCount;




    answerCount.push_back(mathGiveUpMan1AnswerCount);
    answerCount.push_back(mathGiveUpMan2AnswerCount);
    answerCount.push_back(mathGiveUpMan3AnswerCount);
    
    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}

