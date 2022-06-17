#include <iostream>
#include <iomanip>
#include <fstream> 
#include <string>

using namespace std;

int main()
{
    // 파일 출력은 ofstream을 이용한다.
    std::ofstream of("temp.txt");

    string str2[] = { "|용준헌", "|김재성", "|김재민", "|성권문", "|김재민", "|이수연", "|리진호", "|이승일", "|노우진"};
    string age[] = { "28|", "31|", "25|", "30|", "25|", "26|", "25|", "26|", "26|"};

    of << "  ----------------------- " << endl;
    of << setw(6) << "|Name" << setw(10) << "|" << setw(7) << "Age|" << endl;     // 출력 길이를 일시적으로 12로 지정한다.
    of << " |-----------------------| " << endl;     // 출력 길이를 일시적으로 12로 지정한다.
    //of << setw(8) << "|용준헌" << setw(8) << "|" << setw(10) << "28|" << endl;     // 출력 길이를 일시적으로 12로 지정한다.
    //of << setw(8) << "|김재성" << setw(8) << "|" << setw(10) << "31|" << endl;     // 출력 길이를 일시적으로 12로 지정한다.
    //of << setw(8) << "|김재민" << setw(8) << "|" << setw(10) << "25|" << endl;     // 출력 길이를 일시적으로 12로 지정한다.
    //of << setw(8) << "|성권문" << setw(8) << "|" << setw(10) << "30|" << endl;     // 출력 길이를 일시적으로 12로 지정한다.

    for (int i = 0; i < sizeof(str2) / sizeof(string); i++)
    {
        of << setw(8) << str2[i] << setw(8) << "|" << setw(10) << age[i] << endl;     // 출력 길이를 일시적으로 12로 지정한다.
    }

    of << "  ----------------------- " << endl;     // 출력 길이를 일시적으로 12로 지정한다.


    // 사용법은 표준 파일과 비슷하다.

    of.close();

    // 파일 입력은 ifstream을 이용한다.
    std::ifstream ifs;

    // is_open()으로 파일을 열었는지 확인할 수 있다.
    if (false == ifs.is_open())
    {
        // open()으로 파일을 열 수 있다.
        ifs.open("temp.txt");
    }

    std::string str;
    std::getline(ifs, str);
    std::cout << str << "\n";

    // eof()로 파일의 끝에 도달했는지 알 수 있다.
    if (ifs.eof())
    {
        std::cout << "파일의 끝에 도달함.\n";
    }

    cout << "  ----------------------- " << endl;
    cout << setw(6) << "|Name" << setw(10) << "|" << setw(10) << "Age|" << endl;     // 출력 길이를 일시적으로 12로 지정한다.
    cout << " |-----------------------| " << endl;     // 출력 길이를 일시적으로 12로 지정한다.
    for (int i = 0; i < 4; i++)
    {
        cout << setw(8) << str2[i] << setw(8) << "|" << setw(10) << age[i] << endl;     // 출력 길이를 일시적으로 12로 지정한다.
    }
    cout << "  ----------------------- " << endl;     // 출력 길이를 일시적으로 12로 지정한다.
}


