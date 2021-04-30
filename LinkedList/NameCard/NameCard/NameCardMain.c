#include <stdio.h>
#include "NameCard.h"
#include "ArrayList.h"

int main()
{
	List list;
	NameCard* pcard;
	ListInit(&list);

	pcard = MakeNameCard("이진수", "010-4018-8762");
	LInsert(&list, pcard);
	pcard = MakeNameCard("심진수", "010-8888-8762");
	LInsert(&list, pcard);
	pcard = MakeNameCard("사진수", "010-1234-8762");
	LInsert(&list, pcard);

	printf("%d", LCount(&list));
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "이진수")) ShowNameCardInfo(pcard);
		while (LNext(&list, &pcard))
		{
			if (!NameCompare(pcard, "이진수"))
			{
				ShowNameCardInfo(pcard);
				break;
			}
		}
	}
	return 0;
}