#include <stdio.h>
#include <algorithm>

//void q_sort(int *array, int s, int e);
//void swap(int *a, int *b);
//int binary_search(int value, int* array, int arr_size);
//int binary_search(int dataArr[], int size, int findData);

int main(void){
	int n;
	scanf("%d", &n);
	int A[n];
	for(int i=0; i<n; i++) scanf("%d", &A[i]);

	int m;
	scanf("%d", &m);
	int B[m];
	for(int i=0; i<m; i++) scanf("%d", &B[i]);

	std::sort(A, A+n);
	//q_sort(A, 0, n-1);

	//검색
	//for(int i=0; i<m; i++) printf("%d\n", binary_search(B[i], A, n));
	//for(int i=0; i<m; i++) printf("%d\n", binary_search(A, n, B[i]));
	for(int i=0; i<m; i++) printf("%d\n", std::binary_search(A, A+n, B[i]));

	return 0;
}

//퀵 정렬
/*void q_sort(int *array, int s, int e){ 
	int bs=s, be=e;
	int pivot=array[s];
	while(s<e){
		while(pivot<=array[e] && s<e) e--;
		if(s>e) break;
		while(pivot>=array[s] && s<e) s++;
		if(s>e) break;
		swap(&array[s], &array[e]);
	}
	swap(&array[bs], &array[s]);
	if(bs<s) q_sort(array, bs, s-1);
	if(be>e) q_sort(array, s+1, be);
}

void swap(int *a, int *b){
	int tmp=*a;
	*a = *b;
	*b = tmp;
}*/

// 이진 탐색
/*int binary_search(int value, int *array, int arr_size){
	int s=0, e=arr_size-1;

	while(s<e){
		int mid=(s+e)/2;
		if(vlaue<array[mid]) e=mid-1;
		else if(vlaue>array[mid]) s=mid+1;
		else return 1;
	}
	return 0;
}*/