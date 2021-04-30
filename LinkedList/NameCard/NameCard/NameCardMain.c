#include <stdio.h>
#include "NameCard.h"
#include "ArrayList.h"

int main()
{
	List list;
	NameCard* pcard;
	ListInit(&list);

	pcard = MakeNameCard("������", "010-4018-8762");
	LInsert(&list, pcard);
	pcard = MakeNameCard("������", "010-8888-8762");
	LInsert(&list, pcard);
	pcard = MakeNameCard("������", "010-1234-8762");
	LInsert(&list, pcard);

	printf("%d", LCount(&list));
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "������")) ShowNameCardInfo(pcard);
		while (LNext(&list, &pcard))
		{
			if (!NameCompare(pcard, "������"))
			{
				ShowNameCardInfo(pcard);
				break;
			}
		}
	}
	return 0;
}