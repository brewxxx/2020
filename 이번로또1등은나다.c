#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int winning_number=0, i, answer;
	printf("**되자되자 로또 1등 당첨되자!!!!!**\n");
	printf("공을 뽑으시겠습니까?\n");
	scanf_s("%d", &answer);

	for (i = 1; i <= 6; i++)
	{
		winning_number = rand() % 45;
		if (winning_number == 0) winning_number = 45;
		printf("The winning number is %d!!\n",winning_number);
	}
	return 0;
}