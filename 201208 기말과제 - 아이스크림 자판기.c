#include <stdio.h>
#include <stdlib.h>
int recommend(void);
int main(void)
{
	int base = 1, topping = 1, set=1, price=0, payment,offer,answer=1;
	char receipt=1;

	printf("어서오세요. 아이스크림 자판기입니다.\n\n");
	do {
		if((answer != 2) && (answer != 1))
			printf("1 또는 2을 입력해주세요.\n");
		
		printf("가격에 따른 메뉴를 추천받으시겠습니까?\n");
		printf("************************************************************************\n");
		printf("** 메뉴 추천은 제시한 가격을 넘지 않게 토핑을 조합해드리는 서비스이며 **\n");
		printf("** 아이스크림의 기본맛은 선택 가능합니다.                             **\n");
		printf("** (메뉴 추천의 경우 토핑은 최대 두가지로 제한됩니다.)                **\n");
		printf("************************************************************************\n");
		printf("추천을 받으시려면 1을, 직접 선택하시려면 2을 입력해주세요.\n");
		scanf_s("%d", &answer);
	} while ((answer != 2) && (answer != 1)); //1,2외의 숫자를 입력할 경우를 방지
		
	menu_1:printf("------------------------------------------------\n");
		printf("   원하는 아이스크림 맛의 번호를 입력해주세요   \n");
		printf("------------------------------------------------\n");
		printf(" 1.바닐라 2.초콜릿 3.요거트 4.녹차 5.딸기 6.체리\n");
		scanf_s("%d", &base);
		price = 1500; // 아이스크림의 기본 가격은 1500원
		switch (base) // 선택한 맛을 보여주기 위해 switch문 사용
		{
		case 1:
			printf("바닐라맛을 선택하셨습니다.\n\n");
			break;
		case 2:
			printf("초콜릿맛을 선택했습니다.\n\n");
			break;
		case 3:
			printf("요거트맛을 선택했습니다.\n\n");
			break;
		case 4:
			printf("녹차맛을 선택했습니다.\n\n");
			break;
		case 5:
			printf("딸기맛을 선택했습니다.\n\n");
			break;
		case 6:
			printf("체리맛을 선택했습니다.\n\n");
			break;
		default:
			printf("입력한 번호가 목록에 없습니다.\n\n"); // 1~6외의 숫자 입력 방지
			goto menu_1; 
		}
		if (answer == 1) // 메뉴 추천을 선택한 경우 아이스크림 맛을 고른 후 토핑 조합을 추천받는 것이므로 menu_1 뒤에 if문을 배치
		{
			price = recommend(); // 메뉴를 추천해주는 recommend 함수로 이동
			goto menu_3;
		}
		
	menu_2:
			printf("------------------------------------------------\n");
			printf("       원하는 토핑의 번호를 입력해주세요        \n");
			printf("------------------------------------------------\n");
			printf("   1.치즈케이크 -- 800원 2.초코볼 -- 300원\n   3.오레오쿠키 -- 450원 4.시리얼 -- 250원\n   5.선택안함\n");
			scanf_s("%d", &topping);
			switch (topping) // 선택한 토핑을 보여주기 위해 switch문 사용
			{
			case 1:
				printf("치즈케이크 토핑을 선택했습니다.\n\n");
				price += 800;
				break;
			case 2:
				printf("초코볼 토핑을 선택했습니다.\n\n");
				price += 300;
				break;
			case 3:
				printf("오레오쿠키 토핑을 선택했습니다.\n\n");
				price += 450;
				break;
			case 4:
				printf("시리얼 토핑을 선택했습니다.\n\n");
				price += 250;
				break;
			case 5:
				goto menu_3; // 토핑을 선택하지 않을 경우 추가 토핑 선택 여부를 묻지 않아도 되므로 바로 menu_3으로 넘어감
				break;
			default:
				printf("선택한 번호가 목록에 없습니다.\n\n"); // 1~5외의 숫자 입력 방지
				goto menu_2;
			}
		
		printf("추가 토핑을 선택하려면 1을, 선택하지 않으시려면 2를 입력해주세요.\n");
		scanf_s("%d", &answer);
		if (answer == 1)
			goto menu_2; // 추가 토핑을 선택할 경우 menu_2로 감
		printf("[현재 주문금액은 %d원입니다.]\n", price); // 현재까지의 아이스크림 + 토핑의 가격을 보여줌

	menu_3:printf("------------------------------------------------\n");
		printf("              콘/컵을 선택해주세요              \n");
		printf("------------------------------------------------\n");
		printf("       1.와플콘 2.초코와플콘(+200원) 3.컵\n");
		scanf_s("%d", &set);
		switch (set)
		{
		case 1:
			printf("와플콘을 선택하셨습니다.\n\n");
			break;
		case 2:
			printf("초코와플콘을 선택하셨습니다.\n\n");
			price += 200; // 초코와플콘을 선택하는 경우 추가 금액 200원을 주문 금액에 더해줌
			break;
		case 3:
			printf("컵을 선택하셨습니다.\n\n");
			break;
		default:
			printf("입력한 번호가 목록에 없습니다.\n\n"); 
			goto menu_3;
		}
		printf("[총 금액은 %d원입니다.]\n\n", price); // 결제 전 총 금액을 보여줌
		
			pay:printf("------------------------------------------------\n");
			printf("            결제방법을 선택해주세요             \n");
			printf("------------------------------------------------\n");
			printf("               1.현금 2.카드\n ");
			printf("(현금은 1000원권 지폐만 지불가능합니다.)\n"); // 거스름돈을 동전으로만 반환하기 위함
			scanf_s("%d", &payment);
			if (payment == 1) // 결제 방법으로 현금을 선택한 경우
			{ 
				if(price%1000!=0)
				printf("[거스름돈은 %d원입니다].\n", (1000-price % 1000)); // 주문금액을 1000으로 나눈 나머지를 이용해 거스름돈 계산
			}
			else if (payment == 2)  // 결제 방법으로 카드를 선택한 경우
			{
				printf("영수증을 출력하려면 y, 출력하지 않으려면 n을 입력해주세요.\n"); 
				while (getchar() != '\n') // 영수증 출력여부를 y/n으로 입력받기 위해 입력 유효성 검사 실시
					continue;
				while ((receipt = getchar()) != 'n')
				{
					if (receipt == 'y')
					{
						printf("영수증이 출력됩니다.\n\n");
						break;
					}
					else 
						printf("y 또는 n을 입력해주세요.\n"); // y,n 외의 문자 입력 방지
					while (getchar() != '\n')
						continue;
				}
				
			}
			else // 1,2외의 숫자 입력 방지
			{
				printf("입력한 문자가 목록에 없습니다.\n"); 
				goto pay;
			}
	printf("주문하신 아이스크림 나왔습니다.");
	return 0;
}

