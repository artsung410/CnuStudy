#include <iostream>

int main()
{
    int itemCnt = 0;
    int money = 100;

    // 아이템을 산다.
    itemCnt++;
    money -= 10;
    printf("아이템을 구매했습니다. \n");
    printf("아이템 개수: %d\n", itemCnt);
    printf(" 잔액 %d\n", money);
}
