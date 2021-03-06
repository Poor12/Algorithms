//sunday算法
int sunday(string p, string t) {
	int len1 = p.length();
	int len2 = t.length();
	const char *tt = t.c_str();
	int charStep[256];
	for (int i = 0;i < 256;++i)
		charStep[i] = -1;
	for (int i = 0;i < len1;++i)
		charStep[p[i]] = i;
	for (int i = 0;i <= len2 - len1;) {
		int j = 0;
		while (j<len1)
		{
			if (t[i] == p[j]) {
				++i;
				++j;
			}
			else {
				const char *pp = tt + i + len1 - j;//位于t字符串中位于p字符串后的位置
				if (charStep[(int)*pp] == -1)
					i = pp - tt + 1;
				else {
					i = pp - charStep[(int)*pp] - tt;
				}
				break;
			}
		}
		if (j == len1)
			return i - len1;
	}
	return -1;
}

int main() {
	cout << sunday("asa","sasassasasa");
}