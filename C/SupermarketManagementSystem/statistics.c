#include "stdafx.h"

typedef struct {
	int id;
	char name[MAXGOODSNAME];
	int cnt;
	double earnings;
	UT_hash_handle hh;

} CountStatistics;

//�Ƚ��������ڴ�С��a��b��ȷ���0��a<b����-1��a>b����1
int CompareDate(SoldDate a, SoldDate b)
{
	int t1 = a.year * 10000 + a.month * 100 + a.day;
	int t2 = b.year * 10000 + b.month * 100 + b.day;
	if (t1 != t2) return t1 < t2 ? -1 : 1;
	t1 = a.hour * 3600 + a.min * 60 + a.second;
	t2 = b.hour * 3600 + b.min * 60 + b.second;
	if (t1 != t2) return t1 < t2 ? -1 : 1;
	return 0;
}

void SoldStatisticsByDate(RecordsList head, SoldDate start, SoldDate end, int min_sold_cnt, int min_earnings)
{
	CountStatistics *s, *goods = NULL;
	RecordsList p = head->next;

	while (p) {
		if (CompareDate(p->record.date, start) >= 0 && CompareDate(p->record.date, end) <= 0) {
			HASH_FIND_INT(goods, &p->record.id, s);
			if (s) {
				s->cnt += p->record.sold_quantity;
				s->earnings += (p->record.selling_price - p->record.buying_price)
													*  p->record.sold_quantity;
			}
			else {
				s = (CountStatistics*)malloc(sizeof(CountStatistics));
				s->id = p->record.id;
				strcpy(s->name, p->record.name);
				s->cnt = p->record.sold_quantity;
				s->earnings = (p->record.selling_price - p->record.buying_price)
													*  p->record.sold_quantity;
				HASH_ADD_INT(goods, id, s);
			}
		}

		p = p->next;
	}

	double total_earnings = 0;
	int total_goods_cnt = 0;

	printf("----------------------------------------\n");
	printf("%-5s %-12s %-6s %-6s\n", "ID", "����", "����", "����");
	for (s = goods; s != NULL; s = (CountStatistics*)(s->hh.next)) {
		if (s->cnt >= min_sold_cnt && s->earnings >= min_earnings) {
			total_earnings += s->earnings;
			total_goods_cnt++;
			printf("%-5d %-12s %-6d %-6.2f\n", s->id, s->name, s->cnt, s->earnings);
		}
	}

	printf("\n����Ʒ��:%d  ������:%.2fԪ\n", total_goods_cnt, total_earnings);
	printf("----------------------------------------\n");
}