#include <forward_list> // std::forward_list를 쓰기 위한 헤더
#include <iostream>

using namespace std;

// 단일연결 리스트
typedef struct Node {
    int data; // 데이터 저장 공간
    struct Node* next; // 다음 노드의 연결을 위한 포인터
};

// 이중연결 리스트
typedef struct Node2 {
    struct Node2* prev; // 이전 노드의 연결을 위한 포인터
    int data; // 데이터 저장 공간
    struct Node2* next; // 다음 노드의 연결을 위한 포인터
};

int main()
{
    Node* head = new Node;
    Node* cur = new Node;
    Node* tail = new Node;

    head->data = 1;
    cur->data = 2;
    tail->data = 3;

    head->next = cur;  cur->next = tail; tail->next = head;

    cout << "head가 가리키고 있는 cur의 주소는? : " << head->next << endl;
    cout << "cur가 가리키고 있는 tail의 주소는? : " << cur->next << endl;
    cout << "tail가 가리키고 있는 head의 주소는? : " << tail->next << endl;

    cout << "head의 주소는? : " << head << endl;
    cout << "cur의 주소는? : " << cur << endl;
    cout << "tail의 주소는? : " << tail << endl;

    cout << "head의 값은? : " << head->data << endl;
    cout << "cur의 값은? : " << cur->data << endl;
    cout << "tail의 값은? : " << tail->data << endl;
    
    //Node2* head2 = new Node;
    //Node2* cur2 = new Node;
    //Node2* tail2 = new Node;

    //std::forward_list<int> flist;

    //// 삽입
    //flist.push_front(1); // push_front() : 맨 앞에 삽입한다.
    //// flist{ 1 }
    //flist.insert_after(flist.begin(), 2); // insert_after(pos, value) : pos 뒤에 value를 삽입한다.
    //// flist{ 1, 2 }
    //flist.push_front(3); // flist { 3, 1, 2 }
    //flist.push_front(4); // flist { 3, 1, 2 }
    //flist.push_front(5); // flist { 3, 1, 2 }
    //flist.push_front(6); // flist { 3, 1, 2 }

    //for (auto i = flist.begin(); i != flist.end(); i++)
    //{
    //    std::cout << "[" << *i << "]";
    //}
    //// 반복자
    //std::forward_list<int>::iterator iter;
    //iter = flist.before_begin();

    //// [ ]->[3]->[1]->[2]->[ ]
    ////  ↑
    //iter = flist.begin();
    //// [ ]->[3]->[1]->[2]->[ ]
    ////       ↑
    //iter = flist.end();
    //// [ ]->[3]->[1]->[2]->[ ]
    ////                      ↑

    //// 삭제
    //flist.pop_front(); // pop_front() : 첫 번째 원소를 삭제한다.
    //// flist{ 1, 2 };
    //flist.erase_after(flist.begin()); // erase_after(pos) : pos 다음 원소를 삭제한다.
    //// flist{ 1 }
    //flist.clear(); // clear() : 컨테이너를 전부 비운다.
    //// flist{ }

    //// 크기
    //if (flist.empty()) // empty() : 비었는지 확인한다.
    //{
    //    std::cout << "flist는 비었음.\n";
    //}
    //// 주의! 다른 컨테이너와 다르게 size()는 없음

    //// 아래처럼 초기화 가능
    //std::forward_list<int> flist2 = { 1, 2, 3, 4, 5 };

    //// 읽기
    //std::cout << "flist2.front() : " << flist2.front() << "\n"; // front() : 첫 번째 원소를 반환한다.


    //// 비교 : 다른 컨테이너와 마찬가지로 == / != / > / >= / < / <= 지원
    //flist = flist2;
    //if (flist == flist2)
    //{
    //    std::cout << "flist는 flist2와 같다.\n";
    //}

    //// C++17부터는 원소 타입을 적지 않아도 알아서 추론한다.
    ////std::forward_list flist3 = { 1, 2, 3, 4, 5 };

    return 0;
}
