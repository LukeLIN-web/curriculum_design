/* 如果listentry是表中的最后一个结点，返回非零值 */
int slist_is_last(SListEntry *listentry){
    return listentry->next == NULL;
}