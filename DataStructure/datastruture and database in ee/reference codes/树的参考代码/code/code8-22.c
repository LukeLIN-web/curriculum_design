void huffman_code(BiTree *huffmantree, BiTreeNode **nodes, int len, char **hc) {
	char *cd;
	int start, i;	
	BiTreeNode *node;
	cd = (char *)malloc(len*sizeof(char));	/* 分配求编码的工作空间 */ 
	cd[len-1] = '\0';	/* 编码结束符 */
	for(i = 0; i < len; i++) {	/* 逐个字符求哈夫曼编码 */ 
		start = len-1; /* 编码结束符位置 */
		for(node = nodes[i]; node->parent != NULL; node = node->parent) {	/* 从叶子到根逆向求编码 */
			if(node->parent->children[BITREE_NODE_LEFT] == node)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		} 
		hc[i] = (char *)malloc((len-start)*sizeof(char));	/* 为第i个字符编码分配空间 */
		strcpy(hc[i], &cd[start]);	/* 从cd复制编码到hc */
	}
	free(cd);	/* 释放工作空间 */
}