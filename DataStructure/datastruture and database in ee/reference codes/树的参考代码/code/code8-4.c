static void size_directory(DirectoryOrFile D) {
	int totalsize;
	totalsize = 0;
	if(D is a legitimate entry) {
		totalsize = file_size(D);
		if(D is a directory)
			for each child, C, of D
				totalsize += size_dirctory(C);
	}
	return totalsize;
}