int recommend(void) //랜덤으로 메뉴를 추천하기 위한 recommend 함수
{
	int com, offer, i, answer;
	int price = 1500; // 아이스크림만 선택했을 경우 나오는 최소 금액

	printf("원하는 최대금액을 입력해주세요 =>"); 
	scanf_s("%d", &offer);
	printf("\n");
s_topping:
	for (i = 1; i <= 2; i++) // 랜덤 토핑 추가는 두 번까지 가능
	{
		com = rand() % 5;
		switch (com)
		{
		case 0:
			price += 800;
			break;
		case 1:
			price += 450;
			break;
		case 2:
			price += 300;
			break;
		case 3:
			price += 250;
			break;
		default:
			break;
		}
	}
	while (price > offer) // 사용자가 제시한 가격보다 아이스크림+토핑 가격이 더 높을 경우 price를 다시 1500으로 초기화하고 토핑을 다시 조합
	{
		price = 1500;
		goto s_topping;
	}
	if ((price - 1500) == 1600)
		printf("** 추천 토핑조합은 치즈케이크+치즈케이크 입니다 **\n");
	else if ((price - 1500) == 1250)
		printf("** 추천 토핑조합은 치즈케이크+오레오쿠키 입니다 **\n");
	else if ((price - 1500) == 1100)
		printf("** 추천 토핑조합은 치즈케이크+초코볼 입니다 **\n");
	else if ((price - 1500) == 1050)
		printf("** 추천 토핑조합은 치즈케이크+시리얼 입니다 **\n");
	else if ((price - 1500) == 900)
		printf("** 추천 토핑조합은 오레오쿠키+오레오쿠키 입니다 **\n");
	else if ((price - 1500) == 800)
		printf("** 추천 토핑조합은 치즈케이크 입니다 **\n");
	else if ((price - 1500) == 750)
		printf("** 추천 토핑조합은 오레오쿠키+초코볼 입니다 **\n");
	else if ((price - 1500) == 700)
		printf("** 추천 토핑조합은 오레오쿠키+시리얼 입니다 **\n");
	else if ((price - 1500) == 600)
		printf("** 추천 토핑조합은 초코볼+초코볼 입니다 **\n");
	else if ((price - 1500) == 550)
		printf("** 추천 토핑조합은 초코볼+시리얼 입니다 **\n");
	else if ((price - 1500) == 500)
		printf("** 추천 토핑조합은 시리얼+시리얼 입니다 **\n");
	else if ((price - 1500) == 450)
		printf("** 추천 토핑조합은 오레오쿠키 입니다 **\n");
	else if ((price - 1500) == 300)
		printf("** 추천 토핑조합은 초코볼 입니다 **\n");
	else
		printf("** 추천 토핑조합은 시리얼 입니다 **\n");
	printf("================================================\n");
	printf("       추천 토핑조합을 선택하시겠습니까?\n");
	printf("================================================\n");
	printf("               1.예 2.아니오\n");
	scanf_s("%d", &answer);
	while ((answer != 1) && (answer != 2))
	{
		printf("1 또는 2를 입력해주세요.\n"); // 1,2외의 숫자 입력 방지
		scanf_s("%d", &answer);
	}
		if (answer != 1) // 사용자가 추천 토핑조합을 선택하지 않을 경우 다시 토핑 조합 
			goto s_topping;

	if (answer != 2) printf("추천조합의 금액은 %d원입니다.\n", price); // 사용자가 선택한 토핑 조합 + 아이스크림 가격을 보여줌
	
	return price; // recommend 함수의 리턴값으로 price 를 반환
}