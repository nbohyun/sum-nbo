#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]){
uint32_t n, n1, n2, sum;

FILE* fp = fopen(argv[1], "r");
FILE* fp1 = fopen(argv[2], "r");
FILE* fp2 = fopen(argv[3], "r");
    
    if (!fp || !fp1 || !fp2){
            perror("file open fail.");
	    if (fp) fclose(fp);
	    if (fp1) fclose(fp1);
	    if (fp2) fclose(fp2);
            return 0;
    }

    if (fread(&n, 1, 4, fp) != 4 ||
	fread(&n1, 1, 4, fp1) != 4 ||
	fread(&n2, 1, 4, fp2)	!= 4){
            perror("file read fail.");
            fclose(fp);
	    fclose(fp1);
	    fclose(fp2);
            return 1;	
    }

    fread(&n, 1, 4, fp);
    n = ntohl(n);
    fread(&n1, 1, 4, fp1);
    n1 = ntohl(n1);
    fread(&n2, 1, 4, fp2);
    n2 = ntohl(n2);

    sum = n + n1 +n2;

    printf("%u(0x%08x) + %u(0x%08x) + %u(0x%08x) = %u(0x%08x)\n ", n, n, n1, n1, n2, n2, sum, sum);

    fclose(fp);
    fclose(fp1);
    fclose(fp2);

    return 0;
}
