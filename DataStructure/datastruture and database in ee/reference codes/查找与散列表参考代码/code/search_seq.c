int search_seq(StaticSearchTable st, KeyType key) {
	//在顺序表st中顺序查找其关键字等于key的数据元素。若找到，返回该元素在表中的位置，查找不成功，返回0 
	st.elem[0].key = key;	//0号单元作为监视哨 
	for(i = st.length; st.elem[i].key != key; i--);	//从后往前找 
	return i;	//找不到时，i为0 
}
