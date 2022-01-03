#include<stdio.h>
int binarySearch(int a[],int x,int n){
	int l=0,r=n-1;
	int mid;
	while(l<=r){
		mid = (l+r)/2;
		if (a[mid]==x) return mid;
		if (a[mid]>x) r=mid-1;
		else l=mid+1;
	}
	return -1;
}
int binarySearch_DeQui(int a[], int l, int r, int x) {
  if (r < l)  return -1;
    int mid = l + (r - l) / 2; 
    if (a[mid] == x)
      return mid;
    if (a[mid] > x)
      return binarySearch_DeQui(a, l, mid - 1, x);
    return binarySearch_DeQui(a, mid + 1, r, x);
}
 
int main() {
  int a[] = {2,3,4,5,6};
  int n = 5;
  int x = 4;
 int r = binarySearch_DeQui(a, 0, n - 1, x);
  if (r == -1)
    printf("ko co x trong mang");
  else
    printf("%d xuat hien tai vi tri %d", x, r+1);
  return 0;
}
