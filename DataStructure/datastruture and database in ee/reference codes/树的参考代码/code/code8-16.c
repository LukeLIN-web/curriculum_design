int calculate(BiTreeNode *node, double *rst) {
    double l = 0, r = 0;//l、r分别存放左右子树所代表的字表达式的值
    if(!node) {
		*rst = 0;
		return 1;
	}
    if(node->children[BITREE_NODE_LEFT] == NULL && node->children[BITREE_NODE_RIGHT] == NULL) {
		*rst = atof(node->value);
		return 1;
	} 
	else {
	    //先计算左子树和右子树
        if(calculate(node->children[BITREE_NODE_LEFT], &l))
            if(calculate(node->children[BITREE_NODE_RIGHT], &r)) {
                switch(((char *)node->value)[0]) {
                    case '+' :
						*rst = l+r;
						break;
                    case '-' :
						*rst = l-r;
						break;
                    case '*' :
						*rst = l*r;
						break;
                    case '/' :
						if(r == 0) {
							printf("Divided by 0!\n");	//告警,除数为0
							return 0;
						} 
						else {
							*rst = l/r;
							break;
						}
                    default :
						return 0;
                }
                return 1;
            }
        return 0;
    }
}