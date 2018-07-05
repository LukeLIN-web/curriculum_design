#include "stdafx.h"

const char GOODS_SALES_RECORD_PATH[50] = "Data\\sold_goods_list.txt";

//��ʼ�����ۼ�¼�ѱ䣬������ͷ��������
RecordsList InitRecordsList()
{
	RecordsList head = (RecordsList)malloc(sizeof(struct RecordsListNode));
	head->next = NULL;

	return head;
}


void DeleteRecordsList(RecordsList head)
{
	GoodsList next;

	while (head) {
		next = head->next;
		free(head);
		head = next;
	}
}

//�������ۼ�¼��������ĳ�ֲ���
void TraverseRecordsList(RecordsList head,void(*Fun)(SoldGoodsRecord *))
{
	RecordsList p = head->next;
	while (p) {
		Fun(&p->record);
		p = p->next;
	}
}

//���һ�����ۼ�¼����Ϣ
void DisplayARecordInfo(SoldGoodsRecord *record)
{
	printf("%d %s %.2f %.2f %d %d-%d-%d-%d:%d:%d\n", record->id, record->name, record->buying_price,
		record->selling_price, record->sold_quantity, record->date.year, record->date.month, record->date.day,
		record->date.hour, record->date.min, record->date.second);
}

//�����ۼ�¼����β������һ�����ۼ�¼��Ϣ
void AddRecordToList(RecordsList head, SoldGoodsRecord record)
{
	RecordsList newNode = (RecordsList)malloc(sizeof(struct RecordsListNode));
	newNode->record = record;
	newNode->next = NULL;

	RecordsList p = head;
	while (p->next) p = p->next;
	
	p->next = newNode;
}

FILE* OpenRecordsFile(char *mod)
{
	return fopen(GOODS_SALES_RECORD_PATH, mod);
}

//���ļ���������һ�����ۼ�¼����
void AppendARecordToFile(SoldGoodsRecord record, FILE *fp)
{
	fprintf(fp, "%d %s %.2f %.2f %d %d-%d-%d-%d:%d:%d\n", record.id, record.name, record.buying_price,
		record.selling_price, record.sold_quantity, record.date.year, record.date.month, record.date.day,
		record.date.hour, record.date.min, record.date.second);

	fclose(fp);

}

//���ļ��е������ۼ�¼����
void ImportRecordsFromFile(RecordsList head, FILE *fp)
{
	SoldGoodsRecord record;
	while (!feof(fp))
	{
		fscanf(fp, "%d %s %lf %lf %d %d-%d-%d-%d:%d:%d\n", &record.id, record.name, &record.buying_price,
			&record.selling_price, &record.sold_quantity, &record.date.year, &record.date.month,& record.date.day,
			&record.date.hour, &record.date.min, &record.date.second);
		AddRecordToList(head, record);
	}
	
	fclose(fp);
}

//��ȡ����ʱ��
SoldDate GetNowDate()
{
	SoldDate date;
	time_t now;
	struct tm *tm_now;
	time(&now);
	tm_now = localtime(&now);

	date.year = tm_now->tm_year + 1900;
	date.month = tm_now->tm_mon + 1;
	date.day = tm_now->tm_mday;
	date.hour = tm_now->tm_hour;
	date.min = tm_now->tm_min;
	date.second = tm_now->tm_sec;

	return date;
}


