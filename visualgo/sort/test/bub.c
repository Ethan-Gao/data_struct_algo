void bub_sort(int arr[], int cnt){
	int i = 0, j = 0, tmp = 0;

	for(i = 0; i < (cnt-1); i++)
		for(j = 0; j < (cnt-1-i); j++){
			if(arr[j] > arr[j+1]){// 从小到大
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
}
