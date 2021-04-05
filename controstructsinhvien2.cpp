#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Diem{
	float toan;
	float ly;
	float hoa;
	float dtb;
};
struct Sinhvien{
	char ten[30];
	int tuoi;
	char gioitinh[10];
	Diem*diem;
};
typedef Sinhvien Sv;

void nhapdiem(Diem*diem){
	printf("nhap diem toan: ");
	scanf("%f", diem->toan);
	printf("nhap diem hoa: ");
	scanf("%f", diem->hoa);
	printf("nhap diem ly: ");
	scanf("%f", diem->ly);
}
void xuatdiem(Diem*diem){
	printf("Toan: %.2f", diem->toan);
	printf("Ly: %.2f", diem->ly);
	printf("Hoa: %.2f", diem->hoa);
	
}
void nhapsv(Sv*a){
	fflush(stdin);
	printf("nhap ho va ten: ");
	gets(a->ten);
	printf("nhap tuoi: ");
	scanf("%f", a->tuoi);
	fflush(stdin);
	printf("nhap gioi tinh: ");
	gets(a->gioitinh);
	nhapdiem(a->diem);
	
}
void xuatsv(Sv*a){
	printf("Ho va ten:%s \n", a->ten);
	printf("Tuoi:%d \n", a->tuoi);
	printf("Gioi tinh: %s\n", a->gioitinh);
	xuatdiem(a->diem);
}
void nhapds(Sv*a, int &n){
	printf("nhap so sinh vien: \n");
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		printf("sinh vien thu %d: \n", i);
		nhapsv(a+i);
	}
}
void xuatds(Sv*a, int &n){
	printf("----------Thong tin da nhap--------\n");
	for(int i=0;i<n;i++){
		printf("sinh vien thu %d: \n", i);
		xuatsv(a+i);
	}
}
int main(){
	int n;
	Sv*a;
	a=(Sv*)malloc(sizeof(Sv)*n);
	a->diem=(Diem*)malloc(sizeof(Diem));
	nhapds(a,n);
	xuatds(a,n);
}
