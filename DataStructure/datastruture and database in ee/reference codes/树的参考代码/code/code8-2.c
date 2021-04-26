static void list_dir(DirectoryOrFile D, int depth) {
	if(D is a legitimate entry) {	 /* D合法 */ 
		print_name(D, depth);
		if(D is a directory)	/* D是一个目录 */
			for each child, C, of D
				list_dir(C, depth-1);
	}
}

void list_directory(DirectoryOrFile D) {
	list_dir(D, 0);
}