#include "stdafx.h"

const char GOODS_LIST_PATH[30] = "Data\\goods_list.txt";

//��ʼ����Ʒ���� ������ͷ��������
GoodsList InitGoodsList()
{
	GoodsList head = (GoodsList)malloc(sizeof(struct GoodsListNode));
	head->next = NULL;

	return head;
}

void DeleteGoodsList(GoodsList head)
{
	GoodsList next;

	while (head) {
		next = head->next;
		free(head);
		head = next;
	}
}

//������Ʒ��������ĳ�ֲ���
void TraverseGoodsList(GoodsList head, void(*Fun)(Goods *))
{
	GoodsList p = head->next;
	while (p) {
		Fun(&p->goods);
		p = p->next;
	}
}


//���һ����Ʒ����Ϣ
void DisplayGoodsInfo(Goods *goods)
{
	printf("%-5d %-12s %-6.2f %-6.2f %-15s %-5d\n", goods->id, goods->name, goods->buying_price, goods->selling_price,
																goods->manufacturer, goods->quantity);
}

//��ʾһ����Ʒ������Ϣ
void DisplayBasicGoodsInfo(Goods *goods)
{
	printf("%-5d %-12s %-6.2f %-15s %-5d\n", goods->id, goods->name, goods->selling_price, goods->manufacturer, goods->quantity);
}


//����Ʒ���������һ����Ʒ��Ϣ��ԭ�д���Ʒ�����ϲ�������1
//ԭû�У�������ĩβ��ӣ�����0
int AddGoodsToList(GoodsList head, Goods goods)
{
	int id = goods.id;
	GoodsList p = head->next;
	while (p) {
		if (p->goods.id == id) {
			p->goods.quantity += goods.quantity;
			return 1;
		}
		p = p->next;
	}
	
	GoodsList newNode = (GoodsList)malloc(sizeof(struct GoodsListNode));
	newNode->goods = goods;
	newNode->next = head->next;
	head->next = newNode;
	
	return 0;
}


//����Ʒ�����в�����Ʒ���Ϊid����Ʒ������Ʒ��������quantity
//�ɹ�����1����Ʒ������������0���޴�id��Ʒ����-1
int ReduceGoodsQuantity(GoodsList head, int id, int quantity)
{
	GoodsList p = head->next;
	while (p) {
		if (p->goods.id == id) {
			if (p->goods.quantity < quantity)
				return 0;
			p->goods.quantity -= quantity;
			return 1;
		}
		p = p->next;
	}
	return -1;
}


//����Ʒ�����в�����Ʒ���Ϊid����Ʒ������Ʒ��������quantity
//�ɹ�����1���޴�id��Ʒ����-1
int IncreaseGoodsQuantity(GoodsList head, int id, int quantity)
{
	GoodsList p = head->next;
	while (p) {
		if (p->goods.id == id) {
			p->goods.quantity += quantity;
			return 1;
		}
		p = p->next;
	}
	return -1;
}


//�����Ʒ������Ϊ����Ϊ0����Ʒ
void RemoveZeroQuantityGoods(GoodsList head)
{
	GoodsList pre = head;
	GoodsList p = head->next;
	while (p) {
		if (p->goods.quantity == 0) {
			GoodsList tmp = p;
			pre->next = tmp->next;
			free(tmp);
			p = pre->next;
		}
		else {
			p = p->next;
			pre = pre->next;
		}
	}
}


//���ļ��е�����Ʒ����
void ImportGoodsFromFile(GoodsList head, FILE *fp)
{
	Goods goods;
	while (!feof(fp))
	{
		fscanf(fp, "%d %s %lf %lf %s %d\n", &goods.id, goods.name, &goods.buying_price,
			&goods.selling_price, goods.manufacturer, &goods.quantity);
		AddGoodsToList(head, goods);
	}
	fclose(fp);
}

FILE* OpenGoodsFile(char *mod)
{
	return fopen(GOODS_LIST_PATH, mod);
}

//��ϵͳ����Ʒ���ݵ������ļ�
void ExportGoodsToFile(GoodsList head, FILE *fp)
{
	Goods goods;
	GoodsList p = head->next;
	while (p) {
		goods = p->goods;
		fprintf(fp, "%d %s %.2lf %.2lf %s %d\n", goods.id, goods.name, goods.buying_price,
			goods.selling_price, goods.manufacturer, goods.quantity);
		p = p->next;
	}
	fclose(fp);
}


//��ID����Ʒ�����в�����Ʒ�����ҵ�������������λ�ã����򷵻�NULL
GoodsList FindGoodsByID(GoodsList head, int id)
{
	if (id < 0) return NULL;

	GoodsList p = head->next;
	while (p) {
		if (p->goods.id == id)
			return p;
		p = p->next;
	}
	
	return NULL;
}


