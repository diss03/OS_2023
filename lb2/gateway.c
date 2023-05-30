#include <stdio.h>
int main ( int argc, char *argv [] )
{
	if (argc>1) {
		FILE *f;
		f=fopen(argv[1],"r");
		if (f) {
			char str[64];
			while ( fgets(str, sizeof(str), f) ) {
				printf("%s", str);
			}
			fclose(f);
		}
		else	printf("%s: File %s couldn't be open\n", argv[0], argv[1]);
	}
	else printf("%s: File was not specified\n", argv[0]);
	return 0;
}

