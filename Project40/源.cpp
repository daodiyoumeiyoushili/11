#include "calendar.h"
int IsLeapYear(int year)   //�ж�һ���Ƿ�Ϊ����
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int dayOfTheMonth(int year, int month)	//�ж�ĳ���ĳ�·��ж�����
{
	int day = -1;

	if (1 == month || 3 == month || 5 == month || 7 == month || 8 == month || 10 == month || 12 == month)
	{
		day = 31;
	}
	else if (4 == month || 6 == month || 9 == month || 11 == month)
	{
		day = 30;
	}
	else
	{
		if (IsLeapYear(year))
		{
			day = 29;
		}
		else
		{
			day = 28;
		}
	}

	return day;
}

int dayOfcurYearFrom1900(int year, int month)	//����1900�굽Ŀǰ�·ݣ���������Ҫ��ӡ�����·ݣ���������������
{
	int day = 0;
	int i = 0;

	for (i = 1900; i < year; ++i)
	{
		if (IsLeapYear(i))
		{
			day += 366;
		}
		else
		{
			day += 365;
		}
	}
	for (i = 1; i < month; ++i)
	{
		day += dayOfTheMonth(year, i);
	}
	return day;
}

int weekdayOfFirstDay(int year, int month)	//�ڼ�����������󣬼���month�ĵ�һ�����ܼ�������������0Ϊ��ĩ��
{
	return (dayOfcurYearFrom1900(year, month) + 1) % 7;
}

void displayMonth(int year, int month)		//������ʾģ��
{
	char week[7][10] = { "Sun", "Mon", "Tue", "Wen", "Thu", "Fri", "Sat" };
	int day = 0;
	int i = 0;

	day = weekdayOfFirstDay(year, month);

	for (i = 0; i < 7; ++i)
	{
		printf("  %s  ", week[i]);
	}
	putchar('\n');
	for (i = 0; i < day; ++i)
	{
		printf("       ");
	}
	for (i = 1; i <= dayOfTheMonth(year, month); ++i)
	{
		printf("  %3d  ", i);
		if ((day + i) % 7 == 0)
		{
			putchar('\n');
		}
	}

	putchar('\n');
	return;
}
int main(int argc, const char *argv[])
{

	int year, month;

	scanf_s("%d%d", &year, &month);
	displayMonth(year, month);
	return 0;
}
