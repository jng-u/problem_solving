#include <stdio.h>

int main(){
	int length;
	scanf("%d", &length);

	int A[length], B[length];
	for(int i=0; i<length; i++){
		scanf("%d", &A[i]);
	}
	for(int i=0; i<length; i++){
		scanf("%d", &B[i]);
	}

	for(int n=0; n<length; n++){
		for(int i=0; i<length-1; i++){
			if(A[i]<A[i+1]){
				int tmp = A[i+1];
				A[i+1] = A[i];
				A[i] = tmp;
			}
			if(B[i]>B[i+1]){
				int tmp = B[i+1];
				B[i+1] = B[i];
				B[i] = tmp;
			}
		}
	}

	int S=0;
	for(int i=0; i<length; i++) S+=A[i]*B[i];

	printf("%d\n", S);
	return 0;
}