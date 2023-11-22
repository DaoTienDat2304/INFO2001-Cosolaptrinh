#include <stdio.h>
	int main (){
	int N, i, Sum = 0;
	printf ("Nhap mot so tu nhien N:");
	scanf ("%d", &N);
    for (i = 1; i <= 2 * N; i += 2){
	Sum += i;
}
	printf ( "Tong cua %d so le dau tien la %d\n", N, Sum);
	return 0; 
	} 
