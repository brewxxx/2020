#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int winning_number=0, i, answer;
	printf("**���ڵ��� �ζ� 1�� ��÷����!!!!!**\n");
	printf("���� �����ðڽ��ϱ�?\n");
	scanf_s("%d", &answer);

	for (i = 1; i <= 6; i++)
	{
		winning_number = rand() % 45;
		if (winning_number == 0) winning_number = 45;
		printf("The winning number is %d!!\n",winning_number);
	}
	return 0;
}