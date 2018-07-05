#include "stdafx.h"

//�ж��Ƿ�Ϊ����Ա�˻����޷����ļ�����-1���Ƿ���1���񷵻�0
int IsSalesmanAccount(char *account, char *password)
{
	FILE *fp = fopen("Data\\user.dat", "rb");

	if (fp == NULL)
		return -1;

	fseek(fp, 0, SEEK_END);
	int size = ftell(fp) / sizeof(UserAccount);
	fseek(fp, 0, SEEK_SET);

	UserAccount* user = (UserAccount*)malloc(size * sizeof(UserAccount));

	for (int i = 0; i < size; i++) {
		fread(user + i, sizeof(UserAccount), 1, fp);
		if (strcmp(account, user[i].account) == 0 && strcmp(password, user[i].password) == 0
			&& user[i].permission_level == 0)
			return 1;
	}

	free(user);
	fclose(fp);

	return 0;
}

void DisplaySoldGoods(GoodsList head)
{
	printf("------------------------------------------------\n");
	printf("%-5s %-12s %-6s %-15s %-5s\n", "ID", "����", "�ۼ�", "��������", "����");
	TraverseGoodsList(head, DisplayBasicGoodsInfo);
	printf("------------------------------------------------\n");
}


//������Ʒ����������Ʒ�����ۼ�¼
void SoldGoods(GoodsList head)
{
	int id, cnt;
	GoodsList found_goods;
	while (1) {
		system("cls");
		DisplaySoldGoods(head);
		printf("\n��������۵���ƷID (����-1�˳�)\n>");
		scanf("%d", &id);

		if (id < 0) break;
		
		found_goods = FindGoodsByID(head, id);
		if (found_goods) {
			DisplayBasicGoodsInfo(&found_goods->goods);
			printf("������������\n>");
			scanf("%d", &cnt);
			if (cnt <= 0) {
				printf("��Ʒ��������\n");
				system("pause");
				continue;
			}
			else {
				FILE *goods_fp = OpenGoodsFile("w");
				FILE *records_fp = OpenRecordsFile("a");
				if (goods_fp && records_fp) {
					if (!ReduceGoodsQuantity(head, id, cnt)) {
						printf("����Ʒ��治��\n");
						system("pause");;
						continue;
					}
					ExportGoodsToFile(head, goods_fp);
					
					SoldGoodsRecord record;
					record.id = found_goods->goods.id;
					strcpy(record.name, found_goods->goods.name);
					record.selling_price = found_goods->goods.selling_price;
					record.sold_quantity = cnt;
					record.buying_price = found_goods->goods.buying_price;
					record.date = GetNowDate();

					AppendARecordToFile(record, records_fp);
					printf("���۳ɹ�\n");
					system("pause");
					continue;
				}
				else {
					if (goods_fp) fclose(goods_fp);
					if (records_fp) fclose(records_fp);
					printf("����ϵͳ����ʧ��\n");
					system("pause");
					break;
				}
					
			}
		}
		else {
			printf("�޴���Ʒ\n");
			system("pause");
			continue;
		}
	}
	
}


void SalesmanInitMenu()
{
	system("cls");
	
	int op = -1;

	printf("1) ������Ʒ\n");
	printf("2) ��ѯ��Ʒ\n");
	printf("0) �˳���½\n");

	printf(">> ");
	scanf("%d", &op);

	GoodsList head = InitGoodsList();
	ImportGoodsFromFile(head, OpenGoodsFile("r"));
	if (op == 1) {
		SoldGoods(head);
		DeleteGoodsList(head);
		SalesmanInitMenu();
	}
	else if (op == 2)
		SalesmanLookUpGoods(head);
	else {
		DeleteGoodsList(head);
		LogIn();
	}
		
}


void SalesmanLookUpGoods(GoodsList head)
{
	system("cls");

	if (head->next == NULL) {
		printf("���Ϊ��\n");
		system("pause");
		SalesmanInitMenu();
	}

	int op = -1;

	printf("1) ����Ʒ����ѯ\n");
	printf("2) ���������Ҳ�ѯ\n");
	printf("3) �ۺϲ�ѯ\n");
	printf("0) �����ϼ�\n");

	scanf("%d", &op);

	if (op == 1)
		SalesmanLookUpGoodsByName(head);
	else if (op == 2)
		SalesmanLookUpGoodsByManufacturer(head);
	else if (op == 3)
		SalesmanLookUpGoodsByNameAndManufacturer(head);
	else {
		SalesmanInitMenu();
	}
}

void ShowQueriedGoodsListToSalesman(GoodsList queried_goods)
{
	printf("----------------------------------------------------\n");
	printf("%-5s %-12s %-6s %-15s %-5s\n", "ID", "����", "�ۼ�", "��������", "����");
	TraverseGoodsList(queried_goods, DisplayBasicGoodsInfo);
	printf("----------------------------------------------------\n");
}

void SalesmanLookUpGoodsByName(GoodsList head)
{
	char goods_name_prefix[MAXGOODSNAME] = { 0 };
	//char manufacturer_prefix[MAXMANUFACTURERNAME] = { 0 };

	printf("������Ʒ���ƻ�����ǰ׺\n>> ");
	scanf("%s", goods_name_prefix);
	GoodsList queried_goods = QueryGoodsByName(head, goods_name_prefix);
	ShowQueriedGoodsListToSalesman(queried_goods);
	DeleteGoodsList(queried_goods);
	system("pause");
	SalesmanLookUpGoods(head);
}

void SalesmanLookUpGoodsByManufacturer(GoodsList head)
{
	char manufacturer_prefix[MAXMANUFACTURERNAME] = { 0 };

	printf("������Ʒ���������ƻ�����������ǰ׺\n>> ");
	scanf("%s", manufacturer_prefix);
	GoodsList queried_goods = QueryGoodsByManufacturer(head, manufacturer_prefix);
	ShowQueriedGoodsListToSalesman(queried_goods);
	DeleteGoodsList(queried_goods);
	system("pause");
	SalesmanLookUpGoods(head);
}

void SalesmanLookUpGoodsByNameAndManufacturer(GoodsList head)
{
	char goods_name_prefix[MAXGOODSNAME] = { 0 };
	char manufacturer_prefix[MAXMANUFACTURERNAME] = { 0 };

	printf("������Ʒ���ƻ�����ǰ׺\n>> ");
	scanf("%s", goods_name_prefix);
	printf("������Ʒ���������ƻ�����������ǰ׺\n>> ");
	scanf("%s", manufacturer_prefix);
	GoodsList queried_goods = QueryGoodsByNameAndManufacturer(head, goods_name_prefix, manufacturer_prefix);
	ShowQueriedGoodsListToSalesman(queried_goods);
	DeleteGoodsList(queried_goods);
	system("pause");
	SalesmanLookUpGoods(head);
}

