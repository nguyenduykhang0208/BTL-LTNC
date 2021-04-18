#include<stdio.h>
#include<string.h>

struct sinhvien;
void xuatds(struct SinhVien*, int);
void danhsach();

struct Diem{
	float toan;
	float ly;
	float hoa;
	float dtb;
};

struct hoten{
	char ho[30];
	char dem[30];
	char ten[30];
};

struct sinhvien{
	int mssv;
	char gioitinh[10];
	struct Diem diem;
	struct hoten hovaten;
	int tuoi;
	
};

void nhaphoten(struct hoten *ten){
	printf("Ho: ");
	scanf("%s", ten->ho);
	printf("Ten dem: ");
	scanf("%s", ten->dem);
	printf("Ten: ");
	scanf("%s", ten->ten);
}

void nhapdiem(struct Diem *diem){
	printf("Toan: ");
	scanf("%f", &diem->toan);
	printf("Ly: ");
	scanf("%f", &diem->ly);
	printf("Hoa: ");
	scanf("%f", &diem->hoa);
	diem->dtb= (diem->toan + diem->hoa + diem->ly)/3;
}


struct sinhvien nhapSV()
{
	struct sinhvien sv;
	printf("MSSV: ");
	scanf("%d", &sv.mssv);
	nhaphoten(&sv.hovaten);
	printf("Tuoi: ");
	scanf("%d", &sv.tuoi);
	printf("Gioi tinh: ");
	scanf("%s", sv.gioitinh);
	nhapdiem(&sv.diem);
	return sv;
}

void hienthittsv(struct sinhvien sv){
	printf("%-10d %-10s %-20s %-10s %-10d %-10s %-10.2f %-10.2f %-10.2f %-10.2f\n",
	sv.mssv, sv.hovaten.ho, sv.hovaten.dem, sv.hovaten.ten, sv.tuoi, sv.gioitinh, sv.diem.toan, sv.diem.ly, sv.diem.hoa ,sv.diem.dtb);
}

void sapxeptheoten(struct sinhvien *ds, int n){
	for(int i=0 ; i<n-1 ; i++){
		for(int j=n-1 ; j>i ; j-- ){
			if(strcmp(ds[j].hovaten.ten, ds[j-1].hovaten.ten) < 0 ){
				struct sinhvien sv=ds[j];
				ds[j] = ds [j-1];
				ds[j-1] = sv;
				
			}
		}
	}
}
void sapxeptheodiem(struct sinhvien *ds, int n){
	for(int i=0 ; i<n-1 ; i++){
		for(int j=i+1 ; j<n ; j++ ){
			if(ds[i].diem.dtb < ds[j].diem.dtb){
				struct sinhvien sv=ds[j];
				ds[j] = ds [i];
				ds[i] = sv;
				
			}
		}
	}
}


void timkiem(struct sinhvien* ds, int n){
	char ten[30];
	printf("Nhap ten can tim: \n");
	scanf("%s", &ten);
	int dem=0;
	danhsach();
	for(int i=0; i<n ; i++){
		if(strcmp(ten, ds[i].hovaten.ten) == 0 ){
			hienthittsv(ds[i]);
			dem = 1;
		}
	}
	if(dem == 0){
		printf("Khong co sinh vien %s trong danh sach!\n", ten);
	}
}

void ghiFile(struct sinhvien* ds, int n) {
	getchar();
	char fName[26];
	printf("Nhap ten file: ");
	gets(fName);
	FILE* fOut = fopen(fName, "a");
	int i;
	for(i = 0; i < n; i++) {
		struct sinhvien sv = ds[i];
		fprintf(fOut, "%-10d %-10s %-20s %-10s %-10d %-10s %-10.2f %-10.2f %-10.2f %-10.2f\n",
		sv.mssv, sv.hovaten.ho, sv.hovaten.dem, sv.hovaten.ten, sv.tuoi, sv.gioitinh,
		sv.diem.toan, sv.diem.ly, sv.diem.hoa, sv.diem.dtb);
	}
	fclose(fOut);
}

void docFile(struct sinhvien* ds, int* n) {
	FILE* fOut = fopen("SV.txt", "r");
	int i = 0;
	if(fOut) {
		for(;;) {
			struct sinhvien sv;
			fscanf(fOut, "%10d %10s %20[^\n] %10s %10d %10s %10f %10f %10f %10f\n",
			&sv.mssv, sv.hovaten.ho, sv.hovaten.dem, sv.hovaten.ten, &sv.tuoi, sv.gioitinh,
			&sv.diem.toan, &sv.diem.ly, &sv.diem.hoa, &sv.diem.dtb);
			
			ds[i++] = sv;
			if(feof(fOut)) { 
				break;
			}
		}
	}
	
	fclose(fOut);
	*n = i;
}

void danhsach(){
	printf("----------------------------------------------------"
	"----------------------------------------------------------------\n");
	printf("%-10s %-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n " , "MSSV" , "Ho" ,
	 "Ten dem" , "Ten", "Tuoi" , "Gioi tinh" , "Toan", "Ly" , "Hoa" , "DiemTB");
}

void xuatds(struct sinhvien* ds, int n){
	danhsach();
	for(int i=0;i<n;i++){
		hienthittsv(ds[i]);
	}
	printf("-----------------------------------------------------"
	"--------------------------------------------------------------\n");

}

int main() {
	struct sinhvien dssv[100];
	int n = 0;
	int luaChon;
	
	docFile(dssv, &n);
	printf("DANH SACH SINH VIEN HIEN THOI:\n");
	xuatds(dssv, n);
	int i;
				
	do {
		printf("=============== MENU ===============");
		printf("\n1. Them Sinh vien vao danh sach.");
		printf("\n2. Hien thi danh sach sinh vien.");
		printf("\n3. Sap xep theo ten.");
		printf("\n4. Sap xep theo diem giam dan.");
		printf("\n5. Tim sinh vien theo ten.");
		printf("\n6. Ghi thong tin sinh vien ra file.");
		printf("\n0. Thoat chuong trinh.");
		printf("\nBan chon ? ");
		
		scanf("%d", &luaChon);
		struct sinhvien sv;
		
		switch(luaChon) {
			case 0:
				break;
				
			case 1:
				sv = nhapSV();
				dssv[n++] = sv;
				break; 
				
			case 2:
				xuatds(dssv, n);
				break;
				
			case 3:
				sapxeptheoten(dssv, n);
				printf("\nDanh sach sinh vien sau khi sap xep theo ten a-z:\n");
				xuatds(dssv, n);
				break;
				
			case 4:
				sapxeptheodiem(dssv, n);
				printf("\nDanh sach sinh vien sau khi sap xep theo diem giam dan:\n");
				xuatds(dssv, n);
				break;
				
			case 5:
				timkiem(dssv, n);
				break;
				
			case 6:
				ghiFile(dssv, n);
				break;
				
			default:
				printf("Sai chuc nang, vui long chon lai!\n");
				break;
		}
		
	} while(luaChon);
	
	return 0;
}

