#include <stdio.h>      /* printf */
#include <stdarg.h>     /* va_list, va_start, va_arg, va_end */

void myprintf(const char* format, ...) // ...은 가변 인수다., 첫번째 인자를 pointer to const char로 받은 이유는 printf함수의 원형을 보면 매개변수가 pointer to const char형태이기 때문이다.
{
	// va_list : 함수로 전달되는 인수들은 스택에 저장되며 함수는 스택에서 인수를 꺼내 쓴다. 스택에 있는 가변 인수를 읽을 때 현재 읽고 있는 번지를 기억하기 위한 포인터 변수이다.
	va_list args; 

	// va_start : format의 사이즈를 구해서 가변인자의 시작주소까지 메모리상의 거리를 구해주는 매크로가 들어있다.따라서 함수 내부의 연산을 통해 가변인자 중 첫번째 인자의 주소를 가르켜 줄 수 있게된다.
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			char* str;
			int val;
			switch (*format)
			{

			case 'c':
				// va_arg(args, 인수타입) : args 위치에서 타입에 맞는 값을 읽어 리턴해주며 또한 ap를 다음 가변 인수 위치로 옮겨준다.
				val = va_arg(args, char);
				putchar(val);
				break;

			case 's':
				str = va_arg(args, char*);
				while (*str != NULL)
				{
					putchar(*str);
					str++;
				}
				break;

			case 'd':
				val = va_arg(args, int);
				int cnt = 0;
				char arrInt[100] = { 0 };
				if (val < 0)
				{
					putchar(45);
					val = val * (-1);
				}

				while (val > 0)
				{
					arrInt[cnt] = (val % 10) + 48;
					val /= 10;
					cnt++;
					// 54321, cnt = 5
				}
				
				while (cnt > 0)
				{
					cnt--; // 인덱스 4부터 접근하기위해서 cnt = 5 - 1을 해줘야함.
					putchar(arrInt[cnt]);
				}
				break;

			case '%':
				putchar(*format);
				break;

			default:
				break;
			}
		}

		else
		{
			putchar(*format);
		}
		format++;
	}
	// 가변인수를 다 읽은 후 args는 NULL을 가리키게 된다.
	va_end(args);
}


int main ()
{
	char* str1 = "artsung12341asdf;lkjas;dfl";
	char ch = 'k';

	int val = -12345;
	int val2 = 12345;
	myprintf("char형 : %c, 문자열 : %s, 양의정수 : %d 음의정수 : %d, 소수형 : ", ch, str1, val2, val);
	return 0;
}