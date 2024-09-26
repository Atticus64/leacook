
int len(char* str) {
	int i = 0;
	while(str[i] != '\0') {
		i++;
	}

	return i;
}

void cat(char* str1, char* str2) {
	int val_len = len(str1);
	int i = 0;
	str1 += val_len;

	while (*str2 != '\0') {
		*str1 = *str2;
		str1++;
		str2++;
	}
}
