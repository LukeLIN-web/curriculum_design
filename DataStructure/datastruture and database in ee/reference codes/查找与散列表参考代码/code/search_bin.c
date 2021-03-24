int search_bin(StaticSearchTable st, KeyType key) {
	//在有序表中折半查找其关键字等于key的数据元素，设关键字按升序排列 
	//若找到，则返回该元素在表中的位置，否则返回0
	int low = 1, high = st.length, mid;	//设置区间初值
	while(low <= high) {
		mid = (low + high)/2;
		if(st.elem[mid].key == key)
			return mid;	//找到待查元素
		else if(st.elem[mid].key > key)
			high = mid - 1;	//继续在前半区间进行查找 
		else
			low = mid + 1;	//继续在后半区间进行查找 
	} 
	return 0	//表中不存在待查元素 
}
